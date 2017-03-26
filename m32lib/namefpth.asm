; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

NameFromPath proc src:DWORD,dst:DWORD

    push esi
    push edi

    mov esi, src
    mov ecx, esi
    mov edx, -1
    xor eax, eax

  @@:
    add edx, 1
    cmp BYTE PTR [esi+edx], 0       ; test for terminator
    je @F
    cmp BYTE PTR [esi+edx], "\"     ; test for "\"
    jne @B
    mov ecx, edx
    jmp @B
  @@:
    cmp ecx, esi                    ; test if ECX has been modified
    je error                        ; exit on error if it is the same
    lea ecx, [ecx+esi+1]            ; add ESI to ECX and increment to following character
    mov edi, dst                    ; load destination address
    mov edx, -1
  @@:
    add edx, 1
    mov al, [ecx+edx]               ; copy file name to destination
    mov [edi+edx], al
    test al, al                     ; test for written terminator
    jnz @B

    sub eax, eax                    ; return value zero on success
    jmp nfpout

  error:
    mov eax, -1                     ; invalid path no "\"

  nfpout:

    pop edi
    pop esi

    ret

NameFromPath endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end