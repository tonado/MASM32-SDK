; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    ucRemove PROTO :DWORD,:DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

ucRemove proc src:DWORD,dst:DWORD,remv:DWORD

    push ebx
    push esi
    push edi

    mov edx, [esp+12+12]
    mov bx, [edx]               ; 1st remv char in BX

    mov esi, [esp+4+12]
    mov edi, [esp+8+12]
    sub esi, 2

  ; --------------------------------------------------------

  prescan:
    add esi, 2
  scanloop:
    cmp [esi], bx               ; test for "remv" start char
    je presub
  backin:
    movzx eax, WORD PTR [esi]
    mov [edi], ax
    cmp WORD PTR [edi], 0       ; exit when zero terminator
    je szrOut                   ; has been written
    add edi, 2
    jmp prescan

  align 4
  presub:
    xor ecx, ecx
  subloop:

  REPEAT 3
    movzx eax, WORD PTR [esi+ecx]
    cmp ax, [edx+ecx]
    jne backin                  ; jump back on mismatch
    add ecx, 2
    cmp BYTE PTR [edx+ecx], 0   ; test if next byte is zero
    je @F
  ENDM

    movzx eax, WORD PTR [esi+ecx]
    cmp ax, [edx+ecx]
    jne backin                  ; jump back on mismatch
    add ecx, 2
    cmp BYTE PTR [edx+ecx], 0   ; test if next byte is zero
    jne subloop

  @@:
    add esi, ecx
    jmp scanloop

  ; --------------------------------------------------------

  szrOut:

    mov eax, [esp+8+12]         ; return the destination address

    pop edi
    pop esi
    pop ebx

    ret 12

ucRemove endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
