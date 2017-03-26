; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 4

readline proc source:DWORD,buffer:DWORD,spos:DWORD

comment * ------------------------------------------------------

        source  =   source memory to read line from
        buffer  =   buffer that line of text is written to
        spos    =   start position in buffer to write to

        readline copies a line of text from the source
        to the buffer starting from the offset set in "spos",
        updates the "spos" variable to the start of the following
        line of text and returns that variable in EAX.
        EAX returns ZERO if the end of the source is on the
        curent line.

        The length of the line not including ascii
        0 and 13 is returned in ECX. You should test
        the buffer if ZERO is returned in EAX as it may
        contain the last line of text that is zero terminated.

        Conditions to test for.
        1. End of source returns zero in EAX.
        2. blank line has 1st byte in buffer set to zero
           and a line length in ECX of ZERO.
        3. Line length is returned in ECX.

        ------------------------------------------------------ *

    push edi

    mov edx, [esp+8]            ; source address in EDX
    mov edi, [esp+12]           ; buffer address in EDI
    add edx, [esp+16]           ; add spos to source
    xor eax, eax                ; clear EAX
    mov ecx, -1                 ; set index and counter to -1
    jmp ristart

  align 4
  pre:
    mov [edi+ecx], al           ; write BYTE to buffer
  ristart:
    add ecx, 1
    mov al, [edx+ecx]           ; read BYTE from source
    cmp al, 9                   ; handle TAB character
    je pre
    cmp al, 13                  ; test for ascii 13 and 0
    ja pre

    mov BYTE PTR [edi+ecx], 0   ; write terminator to buffer
    test eax, eax               ; test for end of source
    jz liout                    ; return zero if end of source
    lea eax, [ecx+2]            ; add counter + 2 to EAX
    add eax, [esp+16]           ; return next spos in eax

  liout:
    pop edi

    ret 12

readline endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
