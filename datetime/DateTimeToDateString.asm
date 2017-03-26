.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToDateString PROC pdt:PTR DATETIME, pszDate:PTR BYTE

    LOCAL dlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL dbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetDateFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, ADDR _st, NULL, ADDR dbuffer, SIZEOF dbuffer
    INVOKE lstrlen, ADDR dbuffer 
    inc eax
    mov dlen, eax
    INVOKE lstrcpyn, pszDate, ADDR dbuffer, dlen
    ret
DateTimeToDateString ENDP 
;---------------------------------------
END