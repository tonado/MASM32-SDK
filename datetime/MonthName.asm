.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.DATA

    IFNDEF pszMonth
        szPad BYTE 0
        szJan BYTE "January", 0
        szFeb BYTE "February", 0
        szMar BYTE "March", 0
        szApr BYTE "April", 0
        szMay BYTE "May", 0
        szJun BYTE "June", 0
        szJul BYTE "July", 0
        szAug BYTE "August", 0
        szSep BYTE "September", 0
        szOct BYTE "October", 0
        szNov BYTE "November", 0
        szDec BYTE "December", 0
        pszMonth PBYTE szPad, szJan, szFeb, szMar, szApr, szMay, szJun, szJul, szAug, szSep, szOct, szNov, szDec
    ENDIF        

.CODE
;---------------------------------------
MonthName PROC pdt:PTR DATETIME, pszMonthName:PTR BYTE

    ; receiving buffer must be at least 10 characters.

    LOCAL _st:SYSTEMTIME
    LOCAL pszName:PTR BYTE
    LOCAL len:DWORD

    INVOKE FileTimeToSystemTime, pdt, ADDR _st
    .IF eax == 0
       xor eax, eax
    .ELSE   
        movzx eax, _st.wMonth
        mov edx, pszMonth[eax*DWORD] 
        mov pszName, edx
        INVOKE lstrlen, pszName
        inc eax
        mov len, eax
        INVOKE lstrcpyn, pszMonthName, pszName, len
    .ENDIF    
    ret
MonthName ENDP
;---------------------------------------
END
