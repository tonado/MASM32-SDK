; #########################################################################

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

        wsprintfA PROTO C :DWORD,:VARARG
        wsprintf equ <wsprintfA>

    .data
      fMtStrinG db "%lu",0

    .code

; #########################################################################

dw2a proc dwValue:DWORD, lpBuffer:DWORD

    ; -------------------------------------------------------------
    ; convert DWORD to ascii string
    ; dwValue is passed as a value, direct, indirect or in register
    ; lpBuffer is the ADDRESS of the receiving buffer
    ; EXAMPLE:
    ; invoke dw2a,edx,ADDR buffer
    ; -------------------------------------------------------------
    
    invoke wsprintf,lpBuffer,ADDR fMtStrinG,dwValue

    ret

dw2a endp

; #########################################################################

end