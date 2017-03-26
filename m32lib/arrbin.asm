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

arrbin proc arr:DWORD,indx:DWORD,psrc:DWORD,lsrc:DWORD

  ; ---------------------------------------------------
  ; write byte data of specified length to array member
  ; ---------------------------------------------------
  ; 4 possible return values
  ; ------------------------
  ; 1. The written binary data length.
  ; 2. 0 if length is zero.
  ; 3. -1 bounds error, below 1.
  ; 4. -2 bounds error, above index.
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
      mov eax, -1                               ; return -1 error
      jmp quit
    .endif

    .if ebx > mcnt
      mov eax, -2                               ; return -2 error
      jmp quit
    .endif

    invoke SysFreeString,[esi+ebx*4]            ; deallocate the array member

    .if lsrc == 0
    null_string:                                ; reset to default null string
      mov [esi+ebx*4], OFFSET d_e_f_a_u_l_t__n_u_l_l_$
      xor eax, eax                              ; return zero for string length
      jmp quit
    .else
      invoke SysAllocStringByteLen,0,lsrc       ; allocate a buffer of length "lsrc"
      mov [esi+ebx*4], eax
      invoke MemCopy,psrc,[esi+ebx*4],lsrc      ; copy source to buffer
      mov eax, lsrc                             ; return string length
    .endif

  quit:
    pop edi
    pop esi
    pop ebx

    ret

arrbin endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
