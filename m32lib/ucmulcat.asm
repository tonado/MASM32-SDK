; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;           UNICODE version of Alex Yackubtchik's szMultiCat

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ucMultiCat proc C pcount:DWORD,lpBuffer:DWORD,args:VARARG

    push esi
    push edi

    xor eax, eax                ; clear EAX for following partial reads and writes
    mov edi, lpBuffer
    xor ecx, ecx                ; clear arg counter
    lea edx, args
    sub edi, 2
  @@:
    add edi, 2
    mov ax, [edi]
    test ax, ax
    jne @B
  newstr:
    sub edi, 2
    mov esi, [edx+ecx*4]
  @@:
    add edi, 2
    mov ax, [esi]
    mov [edi], ax
    add esi, 2
    test ax, ax
    jne @B
    add ecx, 1
    cmp ecx, pcount
    jne newstr

    mov eax, lpBuffer

    pop edi
    pop esi

    ret

ucMultiCat endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
