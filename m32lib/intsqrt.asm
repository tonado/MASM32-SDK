; #########################################################################

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; #########################################################################

IntSqrt proc source:DWORD

    LOCAL var:DWORD

    fild source     ; load source integer
    fsqrt
    fistp var       ; store result in variable
    mov eax, var

    ret

IntSqrt endp

; #########################################################################

end