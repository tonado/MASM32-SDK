; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

stripasm proc src:DWORD,dst:DWORD,ln:DWORD

  ; -------------------------------
  ; left and right trims each line
  ; removes duplicate spaces
  ; removes comments, everything from ";" to end of line
  ; left and right trims commas
  ; copies quoted text without filtering the content
  ; reports quotation errors as -1 ret val
  ; -------------------------------

    LOCAL exo   :DWORD      ; exit offset
    LOCAL lc    :DWORD      ; line count

    push ebx
    push esi
    push edi

    mov esi, src
    mov edi, dst
    mov eax, ln
    add eax, esi
    mov exo, eax
    inc exo                 ; exo is the exit offset

  pre:                      ; strip leading blanks
    mov al, [esi]
    inc esi
    cmp esi, exo
    je saOut
    cmp al, 32
    je pre
    dec esi

; --------------------
; main branching loop
; --------------------
  saStart:
    mov al, [esi]
    inc esi
    cmp esi, exo
    je saOut
    cmp al, 34
    je quote
    cmp al, 13
    je cret
    cmp al, 10
    je lfeed
    cmp al, ","
    je comma
    cmp al, 32
    je blanks
    cmp al, ";"
    je scolon
    mov [edi], al
    inc edi
    jmp saStart

  ; -----------------------------------------------------
  quote:
    mov [edi], al           ; write 1st quote
    inc edi
  @@:
    mov al, [esi]
    inc esi
    cmp esi, exo
    je qerror
    mov [edi], al
    inc edi
    cmp al, 34
    je saStart
    cmp al, 13
    je qerror
    jmp @B

  qerror:
    mov eax, -1
    jmp errOut
  ; -----------------------------------------------------
  scolon:                   ; ";" semicolon
    mov al, [esi]
    inc esi
    cmp esi, exo
    je saOut
    cmp al, 13              ; scan forward to find next CR
    jne scolon              ; while not writing to output buffer
  @@:
    cmp BYTE PTR [edi-1], 32
    jne @F
    dec edi
    jmp @B                  ; trim trailing blanks
  @@:
    mov [edi], al
    inc edi
    jmp pre
  ; -----------------------------------------------------
  comma:                    ; , comma
    cmp BYTE PTR [edi-1], 32
    jne @F
    dec edi
    jmp comma               ; trim trailing blanks
  @@:
    mov [edi], al
    inc edi
    jmp pre
  ; -----------------------------------------------------
  cret:                     ; 13 carriage return
    cmp BYTE PTR [edi-1], 32
    jne @F
    dec edi
    jmp cret                ; strip trailing blanks
  @@:
    mov [edi], al
    inc edi
    jmp pre
  ; -----------------------------------------------------
  lfeed:                    ; 10 line feed
    mov [edi], al
    inc edi
    jmp pre
  ; -----------------------------------------------------
  blanks:                   ; 32 space
    mov [edi], al           ; write 1st blank space
    inc edi
    cmp BYTE PTR [esi-1], 32; next char in ESI
    jne saStart
    jmp pre
  ; -----------------------------------------------------

  saOut:
    mov eax, edi
    sub eax, dst            ; calculate bytes written to output buffer

  errOut:

    pop edi
    pop esi
    pop ebx

    ret

stripasm endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
