;---------------------------------------------------------------------------
;This program is written by NaN.
;---------------------------------------------------------------------------

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

GetFPU MACRO stk:REQ, Data:REQ
     fxch stk
     fst Data
     fxch stk
ENDM

SetStatus MACRO
     xor eax, eax
     fstsw ax
     PrintHex eax
endm

.data
     One  dq 1.1
     Two  dq 2.2
     Three dq 3.3
     Four dq 4.4
   
.data?
     buf  db  128 dup(?)
     Data1     dq   ?
     Data2     dq   ?
.code
start:

     finit
     DumpFPU "No Numbers"
     fld1
     DumpFPU "One Number"
     fld Three
     fld Two
     fld One
     fldpi
     DumpFPU "5 Numbers"
     fld One
     fld Two
     fld Three
     DumpFPU "8 Numbers"
     SetStatus 
     fcom
     DumpFPU "Compare ST0 to ST1 (source)"
     fxch
     fcom
     DumpFPU "Xchg & Compare ST0 to ST1 (source)"
     fstp st(0)
     DumpFPU "After Pop!"
     fld st(0)
     fcom
     DumpFPU "Equal Compare ST0 to ST1 (source)"
     invoke ExitProcess, NULL
end start
end
