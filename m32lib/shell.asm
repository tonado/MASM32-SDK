; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; create 32 bit code
    .model flat, stdcall      ; 32 bit memory model
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

shell proc lpfilename:DWORD

    LOCAL xc :DWORD         ; exit code
    LOCAL st_info:STARTUPINFO
    LOCAL pr_info:PROCESS_INFORMATION

    push edi

  ; ----------------------------
  ; zero fill the two structures
  ; ----------------------------
    mov ecx, SIZEOF STARTUPINFO
    lea edi, st_info
    xor eax, eax
    rep stosb
    mov st_info.cb, SIZEOF STARTUPINFO      ; set the structure size AFTER
                                            ; zero filling the rest
    mov ecx, SIZEOF PROCESS_INFORMATION
    lea edi, pr_info
    xor eax, eax
    rep stosb

    pop edi

    invoke CreateProcess,lpfilename,NULL,NULL,NULL,
                         NULL,NULL,NULL,NULL,
                         ADDR st_info,
                         ADDR pr_info

  ; -------------------------------------------
  ; loop while created process is still active
  ; -------------------------------------------
  @@:
    invoke GetExitCodeProcess,pr_info.hProcess,ADDR xc
    invoke Sleep, 1                                     ; surrender time slice
    cmp xc, STILL_ACTIVE
    je @B

    ret

shell endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end