; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucRtrim proc wsrc:DWORD,wdst:DWORD

    push esi
    push edi

    mov esi, [esp+12]
    mov edi, [esp+16]
    xor ecx, ecx
    xor eax, eax
    xor edx, edx

  rtst:
    mov ax, [esi+ecx]
    mov [edi+ecx], ax
    test ax, ax
    jz rtout
    add ecx, 2
    cmp ax, 32
    je rtst
    mov edx, ecx
    jmp rtst

  rtout:

    mov WORD PTR [edi+edx], 0

    pop edi
    pop esi

    ret 8

ucRtrim endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
