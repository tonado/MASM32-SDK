; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

    dissort PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

dcisort proc arr:DWORD,cnt:DWORD

    LOCAL gap   :DWORD
    LOCAL sflag :DWORD
    LOCAL hflag :DWORD
    LOCAL eflag :DWORD

    push ebx
    push esi
    push edi

    mov eax, cnt
    mov gap, eax                ; copy cnt to gap
    mov ebx, arr                ; address of 1st element
    dec cnt
  ; --------------------------------------------------
  ;        bi-directional COMB preordering pass
  ; --------------------------------------------------
  setgap:
    fild gap                    ; load integer memory operand to divide
    fdiv FP8(1.35)              ; divide gap by constant
    fistp gap                   ; store result back in integer memory operand
    sub gap, 1                  ; round down by 1

    cmp gap, 10
    jg @F
    cmp gap, 9                  ; comb 11 code
    jl @F
    mov gap, 11
  @@:

    cmp gap, 1
    jle nxt                     ; exit when gap <= 1
    mov edi, cnt
    sub edi, gap
    mov eflag, edi
    xor ecx, ecx                ; low value index
  inner:
    mov edx, ecx
    add edx, gap                ; high value index
    push ebp
    mov ebp, [ebx+ecx*4]        ; lower value
    mov esi, [ebx+edx*4]        ; swap values
    mov edi, -1
  ; ===========================================
  cmpstrings:
    add edi, 1
    mov al, [ebp+edi]           ; compare both strings
    cmp al, [esi+edi]
    jl swap                     ; ascending sort
    jg noswap                   ; swap these two labels for descending
    test al, al
    jnz cmpstrings
  ; ===========================================
    jmp noswap
  swap:
    mov [ebx+edx*4], ebp
    mov [ebx+ecx*4], esi
  noswap:
    pop ebp
    add ecx, 1
    cmp ecx, eflag
    jle inner
  ; *******************************
    fild gap                    ; load integer memory operand to divide
    fdiv FP8(1.4)               ; divide gap by constant
    fistp gap                   ; store result back in integer memory operand
    sub gap, 1                  ; round down by 1

    cmp gap, 10
    jg @F
    cmp gap, 9                  ; comb 11 code
    jl @F
    mov gap, 11
  @@:

    cmp gap, 1
    jle nxt                     ; exit when gap <= 1
    mov ecx, cnt
    sub ecx, gap                ; calculate ECX as cnt - gap
  rinner:
    mov edx, ecx
    add edx, gap                ; high value index
    push ebp
    mov ebp, [ebx+ecx*4]        ; lower value
    mov esi, [ebx+edx*4]        ; swap values
    mov edi, -1
  ; ===========================================
  rcmpstrings:
    add edi, 1
    mov al, [ebp+edi]           ; compare both strings
    cmp al, [esi+edi]
    jl rswap                    ; ascending sort
    jg rnoswap                  ; swap these two labels for descending
    test al, al
    jnz rcmpstrings
  ; ===========================================
    jmp rnoswap
  rswap:
    mov [ebx+edx*4], ebp
    mov [ebx+ecx*4], esi
  rnoswap:
    pop ebp
    sub ecx, 1
    jnz rinner
    jmp setgap
  nxt:

    inc cnt
    invoke dissort,arr,cnt      ; call the insertion sort to clean up the rest

  done:
    pop edi
    pop esi
    pop ebx

    ret

dcisort endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
