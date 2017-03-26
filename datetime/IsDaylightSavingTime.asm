.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE

;---------------------------------------
IsDaylightSavingTime PROC pdt:PTR DATETIME, pdwIsDST:PTR DWORD

    ; Returns eax = -1 on error, 0 otherwise
    ; The result is in the DWORD pointed to by pdwIsDST
    
    ALIGN 8
    LOCAL dtStart:DATETIME
    LOCAL dtEnd:DATETIME
    LOCAL dtTemp:DATETIME
    LOCAL dwYear:DWORD
    LOCAL lCmp1:SDWORD
    LOCAL lCmp2:SDWORD
                        
    INVOKE Year, pdt
    mov dwYear, eax
    .IF dwYear == 0
        mov eax, -1
    .ELSE    
        INVOKE DaylightSavingTimeStartDateTime, dwYear, ADDR dtStart
        INVOKE DaylightSavingTimeEndDateTime, dwYear, ADDR dtEnd
        INVOKE CopyDateTime, pdt, ADDR dtTemp
        INVOKE CompareDateTime, ADDR dtTemp, ADDR dtStart
        mov lCmp1, eax
        INVOKE CompareDateTime, ADDR dtTemp, ADDR dtEnd
        mov lCmp2, eax
        .IF ((SDWORD PTR lCmp1 == 1) || (SDWORD PTR lCmp1 ==  0)) && (SDWORD PTR lCmp2 == -1)
            mov eax, pdwIsDST
            mov DWORD PTR [eax], TRUE
        .ELSE
            mov eax, pdwIsDST
            mov DWORD PTR [eax], FALSE
        .ENDIF    
        xor eax, eax    
    .ENDIF    
    ret
IsDaylightSavingTime ENDP    
;---------------------------------------
END