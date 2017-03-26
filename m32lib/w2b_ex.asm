; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    EXTERNDEF bintable:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

wrd2bin_ex proc var:WORD,buffer:DWORD

    push ebx

    mov ebx, OFFSET bintable
    xor eax, eax
    mov edx, buffer

    mov al, BYTE PTR [var+1]
    mov ecx, [ebx+eax*8]
    mov [edx], ecx
    mov ecx, [ebx+eax*8+4]
    mov [edx+4], ecx

    mov al, BYTE PTR [var]
    mov ecx, [ebx+eax*8]
    mov [edx+8], ecx
    mov ecx, [ebx+eax*8+4]
    mov [edx+12], ecx

    mov BYTE PTR [edx+16], 0

    pop ebx

    ret

wrd2bin_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
