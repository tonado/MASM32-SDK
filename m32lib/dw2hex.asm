; ########################################################################
;
;               This original module was written by f0dder.
;
;      Part of the code has been optimised by Alexander Yackubtchik
;
; ########################################################################

    .386
    .model flat, stdcall
    option casemap :none   ; case sensitive

    .code

; ########################################################################

dw2hex proc source:DWORD, lpBuffer:DWORD

    push esi

    mov edx, lpBuffer
    mov esi, source

    xor eax, eax
    xor ecx, ecx

    mov [edx+8], al         ; put terminator at correct length
    mov cl, 7               ; length of hexstring - 1

  @@:
    mov eax, esi            ; we're going to work on AL
    and al, 00001111b       ; mask out high nibble

    cmp al,10
    sbb al,69h
    das

    mov [edx + ecx], al     ; store the asciihex(AL) in the string
    shr esi, 4              ; next nibble
    dec ecx                 ; decrease counter (one byte less than dec cl :-)
    jns @B                  ; eat them if there's any more

    pop esi

    ret

dw2hex endp

; #########################################################################

end 