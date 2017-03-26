; Date Format
; Picture Meaning
; ------- -------
; d       Day of month as digits with no leading zero for single-digit days. 
; dd      Day of month as digits with leading zero for single-digit days. 
; ddd     Day of week as a three-letter abbreviation. The function uses the LOCALE_SABBREVDAYNAME value associated with the specified locale. 
; dddd    Day of week as its full name. The function uses the LOCALE_SDAYNAME value associated with the specified locale. 
; M       Month as digits with no leading zero for single-digit months. 
; MM      Month as digits with leading zero for single-digit months. 
; MMM     Month as a three-letter abbreviation. The function uses the LOCALE_SABBREVMONTHNAME value associated with the specified locale. 
; MMMM    Month as its full name. The function uses the LOCALE_SMONTHNAME value associated with the specified locale. 
; y       Year as last two digits, but with no leading zero for years less than 10. 
; yy      Year as last two digits, but with leading zero for years less than 10. 
; yyyy    Year represented by full four digits. 
; gg      Period/era string. The function uses the CAL_SERASTRING value associated with the specified locale. This element is ignored if the date to be formatted does not have an associated era or period string. 

; Time Format
; Picture Meaning 
; ------- -------
; h       Hours with no leading zero for single-digit hours; 12-hour clock. 
; hh      Hours with leading zero for single-digit hours; 12-hour clock. 
; H       Hours with no leading zero for single-digit hours; 24-hour clock. 
; HH      Hours with leading zero for single-digit hours; 24-hour clock. 
; m       Minutes with no leading zero for single-digit minutes. 
; mm      Minutes with leading zero for single-digit minutes. 
; s       Seconds with no leading zero for single-digit seconds. 
; ss      Seconds with leading zero for single-digit seconds. 
; t       One character time-marker string, such as A or P. 
; tt      Multicharacter time-marker string, such as AM or PM. 

.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\macros\macros.asm
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToStringFormat PROC pdt:PTR DATETIME, pszDateFormat:PTR BYTE, pszTimeFormat:PTR BYTE, pszFormatted:PTR BYTE

    LOCAL dlen:DWORD
    LOCAL _st:SYSTEMTIME
    LOCAL dbuffer[64]:BYTE
    LOCAL tbuffer[64]:BYTE

    INVOKE FileTimeToSystemTime, pdt, ADDR _st  
    INVOKE GetDateFormat, LOCALE_USER_DEFAULT, 0, ADDR _st, pszDateFormat, ADDR dbuffer, SIZEOF dbuffer
    INVOKE GetTimeFormat, LOCALE_USER_DEFAULT, 0, ADDR _st, pszTimeFormat, ADDR tbuffer, SIZEOF tbuffer
    INVOKE lstrcat, ADDR dbuffer, SADD("  ")
    INVOKE lstrcat, ADDR dbuffer, ADDR tbuffer
    INVOKE lstrlen, ADDR dbuffer 
    inc eax
    mov dlen, eax
    INVOKE lstrcpyn, pszFormatted, ADDR dbuffer, dlen
    ret
DateTimeToStringFormat ENDP 
;---------------------------------------
END