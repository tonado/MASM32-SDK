; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

existW proc ucFileName:DWORD

    LOCAL ucwfd :WIN32_FIND_DATAW

    invoke FindFirstFile,ucFileName,ADDR ucwfd

    .if eax == INVALID_HANDLE_VALUE
      mov eax, 0                    ; 0 = NOT exist
    .else
      invoke FindClose, eax
      mov eax, 1                    ; 1 = exist
    .endif

    ret

existW endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
