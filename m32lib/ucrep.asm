; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .686p                       ; maximum processor model
    .XMM                        ; SIMD extensions
    .model flat, stdcall        ; memory model & calling convention
    option casemap :none        ; case sensitive
 
    ucLen PROTO :DWORD
    ucRep PROTO :DWORD,:DWORD,:DWORD,:DWORD

    .code                       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

ucRep proc src:DWORD,dst:DWORD,txt1:DWORD,txt2:DWORD

    LOCAL lsrc  :DWORD

    push ebx
    push esi
    push edi

    invoke ucLen,src
    mov lsrc, eax

    invoke ucLen,txt1
    sub lsrc, eax

    mov eax, lsrc
    add lsrc, eax               ; double len to get byte length

    mov esi, src
    add lsrc, esi               ; set exit condition
    mov ebx, txt1
    add lsrc, 2                 ; adjust to get last character
    mov edi, dst
    sub esi, 2
    jmp rpst
  ; ----------------------------
  align 4
  pre:
    add esi, ecx                ; ecx = len of txt1, add it to ESI for next read
  align 4
  rpst:
    add esi, 2
    cmp lsrc, esi               ; test for exit condition
    jle rpout
    movzx eax, WORD PTR [esi]   ; load WORD from source
    cmp ax, [ebx]               ; test it against 1st character in txt1
    je test_match
    mov [edi], ax               ; write byte to destination
    add edi, 2
    jmp rpst
  ; ----------------------------
  align 4
  test_match:
    mov ecx, -2                 ; clear ECX to use as index
    mov edx, ebx                ; load txt1 address into EDX
  @@:
    add ecx, 2
    movzx eax, WORD PTR [edx]
    test eax, eax               ; if you have got to the zero
    jz change_text              ; replace the text in the destination
    add edx, 2
    cmp [esi+ecx], ax           ; keep testing character matches
    je @B
    movzx eax, WORD PTR [esi]   ; if text does not match
    mov [edi], ax               ; write byte at ESI to destination
    add edi, 2
    jmp rpst
  ; ----------------------------
  align 4
  change_text:                  ; write txt2 to location of txt1 in destination
    mov edx, txt2
    sub ecx, 2
  @@:
    movzx eax, WORD PTR [edx]
    test eax, eax
    jz pre
    add edx, 2
    mov [edi], ax
    add edi, 2
    jmp @B
  ; ----------------------------
  align 4
  rpout:                        ; write any last characters and terminator
    mov ecx, -2
  @@:
    add ecx, 2
    movzx eax, WORD PTR [esi+ecx]
    mov [edi+ecx], ax
    test eax, eax
    jnz @B

    pop edi
    pop esi
    pop ebx

    ret

ucRep endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
