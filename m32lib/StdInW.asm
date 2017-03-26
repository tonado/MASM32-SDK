; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

StdInW proc lpszBuffer:DWORD,chcnt:DWORD

    LOCAL hInput :DWORD
    LOCAL bRead  :DWORD

    mov hInput, rv(GetStdHandle,STD_INPUT_HANDLE)
    invoke SetConsoleMode,hInput,ENABLE_LINE_INPUT or \
                                 ENABLE_ECHO_INPUT or \
                                 ENABLE_PROCESSED_INPUT

    fn ReadConsole,hInput,lpszBuffer,chcnt,ADDR bRead,NULL

  ; -------------------------------------------
  ; trim off the CR LF and terminate the string
  ; -------------------------------------------
    mov edx, lpszBuffer
    sub edx, 2
  @@:
    add edx, 2
    cmp WORD PTR [edx], 0
    je @F
    cmp WORD PTR [edx], 13
    jne @B
    mov WORD PTR [edx], 0
  @@:

    mov eax, bRead
    sub eax, 2

    ret

StdInW endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
