; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    include \masm32\macros\macros.asm

    szRep   PROTO :DWORD,:DWORD,:DWORD,:DWORD
    szLen   PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

szRep proc src:DWORD,dst:DWORD,txt1:DWORD,txt2:DWORD

    LOCAL lsrc  :DWORD

    push ebx
    push esi
    push edi

    mov lsrc, len(src)          ; procedure call for src length
    sub lsrc, len(txt1)         ; procedure call for 1st text length

    mov esi, src
    add lsrc, esi               ; set exit condition
    mov ebx, txt1
    add lsrc, 1                 ; adjust to get last character
    mov edi, dst
    sub esi, 1
    jmp rpst
  ; ----------------------------
  align 4
  pre:
    add esi, ecx                ; ecx = len of txt1, add it to ESI for next read
  align 4
  rpst:
    add esi, 1
    cmp lsrc, esi               ; test for exit condition
    jle rpout
    movzx eax, BYTE PTR [esi]   ; load byte from source
    cmp al, [ebx]               ; test it against 1st character in txt1
    je test_match
    mov [edi], al               ; write byte to destination
    add edi, 1
    jmp rpst
  ; ----------------------------
  align 4
  test_match:
    mov ecx, -1                 ; clear ECX to use as index
    mov edx, ebx                ; load txt1 address into EDX
  @@:
    add ecx, 1
    movzx eax, BYTE PTR [edx]
    test eax, eax               ; if you have got to the zero
    jz change_text              ; replace the text in the destination
    add edx, 1
    cmp [esi+ecx], al           ; keep testing character matches
    je @B
    movzx eax, BYTE PTR [esi]   ; if text does not match
    mov [edi], al               ; write byte at ESI to destination
    add edi, 1
    jmp rpst
  ; ----------------------------
  align 4
  change_text:                  ; write txt2 to location of txt1 in destination
    mov edx, txt2
    sub ecx, 1
  @@:
    movzx eax, BYTE PTR [edx]
    test eax, eax
    jz pre
    add edx, 1
    mov [edi], al
    add edi, 1
    jmp @B
  ; ----------------------------
  align 4
  rpout:                        ; write any last bytes and terminator
    mov ecx, -1
  @@:
    add ecx, 1
    movzx eax, BYTE PTR [esi+ecx]
    mov [edi+ecx], al
    test eax, eax
    jnz @B

    pop edi
    pop esi
    pop ebx

    ret

szRep endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
