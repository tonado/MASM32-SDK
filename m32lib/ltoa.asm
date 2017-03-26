; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\user32.inc

    ltoa PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ltoa proc lValue:DWORD, lpBuffer:DWORD

comment * -------------------------------------------------------
        convert signed 32 bit integer "lValue" to zero terminated
        string and store string at address in "lpBuffer"
        ------------------------------------------------------- *

    jmp @F
    fMtStrinG db "%ld",0
  @@:

    invoke wsprintf,lpBuffer,ADDR fMtStrinG,lValue
    cmp eax, 3
    jge @F
    xor eax, eax    ; zero EAX on fail
  @@:               ; else EAX contain count of bytes written

    ret

ltoa endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end