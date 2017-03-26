; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

.data
  align 4
  ctbl \
    db 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0
    db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0
    db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    db 1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1
    db 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

    ;   allowable character range
    ;   -------------------------
    ;   upper & lower case characters
    ;   numbers
    ;   " "           ; quotation marks
    ;   [ ]           ; address enclosure
    ;   + - *         ; displacement and multiplier calculation
    ;   : @           ; label identification

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

parse_line proc src:DWORD,array:DWORD

    push esi
    push edi

    mov esi, src                        ; line in ESI
    mov edi, array                      ; word array in EDI
    mov ecx, [edi]                      ; 1st array member address in ECX
    xor eax, eax                        ; clear EAX
    xor edx, edx                        ; set arg counter to zero

  ; ----------------------------------
  align 4
  badchar:
    mov al, [esi]
    add esi, 1
    test al, al                         ; test if byte is terminator
    jz gaout
    cmp BYTE PTR [eax+ctbl], 1          ; is it a good char ?
    jne badchar
    add edx, 1                          ; add to arg counter
    jmp writechar
  goodchar:
    mov al, [esi]
    add esi, 1
    test al, al                         ; test if byte is terminator
    jz gaout
    cmp BYTE PTR [eax+ctbl], 0          ; is it a bad char ?
    je reindex
  writechar:
    cmp al, "["                         ; test for opening square bracket
    je wsqb                             ; branch to handler if it is
    cmp al, 34                          ; test for opening quotation
    je preq                             ; branch to quote handler if it is
    mov [ecx], al                       ; write byte to buffer
    add ecx, 1
    jmp goodchar
  ; ----------------------------------
  align 4
  reindex:
    mov BYTE PTR [ecx], 0               ; write terminator to array member
    add edi, 4                          ; index to next array member
    mov ecx, [edi]                      ; put its address in ECX
    jmp badchar
  ; ----------------------------------
  align 4
  preq:
    mov [ecx], al                       ; write byte to buffer
    add ecx, 1
  quotes:                               ; quotation handler
    mov al, [esi]
    add esi, 1
    test al, al                         ; test if byte is terminator
    jz qterror                          ; jump to quotation error
 ;     cmp al, 32
 ;     je quotes                           ; uncomment these lines to strip spaces in quotes
  wqot:
    mov [ecx], al                       ; write byte to buffer
    add ecx, 1
    cmp al, 34                          ; test for closing quote
    je reindex
    jmp quotes

  align 4
  squareb:                              ; square bracket handler
    mov al, [esi]
    add esi, 1
    test al, al                         ; test if byte is terminator
    jz sberror                          ; jump to square bracket error
    cmp al, 32
    je squareb
  wsqb:
    mov [ecx], al                       ; write byte to buffer
    add ecx, 1
    cmp al, "]"
    je reindex
    jmp squareb
  ; ----------------------------------
  align 4
  qterror:                              ; quotation error
    mov ecx, 2                          ; set ECX as 2
    jmp gaquit                          ; no closing quoation

  align 4
  sberror:                              ; square bracket error
    mov ecx, 1                          ; set ECX to 1
    jmp gaquit                          ; no closing square bracket

  align 4
  gaout:
    mov BYTE PTR [ecx], 0               ; terminate last buffer written to.
    add edi, 4
    mov ecx, [edi]
    mov BYTE PTR [ecx], 0               ; set next buffer with leading zero
    xor ecx, ecx                        ; ECX set to zero is NO ERROR
  gaquit:
    mov eax, edx                        ; return arg count

    pop edi
    pop esi

    ret

parse_line endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
