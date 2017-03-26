; #########################################################################

    ; -------------------------------------------------------
    ; This procedure was written by Ernie Muphy    8/12/00
    ; -------------------------------------------------------

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; #########################################################################

dw2ah proc public dwValue:DWORD, lpBuffer:DWORD
	
    ; -------------------------------------------------------------
    ; convert DWORD to hexadecimal ascii string
    ; dwValue is value to be converted
    ; lpBuffer is the address of the receiving buffer
    ; EXAMPLE:
    ; invoke dwtoa,edx,ADDR buffer
    ;
    ; lpBuffer must be at least 10 bytes long
    ;
    ; Uses: eax, ecx.
    ;
    ;
    ; -------------------------------------------------------------

    mov ecx, lpBuffer
    add ecx, 8
    mov WORD PTR [ecx], 0048H   ; "H", 0  (Hex identifier and trailing zero)
    dec ecx
Convert:
    mov eax, dwValue
    and eax, 0FH            ; get digit
    .IF al < 10
        add al, "0"         ; convert digits 0-9 to ascii
    .ELSE
        add al, ("A"-10)    ; convert digits A-F to ascii
    .ENDIF
    mov BYTE PTR [ecx], al            
    dec ecx
    ror dwValue,4           ; shift in next hex digit
    cmp ecx, lpBuffer       ; see if we have more to do
    jae Convert
    ret

dw2ah endp
; #########################################################################

end
