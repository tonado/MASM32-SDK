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

ucCmp proc wst1:DWORD,wst2:DWORD

    push edi

    mov edx, [esp+8]
    mov edi, [esp+12]
    mov eax, -2
    xor ecx, ecx

  @@:
    add eax, 2
    mov cx, [edx+eax]
    cmp cx, [edi+eax]
    jne mismatch
    test cx, cx
    jnz @B

    shr eax, 1          ; half for character count on match
    jmp match

  mismatch:
    xor eax, eax        ; zero for mismatch

  match:
    pop edi

    ret 8

ucCmp endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
