; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    StrLen PROTO :DWORD

    wtok PROTO :DWORD,:DWORD

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

wtok proc pText:DWORD,pArray:DWORD

  ; -------------------------------------------------
  ; tokenise an array of words based on the character
  ; range specified in the following table and return
  ; an array of pointers to the tokens.
  ; -------------------------------------------------
    .data
    align 4
    @_chtbl_@ \
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
      db 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    .code
  ; -------------------------------------------------------
  ; Note that if you modify the table you should not change
  ; the single or double quote as their capacity is built
  ; into the following algorithm.
  ;
  ; The memory handle to the pointer array written to the
  ; variable "pArray" should be released within the same
  ; scope as the variable with a call to GlobalFree().
  ; The MASM32 Macro "free" works fine.
  ; -------------------------------------------------------

    push ebx
    push esi
    push edi

    xor ebx, ebx                    ; zero the array counter

    invoke StrLen,pText             ; get the buffer length
    add eax, eax                    ; set pointer array size
    mov edx, alloc(eax)             ; allocate pointer array

  ; ======================
    mov esi, pText                  ; text address in ESI
    sub esi, 1
    mov edi, edx                    ; array address in EDI
  ; ======================

  badchar:
    add esi, 1
    movzx eax, BYTE PTR [esi]       ; zero extend byte
    test eax, eax                   ; test for zero terminator
    jz endsrc                       ; exit on terminator
    cmp BYTE PTR [@_chtbl_@+eax], 0 ; test if bad character in table
    je badchar                      ; loop back for next if it is

  ; д=ў=д=ў=д=ў=д=ў=д
    mov [edi], esi                  ; write current location to pointer array
    add edi, 4                      ; set next array write location
    add ebx, 1                      ; increment the array counter
  ; д=ў=д=ў=д=ў=д=ў=д

    cmp eax, 39                     ; is character a single quote ?
    je squote
    cmp eax, 34                     ; is character a double quote ?
    je dquote

  goodchar:
    add esi, 1
    movzx eax, BYTE PTR [esi]       ; zero extend byte
    test eax, eax                   ; test for zero terminator
    jz endsrc                       ; exit on terminator
    cmp BYTE PTR [@_chtbl_@+eax], 0 ; test if bad character in table
    jne goodchar                    ; loop back for next if its not

  ; д=ў=д=ў=д=ў=д=ў=д
    mov BYTE PTR [esi], 0           ; overwrite trailing bad char with zero
    jmp badchar
  ; д=ў=д=ў=д=ў=д=ў=д

  squote:                           ; single quote
    add esi, 1
    movzx eax, BYTE PTR [esi]
    test eax, eax
    jz qterror
    sub eax, 39
    jnz squote

    add esi, 1
    mov BYTE PTR [esi], 0
    jmp badchar

  dquote:                           ; double quote
    add esi, 1
    movzx eax, BYTE PTR [esi]
    test eax, eax
    jz qterror
    sub eax, 34
    jnz dquote

    add esi, 1
    mov BYTE PTR [esi], 0
    jmp badchar

  ; ======================

  ; The label "qterror" currently resolves to the same address as the
  ; following label "endsrc" but it is put in place if a user wants to
  ; modify this algorithm to flag a quotation error in the source text

  qterror:
  ; ----------------------------------------
  ; write quotation error handling code here
  ; ----------------------------------------

  endsrc:

; -------------------------------------------------------------------------

  ; -------------------------
  ; multiply array count by 4
  ; -------------------------
    mov eax, ebx                    ; EBX is the array count
    add eax, eax
    add eax, eax

  ; ----------------------
  ; truncate unused memory
  ; ----------------------
    invoke GlobalReAlloc,edx,eax,0  ; EDX is the allocate memory handle being reallocated

  ; -----------------------------------
  ; copy the local array handle back
  ; to the address of the passed handle
  ; -----------------------------------
    mov esi, pArray                 ; load passed handle address into EDX
    mov DWORD PTR [esi], eax        ; store local array handle at address of passed handle

    mov eax, ebx                    ; return array count in EAX

    pop edi
    pop esi
    pop ebx

    ret

wtok endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
