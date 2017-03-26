; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

  ; ---------------------------------------------------------------
  ; This procedure was written by Tim Roberts
  ; Minor fix by Jibz, December 2004
  ; ---------------------------------------------------------------

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

dwtoa proc dwValue:DWORD, lpBuffer:DWORD

    ; -------------------------------------------------------------
    ; convert DWORD to ascii string
    ; dwValue is value to be converted
    ; lpBuffer is the address of the receiving buffer
    ; EXAMPLE:
    ; invoke dwtoa,edx,ADDR buffer
    ;
    ; Uses: eax, ecx, edx.
    ; -------------------------------------------------------------

    push ebx
    push esi
    push edi

    mov eax, dwValue
    mov edi, [lpBuffer]

    test eax,eax
    jnz sign

  zero:
    mov word ptr [edi],30h
    jmp dtaexit

  sign:
    jns pos
    mov byte ptr [edi],'-'
    neg eax
    add edi, 1

  pos:
    mov ecx, 3435973837
    mov esi, edi

    .while (eax > 0)
      mov ebx,eax
      mul ecx
      shr edx, 3
      mov eax,edx
      lea edx,[edx*4+edx]
      add edx,edx
      sub ebx,edx
      add bl,'0'
      mov [edi],bl
      add edi, 1
    .endw

    mov byte ptr [edi], 0       ; terminate the string

    ; We now have all the digits, but in reverse order.

    .while (esi < edi)
      sub edi, 1
      mov al, [esi]
      mov ah, [edi]
      mov [edi], al
      mov [esi], ah
      add esi, 1
    .endw

  dtaexit:

    pop edi
    pop esi
    pop ebx

    ret

dwtoa endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end