.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\macros\macros.asm
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToTimeString12 PROC pdt:PTR DATETIME, pszTime12:PTR BYTE

    LOCAL tlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL tbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetTimeFormat, LOCALE_USER_DEFAULT, 0, ADDR _st, SADD("h:mm:ss tt"), ADDR tbuffer, SIZEOF tbuffer
    INVOKE lstrlen, ADDR tbuffer 
    inc eax
    mov tlen, eax
    INVOKE lstrcpyn, pszTime12, ADDR tbuffer, tlen
    ret
DateTimeToTimeString12 ENDP 
;---------------------------------------
END