; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    ; EXTERNDEF d_e_f_a_u_l_t__n_u_l_l_$ :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

    align 16

arrfree proc arr:DWORD

    push ebx
    push esi
    push edi

    mov esi, [esp+4][12]
    mov edi, [esi]                  ; get count from 1st member
    mov ebx, 1
  @@:
    mov eax, [esi+ebx*4]
    cmp DWORD PTR [eax], 0          ; if member is a NULL pointer
    jz nxt                          ; don't try and free an OLE string
    invoke SysFreeString,eax        ; else free each OLE string
  nxt:
    add ebx, 1
    cmp ebx, edi
    jl @B

    invoke GlobalFree,[esp+4][12]   ; free the pointer array

    mov eax, edi

    pop edi
    pop esi
    pop ebx

    ret 4

arrfree endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
