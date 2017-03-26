; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    __UNICODE__ equ 1

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

    ucLen     PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ucFind proc sPos:DWORD, wsrc:DWORD, wsub:DWORD

    LOCAL lsrc  :DWORD
    LOCAL lsub  :DWORD

    push ebx
    push esi
    push edi

    xor edx, edx
    xor ebx, ebx
    mov edi, wsub
    mov bx, [edi]           ; 1st substring char in BX

    mov lsrc, ulen$(wsrc)
    mov eax, lsrc
    add lsrc, eax           ; double for byte length

    mov lsub, ulen$(wsub)
    mov eax, lsub
    add eax, eax
    mov lsub, eax           ; double for byte length
    sub lsub, 2             ; correct for subloop

    sub lsrc, eax           ; exit position

    mov eax, sPos           ; double sPos to get byte location
    add sPos, eax
    mov esi, wsrc
    add esi, sPos
    add lsrc, esi

    sub esi, 2
  stlp:
    add esi, 2
    cmp [esi], bx           ; test for start character
    je presub
    cmp esi, lsrc
    jle stlp                ; fall through on no match

    jmp notfound

  presub:
    mov ecx, lsub
  sublp:
    mov dx, [esi+ecx]       ; do substring compare backwards
    cmp dx, [edi+ecx]
    jne stlp
    sub ecx, 2
    jnz sublp               ; fall through on match

  match:
    sub esi, wsrc           ; calculated byte length
    mov eax, esi
    add eax, 2              ; correct for 1 base index
    shr eax, 1              ; divide by 2 to return character position
    jmp findout

  notfound:
    xor eax, eax            ; return zero on no match

  findout:
    pop edi
    pop esi
    pop ebx

    ret

ucFind endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
