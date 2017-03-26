; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    SetClipboardText PROTO :DWORD

    .code       ; code section

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

SetClipboardText proc ptxt:DWORD

    LOCAL hMem  :DWORD
    LOCAL pMem  :DWORD
    LOCAL slen  :DWORD

    invoke StrLen, ptxt                         ; get length of text
    mov slen, eax
    add slen, 64

    invoke GlobalAlloc,GMEM_MOVEABLE or \
           GMEM_DDESHARE,slen                   ; allocate memory
    mov hMem, eax
    invoke GlobalLock,hMem                      ; lock memory
    mov pMem, eax

    cst pMem, ptxt                              ; copy text to allocated memory

    invoke OpenClipboard,NULL                   ; open clipboard
    invoke SetClipboardData,CF_TEXT,pMem        ; write data to it
    invoke CloseClipboard                       ; close clipboard

    invoke GlobalUnlock,hMem                    ; unlock memory
    invoke GlobalFree,hMem                      ; deallocate memory

    ret

SetClipboardText endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
