; #########################################################################

    .386
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    .code

; #########################################################################

locate proc x:DWORD,y:DWORD

    LOCAL hOutPut  :DWORD
    LOCAL xyVar    :DWORD

    invoke GetStdHandle,STD_OUTPUT_HANDLE
    mov hOutPut, eax

  ; -----------------------------------
  ; make both co-ordinates into a DWORD
  ; -----------------------------------
    mov  ecx, x
    mov  eax, y
    shl  eax, 16
    mov  ax, cx

    invoke SetConsoleCursorPosition,hOutPut,eax

    ret

locate endp

; #########################################################################

end