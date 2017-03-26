; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

shell_ex proc lpfilename:DWORD,process_priority:DWORD

    LOCAL xc    :DWORD          ; exit code
    LOCAL cth   :DWORD          ; current thread handle
    LOCAL cpr   :DWORD          ; current priority status
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

    invoke SetPriorityClass,pr_info.hProcess,process_priority

    mov cth, FUNC(GetCurrentThread)
    mov cpr, FUNC(GetThreadPriority,cth)
    invoke SetThreadPriority,cth,THREAD_PRIORITY_IDLE

  ; -------------------------------------------
  ; loop while created process is still active
  ; -------------------------------------------
  @@:
    invoke GetExitCodeProcess,pr_info.hProcess,ADDR xc
    invoke Sleep, 1                                     ; modified on suggestion by Jibz.
    cmp xc, STILL_ACTIVE
    je @B

    invoke SetThreadPriority,cth,cpr

    invoke CloseHandle, pr_info.hThread
    invoke CloseHandle, pr_info.hProcess

    ret

shell_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
