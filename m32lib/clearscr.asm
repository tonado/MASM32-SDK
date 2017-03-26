; #########################################################################

    .386
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    locate PROTO :DWORD,:DWORD

    .code

; #########################################################################

ClearScreen proc

  ; -----------------------------------------------------------
  ; This procedure reads the column and row count, multiplies
  ; them together to get the number of characters that will fit
  ; onto the screen, writes that number of blank spaces to the
  ; screen and reposition the prompt at position 0,0.
  ; -----------------------------------------------------------

    LOCAL hOutPut:DWORD
    LOCAL noc    :DWORD
    LOCAL cnt    :DWORD
    LOCAL sbi    :CONSOLE_SCREEN_BUFFER_INFO

    invoke GetStdHandle,STD_OUTPUT_HANDLE
    mov hOutPut, eax

    invoke GetConsoleScreenBufferInfo,hOutPut,ADDR sbi

    mov eax, sbi.dwSize     ; 2 word values returned for screen size

  ; -----------------------------------------------
  ; extract the 2 values and multiply them together
  ; -----------------------------------------------
    push ax
    rol eax, 16
    mov cx, ax
    pop ax
    mul cx
    cwde
    mov cnt, eax

    invoke FillConsoleOutputCharacter,hOutPut,32,cnt,NULL,ADDR noc

    invoke locate,0,0

    ret

ClearScreen endp

; #########################################################################

end