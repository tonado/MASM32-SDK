; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    EXTERNDEF bintable:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

byt2bin_ex proc var:BYTE,buffer:DWORD

    push ebx

    mov ebx, OFFSET bintable
    xor eax, eax
    mov edx, buffer

    mov al, BYTE PTR [var]
    mov ecx, [ebx+eax*8]
    mov [edx], ecx
    mov ecx, [ebx+eax*8+4]
    mov [edx+4], ecx

    mov BYTE PTR [edx+8], 0

    pop ebx

    ret

byt2bin_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
