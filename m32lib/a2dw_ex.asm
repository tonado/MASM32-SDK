; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    EXTERNDEF decade :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

atodw_ex proc lpstring:DWORD

    mov [ebp+12], edi

  ; ----------------------------------------------------
  ; unrolled StrLen algo to test up to 12 bytes for zero
  ; ----------------------------------------------------
    mov eax,lpstring                    ; get pointer to string
    lea edx,[eax+3]                     ; pointer+3 used in the end

    mov edi,[eax]                       ; read first 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h
    jnz @F

    mov edi,[eax]                       ; read next 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h
    jnz @F

    mov edi,[eax]                       ; read last 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h

  @@:
    test ecx,00008080h                  ; test first two bytes
    jnz @F
    shr ecx,16                          ; not in the first 2 bytes
    add eax,2
  @@:
    shl cl,1                            ; use carry flag to avoid branch
    sbb eax,edx                         ; compute length
  ; -------------------------------------------

    mov edi, eax                        ; length in EDI
    mov edx, lpstring
    sub edx, 1

    xor eax, eax

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+40]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+80]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+120]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+160]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+200]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+240]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+280]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+320]
    sub edi, 1
    jz atout

    movzx ecx, BYTE PTR [edx+edi]
    add eax, [ecx*4+decade-192+360]

  atout:

    mov edi, [ebp+12]

    ret

atodw_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
