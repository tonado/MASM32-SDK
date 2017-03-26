;----------------------------------------------------------------------------
;This file is written by vkim. All functions based on TTom's code.
;vkim@aport2000.ru
;----------------------------------------------------------------------------

comment 
    invoke SetRegString, HKEY_LOCAL_MACHINE,
                        CTEXT("Software\MASM\Registry Test\"),
                        CTEXT("StringKeyName"), 
                        CTEXT("aaa") 

    invoke SetRegDword, HKEY_LOCAL_MACHINE, 
                        CTEXT("Software\MASM\Registry Test\"), 
                        CTEXT("DwordKeyName"), 
                        4500

    invoke GetRegString, addr szBigBuffer,
                        HKEY_LOCAL_MACHINE,
                        CTEXT("Software\MASM\Registry Test\"),
                        CTEXT("StringKeyName")

    invoke GetRegDword, HKEY_LOCAL_MACHINE, 
                        CTEXT("Software\MASM\Registry Test\"), 
                        CTEXT("DwordKeyName"), 
                        addr dwValue



.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\advapi32.inc
include \masm32\include\kernel32.inc

includelib \masm32\lib\advapi32.lib
includelib \masm32\lib\kernel32.lib

.data

.code

SetRegString  proc HKEY: dword, lpszKeyName: dword, lpszValueName: dword, lpszString: dword
    local Disp: dword
    local pKey: dword
    local dwSize: dword
    invoke RegCreateKeyEx, HKEY_LOCAL_MACHINE,
        lpszKeyName, NULL, NULL, 
        REG_OPTION_NON_VOLATILE, 
        KEY_ALL_ACCESS, NULL,
        addr pKey, addr Disp
    .if eax == ERROR_SUCCESS
        invoke lstrlen, lpszString
        mov dwSize, eax
        invoke RegSetValueEx, pKey, lpszValueName, 
            NULL, REG_SZ, 
            lpszString, dwSize 
        push eax
        invoke RegCloseKey, pKey
        pop eax
    .endif
    ret
SetRegString endp

; -------------------------------------------------------------------------

GetRegString proc lpszBuffer: dword, HKEY: dword, lpszKeyName: dword, lpszValueName: dword
    local TType: dword
    local pKey: dword
    local dwSize: dword
    mov TType, REG_SZ
    invoke RegOpenKey, HKEY, lpszKeyName, addr pKey
    invoke RegQueryValueEx, pKey, lpszValueName, NULL, NULL, NULL, addr dwSize
    invoke RegCreateKeyEx, HKEY, lpszKeyName, NULL, NULL, REG_OPTION_NON_VOLATILE, 
        KEY_ALL_ACCESS, NULL, addr pKey, addr TType
    .if eax == ERROR_SUCCESS
        mov eax, REG_DWORD
        mov TType, eax
        inc dwSize
        invoke RegQueryValueEx, pKey, lpszValueName, 
            NULL, addr TType, 
            lpszBuffer, addr dwSize
        push eax
        invoke RegCloseKey, pKey
        pop eax
    .endif
    ret
GetRegString endp

; -------------------------------------------------------------------------

SetRegDword proc HKEY: dword, lpszKeyName: dword, lpszValueName: dword, lpdwValue: dword
    local Disp: dword
    local pKey: dword
    local dwValue: dword
    push lpdwValue
    pop dwValue
    DW_SIZE equ 4
    invoke RegCreateKeyEx, HKEY,
        lpszKeyName, NULL, NULL, 
        REG_OPTION_NON_VOLATILE, 
        KEY_ALL_ACCESS, NULL,
        addr pKey, addr Disp
    .if eax == ERROR_SUCCESS
        invoke RegSetValueEx, pKey, lpszValueName, 
        NULL, REG_DWORD_LITTLE_ENDIAN, 
        addr dwValue, DW_SIZE
        push eax
        invoke RegCloseKey, pKey
        pop eax
    .endif
    ret
SetRegDword endp

; -------------------------------------------------------------------------

GetRegDword proc HKEY: dword, lpszKeyName: dword, lpszValueName: dword, lpdwValue: dword
    local Temp: dword
    local pKey: dword
    local DWordSize: dword
    DW_SIZE EQU 4
    mov DWordSize, DW_SIZE
    invoke RegCreateKeyEx, HKEY, 
        lpszKeyName, NULL, NULL, 
        REG_OPTION_NON_VOLATILE, 
        KEY_ALL_ACCESS, NULL,
        addr pKey, addr Temp
    .if eax == ERROR_SUCCESS
        mov eax, REG_DWORD
        mov Temp, eax
        invoke RegQueryValueEx, pKey, lpszValueName, 
            NULL, addr Temp, 
            lpdwValue, addr DWordSize 
        push eax
        invoke RegCloseKey, pKey
        pop eax
    .endif
    ret
GetRegDword endp

end
