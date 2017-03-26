; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    EXTERNDEF d_e_f_a_u_l_t__n_u_l_l_$ :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arrextnd proc arr:DWORD,indx:DWORD

    LOCAL acnt  :DWORD
    LOCAL oldc  :DWORD

    push ebx
    push esi
    push edi

    mov eax, arr                            ; get the array member count
    mov eax, [eax]
    mov oldc, eax                           ; write it to old count variable

    mov edi, indx
    cmp edi, oldc
    jg @F
    mov eax, -1                             ; *** ERROR *** indx not greater than oldc
    jmp quit

  @@:
    mov ecx, edi
    lea ecx, [4+ecx*4]                      ; set new pointer array size
    mov arr, rv(GlobalReAlloc,arr,ecx,GMEM_MOVEABLE)
    mov esi, arr
    mov [esi], edi                          ; store new array count in 1st array member
    mov ebx, oldc                           ; copy the old count to EBX
    add ebx, 1                              ; add 1 for 1 based index

  @@:
    mov [esi+ebx*4], OFFSET d_e_f_a_u_l_t__n_u_l_l_$
    add ebx, 1                              ; increment index
    cmp ebx, [esi]                          ; test if it matches the array count yet
    jle @B

    mov eax, arr                            ; return the reallocated memory address

  quit:
    pop edi
    pop esi
    pop ebx

    ret

arrextnd endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
