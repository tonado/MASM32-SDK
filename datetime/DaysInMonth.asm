.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE DateTime.inc

.DATA

    dwDaysInMonth DWORD 00,31,28,31,30,31,30,31,31,30,31,30,31

.CODE
;---------------------------------------
DaysInMonth PROC pdt:PTR DATETIME

    LOCAL dwYear:DWORD
    LOCAL dwIsLeapYear:DWORD
    
    INVOKE Year, pdt
    mov dwYear, eax
    .IF dwYear == -1
        mov eax, -1
    .ELSE
        INVOKE IsLeapYear, dwYear 
        .IF eax != FALSE
            mov dwDaysInMonth[2*4], 29
        .ENDIF    
        INVOKE Month, pdt
        mov eax, dwDaysInMonth[eax*DWORD]
    .ENDIF    
    ret
DaysInMonth ENDP

END