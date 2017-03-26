; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

    align 16

arrtotal proc arr:DWORD,crlf:DWORD

    push esi
    push edi

    mov esi, [esp+4][8]             ; get the array member count
    mov edi, [esi]
    xor edx, edx
    mov ecx, 1

  @@:
    mov eax, [esi+ecx*4]            ; get array member address
    sub eax, 4                      ; sub 4 to get stored OLE length
    add edx, [eax]                  ; add it to EDX
    add ecx, 1                      ; increment index
    cmp ecx, edi                    ; test if index == array count
    jle @B

    cmp DWORD PTR [esp+8][8], 0
    je @F
    add edx, edi
    add edx, edi
  @@:

    mov eax, edx

    pop edi
    pop esi

    ret 8

arrtotal endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
