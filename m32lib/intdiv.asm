; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

IntDiv proc source:DWORD,divider:DWORD

    LOCAL var1:DWORD

    fild source     ; load source
    fild divider    ; load divider
    fdiv            ; divide source by divider
    fistp var1      ; store result in variable
    mov eax, var1

    ret

IntDiv endp

; #########################################################################

end