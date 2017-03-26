; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

bstsorta proc arr:DWORD,lower:DWORD,upper:DWORD

    push ebx
    push esi
    push edi
    push ebp

    add lower, 1
    add upper, 1
    mov ebx, arr
    mov eax, lower
    add eax, eax
    add eax, eax
    add ebx, eax
    sub ebx, 4

    mov edi, upper
    sub edi, lower

    sub edi, 1
  bubble:
    xor ecx, ecx                ; low value index
    xor edx, edx                ; zero swap flag
  inner:
    mov ebp, [ebx+ecx*4]        ; lower value
    mov esi, [ebx+ecx*4+4]      ; swap values
    push edi
    mov edi, -1
  ; -------------------------------------------
  cmpstrings:
    add edi, 1
    mov al, [ebp+edi]           ; compare both strings
    cmp al, [esi+edi]
    jl noswap                   ; ascending sort
    jg swap                     ; swap these two labels for descending
    test al, al
    jnz cmpstrings
  ; -------------------------------------------
    jmp noswap
  swap:
    mov [ebx+ecx*4], esi
    mov [ebx+ecx*4+4], ebp
    mov edx, 1                  ; set the swap flag
  noswap:
    pop edi
    add ecx, 1
    cmp ecx, edi
    jle inner
    test edx, edx               ; EDX as zero means no swaps left.
    jnz bubble                  ; return and try again if there is.

    pop ebp
    pop edi
    pop esi
    pop ebx

    ret

bstsorta endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
