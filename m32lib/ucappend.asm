; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    ucappend PROTO :DWORD,:DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

ucappend proc buffer:DWORD,string:DWORD,cloc:DWORD

  ; -----------------------------------------------
  ; buffer = the buffer to append characters onto
  ; string = the characters to append to the buffer
  ; cloc   = the current append location POINTER
  ; NOTE that cloc POINTER is a BYTE counter. To
  ; get the UNICODE character count, divide "cloc"
  ; by 2.
  ; -----------------------------------------------

    push esi

    mov esi, [esp+4][4]     ; buffer
    add esi, [esp+12][4]    ; cloc
    mov ecx, [esp+8][4]     ; string

    xor eax, eax

  @@:
    movzx edx, WORD PTR [ecx+eax]
    mov [esi+eax], dx
    add eax, 2
    cmp dx, 0
    jne @B

    add eax, [esp+12][4]    ; cloc
    sub eax, 2

    pop esi

    ret 12

ucappend endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
