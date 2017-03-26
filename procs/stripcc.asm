; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
;               Strip C and C++ comments from source code
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

stripcc proc lpsource:DWORD,lnsource:DWORD,lpresult:DWORD

; -------------------------------------------------------------
; stripcc removes C++ comments // and old style C comments
; /*------------- old style C comment -----------------*/
; removes trailing spaces on lines, with or without comments
; -------------------------------------------------------------

    push ebx
    push esi
    push edi

    mov esi, lpsource
    mov edi, lpresult
    mov ecx, lnsource
    add ecx, esi            ; exit condition in ECX

  lbl1:
    mov al, [esi]
    inc esi
    cmp al, "/"
    je comment1
  rtn:
    cmp al, 13              ; branch to trim trailing spaces
    je trimr
  nxt1:
    mov [edi], al
    inc edi
    cmp esi, ecx
    je outa_here            ; exit on source length
    jmp lbl1

  trimr:                    ; trim trailing spaces
    cmp BYTE PTR [edi-1], 32
    jne nxt1
    dec edi
    jmp trimr

  comment1:
    cmp BYTE PTR [esi], "/" ; read next character in ESI
    je cpp
    cmp BYTE PTR [esi], "*"
    je oldc
    jmp rtn                 ; if not a comment, write byte in AL to [EDI]

  cpp:
    mov al, [esi]
    inc esi
    cmp esi, ecx
    je outa_here            ; exit on source length
    cmp al, 13
    je rtn
    jmp cpp

  oldc:
    mov al, [esi]
    inc esi
    cmp esi, ecx
    je outa_here            ; exit on source length
    cmp al, "*"
    je last
    jmp oldc

  last:
    cmp BYTE PTR [esi], "/"
    jne oldc
    inc esi
    jmp lbl1

  outa_here:

    sub edi, lpresult       ; get the byte count written to [edi]
    mov eax, edi            ; set it as the return value

    pop edi
    pop esi
    pop ebx

    ret

stripcc endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
