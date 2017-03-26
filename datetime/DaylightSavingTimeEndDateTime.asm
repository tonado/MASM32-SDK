.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DaylightSavingTimeEndDateTime PROC dwYear:DWORD, pdt:PTR DATETIME

    LOCAL tzi:TIME_ZONE_INFORMATION
    
    INVOKE GetTimeZoneInformation, ADDR tzi
    .IF eax > 2
        mov eax, -1
    .ELSE    
        mov eax, dwYear
        mov tzi.StandardDate.wYear, ax
        INVOKE TziDateToDateTime, ADDR tzi.StandardDate, pdt
        .IF eax != 0
            mov eax, -1
        .ELSE    
            xor eax, eax
        .ENDIF    
    .ENDIF
    ret   
DaylightSavingTimeEndDateTime ENDP
;---------------------------------------
END