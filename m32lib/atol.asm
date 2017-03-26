; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    atol PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

atol proc lpSrc:DWORD

    xor eax, eax                ; zero EAX
    mov edx, [esp+4]
    movzx ecx, BYTE PTR [edx]
    add edx, 1
    cmp ecx, "-"                ; test for sign
    jne lbl0
    add eax, 1                  ; set EAX if sign
    movzx ecx, BYTE PTR [edx]
    add edx, 1

  lbl0:
    push eax                    ; store sign on stack
    xor eax, eax                ; so eax*10 will be 0 for first digit

  lbl1:
    sub ecx, 48
    jc  lbl2
    lea eax, [eax+eax*4]        ; mul eax by 5
    lea eax, [ecx+eax*2]        ; mul eax by 2 and add digit value
    movzx ecx, BYTE PTR [edx]   ; get next digit
    add edx, 1
    jmp lbl1

  lbl2:
    pop ecx                     ; retrieve sign
    test ecx, ecx
    jnz lbl3
    ret 4

  lbl3:
    neg eax                     ; negative return value is sign set
    ret 4

atol endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end