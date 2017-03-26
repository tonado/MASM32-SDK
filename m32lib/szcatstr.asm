; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall
    option casemap :none

    szLen PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

szCatStr proc lpszSource:DWORD, lpszAdd:DWORD

    push edi

    invoke szLen,[esp+8]            ; get source length
    mov edi, [esp+8]
    mov ecx, [esp+12]
    add edi, eax                    ; set write starting position
    xor edx, edx                    ; zero index

  @@:
    movzx eax, BYTE PTR [ecx+edx]   ; write append string to end of source
    mov [edi+edx], al
    add edx, 1
    test eax, eax                   ; exit when terminator is written
    jne @B

    pop edi

    mov eax, [esp+8]                ; return start address of source

    ret 8

szCatStr endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end

