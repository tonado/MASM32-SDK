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
islower proc char:BYTE

    cmp BYTE PTR [esp+4], 97        ; test if below "a"
    jb fail
    cmp BYTE PTR [esp+4], 122       ; test if above "z"
    ja fail
    mov eax, 1
    ret 4

islower endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
