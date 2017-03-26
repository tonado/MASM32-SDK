.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\macros\macros.asm
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToStringShort24 PROC pdt:PTR DATETIME, pszShort24:PTR BYTE

    LOCAL dlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL dbuffer[64]:BYTE
    LOCAL tbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetDateFormat, LOCALE_USER_DEFAULT, DATE_SHORTDATE, ADDR _st, NULL, ADDR dbuffer, SIZEOF dbuffer
    INVOKE GetTimeFormat, LOCALE_USER_DEFAULT, (TIME_FORCE24HOURFORMAT OR TIME_NOTIMEMARKER), ADDR _st, NULL, ADDR tbuffer, SIZEOF tbuffer
    INVOKE lstrcat, ADDR dbuffer, SADD("  ")
    INVOKE lstrcat, ADDR dbuffer, ADDR tbuffer
    INVOKE lstrlen, ADDR dbuffer 
    inc eax
    mov dlen, eax
    INVOKE lstrcpyn, pszShort24, ADDR dbuffer, dlen
    ret
DateTimeToStringShort24 ENDP 
;---------------------------------------
END