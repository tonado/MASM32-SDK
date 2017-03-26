.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToTimeString PROC pdt:PTR DATETIME, pszTime:PTR BYTE

    LOCAL tlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL tbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, ADDR _st, NULL, ADDR tbuffer, SIZEOF tbuffer
    INVOKE lstrlen, ADDR tbuffer 
    inc eax
    mov tlen, eax
    INVOKE lstrcpyn, pszTime, ADDR tbuffer, tlen
    ret
DateTimeToTimeString ENDP 
;---------------------------------------
END