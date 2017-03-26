; #########################################################################
;
;           Small code replacement for Microsoft's DUMPBIN.EXE
;            This file is built as a console mode application
;
; #########################################################################

      .386
      .model flat, stdcall
      option casemap :none   ; case sensitive

      ArgClC PROTO :DWORD,:DWORD    ; console mode version
      Parse_Args PROTO

; #########################################################################

      include \masm32\include\windows.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\masm32.inc

      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\masm32.lib

; #########################################################################

    .code

start:

    invoke Parse_Args

    invoke ExitProcess,0

; #########################################################################

Parse_Args proc

    LOCAL counter:DWORD
    LOCAL szBuffer[128]:BYTE
    LOCAL szCmdline[128]:BYTE

    jmp @F
        lead$       db "link -dump ",0
        quote$      db 34,0
        quotspc$    db 34,32,0
    @@:

    invoke GetAppPath,ADDR szCmdline
    invoke lstrcat,ADDR szCmdline,ADDR lead$

    mov counter, 1

  StLoop:
    invoke ArgClC,counter,ADDR szBuffer
      cmp eax, 0
      je do_it
      cmp eax, 2
      je do_it

      invoke lstrcat,ADDR szCmdline,ADDR quote$
      invoke lstrcat,ADDR szCmdline,ADDR szBuffer
      invoke lstrcat,ADDR szCmdline,ADDR quotspc$
      inc counter
      jmp StLoop
      
  do_it:

      invoke WinExec,ADDR szCmdline,SW_SHOWNORMAL

    ret

Parse_Args endp

; #########################################################################

end start