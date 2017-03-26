; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    __UNICODE__ equ 1

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

ucLen proc lpwstr:DWORD

  ; --------------------------------------------------
  ; returns character count in EAX without terminator.
  ; --------------------------------------------------
    mov ecx, [esp+4]
    mov edx, -2
    mov eax, -1

  @@:
    add edx, 2
    add eax, 1
    cmp WORD PTR [ecx+edx], 0
    jne @B

    ret 4

ucLen endp

OPTION PROLOGUE:ProLogueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
