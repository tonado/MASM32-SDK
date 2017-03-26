; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; create 32 bit code
    .model flat, stdcall      ; 32 bit memory model
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

szTrim proc src:DWORD

    push esi
    push edi

    mov esi, src
    mov edi, src
    xor ecx, ecx

    sub esi, 1
  @@:
    add esi, 1
    cmp BYTE PTR [esi], 32  ; strip space
    je @B
    cmp BYTE PTR [esi], 9   ; strip tab
    je @B
    cmp BYTE PTR [esi], 0   ; test for zero after tabs and spaces
    jne @F
    xor eax, eax            ; set EAX to zero on 0 length result
    mov BYTE PTR [edi], 0   ; set string length to zero
    jmp tsOut               ; and exit

  @@:
    mov al, [esi+ecx]       ; copy bytes from src to dst
    mov [edi+ecx], al
    add ecx, 1
    test al, al
    je @F                   ; exit on zero
    cmp al, 33              ; don't store positions lower than 33 (32 + 9)
    jb @B
    mov edx, ecx            ; store count if asc 33 or greater
    jmp @B

  @@:
    mov BYTE PTR [edi+edx], 0

    mov eax, edx        ; return trimmed string length
    mov ecx, src

  tsOut:

    pop edi
    pop esi

    ret

szTrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end