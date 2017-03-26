.586
.model flat,stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
include \masm32\include\gdi32.inc
include \masm32\include\user32.inc
include \masm32\include\debug.inc

includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\debug.lib

DBGWIN_EXT_INFO = 0

.data
   oneline   dd 11111111h, 22222222h, 33333333h, 44444444h
   TwoLine   dd 55555555h, 66666666h, 77777777h, 88888888h
   ThreeLine dd 99999999h, 0aaaaaaaah, 0bbbbbbbbh, 0cccccccch
   Fourline  dd 0ddddddddh, 0eeeeeeeeh, 0ffffffffh, 0f0f0f0f0h
   
.data?

.code
start:
     DumpMem offset oneline, 16, "Hello"
     DumpMem offset oneline, 32
     DumpMem offset oneline, 48
     DumpMem offset oneline, 64
     DumpMem offset oneline, 17
     DumpMem offset oneline, 33
     DumpMem offset oneline, 49
     DumpMem offset oneline, 63

     invoke ExitProcess, NULL
end start
end
