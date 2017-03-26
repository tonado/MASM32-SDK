; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

StrLen proc item:DWORD

    mov     eax, [esp+4]            ; get pointer to string
    lea     edx, [eax+3]            ; pointer+3 used in the end
    push    ebp
    push    edi
    mov     ebp, 80808080h

  @@:     
  REPEAT 3
    mov     edi, [eax]              ; read first 4 bytes
    add     eax, 4                  ; increment pointer
    lea     ecx, [edi-01010101h]    ; subtract 1 from each byte
    not     edi                     ; invert all bytes
    and     ecx, edi                ; and these two
    and     ecx, ebp
    jnz     nxt
  ENDM

    mov     edi, [eax]              ; read first 4 bytes
    add     eax, 4                  ; 4 increment DWORD pointer
    lea     ecx, [edi-01010101h]    ; subtract 1 from each byte
    not     edi                     ; invert all bytes
    and     ecx, edi                ; and these two
    and     ecx, ebp
    jz      @B                      ; no zero bytes, continue loop

  nxt:
    test    ecx, 00008080h          ; test first two bytes
    jnz     @F
    shr     ecx, 16                 ; not in the first 2 bytes
    add     eax, 2
  @@:
    shl     cl, 1                   ; use carry flag to avoid branch
    sbb     eax, edx                ; compute length
    pop     edi
    pop     ebp

    ret     4

StrLen endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end