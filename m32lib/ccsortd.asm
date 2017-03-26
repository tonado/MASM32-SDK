; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

ccsortd proc arr:DWORD,cnt:DWORD

comment * --------------------------------------------------
        CCSORT is a hybrid sort that uses a bi-directional
        COMB sort technique to pre-order the data and a
        bi-directional bubble sort to finally sort the data.
        -------------------------------------------------- *

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
  ; first loop is descending gap comb preordering pass
  ; --------------------------------------------------
  setgap:
    fild gap                    ; load integer memory operand to divide
    fdiv FP8(1.35)              ; divide gap by constant
    fistp gap                   ; store result back in integer memory operand
    sub gap, 1                  ; round down by 1
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
    jl swap                   ; ascending sort
    jg noswap                     ; swap these two labels for descending
    cmp BYTE PTR [ebp+edi], 0   ; cmp first byte
    jne cmpstrings              ; loop again if not zero
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
    jl rswap                  ; ascending sort
    jg rnoswap                    ; swap these two labels for descending
    cmp BYTE PTR [ebp+edi], 0   ; cmp first byte
    jne rcmpstrings             ; loop again if not zero
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
  ; ------------------------------------------------------------
  ; second loop is a bi-directional bubble/cocktail shaker sort
  ; ------------------------------------------------------------
  nxt:
    push cnt
    pop hflag
    sub hflag, 1
  ; ------------------------------------------------------------
  cocktail:
    xor ecx, ecx                ; low value index
    mov sflag, 0                ; zero swap flag
  cinner:
    mov eax, [ebx+ecx*4]        ; lower value
    mov esi, [ebx+ecx*4+4]      ; swap values
    mov edi, -1
  ; ===========================================
  cmpstrings1:
    add edi, 1
    mov dl, [eax+edi]           ; compare both strings
    cmp dl, [esi+edi]
    jl swap1                  ; ascending sort
    jg cnoswap                    ; swap these two labels for descending
    test dl, dl
    jnz cmpstrings1
  ; ===========================================
    jmp cnoswap
  swap1:
    mov [ebx+ecx*4], esi
    mov [ebx+ecx*4+4], eax
    mov sflag, 1
  cnoswap:
    add ecx, 1                  ; ascending pass
    cmp ecx, hflag
    jle cinner
  ; ------------------------------------------------------------
    cmp sflag, 0
    je done
  ; ------------------------------------------------------------
    xor edx, edx
    sub ecx, 1
  cinner2:
    mov eax, [ebx+ecx*4]        ; lower value
    mov esi, [ebx+ecx*4+4]      ; swap values
    mov edi, -1
  ; ===========================================
  cmpstrings2:
    add edi, 1
    mov dl, [eax+edi]           ; compare both strings
    cmp dl, [esi+edi]
    jl swap2                 ; ascending sort
    jg cnoswap2                    ; swap these two labels for descending
    test dl, dl
    jnz cmpstrings2
  ; ===========================================
    jmp cnoswap2
  swap2:
    mov [ebx+ecx*4], esi
    mov [ebx+ecx*4+4], eax
    mov sflag, 1                ; set the swap flag
  cnoswap2:
    sub ecx, 1                  ; descending pass
    jnz cinner2
  ; ------------------------------------------------------------
    cmp sflag, 0
    jne cocktail
  ; ------------------------------------------------------------

  done:
    pop edi
    pop esi
    pop ebx

    ret

ccsortd endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
