; #########################################################################

    .386
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    StrLen PROTO :DWORD

    .code

; #########################################################################

StdOut proc lpszText:DWORD

    LOCAL hOutPut  :DWORD
    LOCAL bWritten :DWORD
    LOCAL sl       :DWORD

    invoke GetStdHandle,STD_OUTPUT_HANDLE
    mov hOutPut, eax

    invoke StrLen,lpszText
    mov sl, eax

    invoke WriteFile,hOutPut,lpszText,sl,ADDR bWritten,NULL

    mov eax, bWritten
    ret

StdOut endp

; #########################################################################

end