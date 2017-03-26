.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\macros\macros.asm
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DayOfYear PROC pdt:PTR DATETIME

    LOCAL dwYear:DWORD
    LOCAL dtTemp:DATETIME
    LOCAL sdwRv:SDWORD
    
    INVOKE Year, pdt
    mov dwYear, eax
    .IF dwYear == -1
        mov eax, -1
    .ELSE    
        dec dwYear
        INVOKE YMDHMSToDateTime, dwYear, 12, 31, 0, 0, 0, ADDR dtTemp
        INVOKE DateDiff, SADD("d"), ADDR dtTemp, pdt, ADDR sdwRv
        mov eax, sdwRv
    .ENDIF   
    
  @@:   
    ret
DayOfYear ENDP    
;---------------------------------------
END