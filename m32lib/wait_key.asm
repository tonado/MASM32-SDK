; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\msvcrt.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

wait_key proc

    invoke FlushConsoleInputBuffer, rv(GetStdHandle,STD_INPUT_HANDLE)

  @@:
    invoke Sleep, 1
    call crt__kbhit
    test eax, eax
    jz @B

    call crt__getch     ; recover the character in the keyboard
                        ; buffer and return it in EAX
    ret

wait_key endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
