; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

comment * ----------------------------------
    This algorithm was designed by Greg Lyon
    -------------------------------------- *

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\msvcrt.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ret_key proc

    invoke FlushConsoleInputBuffer,rv(GetStdHandle,STD_INPUT_HANDLE)

    call crt__getch
    xor ecx, ecx        ; zero ecx for non extended key return value
    test eax, eax
    jz @F
    cmp eax, 0E0h
    jnz quit
  @@:
    call crt__getch
    mov ecx, 1          ; return 1 in ECX if an extended key is pressed
  quit:
    ret

ret_key endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
