; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

    szWcnt PROTO :DWORD,:DWORD
    szLen  PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

szWcnt proc src:DWORD,txt:DWORD

    push ebx
    push esi
    push edi

    mov edx, len([esp+16])      ; procedure call for src length
    sub edx, len([esp+20])      ; procedure call for 1st text length

    mov eax, -1
    mov esi, [esp+16]           ; source in ESI
    add edx, esi                ; add src to exit position
    xor ebx, ebx                ; clear EBX to prevent stall with BL
    add edx, 1                  ; correct to get last word
    mov edi, [esp+20]           ; text to count in EDI
    sub esi, 1

  pre:
    add eax, 1                  ; increment word count return value
  align 4
  wcst:
    add esi, 1
    cmp edx, esi                ; test for exit condition
    jle wcout
    mov bl, [esi]               ; load byte at ESI
    cmp bl, [edi]               ; test against 1st character in EDI
    jne wcst
    xor ecx, ecx
  align 4
  test_word:
    add ecx, 1
    cmp BYTE PTR [edi+ecx], 0   ; if terminator is reached
    je pre                      ; jump back and increment counter
    mov bl, [esi+ecx]           ; load byte at ESI
    cmp bl, [edi+ecx]           ; test against 1st character in EDI
    jne wcst                    ; exit if mismatch
    jmp test_word               ; else loop back
  wcout:

    pop edi
    pop esi
    pop ebx

    ret 8

szWcnt endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
