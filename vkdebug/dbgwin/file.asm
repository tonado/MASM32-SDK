.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\masm32.inc
include \masm32\vkdebug\dbproc\debug.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\masm32.lib

extern hwnd: dword

.code

SaveAsFile proc lpszFileName: dword, lpszText: dword
    local hFile: dword
    local dwBts: dword
    local dwLen: dword
    invoke CreateFile,lpszFileName,    
            GENERIC_WRITE,              
            NULL,                       
            NULL,                       
            CREATE_ALWAYS,              
            FILE_ATTRIBUTE_NORMAL,      
            NULL
    mov hFile,eax
    invoke lstrlen, lpszText
    mov dwLen, eax
    invoke WriteFile, hFile, lpszText, dwLen, addr dwBts, NULL
    invoke CloseHandle, hFile
    ret
SaveAsFile endp

ReadFromFile proc lpszFileName: dword
    local hFile: dword
    local dwLen: dword
    local hMem: dword
    local pMem: dword
    local dwBts: dword
    invoke CreateFile, lpszFileName,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    mov hFile, eax
    invoke GetFileSize, hFile, NULL
    mov dwLen, eax
    .if dwLen > 32767
        invoke MessageBox, hwnd, CTEXT("Sorry, file is too large"), CTEXT("Error"), MB_OK+MB_ICONERROR
        mov pMem, 0
        jmp ext
    .endif
    inc dwLen
    invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, dwLen
    .if eax == 0
        jmp ext
    .endif
    mov pMem, eax
    invoke ReadFile, hFile, pMem, dwLen, addr dwBts, NULL
ext:
    invoke CloseHandle, hFile
    mov eax, pMem
    ret
ReadFromFile endp

end