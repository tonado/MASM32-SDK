; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

wshell proc lpfilename:DWORD

    LOCAL xc :DWORD             ; exit code
    LOCAL st_info:STARTUPINFO
    LOCAL pr_info:PROCESS_INFORMATION

  ; ---------------------
  ; zero fill STARTUPINFO
  ; ---------------------
    mov ecx, 17                 ; 68 bytes SIZEOF STARTUPINFO
    lea edx, st_info
    xor eax, eax
  @@:
    mov [edx], eax
    add edx, 4
    sub ecx, 1
    jnz @B

    mov st_info.cb, 68          ; set the structure size member

    invoke CreateProcess,NULL,lpfilename,NULL,NULL,
                         NULL,NULL,NULL,NULL,
                         ADDR st_info,
                         ADDR pr_info

    invoke WaitForSingleObject, pr_info.hProcess, INFINITE

    invoke CloseHandle, pr_info.hThread
    invoke CloseHandle, pr_info.hProcess

    ret

wshell endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
