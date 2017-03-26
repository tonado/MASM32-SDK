.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToTimeString24 PROC pdt:PTR DATETIME, pszTime24:PTR BYTE

    LOCAL tlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL tbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetTimeFormat, LOCALE_USER_DEFAULT, (TIME_FORCE24HOURFORMAT OR TIME_NOTIMEMARKER), ADDR _st, NULL, ADDR tbuffer, SIZEOF tbuffer
    INVOKE lstrlen, ADDR tbuffer 
    inc eax
    mov tlen, eax
    INVOKE lstrcpyn, pszTime24, ADDR tbuffer, tlen
    ret
DateTimeToTimeString24 ENDP 
;---------------------------------------
END