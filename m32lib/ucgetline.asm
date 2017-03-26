; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .code                     ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

ucgetline proc src:DWORD,dst:DWORD,cloc:DWORD

    push esi

    mov esi, [esp+4][4]         ; src
    mov edx, [esp+8][4]         ; dst
    add esi, [esp+12][4]        ; cloc
    sub esi, 2
    sub edx, 2

  lbl0:
    add esi, 2
    add edx, 2
    movzx eax, WORD PTR [esi]
    test eax, eax               ; test for terminator
    jz iszero
    cmp eax, 13                 ; test for leading CR
    je quit
    mov [edx], ax               ; write WORD to destination buffer
    jmp lbl0

  iszero:                       ; EAX is set to ZERO by preceding loop
    mov DWORD PTR [edx], 0      ; write terminator to destination buffer
    pop esi
    ret 12

  quit:
    mov DWORD PTR [edx], 0      ; write the terminator
    add esi, 4                  ; increment ESI up 2 WORD characters

    mov eax, esi
    sub eax, [esp+4][4]         ; return the current location in the source

    pop esi

    ret 12

ucgetline endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
