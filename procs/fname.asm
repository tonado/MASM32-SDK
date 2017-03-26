; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;       Overwrites the full pathname of a file with its file name

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

FileFromPath proc lppath:DWORD

    mov ecx, lppath
    mov edx, lppath

  @@:
    mov al, [ecx]
    inc ecx
    mov [edx], al
    inc edx
    cmp al, 0           ; test for zero
    je @F               ; exit if zero
    cmp al, "\"         ; test for "\"
    jne @B              ; jump back if not
    mov edx, lppath     ; else reset edx with buffer address
    jmp @B              ; then jump back
  @@:

    ret

FileFromPath endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
