; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .data
      align 16
      multitable \
        db 0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0
        db 1,1,1,1,1,1,1,1,1,1,0,3,0,0,0,0
        db 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

      ; 0 = unacceptable character
      ; 1 = acceptable characters   (0 to 9, A to F, a to f)
      ; 2 = ignored characters      (space, minus and CRLF)
      ; 3 = comment character       ( ; )

      ; 1st offset table
        db 00h,10h,20h,30h,40h,50h,60h,70h,80h,90h,0,0,0,0,0,0      ; 63
        db 00h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h,0,0,0,0,0,0,0,0,0      ; 79
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0                          ; 95
        db 00h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h

      ; 2nd offset table
        db 00h,01h,02h,03h,04h,05h,06h,07h,08h,09h,0,0,0,0,0,0      ; 63
        db 00h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh,0,0,0,0,0,0,0,0,0            ; 79
        db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0                          ; 95
        db 00h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh

      ; add 256 for allowable character table
      ; sub 48 from 1st offset table
      ; add 7 for the second BYTE

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

hex2bin proc src:DWORD,dst:DWORD

comment * ---------------------------------
        EAX and EBX are unused in loop code
        --------------------------------- *

    push ebx
    push esi
    push edi
    push ebp

    mov esi, src
    mov edi, dst

    xor ebp, ebp

    jmp h2b                             ; mispredicted only once

  align 4
  stripcomment:
    add esi, 1
    cmp BYTE PTR [esi], 10
    jb zerofound                        ; < 10 = 0
    jne stripcomment                    ; loop if not 10
  align 4
  pre:
    add esi, 1
  align 4
  h2b:
    movzx ebp, BYTE PTR [esi]           ; zero extend 1st byte into EBP
    cmp BYTE PTR [ebp+multitable], 2    ; 1st compare short circuit on ignored characters
    je pre                              ; predicted backwards
    movzx edx, BYTE PTR [esi+1]         ; zero extend 2nd BYTE into EDX
    ja stripcomment                     ; predicted backwards

    mov cl, [ebp+multitable+208]        ; load 1st character into CL from 2nd table
    add cl, [edx+multitable+263]        ; add value of second character from 3rd table
    cmp BYTE PTR [ebp+multitable], 0    ; exit on error or ZERO
    je error1                           ; mispredicted only once

    mov [edi], cl                       ; write BYTE to output buffer
    add esi, 2
    add edi, 1
    cmp BYTE PTR [edx+multitable], 1    ; test if second byte is allowable character
    je h2b                              ; predicted backwards

  error2:
    mov ecx, 2                          ; error 2 = illegal character
    jmp exitproc
  error1:
    test ebp, ebp                       ; test if byte is terminator
    jz zerofound
    mov ecx, 1                          ; error 1 = non matching hex character pairs
    jmp exitproc
  zerofound:
    xor ecx, ecx                        ; no error 0

  exitproc:

    pop ebp                             ; restore EBP before using stack parameter
    sub edi, dst
    mov eax, edi

    pop edi
    pop esi
    pop ebx

    ret

hex2bin endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
