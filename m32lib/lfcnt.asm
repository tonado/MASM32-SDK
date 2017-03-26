; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    lfcnt PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

lfcnt proc txt:DWORD

  ; ---------------------------------------------
  ; get line count of text by counting line feeds
  ; ---------------------------------------------
    mov eax, -1
    mov ecx, txt
    sub ecx, 1

  pre:
    add eax, 1                              ; add 1 to return value if LF found
  @@:
    add ecx, 1
    cmp BYTE PTR [ecx], 0                   ; test for zero terminator
    je ccout
    cmp BYTE PTR [ecx], 10                  ; test line feed
    je pre
    jmp @B

  ccout:

    ret

lfcnt endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
