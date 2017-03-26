; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    EXTERNDEF hex_table :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

bin2hex proc lpString:DWORD,lnString:DWORD,lpbuffer:DWORD

comment * ------------------------
        EAX is unused in loop code
        ------------------------ *

    push ebx
    push esi
    push edi
    push ebp

    mov esi, lpString                   ; address of source string
    mov edi, lpbuffer                   ; address of output buffer
    mov ecx, esi
    add ecx, lnString                   ; exit condition for byte read
    xor ebx, ebx                        ; line counter
    jmp hxlp

; -------------------------------------------------------------------------

  align 4
  hxpre:
    mov WORD PTR [edi], " -"            ; write centre seperator
    add edi, 2
  align 4
  pre:
    cmp esi, ecx                        ; test exit condition
    jge hxout                           ; mispredicted only once
  hxlp:
    movzx ebp, BYTE PTR [esi]           ; zero extend byte into EBP
    mov dx, WORD PTR [ebp*2+hex_table]  ; put WORD from table into DX
    add ebx, 1
    add esi, 1
    mov [edi], dx                       ; write 2 byte string to buffer
    mov BYTE PTR [edi+2], 32            ; write space
    add edi, 3
    cmp ebx, 8                          ; test for half to add "-"
    je hxpre                            ; predicted backwards
    cmp ebx, 16                         ; break line at 16 characters
    jne pre                             ; predicted backwards
    mov WORD PTR [edi-1], 0A0Dh         ; overwrite last byte with CRLF
    add edi, 1
    xor ebx, ebx                        ; clear line counter
    jmp pre                             ; predicted backwards
  hxout:

; -------------------------------------------------------------------------

    pop ebp

    mov BYTE PTR [edi-1], 0             ; append terminator
    sub edi, 1

    sub edi, lpbuffer
    mov eax, edi                        ; return written length of hex output

    pop edi
    pop esi
    pop ebx

    ret

bin2hex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
