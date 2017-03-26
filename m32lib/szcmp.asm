; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                        ; force 32 bit code
    .model flat, stdcall        ; memory model & calling convention
    option casemap :none        ; case sensitive

    szCmp PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

szCmp proc str1:DWORD, str2:DWORD

  ; --------------------------------------
  ; scan zero terminated string for match
  ; --------------------------------------
    mov ecx, [esp+4]
    mov edx, [esp+8]

    push ebx
    push esi
    mov eax, -1
    mov esi, 1

  align 4
  cmst:
  REPEAT 3
    add eax, esi
    movzx ebx, BYTE PTR [ecx+eax]
    cmp bl, [edx+eax]
    jne no_match
    test ebx, ebx       ; check for terminator
    je retlen
  ENDM

    add eax, esi
    movzx ebx, BYTE PTR [ecx+eax]
    cmp bl, [edx+eax]
    jne no_match
    test ebx, ebx       ; check for terminator
    jne cmst

  retlen:               ; length is in EAX
    pop esi
    pop ebx
    ret 8

  no_match:
    xor eax, eax        ; return zero on no match
    pop esi
    pop ebx
    ret 8

szCmp endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end