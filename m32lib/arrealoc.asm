; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    realloc_string_array  PROTO :DWORD,:DWORD
    truncate_string_array PROTO :DWORD,:DWORD
    extend_string_array   PROTO :DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

realloc_string_array proc arr:DWORD,cnt:DWORD

    .if cnt < arrcnt$(arr)
      invoke truncate_string_array,arr,cnt  ; truncate array to new size
      ret
    .elseif cnt > arrcnt$(arr)
      invoke extend_string_array,arr,cnt    ; extend array to new size
      ret
    .else
      mov eax, arr                          ; return original array pointer
    .endif

    ret

realloc_string_array endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
