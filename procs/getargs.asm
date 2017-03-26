; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

 ;   GetArgs PROTO :DWORD,:DWORD,:DWORD,:DWORD
 ;   SetVar  PROTO :DWORD,:DWORD,:DWORD,:DWORD
 ;   ccount  PROTO :DWORD,:BYTE

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

GetArgs proc src:DWORD,buffer:DWORD,lplb:DWORD,lprb:DWORD

  ; ---------------------------------------------------
  ; procedure reads the first argument between inner
  ; brackets reading from left to right. it writes the
  ; argument including the brackets to "buffer" and
  ; the starting and ending location for the argument 
  ; inclding brackets to the address of "lb" and "rb".
  ; ---------------------------------------------------

    push ebx
    push esi
    push edi

    mov esi, src
    mov edx, -1
    mov ecx, lplb
    mov DWORD PTR [ecx], -1
    mov edi, lprb
    mov DWORD PTR [edi], -1

    mov ebx, buffer             ; reset buffer address each "("

  lpStart:
    inc edx
    mov al, [esi+edx]
    cmp al, 0
    je lpEnd
    cmp al, "("
    jne @F
    mov [ecx], edx
    mov ebx, buffer             ; reset buffer address each "("
  @@:
    cmp al, ")"
    jne @F
    mov [edi], edx
    mov [ebx], al               ; write ")"
    inc ebx
    mov BYTE PTR [ebx], 0       ; append terminator after ")"
    jmp lpEnd                   ; then exit loop
  @@:
    mov [ebx], al               ; write each byte
    inc ebx
    jmp lpStart
  lpEnd:

    pop edi
    pop esi
    pop ebx

    ret

GetArgs endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

SetVar proc src:DWORD,repl:DWORD,lb:DWORD,rb:DWORD

  ; ------------------------------------------------------
  ; replace inner bracketed argument with variable "repl"
  ; ------------------------------------------------------
    push esi
    push edi

    mov esi, repl
    mov edi, src
    add edi, lb     ; set starting position to write

  @@:
    mov al, [esi]
    inc esi
    cmp al, 0
    je @F
    mov [edi], al
    inc edi
    jmp @B

  @@:
    mov esi, src
    add esi, rb
    inc esi

  @@:
    mov al, [esi]
    inc esi
    mov [edi], al
    inc edi
    cmp al, 0
    jne @B
    
    pop edi
    pop esi

    ret

SetVar endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ccount proc src:DWORD, char:BYTE

  ; ------------------------------------------
  ; count character in zero terminated string
  ; ------------------------------------------
    mov ecx, src
    xor eax, eax        ; use as counter
    mov dl, char
    dec ecx

  @@:
    inc ecx
    cmp BYTE PTR [ecx], 0
    je @F
    cmp [ecx], dl
    jne @B
    inc eax
    jmp @B
  @@:

    ret

ccount endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
