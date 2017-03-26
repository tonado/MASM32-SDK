; #########################################################################

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

memfill proc lpmem:DWORD,ln:DWORD,fill:DWORD

    mov edx, lpmem      ; buffer address
    mov eax, fill       ; fill chars

    mov ecx, ln         ; byte length
    shr ecx, 5          ; divide by 32
    cmp ecx, 0
    jz rmndr

    align 4

  ; ------------
  ; unroll by 8
  ; ------------
  @@:
    mov [edx],    eax   ; put fill chars at address in edx
    mov [edx+4],  eax
    mov [edx+8],  eax
    mov [edx+12], eax
    mov [edx+16], eax
    mov [edx+20], eax
    mov [edx+24], eax
    mov [edx+28], eax
    add edx, 32
    dec ecx
    jnz @B

  rmndr:

    and ln, 31          ; get remainder
    cmp ln, 0
    je mfQuit
    mov ecx, ln
    shr ecx, 2          ; divide by 4

  @@:
    mov [edx], eax
    add edx, 4
    dec ecx
    jnz @B

  mfQuit:

    ret

memfill endp

; #########################################################################

end
