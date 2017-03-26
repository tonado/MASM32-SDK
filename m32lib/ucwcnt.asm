; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .686p                       ; maximum processor model
    .XMM                        ; SIMD extensions
    .model flat, stdcall        ; memory model & calling convention
    option casemap :none        ; case sensitive

    ucLen  PROTO :DWORD
    ucWcnt PROTO :DWORD,:DWORD

    .code                       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

align 4

ucWcnt proc src:DWORD,txt:DWORD

    push ebx
    push esi
    push edi

    invoke ucLen,src            ; get src length
    add eax, eax
    push eax
    invoke ucLen,txt            ; get txt length
    add eax, eax
    pop edx
    sub edx, eax

    mov eax, -1
    mov esi, src                ; source in ESI
    add edx, esi                ; add src to exit position
    xor ebx, ebx                ; clear EBX to prevent stall with BH
    add edx, 2                  ; correct to get last word
    mov edi, txt                ; text to count in EDI
    sub esi, 2

  pre:
    add eax, 1                  ; increment word count return value
  align 4
  wcst:
    add esi, 2
    cmp edx, esi                ; test for exit condition
    jle wcout
    mov bx, [esi]               ; load byte at ESI
    cmp bx, [edi]               ; test against 1st character in EDI
    jne wcst
    xor ecx, ecx
  align 4
  test_word:
    add ecx, 2
    cmp WORD PTR [edi+ecx], 0   ; if terminator is reached
    je pre                      ; jump back and increment counter
    mov bx, [esi+ecx]           ; load character at ESI
    cmp bx, [edi+ecx]           ; test against 1st character in EDI
    jne wcst                    ; exit if mismatch
    jmp test_word               ; else loop back
  wcout:

    pop edi
    pop esi
    pop ebx

    ret

ucWcnt endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
