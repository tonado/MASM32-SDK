.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DayOfWeek PROC pdt:PTR DATETIME

    ; Return in eax
    ; Sunday = 0, Monday = 1, ... Saturday = 6
    
    LOCAL _st:SYSTEMTIME
    
    INVOKE FileTimeToSystemTime, pdt, ADDR _st
    .IF eax == 0
        xor eax, eax
    .ELSE    
        movzx eax, _st.wDayOfWeek
    .ENDIF    
    ret    
DayOfWeek ENDP
;---------------------------------------
END