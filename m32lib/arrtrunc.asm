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

arrtrunc proc arr:DWORD,indx:DWORD

    LOCAL acnt  :DWORD

    push ebx
    push esi
    push edi

    mov eax, arr                            ; get the array member count
    mov eax, [eax]
    mov acnt, eax                           ; write it to old count variable
    mov edi, indx

    cmp edi, acnt
    jl @F
    mov eax, -1                             ; *** ERROR *** indx exceeds array length
    jmp quit
  @@:

    mov esi, arr
    mov ebx, indx
    add ebx, 1

  @@:
    mov eax, [esi+ebx*4]
    cmp DWORD PTR [eax], 0                  ; if member is a null pointer
    je nxt                                  ; bypass deallocating OLE string
    invoke SysFreeString,[esi+ebx*4]
  nxt:

    add ebx, 1
    cmp ebx, acnt
    jle @B

    mov ecx, indx
    lea ecx, [4+ecx*4]                      ; mul by 4 plus 4 added

    mov arr, rv(GlobalReAlloc,arr,ecx,GMEM_MOVEABLE)
    mov esi, arr
    mov edi, indx
    mov DWORD PTR [esi], edi

    mov eax, arr

  quit:
    pop edi
    pop esi
    pop ebx

    ret

arrtrunc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
