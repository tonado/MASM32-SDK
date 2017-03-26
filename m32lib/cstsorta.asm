; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

comment * ------------------------------------------------------
        The comb sort is from an original idea published in BYTE
        Magazine in April 1991 by Stephen Lacey and Richard Box.
        ------------------------------------------------------ *

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

cstsorta proc Arr:DWORD,aSize:DWORD

    LOCAL Gap   :DWORD

    .data
      align 4
      eFlag@mangled@@?? dd 0
    .code

    push ebx
    push esi
    push edi

    mov eax, aSize
    mov Gap, eax
    mov ebx, Arr    ; address of 1st element
    sub aSize, 1

  stLbl:
    fild Gap        ; load integer memory operand to divide
    fdiv FP8(1.29)  ; divide Gap by 1.29
    fistp Gap       ; store result back in integer memory operand
    sub Gap, 1
    jnz ovr
    mov Gap, 1
  ovr:
    mov eFlag@mangled@@??, 0
    mov edi, aSize
    sub edi, Gap
    xor ecx, ecx              ; low value index
  iLoop:
    mov edx, ecx
    add edx, Gap              ; high value index
    push edi
    push ebp
    mov edi, [ebx+ecx*4]      ; lower value
    mov esi, [ebx+edx*4]      ; higher value
    mov ebp, -1
  ; -------------------------------------------
  cmpstrings:
    add ebp, 1
    mov al, [edi+ebp]           ; compare both strings
    cmp al, [esi+ebp]
    jl noswap                   ; ascending sort
    jg swap                     ; swap these two labels for descending
    test al, al
    jnz cmpstrings
  ; -------------------------------------------
    jmp noswap
  swap:
    mov [ebx+edx*4], edi
    mov [ebx+ecx*4], esi
    add eFlag@mangled@@??, 1
  noswap:
    pop ebp
    pop edi

    add ecx, 1
    cmp ecx, edi
    jle iLoop

    cmp eFlag@mangled@@??, 0
    jg stLbl
    cmp Gap, 1
    jg stLbl

    pop edi
    pop esi
    pop ebx

    ret

cstsorta endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
