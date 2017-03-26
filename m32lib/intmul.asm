; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

IntMul proc source:DWORD,multiplier:DWORD

    LOCAL var1:DWORD

    fild source         ; load source
    fild multiplier     ; load multiplier
    fmul                ; multiply source by multiplier
    fistp var1          ; store result in variable
    mov eax, var1

    ret

IntMul endp

; #########################################################################

    end