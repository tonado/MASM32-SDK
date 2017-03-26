; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    cmpmem PROTO :DWORD,:DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

cmpmem proc buf1:DWORD,buf2:DWORD,bcnt:DWORD

    mov ecx, [esp+4]    ; buf1
    mov edx, [esp+8]    ; buf2

    push esi
    push edi

    xor esi, esi
    xor eax, eax
    mov edi, [esp+20]   ; bcnt
    cmp edi, 4
    jb under

    shr edi, 2                      ; div by 4

  align 4
  @@:
    mov eax, [ecx+esi]              ; DWORD compare main file
    cmp eax, [edx+esi]
    jne fail
    add esi, 4
    sub edi, 1
    jnz @B

    mov edi, [esp+20]   ; bcnt      ; calculate any remainder
    and edi, 3
    jz match                        ; exit if its zero

  under:
    movzx eax, BYTE PTR [ecx+esi]   ; BYTE compare tail
    cmp al, [edx+esi]
    jne fail
    add esi, 1
    sub edi, 1
    jnz under

    jmp match

  fail:
    xor eax, eax                    ; return zero if DIFFERENT
    jmp quit

  match:
    mov eax, 1                      ; return NON zero if SAME

  quit:
    pop edi
    pop esi

    ret 12

cmpmem endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
