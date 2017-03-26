.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc

.CODE
;---------------------------------------
CurrentUtcOffsetInMinutes PROC psdwOffset:PTR SDWORD   
    ; Returns eax = -1 on error, 0 otherwise
    ; Example: sdwOffset = -480 for Pacific Standard Time
    ;          sdwOffset = -420 for Pacific Daylight Time 
   
    LOCAL tzi:TIME_ZONE_INFORMATION
    LOCAL dwTimeZoneMode:DWORD
    LOCAL sdwRv:SDWORD
               
    INVOKE GetTimeZoneInformation, ADDR tzi               
    mov dwTimeZoneMode, eax

    mov eax, tzi.Bias
    .IF (dwTimeZoneMode == TIME_ZONE_ID_STANDARD) || (dwTimeZoneMode == TIME_ZONE_ID_UNKNOWN)
        add eax, tzi.StandardBias
        mov edx, psdwOffset
        mov SDWORD PTR [edx], eax
        neg SDWORD PTR [edx]
        mov sdwRv, 0
    .ELSEIF dwTimeZoneMode == TIME_ZONE_ID_DAYLIGHT
        add eax, tzi.DaylightBias
        mov edx, psdwOffset
        mov SDWORD PTR [edx], eax
        neg SDWORD PTR [edx]
        mov sdwRv, 0
    .ELSE ; dwTimeZoneMode == TIME_ZONE_ID_INVALID
        mov sdwRv, -1
    .ENDIF       
   
    mov eax, sdwRv
    ret
   
CurrentUtcOffsetInMinutes ENDP
;---------------------------------------
END
