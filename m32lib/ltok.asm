; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    ltok PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

ltok proc pTxt:DWORD,pArray:DWORD

  ; ---------------------------------------------------------------
  ; tokenise lines in a text source writing an array of pointers
  ; to the address of "pArray" and returning the line count in EAX.
  ;
  ; The address written to the variable "pArray" should be released
  ; within the same scope as the variable with a call to GlobalFree()
  ; when the pointer array is no longer required.
  ; ---------------------------------------------------------------

    push esi
    push edi

    mov edi, 1                      ; set counter to 1 in case of no trailing CRLF

    mov esi, pTxt
    sub esi, 1
  ; ----------------
  ; count line feeds
  ; ----------------
  @@:
    add esi, 1
    movzx edx, BYTE PTR [esi]
    test edx, edx                   ; test for terminator
    jz @F
    cmp edx, 10                     ; test for line feed
    jne @B
    add edi, 1                      ; lf count in EDI
    jmp @B
  @@:
  ; --------------------
  ; multiply result by 4
  ; --------------------
    add edi, edi
    add edi, edi
    mov ecx, alloc(edi)             ; allocate pointer array memory

    mov edi, ecx                    ; copy allocated memory address into EDI
    mov esi, pTxt
    xor eax, eax                    ; zero arg counter
    sub esi, 1
    jmp ftrim

  ; ---------------------------------

  terminate:
    mov BYTE PTR [esi], 0           ; terminate end of current line

  ftrim:                            ; scan to find next acceptable character
    add esi, 1
    movzx edx, BYTE PTR [esi]       ; zero extend byte
    test edx, edx                   ; test for zero terminator
    jz lout
    cmp edx, 32
    jbe ftrim                       ; scan again for 32 or less

  ; д=ў=д=ў=д=ў=д=ў=д
    mov [edi], esi                  ; write current location to pointer
    add edi, 4                      ; set next pointer location
    add eax, 1                      ; increment arg count return value
  ; д=ў=д=ў=д=ў=д=ў=д

  ttrim:                            ; scan to find the next CR or LF
    add esi, 1
    movzx edx, BYTE PTR [esi]       ; zero extend byte
    cmp edx, 13
    jg ttrim                        ; short loop on normal case

    je terminate
    cmp edx, 10                     ; extra test for ascii 10
    je terminate
    test edx, edx
    jnz ttrim                       ; loop back if not zero, IE TAB.

  ; ---------------------------------

  lout:
    mov esi, pArray                 ; load passed handle address into ESI
    mov [esi], ecx                  ; store local array handle at address of passed handle

    pop edi
    pop esi

    ret

ltok endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
