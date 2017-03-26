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

ucLeft proc wsrc:DWORD,wdst:DWORD,ccnt:DWORD

    push edi

    mov eax, [esp+16]
    add [esp+16], eax               ; double ccnt

    mov eax, [esp+8]
    mov edi, [esp+12]
    xor ecx, ecx

  @@:
    mov dx, [eax+ecx]
    mov [edi+ecx], dx
    add ecx, 2
    cmp ecx, [esp+16]
    jne @B

    mov WORD PTR [edi+ecx], 0

    pop edi

    ret 12

ucLeft endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
