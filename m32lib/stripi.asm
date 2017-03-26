; #########################################################################

      .386                      ; force 32 bit code
      .model flat, stdcall      ; memory model & calling convention
      option casemap :none      ; case sensitive

    .code

; ########################################################################

StripRangeI proc lpszSource:DWORD,lpszDest:DWORD,stByte:BYTE,enByte:BYTE

; ---------------------------------------------------
; Strip range inclusive. This means remove characters
; from string from "stByte" to "enByte" INCLUDING the
; two bytes used to identify the range. Use this proc
; to strip html tags from html script.
; ---------------------------------------------------

    push esi
    push edi

    mov cl, stByte
    mov dl, enByte

    mov esi, lpszSource
    mov edi, lpszDest

  lpSt:
    mov al, [esi]   ; read BYTE
    inc esi
    cmp al, 0       ; test for zero
    je @@1
    cmp al, cl      ; test for start byte
    je @F
    mov [edi], al   ; write byte
    inc edi
    jmp lpSt

  @@:
    mov al, [esi]
    inc esi
    cmp al, 0       ; test for zero
    je @@1
    cmp al, dl      ; test for end byte
    je lpSt
    jmp @B

  @@1:
    mov [edi], al   ; write terminator

    pop edi
    pop esi

    ret

StripRangeI endp

; ########################################################################

end