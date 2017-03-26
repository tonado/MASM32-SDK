; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    StrLen PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

StdErr proc lpszText:DWORD

    LOCAL hOutPut  :DWORD
    LOCAL bWritten :DWORD
    LOCAL sl       :DWORD

    invoke GetStdHandle,STD_ERROR_HANDLE
    mov hOutPut, eax

    invoke StrLen,lpszText
    mov sl, eax

    invoke WriteFile,hOutPut,lpszText,sl,ADDR bWritten,NULL

    mov eax, bWritten
    ret

StdErr endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
