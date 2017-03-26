; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    arrtrunc  PROTO :DWORD,:DWORD
    arrextnd  PROTO :DWORD,:DWORD
    arrcnt    PROTO :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arrealloc proc arr:DWORD,cnt:DWORD

    push esi

    mov esi, arrcnt$(arr)

    .if cnt < esi
      invoke arrtrunc,arr,cnt               ; truncate array to new size
      jmp quit
    .elseif cnt > esi
      invoke arrextnd,arr,cnt               ; extend array to new size
      jmp quit
    .else
      mov eax, arr                          ; return original array pointer
    .endif

  quit:
    pop esi
    ret

arrealloc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
