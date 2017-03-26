.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc

.CODE
;---------------------------------------
CurrentTimeZoneName PROC pszTZName:PTR BYTE

    ; Returns eax = -1 on error, 0 otherwise
    
    LOCAL tzi:TIME_ZONE_INFORMATION
    LOCAL dwTimeZoneMode:DWORD
    LOCAL szTZ[128]:BYTE
    LOCAL len:DWORD
    LOCAL sdwRv:SDWORD
                    
    INVOKE GetTimeZoneInformation, ADDR tzi
    mov dwTimeZoneMode, eax

    .IF (dwTimeZoneMode == TIME_ZONE_ID_STANDARD) || (dwTimeZoneMode == TIME_ZONE_ID_UNKNOWN)
        ;      WideCharToMultiByte, CodePage, dwFlags, lpWideCharStr,
        INVOKE WideCharToMultiByte, CP_ACP, 0, ADDR tzi.StandardName, -1, ADDR szTZ, SIZEOF szTZ, NULL, NULL
        mov sdwRv, 0
    .ELSEIF dwTimeZoneMode == TIME_ZONE_ID_DAYLIGHT
        INVOKE WideCharToMultiByte, CP_ACP, 0, ADDR tzi.DaylightName, -1, ADDR szTZ, SIZEOF szTZ, NULL, NULL
        mov sdwRv, 0
    .ELSE ; dwTimeZoneMode == TIME_ZONE_ID_INVALID 
        mov BYTE PTR szTZ, 0
        mov sdwRv, -1
    .ENDIF 
 
    INVOKE lstrlen, ADDR szTZ
    inc eax
    mov len, eax
    INVOKE lstrcpyn, pszTZName, ADDR szTZ, len
    
  @@:    
    mov eax, sdwRv
    ret
CurrentTimeZoneName ENDP
;---------------------------------------
END