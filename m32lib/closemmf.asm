; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    CloseMMF PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

CloseMMF proc lpMem:DWORD,hMMF:DWORD

    invoke UnmapViewOfFile,lpMem
    invoke CloseHandle,hMMF

    ret

CloseMMF endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
