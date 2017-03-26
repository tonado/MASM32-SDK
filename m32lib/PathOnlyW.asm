; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    GetPathOnlyW PROTO :DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

GetPathOnlyW proc src:DWORD,dst:DWORD

  ; ------------------------------------
  ; ARGUMENTS
  ; src = unicode path address
  ; dst = buffer address at least as
  ;       long as the src path
  ;
  ; RETURN VALUE
  ; 0 = invalid path (no "\" char)
  ; 1 = successful operation
  ;
  ; result is written to the dst buffer
  ; or set to 0 length if invalid path
  ; ------------------------------------

    mov ecx, [esp+4]            ; src
    mov edx, [esp+8]            ; dst
    sub ecx, 2
  @@:
    add ecx, 2
    movzx eax, WORD PTR [ecx]
    mov [edx], ax
    add edx, 2
    test ax, ax
    jnz @B
    sub ecx, [esp+4]            ; src
    mov eax, ecx                ; byte length is EAX

    mov edx, [esp+8]            ; dst
    add edx, eax
    add edx, 2

  stlp:
    sub edx, 2
    movzx eax, WORD PTR [edx]
    cmp ax, "\"
    je lpout
    cmp edx, [esp+8]            ; dst
    jne stlp

    mov edx, [esp+8]            ; dst
    mov WORD PTR [edx], 0       ; blank dst buffer
    xor eax, eax                ; zero EAX on no path in src
    ret 8

  lpout:
    mov WORD PTR [edx+2], 0     ; terminate the dst buffer
    mov eax, 1                  ; set EAX as non zero
    ret 8

GetPathOnlyW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
