; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szMonoSpace proc src:DWORD

  ; -------------------------------------------------------
  ; trim tabs and spaces from each end of "src" and replace
  ; any duplicate tabs and spaces with a single space. The
  ; result is written back to the source string address.
  ; -------------------------------------------------------

    push ebx
    push esi
    push edi
    push ebp

    mov esi, 1
    mov edi, 32
    mov bl, 32
    mov ebp, 9

    mov ecx, [esp+20]
    xor eax, eax
    sub ecx, esi
    mov edx, [esp+20]
    jmp ftrim                       ; trim the start of the string

  wspace:
    mov BYTE PTR [edx], bl          ; always write a space
    add edx, esi

  ftrim:
    add ecx, esi
    movzx eax, BYTE PTR [ecx]
    cmp eax, edi                    ; throw away space
    je ftrim
    cmp eax, ebp                    ; throw away tab
    je ftrim
    sub ecx, esi

  stlp:
    add ecx, esi
    movzx eax, BYTE PTR [ecx]
    cmp eax, edi                    ; loop back on space
    je wspace
    cmp eax, ebp                    ; loop back on tab
    je wspace
    mov [edx], al                   ; write the non space character
    add edx, esi
    test eax, eax                   ; if its not zero, loop back
    jne stlp

    cmp BYTE PTR [edx-2], bl        ; test for a single trailing space
    jne quit
    mov BYTE PTR [edx-2], 0         ; overwrite it with zero if it is

  quit:
    mov eax, [esp+20]

    pop ebp
    pop edi
    pop esi
    pop ebx

    ret 4

szMonoSpace endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
