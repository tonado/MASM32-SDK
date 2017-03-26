; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

szLtrim proc src:DWORD,dst:DWORD

    push edi

    xor ecx, ecx
    mov edx, src
    mov edi, dst
    sub edx, 1

  @@:
    add edx, 1
    cmp BYTE PTR [edx], 32
    je @B
    cmp BYTE PTR [edx], 9
    je @B
    cmp BYTE PTR [edx], 0
    jne @F
    xor eax, eax            ; return zero on empty string
    mov BYTE PTR [edi], 0   ; set string length to zero
    jmp szlOut
  @@:
    mov al, [edx+ecx]
    mov [edi+ecx], al
    add ecx, 1
    test al, al
    jne @B

    mov eax, ecx
    sub eax, 1              ; don't count ascii zero
                            ; return length of remaining string

    mov ecx, dst

  szlOut:
    pop edi

    ret

szLtrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end