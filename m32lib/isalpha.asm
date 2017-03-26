; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

  align 16
  fail:
    xor eax, eax                    ; return zero on fail
    ret 4

  align 16
  trylower:
    cmp BYTE PTR [esp+4], 97        ; test if below "a"
    jb fail
    mov eax, 2                      ; return 2 = lowercase
    ret 4

align 16
isalpha proc char:BYTE              ; proc entry label

    cmp BYTE PTR [esp+4], 65        ; test if below "A"
    jb fail
    cmp BYTE PTR [esp+4], 122       ; test if above "z"
    ja fail
    cmp BYTE PTR [esp+4], 90        ; test if above "Z"
    ja trylower
    mov eax, 1                      ; return 1 = uppercase
    ret 4

isalpha endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
