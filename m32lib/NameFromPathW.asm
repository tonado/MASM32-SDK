; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    NameFromPathW PROTO :DWORD,:DWORD

    .code       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

align 4

NameFromPathW proc src:DWORD,dst:DWORD

    push esi
    push edi

    mov esi, src
    mov ecx, esi
    mov edx, -2
    xor eax, eax

  @@:
    add edx, 2
    cmp WORD PTR [esi+edx], 0       ; test for terminator
    je @F
    cmp WORD PTR [esi+edx], "\"     ; test for "\"
    jne @B
    mov ecx, edx
    jmp @B
  @@:
    cmp ecx, esi                    ; test if ECX has been modified
    je error                        ; exit on error if it is the same
    lea ecx, [ecx+esi+2]            ; add ESI to ECX and increment to following character
    mov edi, dst                    ; load destination address
    mov edx, -2
  @@:
    add edx, 2
    mov ax, [ecx+edx]               ; copy file name to destination
    mov [edi+edx], ax
    test ax, ax                     ; test for written terminator
    jnz @B

    sub eax, eax                    ; return value zero on success
    jmp nfpout

  error:
    mov eax, -2                     ; invalid path no "\"

  nfpout:

    pop edi
    pop esi

    ret

NameFromPathW endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
