; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

  align 4
  fail:
    xor eax, eax
    ret 4

  align 4
  trylower:
    cmp BYTE PTR [esp+4], 97
    jb fail
    cmp BYTE PTR [esp+4], 122
    ja fail
    mov eax, 3                      ; return 3 if lower case
    ret 4

  align 4
  tryupper:
    cmp BYTE PTR [esp+4], 65
    jb fail
    cmp BYTE PTR [esp+4], 90
    ja trylower
    mov eax, 2                      ; return 2 if upper case
    ret 4

align 16
isalphanum proc char:BYTE

    cmp BYTE PTR [esp+4], 48
    jb fail
    cmp BYTE PTR [esp+4], 57
    ja tryupper
    mov eax, 1                      ; return 1 if number
    ret 4

isalphanum endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
