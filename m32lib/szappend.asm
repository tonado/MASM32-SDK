; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szappend proc string:DWORD,buffer:DWORD,location:DWORD

  ; ------------------------------------------------------
  ; string      the main buffer to append extra data to.
  ; buffer      the byte data to append to the main buffer
  ; location    current location pointer
  ; ------------------------------------------------------

    push esi
    push edi
    mov edi, 1

    mov eax, -1
    mov esi, [esp+12]       ; string
    mov ecx, [esp+16]       ; buffer
    add esi, [esp+20]       ; location ; add offset pointer to source address

  @@:
    add eax, edi
    movzx edx, BYTE PTR [ecx+eax]
    mov [esi+eax], dl
    test edx, edx
    jnz @B                  ; exit on written terminator

    add eax, [esp+20]       ; location ; return updated offset pointer

    pop edi
    pop esi

    ret 12

szappend endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
