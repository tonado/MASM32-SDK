; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucRev proc wsrc:DWORD,wdst:DWORD

    push esi
    push edi

    xor eax, eax
    mov esi, [esp+12]
    mov edi, [esp+16]
    mov ecx, -2

  @@:
    add ecx, 2
    mov ax, [esi+ecx]       ; copy src to dst and get character count
    mov [edi+ecx], ax
    test ax, ax
    jnz @B

    cmp ecx, 4              ; test for single character
    jb dont_bother          ; bypass swap code if it is

    mov esi, edi            ; put dst address in ESI
    add edi, ecx
    sub edi, 2
    shr ecx, 2              ; divide byte count by 4 to get loop counter

  @@:
    mov ax, [esi]           ; swap end characters until middle
    mov dx, [edi]
    mov [edi], ax
    mov [esi], dx
    add esi, 2
    sub edi, 2
    sub ecx, 1
    jnz @B

  dont_bother:

    pop edi
    pop esi

    ret 8

ucRev endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
