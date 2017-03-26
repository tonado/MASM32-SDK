.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CONST

        szSun BYTE "Sunday", 0
        szMon BYTE "Monday", 0
        szTue BYTE "Tuesday", 0
        szWed BYTE "Wednesday", 0
        szThu BYTE "Thursday", 0
        szFri BYTE "Friday", 0
        szSat BYTE "Saturday", 0
        
        pszWeekDay PBYTE szSun, szMon, szTue, szWed, szThu, szFri, szSat

.CODE
;---------------------------------------
DayOfWeekName PROC pdt:PTR DATETIME, pszDayOfWeek:PTR BYTE

    ; receiving buffer must be at least 10 characters.

    LOCAL _st:SYSTEMTIME
    LOCAL pszName:PTR BYTE
    LOCAL len:DWORD

    INVOKE FileTimeToSystemTime, pdt, ADDR _st
    .IF eax == 0
        xor eax, eax
    .ELSE    
        movzx eax, _st.wDayOfWeek
        mov edx, pszWeekDay[eax*4] 
        mov pszName, edx
        INVOKE lstrlen, pszName
        inc eax
        mov len, eax
        INVOKE lstrcpyn, pszDayOfWeek, pszName, len
    .ENDIF
    ret
DayOfWeekName ENDP
;---------------------------------------
END
