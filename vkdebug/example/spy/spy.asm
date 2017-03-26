;This program is written by vkim
;vkim@aport2000.ru
;-----------------------------------------------------------------------------

.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
include \masm32\include\debug.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\debug.lib

DBGWIN_DEBUG_ON = 1 ;turn it off if you don't want to include debug info into the program
DBGWIN_EXT_INFO = 1 ;turn it off if you don't want to include extra debug info into the program

.data
dwVar dword 0

.code
start:
    Spy dwVar
    mov dwVar, 5
    add dwVar, 2
    shl dwVar, 1
    sub dwVar, 4
    StopSpy
    ret
end start