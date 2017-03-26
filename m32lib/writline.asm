; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

writeline proc source:DWORD,buffer:DWORD,spos:DWORD,flag:DWORD

comment * ----------------------------------------------------
    source  =   address of string to write to memory
    buffer  =   buffer to write string to.
    spos    =   starting position in buffer to write to
    flag    =   0 to append CRLF, non zero if no CRLF required
        ---------------------------------------------------- *

    push edi

    mov edx, [esp+8]                    ; source address in EDX
    mov edi, [esp+12]                   ; buffer address in EDI
    add edi, [esp+16]                   ; add starting position to buffer address
    xor eax, eax                        ; clear index and counter
    xor ecx, ecx                        ; prevent stall

  @@:
    mov cl, [edx+eax]
    mov [edi+eax], cl
    add eax, 1
    test cl, cl                         ; exit loop if zero is written
    jnz @B

    cmp DWORD PTR [esp+20], 0           ; test flag a CRLF is to be appended
    jne @F
    mov WORD PTR [edi+eax-1], 0A0Dh     ; append CRLF to current location
    add eax, 2
    mov BYTE PTR [edi+eax], 0           ; zero terminate CRLF
  @@:

    sub eax, 1
    mov ecx, eax                        ; bytes written returned in ECX
    add eax, [esp+16]                   ; updated "spos" returned in EAX

    pop edi

    ret 16

writeline endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
