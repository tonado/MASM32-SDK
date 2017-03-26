; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

szRtrim proc src:DWORD,dst:DWORD

    push esi
    push edi

    mov esi, src
    mov edi, dst
    sub esi, 1
  @@:
    add esi, 1
    cmp BYTE PTR [esi], 32
    je @B
    cmp BYTE PTR [esi], 9
    je @B
    cmp BYTE PTR [esi], 0
    jne @F
    xor eax, eax            ; return zero on empty string
    mov BYTE PTR [edi], 0   ; set string length to zero
    jmp szLout

  @@:
    mov esi, src
    xor ecx, edx
    xor ecx, ecx        ; ECX as index and location counter

  @@:
    mov al, [esi+ecx]   ; copy bytes from src to dst
    mov [edi+ecx], al
    add ecx, 1
    test al, al
    je @F               ; exit on zero
    cmp al, 33
    jb @B
    mov edx, ecx        ; store count if asc 33 or greater
    jmp @B

  @@:
    mov BYTE PTR [edi+edx], 0

    mov eax, edx        ; return length of trimmed string
    mov ecx, dst

  szLout:
    pop edi
    pop esi

    ret

szRtrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end