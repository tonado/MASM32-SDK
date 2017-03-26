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
    xor eax, eax
    ret 4

align 16
isupper proc char:BYTE

    cmp BYTE PTR [esp+4], 65        ; test if below "A"
    jb fail
    cmp BYTE PTR [esp+4], 90        ; test if above "Z"
    ja fail
    mov eax, 1
    ret 4

isupper endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
