; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szLen proc src:DWORD

    mov eax, [esp+4]
    sub eax, 4

  @@:
    add eax, 4
    cmp BYTE PTR [eax], 0
    je lb1
    cmp BYTE PTR [eax+1], 0
    je lb2
    cmp BYTE PTR [eax+2], 0
    je lb3
    cmp BYTE PTR [eax+3], 0
    jne @B

    sub eax, [esp+4]
    add eax, 3
    ret 4
  lb3:
    sub eax, [esp+4]
    add eax, 2
    ret 4
  lb2:
    sub eax, [esp+4]
    add eax, 1
    ret 4
  lb1:
    sub eax, [esp+4]
    ret 4

szLen endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end