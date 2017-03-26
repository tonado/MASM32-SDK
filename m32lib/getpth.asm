; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    .486                      ; create 32 bit code
    .model flat, stdcall      ; 32 bit memory model
    option casemap :none      ; case sensitive

    .code

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

GetPathOnly proc src:DWORD, dst:DWORD

    push esi
    push edi

    xor ecx, ecx    ; zero counter
    mov esi, src
    mov edi, dst
    xor edx, edx    ; zero backslash location

  @@:
    mov al, [esi]   ; read byte from address in esi
    inc esi
    inc ecx         ; increment counter
    cmp al, 0       ; test for zero
    je gfpOut       ; exit loop on zero
    cmp al, "\"     ; test for "\"
    jne nxt1        ; jump over if not
    mov edx, ecx    ; store counter in ecx = last "\" offset in ecx
  nxt1:
    mov [edi], al   ; write byte to address in edi
    inc edi
    jmp @B
    
  gfpOut:
    add edx, dst    ; add destination address to offset of last "\"
    mov [edx], al   ; write terminator to destination

    pop edi
    pop esi

    ret

GetPathOnly endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end