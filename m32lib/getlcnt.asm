; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    get_line_count PROTO :DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

get_line_count proc mem:DWORD,blen:DWORD

  ; mem = address of loaded file
  ; blen = length of loaded file

    mov ecx, blen
    mov edx, ecx
    sub edx, 2
    mov eax, mem
    cmp WORD PTR [eax+edx], 0A0Dh       ; if no trailing CRLF
    je cntlf

    mov WORD PTR [eax+ecx], 0A0Dh       ; append CRLF
    mov BYTE PTR [eax+ecx+2], 0         ; add terminator
    add blen, 2                         ; correct blen by 2

  cntlf:
    or ecx, -1
    xor eax, eax
    mov edx, mem
  @@:
    add ecx, 1
    cmp BYTE PTR [edx+ecx], 0
    je @F
    cmp BYTE PTR [edx+ecx], 10          ; count the line feed character
    jne @B
    add eax, 1
    jmp @B
  @@:

    mov ecx, blen                       ; return count in EAX, length in ECX

    ret

get_line_count endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
