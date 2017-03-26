; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    EXTERNDEF d_e_f_a_u_l_t__n_u_l_l_$ :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arrset proc arr:DWORD,indx:DWORD,ptxt:DWORD

  ; --------------------------------------------
  ; write zero terminated string to array member
  ; --------------------------------------------
  ; 5 possible return values
  ; ------------------------
  ; 1. The written text length.
  ; 2. 0 if text length or argument is zero.
  ; 3. -1 bounds error, below 1.
  ; 4. -2 bounds error, above index.
  ; 5. -3 out of memory error.
  ; ----------------------------------------

    LOCAL mcnt  :DWORD

    push ebx
    push esi
    push edi

    mov esi, arr                                ; load array adress in ESI
    mov eax, [esi]                              ; write member count to EAX
    mov mcnt, eax                               ; store count in local mcnt
    mov ebx, indx                               ; store the index in EBX

  ; ---------------------
  ; array bounds checking.
  ; ---------------------
    .if ebx < 1
      mov eax, -1                               ; return -1 below bound error
      jmp quit
    .endif

    .if ebx > mcnt
      mov eax, -2                               ; return -2 above bound error
      jmp quit
    .endif

    mov eax, [esi+ebx*4]
    .if DWORD PTR [eax] != 0                    ; if its not a NULL string
      invoke SysFreeString,[esi+ebx*4]          ; deallocate the array member
    .endif

    .if ptxt == 0
    null_string:                                ; reset to default null string
      mov [esi+ebx*4], OFFSET d_e_f_a_u_l_t__n_u_l_l_$
      xor eax, eax                              ; return zero for string length
      jmp quit
    .else
      mov edi, rv(StrLen,ptxt)
      test edi, edi
      jz null_string
      invoke SysAllocStringByteLen,ptxt,edi     ; allocate a buffer of that length
      .if eax != 0
        mov [esi+ebx*4], eax                    ; write new handle back to pointer array
        mov eax, edi                            ; return the written length
      .else
        mov eax, -3                             ; return -3 out of memory error
        jmp quit
      .endif
    .endif

  quit:
    pop edi
    pop esi
    pop ebx

    ret

arrset endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
