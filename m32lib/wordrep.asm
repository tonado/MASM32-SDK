; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    szCmp PROTO :DWORD,:DWORD

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .data
    align 4
    chtbl \
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     ; 31
      db 0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0     ; 47
      db 1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1     ; 63   ; numbers
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     ; 79   ; upper case
      db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1     ; 95
      db 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1     ; 111  ; lower case
      db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0     ; 127
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

    ; characters     ! # $ % & ? @ _
    ; numbers        0123456789
    ; upper case     ABCDEFGHIJKLMNOPQRSTUVWXYZ
    ; lower case     abcdefghijklmnopqrstuvwxyz

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

comment * -----------------------------------------
        Algorithm scans the source buffer for words
        made up of  acceptable  characters. When it
        finds a word, it  tests if the word matches
        the first word and it  replaces it with the
        second in the destination buffer if it does.
        ----------------------------------------- *
align 4

wordreplace proc src:DWORD,dst:DWORD,wrd1:DWORD,wrd2:DWORD

    LOCAL buffer[512]:BYTE

    push esi
    push edi

    mov esi, src
    mov edi, dst
    xor eax, eax
    jmp badchar
  ; ---------------------------------
  ; handle unacceptable characters
  ; ---------------------------------
  align 4
  prebad:
    xor eax, eax                    ; szCmp alters EAX so clear it again
    sub esi, 1
  badchar:
    mov al, BYTE PTR [esi]
    add esi, 1
    cmp BYTE PTR [chtbl+eax], 1     ; test if BYTE is allowable character
    je pregood
    test eax, eax                   ; test if terminator
    jz repout
    mov [edi], al                   ; write BYTE to destination buffer
    add edi, 1
    jmp badchar
  ; ---------------------------------
  ; handle acceptable characters
  ; ---------------------------------
  align 4
  pregood:
    lea edx, buffer                 ; load temp buffer address in EDX
    mov [edx], al                   ; write 1st good char to temp buffer
    add edx, 1
  goodchar:
    mov al, BYTE PTR [esi]
    add esi, 1
    test eax, eax                   ; test if terminator
    jz lastword                     ; jump to last word test
    cmp BYTE PTR [chtbl+eax], 0     ; test if BYTE is NOT allowable character
    je tstword                      ; jump to word test loop
    mov [edx], al                   ; write next byte to temp buffer
    add edx, 1
    jmp goodchar
  ; ---------------------------------
  ; test word match and return
  ; ---------------------------------
  align 4
  tstword:
    mov BYTE PTR [edx], 0           ; terminate the word in temp buffer
    invoke szCmp,wrd1,ADDR buffer   ; test temp buffer against 1st word
    lea ecx, buffer
    test eax, eax                   ; if no match write original word to buffer
    jz @F
    mov ecx, wrd2                   ; if 1st word matches, put replacement address in ECX
  @@:
    mov al, [ecx]                   ; copy word to destination buffer
    add ecx, 1
    test eax, eax                   ; return on zero
    jz prebad
    mov [edi], al
    add edi, 1
    jmp @B
  ; ---------------------------------
  ; test word match and exit
  ; ---------------------------------
  align 4
  lastword:
    mov BYTE PTR [edx], 0           ; terminate the word in temp buffer
    invoke szCmp,wrd1,ADDR buffer   ; test temp buffer against 1st word
    lea ecx, buffer
    test eax, eax                   ; if no match write original word to buffer
    jz @F
    mov ecx, wrd2                   ; if 1st word matches, put replacement address in ECX
  @@:
    mov al, [ecx]                   ; copy word to destination buffer
    add ecx, 1
    test eax, eax                   ; exit on zero
    jz repout
    mov [edi], al
    add edi, 1
    jmp @B
  ; ---------------------------------
  align 4
  repout:
    mov BYTE PTR [edi], 0           ; write final terminator to destination buffer
    pop edi
    pop esi

    ret

wordreplace endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
