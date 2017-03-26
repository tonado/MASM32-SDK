; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486                      ; processor model
      .model flat, stdcall      ; memory model & calling convention
      option casemap :none      ; case sensitive

      szCopy PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

comment * -----------------------------------------------
        copied length minus terminator is returned in EAX
        ----------------------------------------------- *
align 4

szCopy proc src:DWORD,dst:DWORD

    push ebp
    push esi

    mov edx, [esp+12]
    mov ebp, [esp+16]
    mov eax, -1
    mov esi, 1

  @@:
    add eax, esi
    movzx ecx, BYTE PTR [edx+eax]
    mov [ebp+eax], cl
    test ecx, ecx
    jnz @B

    pop esi
    pop ebp

    ret 8

szCopy endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end