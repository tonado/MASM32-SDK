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

;DBGWIN_DEBUG_ON = 1 ;turn it off if you don't want to include debug info into the program
;DBGWIN_EXT_INFO = 1 ;turn it off if you don't want to include extra debug info into the program

.data
dwVar dword 0
szMessage byte "Message", 0
dblNum real8 -8.596

.code
start:
    mov eax, 0FFFFABCDh
    PrintHex eax, "Hex value"
    PrintHex ax
    PrintHex ah
    PrintHex al
    PrintLine

    PrintDec eax, "Decimal value"
    PrintDec eax
    PrintLine

    PrintDouble dblNum, "Double value"
    PrintDouble dblNum
    PrintLine

    PrintText "Test string"
    PrintLine

    PrintString szMessage
    PrintLine

    lea eax, szMessage
    PrintStringByAddr eax
    PrintLine

    DBGWIN_EXT_INFO = 0
    PrintText "PrintError demo:"
    DBGWIN_EXT_INFO = 1
    invoke SetLastError, 85h
    PrintError
    PrintLine

    xor eax, eax
    ASSERT eax
    ASSERT eax, "eax is zero"
    PrintLine

    Fix <I am going to fix it later>

    DbgDump offset szMessage, 35
    PrintLine

    ;-----------------------------------------------------------------------
    ;the code below shows how to use PrintException macro    
    
    ;install new seh
    assume fs: nothing
    push offset SEHproc
    push fs:[0]
    mov fs:[0], esp
    ;crash code
    xor eax, eax
    xchg eax, [eax]
ext:
    ;restore previous SEH
    mov eax, [esp] 
    mov fs:[0], eax
    add esp, 8
    ret

SEHproc proc C pExcept: dword, pFrame: dword, pContext: dword, pDispatch: dword
    PrintException pExcept
    mov edx, pContext
    mov (CONTEXT ptr [edx]).regEip, offset ext
    mov eax, ExceptionContinueExecution
    ret
SEHproc endp

end start
