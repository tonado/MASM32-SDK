; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucMid proc wsrc:DWORD,wdst:DWORD,stPos:DWORD,ln:DWORD

    push edi

    mov eax, [esp+16]
    add [esp+16], eax               ; double start pos
    sub DWORD PTR [esp+16], 2       ; correct for base 1 character

    mov eax, [esp+20]               ; double length
    add [esp+20], eax

    mov edx, [esp+8]
    add edx, [esp+16]
    mov edi, [esp+12]
    xor ecx, ecx

  @@:
    mov ax, [edx+ecx]
    mov [edi+ecx], ax
    add ecx, 2
    cmp ecx, [esp+20]
    jne @B

    mov WORD PTR [edi+ecx], 0

    pop edi

    ret 16

ucMid endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
