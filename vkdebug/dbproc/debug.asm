;-----------------------------------------------------------------------------
;DebugPrint function is written by vkim and optimized by KetilO.
;-----------------------------------------------------------------------------

.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\masm32.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\masm32.lib

.data
szWinClass      byte "DbgWinClass", 0
szCommandLine   byte "\masm32\bin\dbgwin.exe", 0
szCRLF          byte 13, 10, 0 
szEdit          byte "Edit", 0

.code

DebugPrint proc DebugData: dword
    local hwnd: dword
    invoke FindWindow, addr szWinClass, NULL
    .if !eax
        invoke WinExec, addr szCommandLine, SW_SHOWNORMAL
        invoke FindWindow, addr szWinClass, NULL
    .endif
    .if eax
        mov hwnd, eax
        invoke FindWindowEx, hwnd, NULL, addr szEdit, NULL
        mov hwnd, eax
        invoke SendMessage, hwnd, WM_GETTEXTLENGTH, 0, 0
        push eax
        invoke SendMessage, hwnd, EM_SETSEL, -1, -1
        pop eax
        .if eax
            invoke SendMessage, hwnd, EM_REPLACESEL, FALSE, addr szCRLF
        .endif
        invoke SendMessage, hwnd, EM_REPLACESEL, FALSE, DebugData
        invoke SendMessage, hwnd, EM_SCROLLCARET, 0, 0
    .endif
    ret
DebugPrint endp

end
