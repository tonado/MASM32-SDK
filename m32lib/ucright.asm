; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include masm32.inc

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucRight proc wsrc:DWORD,wdst:DWORD,ccnt:DWORD

    push edi

    mov eax, [esp+16]
    add [esp+16], eax           ; double ccnt

    invoke ucLen, [esp+8]
    add eax, eax                ; double char count to get byte length

    mov edx, [esp+8]
    add edx, eax
    sub edx, [esp+16]
    mov edi, [esp+12]
    xor ecx, ecx

  @@:
    mov ax, [edx+ecx]
    mov [edi+ecx], ax
    add ecx, 2
    test ax, ax
    jne @B

    pop edi

    ret 12

ucRight endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
