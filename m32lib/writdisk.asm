; #########################################################################

      .386                      ; force 32 bit code
      .model flat, stdcall      ; memory model & calling convention
      option casemap :none      ; case sensitive

      include \masm32\include\windows.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\user32.inc

      write_disk_file PROTO :DWORD,:DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

write_disk_file proc lpName:DWORD,lpData:DWORD,fl:DWORD

comment * -------------------------------------------
        return value is the number of bytes written
        if the procedure succeeds or zero if it fails
        ------------------------------------------- *

    LOCAL hOutput:DWORD
    LOCAL bw     :DWORD

    invoke CreateFile,lpName,GENERIC_WRITE,NULL,NULL,
                      CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL

    cmp eax, INVALID_HANDLE_VALUE
    jne @F
    xor eax, eax
    ret
  @@:
    mov hOutput, eax
    invoke WriteFile,hOutput,lpData,fl,ADDR bw,NULL
    invoke FlushFileBuffers,hOutput
    invoke CloseHandle,hOutput

    mov eax, bw                 ; return written byte count
    ret

write_disk_file endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end