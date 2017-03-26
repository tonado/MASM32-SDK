; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucLtrim proc wsrc:DWORD,wdst:DWORD

    mov edx, [esp+4]
    mov ecx, [esp+8]
    sub edx, 2

  @@:
    add edx, 2
    cmp WORD PTR [edx], 32
    jz @B

  @@:
    mov ax, [edx]
    mov [ecx], ax
    add edx, 2
    add ecx, 2
    test ax, ax
    jnz @B

    ret 8

ucLtrim endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
