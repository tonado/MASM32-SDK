; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

aissort proc arr:DWORD,cnt:DWORD

  ; -------------------------------
  ; ascending insertion string sort
  ; -------------------------------
    mov [esp-8],  ebx
    mov [esp-12], esi
    mov [esp-16], edi
    mov [esp-20], ebp

    mov edi, [esp+4]            ; array address
    mov edx, 1
    cmp edx, [esp+8]            ; compare count to EDX
    jge quit
    xor eax, eax                ; clear EAX of previous content

  entry:
    mov ebx, [edi+edx*4]
    mov esi, edx

  inner:
    mov ecx, [edi+esi*4-4]
    mov ebp, -1
  stcmp:                        ; string comparison loop
    add ebp, 1
    mov al, [ecx+ebp]
    cmp al, [ebx+ebp]
    jl outer
    jg swap
    test al, al
    jnz stcmp

    jmp outer

  swap:
    mov [edi+esi*4], ecx
    sub esi, 1
    jnz inner

  outer:
    mov [edi+esi*4], ebx
    add edx, 1
    cmp edx, [esp+8]            ; compare count to EDX
    jl entry

  quit:
    mov ebx, [esp-8]
    mov esi, [esp-12]
    mov edi, [esp-16]
    mov ebp, [esp-20]

    ret 8

aissort endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
