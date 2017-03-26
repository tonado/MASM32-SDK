; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    __UNICODE__ equ 1

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucCatStr proc wstr1:DWORD,wstr2:DWORD

    mov edx, [esp+4]
    sub edx, 2
    mov ecx, [esp+8]
    xor eax, eax

  @@:
    add edx, 2
    cmp WORD PTR [edx], 0       ; find the end
    jne @B

  @@:
    mov ax, [ecx]               ; append 2nd string
    mov [edx], ax
    add ecx, 2
    add edx, 2
    test ax, ax
    jnz @B

    ret 8

ucCatStr endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
