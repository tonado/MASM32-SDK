; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    szRemove PROTO :DWORD,:DWORD,:DWORD

    .code

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

szRemove proc src:DWORD,dst:DWORD,remv:DWORD

    push ebx
    push esi
    push edi

    mov edx, [esp+12+12]
    mov bl, [edx]               ; 1st remv char in AH

    mov esi, [esp+4+12]
    mov edi, [esp+8+12]
    sub esi, 1

  ; --------------------------------------------------------

  prescan:
    add esi, 1
  scanloop:
    cmp [esi], bl               ; test for "remv" start char
    je presub
  backin:
    movzx eax, BYTE PTR [esi]
    mov [edi], al
    cmp BYTE PTR [edi], 0       ; exit when zero terminator
    je szrOut                   ; has been written
    add edi, 1
    jmp prescan

  align 4
  presub:
    xor ecx, ecx
  subloop:
  REPEAT 3
    movzx eax, BYTE PTR [esi+ecx]
    cmp al, [edx+ecx]
    jne backin                  ; jump back on mismatch
    add ecx, 1
    cmp BYTE PTR [edx+ecx], 0   ; test if next byte is zero
    je @F
  ENDM

    movzx eax, BYTE PTR [esi+ecx]
    cmp al, [edx+ecx]
    jne backin                  ; jump back on mismatch
    add ecx, 1
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

szRemove endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end