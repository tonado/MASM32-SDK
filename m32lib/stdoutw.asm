; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    ucLen PROTO :DWORD

    .code       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

StdOutW proc lpszText:DWORD

    LOCAL hOutPut  :DWORD
    LOCAL bWritten :DWORD
    LOCAL sl       :DWORD

    mov hOutPut, rv(GetStdHandle,STD_OUTPUT_HANDLE)
    mov sl, rv(ucLen,lpszText)

    fn WriteConsole,hOutPut,lpszText,sl,ADDR bWritten,NULL
    mov eax, bWritten

    ret

StdOutW endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
