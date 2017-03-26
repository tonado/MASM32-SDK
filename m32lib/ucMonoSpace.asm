; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .686p                       ; maximum processor model
    .XMM                        ; SIMD extensions
    .model flat, stdcall        ; memory model & calling convention
    option casemap :none        ; case sensitive
 
    ucMonoSpace PROTO :DWORD

    .code                       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

ucMonoSpace proc src:DWORD

  ; -------------------------------------------------------
  ; trim tabs and spaces from each end of "src" and replace
  ; any duplicate tabs and spaces with a single space. The
  ; result is written back to the source string address.
  ; -------------------------------------------------------

    push ebx
    push esi
    push edi
    push ebp

    mov esi, 2
    mov edi, 32
    mov ebx, 32
    mov ebp, 9

    mov ecx, [esp+20]
    xor eax, eax
    sub ecx, esi
    mov edx, [esp+20]
    jmp ftrim                       ; trim the start of the string

  wspace:
    mov WORD PTR [edx], bx          ; always write a space
    add edx, esi

  ftrim:
    add ecx, esi
    movzx eax, WORD PTR [ecx]
    cmp eax, edi                    ; throw away space
    je ftrim
    cmp eax, ebp                    ; throw away tab
    je ftrim
    sub ecx, esi

  stlp:
    add ecx, esi
    movzx eax, WORD PTR [ecx]
    cmp eax, edi                    ; loop back on space
    je wspace
    cmp eax, ebp                    ; loop back on tab
    je wspace
    mov [edx], ax                   ; write the non space character
    add edx, esi
    test eax, eax                   ; if its not zero, loop back
    jne stlp

    cmp WORD PTR [edx-4], bx        ; test for a single trailing space
    jne quit
    mov WORD PTR [edx-4], 0         ; overwrite it with zero if it is

  quit:
    mov eax, [esp+20]

    pop ebp
    pop edi
    pop esi
    pop ebx

    ret 4

ucMonoSpace endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
