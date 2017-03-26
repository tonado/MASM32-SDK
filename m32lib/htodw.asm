; #########################################################################

  ; ---------------------------------------------------------------
  ;      This procedure was written by Alexander Yackubtchik 
  ; ---------------------------------------------------------------

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

htodw proc String:DWORD

  ; -----------------------------------
  ; Convert hex string into dword value
  ; Return value in eax
  ; -----------------------------------

    push ebx
    push esi
    push edi

    mov edi, String
    mov esi, String 

     ALIGN 4

  again:  
    mov al,[edi]
    inc edi
    or  al,al
    jnz again
    sub esi,edi
    xor ebx,ebx
    add edi,esi
    xor edx,edx
    not esi             ;esi = lenth

  .while esi != 0
    mov al, [edi]
    cmp al,'A'
    jb figure
    sub al,'a'-10
    adc dl,0
    shl dl,5            ;if cf set we get it bl 20h else - 0
    add al,dl
    jmp next
  figure: 
    sub al,'0'
  next:  
    lea ecx,[esi-1]
    and eax, 0Fh
    shl ecx,2           ;mul ecx by log 16(2)
    shl eax,cl          ;eax * 2^ecx
    add ebx, eax
    inc edi
    dec esi
  .endw

    mov eax,ebx

    pop edi
    pop esi
    pop ebx

    ret

htodw endp

; #########################################################################

end