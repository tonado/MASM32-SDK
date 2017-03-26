; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

arr_add proc arr:DWORD,cnt:DWORD,plus:DWORD

    mov edx, plus
    mov eax, arr
    mov ecx, cnt
    add ecx, ecx
    add ecx, ecx
    add eax, ecx
    neg ecx
    jmp @F

  align 16
  @@:
    add [eax+ecx], edx
    add ecx, 4
    jnz @B

    ret

arr_add endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
