; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ########################################################################

StripRangeX proc lpszSource:DWORD,lpszDest:DWORD,stByte:BYTE,enByte:BYTE

; ---------------------------------------------------
; Strip range of characters excluding the two bytes
; that are used to identify the range This means
; remove characters from string from "stByte" to
; "enByte" EXCLUDING the two bytes used to identify
; the range.
;
; Example: text(attributes) => text()
; ---------------------------------------------------

    push esi
    push edi

    mov cl, stByte
    mov dl, enByte

    mov esi, lpszSource
    mov edi, lpszDest

  srxSt:
    mov al, [esi]   ; read BYTE
    inc esi
    cmp al, 0       ; test for zero
    je srxOut
    cmp al, cl      ; test for start byte
    je @F
    mov [edi], al
    inc edi
    jmp srxSt
  @@:
    mov [edi], al
    inc edi
  srxNxt:
    mov al, [esi]   ; read BYTE
    inc esi
    cmp al, 0       ; test for zero
    je srxOut
    cmp al, dl
    jne srxNxt
    mov [edi], al
    inc edi
    jmp srxSt
  srxOut:

    ret

StripRangeX endp

; ########################################################################

end