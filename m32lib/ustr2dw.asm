; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

; String <-> unsigned DWORD

; ---------------------------------------------------
; This algorithm was written by comrade
; <comrade2k@hotmail.com>; http://www.comrade64.com/
; ---------------------------------------------------

    .code

;#########################################################################

; ustr2dw

; Parameters
;     pszString - null-terminated string to be converted
; Result
;     eax = converted number
; Trashed: ecx, edx, esi

.code

;#########################################################################

ustr2dw proc pszString:DWORD

    push esi

    mov    esi, [pszString]
    xor    eax, eax
    xor    edx, edx
    jmp    @@chkz
  @@redo:    
    sub    dl, "0"
    mov    ecx, eax
    add    eax, eax
    shl    ecx, 3
    inc    esi
    add    eax, ecx
    add    eax, edx
@@chkz:
    mov    dl, [esi]
    test   dl, dl
    jnz    @@redo

    pop esi

    ret

ustr2dw endp

;#########################################################################

end