; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    szLen PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

szRev proc src:DWORD,dst:DWORD

  ; ------------------------------------
  ; this version will reverses a string
  ; in a single memory buffer so it can
  ; accept the same address as both src
  ; and dst.
  ; ------------------------------------

    push esi
    push edi

    mov esi, src
    mov edi, dst
    xor eax, eax            ; use EAX as a counter

  ; ---------------------------------------
  ; first loop gets the buffer length and
  ; copies the first buffer into the second
  ; ---------------------------------------
  @@:
    mov dl, [esi+eax]       ; copy source to dest
    mov [edi+eax], dl
    add eax, 1              ; get the length in ECX
    test dl, dl
    jne @B

    mov esi, dst            ; put dest address in ESI
    mov edi, dst            ; same in EDI
    sub eax, 1              ; correct for exit from 1st loop
    lea edi, [edi+eax-1]    ; end address in edi
    shr eax, 1              ; int divide length by 2
    neg eax                 ; invert sign
    sub esi, eax            ; sub half len from ESI

  ; ------------------------------------------
  ; second loop swaps end pairs of bytes until
  ; it reaches the middle of the buffer
  ; ------------------------------------------
  @@:
    mov cl, [esi+eax]       ; load end pairs
    mov dl, [edi]
    mov [esi+eax], dl       ; swap end pairs
    mov [edi], cl
    sub edi, 1
    add eax, 1
    jnz @B                  ; exit on half length

    mov eax, dst            ; return destination address

    pop edi
    pop esi

    ret

szRev endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end