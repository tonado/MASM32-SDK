; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

hexflip32 proc src:DWORD

comment * ---------------------------------------------------------------
        algorithm accepts assembler format hex notation with the trailing
        "h" and optionally a leading "0" if required. Total string length
        must not exceed 10 bytes including the "h" and "0".

        output is a memory order hex string that is always 8 bytes long. If
        the input string is less than 8 bytes in length the output string
        is padded with trailing "0" s to make up the length.

        The output is always written to the source string buffer and the
        buffer must be at least 9 bytes long. A buffer of 12 bytes satisfies
        alignment criterion.

        01199AAFFh becomes "FFAA9911"
        --------------------------------------------------------------- *

    LOCAL buffer[16]:BYTE

    push ebx
    push esi
    push edi

    lea eax, buffer
    mov DWORD PTR [eax],   "0000"       ; "0" fill buffer
    mov DWORD PTR [eax+4], "0000"
    mov DWORD PTR [eax+8], "0000"
    mov DWORD PTR [eax+12], 0           ; terminate it at 12 bytes

  ; ----------------------------------------------------
  ; unrolled StrLen algo to test up to 12 bytes for zero
  ; ----------------------------------------------------
    mov eax,src                         ; get pointer to string
    lea edx,[eax+3]                     ; pointer+3 used in the end

    mov edi,[eax]                       ; read first 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h
    jnz @F

    mov edi,[eax]                       ; read next 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h
    jnz @F

    mov edi,[eax]                       ; read last 4 bytes
    add eax,4                           ; increment pointer
    lea ecx,[edi-01010101h]             ; subtract 1 from each byte
    not edi                             ; invert all bytes
    and ecx,edi                         ; and these two
    and ecx,80808080h

  @@:
    test ecx,00008080h                  ; test first two bytes
    jnz @F
    shr ecx,16                          ; not in the first 2 bytes
    add eax,2
  @@:
    shl cl,1                            ; use carry flag to avoid branch
    sbb eax,edx                         ; compute length
  ; -------------------------------------------

    sub eax, 1                          ; set length not counting trailing "h"
    cmp eax, 9                          ; allow for leading zero
    jle @F
    xor eax, eax                        ; return zero as length error
    jmp byebye
  @@:

    mov esi, src
    add esi, eax                        ; add length to ESI to be at end of source buffer
    xor eax, eax                        ; clear EAX
    lea edi, buffer
    add edi, 12                         ; add 8 & 4 to EDI to be at last byte position in dest buffer
    xor ebx, ebx

  @@:
    mov al, [esi]                       ; copy the string backwards to buffer
    mov [edi], al
    sub esi, 1
    sub edi, 1
    cmp esi, src                        ; loop until ESI = "src"
    jne @B

    xor ecx, ecx
    xor edx, edx

    lea esi, buffer
    mov edi, src
    mov ax, [esi+10]                    ; write inverted hex bytes back to source
    mov bx, [esi+8]
    mov cx, [esi+6]
    mov dx, [esi+4]
    mov [edi], ax
    mov [edi+2], bx
    mov [edi+4], cx
    mov [edi+6], dx
    mov BYTE PTR [edi+8], 0

    mov eax, 1                          ; no error return value

  byebye:

    pop edi
    pop esi
    pop ebx

    ret

hexflip32 endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
