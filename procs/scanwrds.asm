; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

.data

    align 4
    ctable \
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     ; 31
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0     ; 63
      db 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0     ; 95
      db 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0     ; 127
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

scanwords proc src:DWORD,fl:DWORD,tbl:DWORD

    LOCAL cnt:DWORD
    LOCAL dst[1024]:BYTE    ; local output buffer for words

    push ebx
    push esi
    push edi

    mov cnt, 0          ; set counter to zero

    mov ebx, tbl        ; table address in EBX
    mov esi, src        ; source address in ESI
    lea edi, dst        ; output buffer address in edi
    mov ecx, fl         ; byte count in ECX
    add ecx, esi        ; match ECX to exit
    xor eax, eax        ; zero EAX to prevent stall

  comment * ------------------------------
    1st block is acceptable character loop
    -------------------------------------- *
  lbl1:
    mov al, [esi]
    inc esi
    cmp esi, ecx
    je lbout
    cmp BYTE PTR [ebx+eax], 1
    jne lbl2                    ; exit 1st loop on unacceptable character
  backin:
    mov [edi], al
    inc edi
    jmp lbl1

  lbl2:
    mov BYTE PTR [edi], 0       ; append terminator to word

    comment * -----------------------------------------

    This is the gate where EDI holds the address of
    each zero terminated word. From here you call
    procedures like hashing the word and/or adding
    the word to a hash table.

    Procedure returns the variable "cnt" in EAX on
    exit. Increment "cnt" for whatever process you
    require.

    inc cnt

    -------------------------------------------------- *

    lea edi, dst                ; reload the buffer address for the next word

  comment * --------------------------
    loop while unacceptable characters
    ---------------------------------- *
  lbl3:
    mov al, [esi]
    inc esi
    cmp esi, ecx
    je lbout
    cmp BYTE PTR [ebx+eax], 1
    jne lbl3
    jmp backin

  lbout:

    mov eax, cnt

    pop edi
    pop esi
    pop ebx

    ret

scanwords endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
