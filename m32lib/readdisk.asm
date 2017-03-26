; #########################################################################

      .486                      ; force 32 bit code
      .model flat, stdcall      ; memory model & calling convention
      option casemap :none      ; case sensitive

      include \masm32\include\windows.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\user32.inc
      include \masm32\macros\macros.asm

      read_disk_file PROTO :DWORD,:DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

read_disk_file proc lpfname:DWORD,lpMem:DWORD,lpLen:DWORD

comment * -----------------------------------------------------
        the return value is zero on error else non-zero

        lpMem has the memory address written to it
        lpLen has the file length written to it

        the memory address written to lpMem must be
        deallocated using GlobalFree()
        ----------------------------------------------------- *

    LOCAL hFile :DWORD
    LOCAL fl    :DWORD
    LOCAL hMem  :DWORD
    LOCAL bRead :DWORD

    mov hFile, FUNC(CreateFile,lpfname,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,NULL,NULL)
    cmp hFile, INVALID_HANDLE_VALUE
    jne @F
    xor eax, eax                                    ; return zero on error
    ret
  @@:
    mov fl, FUNC(GetFileSize,hFile,NULL)            ; get the file length
    add fl, 32                                      ; add some spare bytes
    mov hMem, alloc(fl)                             ; allocate a buffer of that size
    invoke ReadFile,hFile,hMem,fl,ADDR bRead,NULL   ; read file into buffer
    invoke CloseHandle,hFile                        ; close the handle

    mov eax, lpMem                                  ; write memory address to
    mov ecx, hMem                                   ; address of variable
    mov [eax], ecx                                  ; passed on the stack

    mov eax, lpLen                                  ; write byte count to
    mov ecx, bRead                                  ; address of variable
    mov [eax], ecx                                  ; passed on the stack

    mov eax, 1                                      ; non zero value returned on success
    ret

read_disk_file endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end