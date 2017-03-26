;Using TrapException macro

.386
.model flat,stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
include \masm32\include\debug.inc

includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\debug.lib

DBGWIN_EXT_INFO = 1
DBGWIN_DEBUG_ON = 1

.data

.code
start:
    TrapException <offset EH>
    xor edx, edx
    mov eax, 1
    xor ecx, ecx
    div ecx    
    ;xor eax, eax
    ;mov eax, [eax]
EH:
    ret
end start