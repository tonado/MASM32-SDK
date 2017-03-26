; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

      fld10 MACRO fpvalue
        LOCAL name
        .data
          name REAL10 fpvalue
          align 4
        .code
        fld name
      ENDM

    .code

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

GetPercent proc source:DWORD, percent:DWORD

    fild DWORD PTR [esp+8]  ; load percent
    fld10 0.01              ; load reciprocal of 100
    fmul                    ; mul by reciprocal = div by 100
    fild DWORD PTR [esp+4]  ; load the source
    fmul                    ; multiply by previous result
    fistp DWORD PTR [esp+8] ; pop FP stack and store result in stack variable
    mov eax, [esp+8]        ; write result to EAX for return value
    ret 8

GetPercent endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    end