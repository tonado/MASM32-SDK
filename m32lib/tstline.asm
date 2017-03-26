; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

tstline proc lpstr:DWORD

comment * -----------------------------------------------------------
        This procedure tests the first character after any tabs or
        spaces to determine if the line has usable text or not.
        If the text has the first non-white space below ascii 32
        which includes ascii zero (0), CR (13) and LF (10) it returns
        zero otherwise it returns the zero extended first character
        in EAX for testing by the caller.

        This can be used to test if the first character is a comment
        so that the caller can bypass the contents of the line. The
        return value can be tested either as a DWORD with a numeric
        value with EAX or directly as a BYTE in AL.
        ----------------------------------------------------------- *

    mov eax, [esp+4]            ; lpstr
    sub eax, 1

  @@:
    add eax, 1
    cmp BYTE PTR [eax], 32      ; loop back on space
    je @B
    cmp BYTE PTR [eax], 9       ; loop back on tab
    je @B
    cmp BYTE PTR [eax], 32      ; reject anything with a start char below 32
    jl reject
    movzx eax, BYTE PTR [eax]   ; return the first char in EAX for testing.
    ret 4

  reject:
    xor eax, eax                ; return ZERO on blank line
    ret 4

tstline endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
