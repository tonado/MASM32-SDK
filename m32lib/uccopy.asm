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

ucCopy proc wsrc:DWORD,wdst:DWORD

    push edi

    xor eax, eax            ; clear EAX for partial register read/writes
    mov edx, [esp+8]
    mov edi, [esp+12]
    mov ecx, -2

  @@:
    add ecx, 2
    mov ax, [edx+ecx]       ; copy src to dst and get character count
    mov [edi+ecx], ax
    test ax, ax
    jnz @B

    pop edi

    ret 8

ucCopy endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
