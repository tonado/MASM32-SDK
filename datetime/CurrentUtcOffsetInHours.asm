.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.DATA

    IFNDEF sixty
        sixty REAL8 60.0
    ENDIF  

.CODE
;---------------------------------------
CurrentUtcOffsetInHours PROC pdblOffset:PTR REAL8    
    ; Returns eax = -1 on error, 0 otherwise
    ; Example: dblOffset = -8.0 for Pacific Standard Time
    ;          dblOffset = -7.0 for Pacific Daylight Time   
       
    LOCAL sdwOffset:SDWORD
    LOCAL sdwRv:SDWORD
    
    INVOKE CurrentUtcOffsetInMinutes, ADDR sdwOffset
    .IF eax == 0
        mov eax, pdblOffset
        finit
        fild sdwOffset
        fld  sixty
        fdiv
        fstp REAL8 PTR [eax]
        mov sdwRv, 0
    .ELSE ; dwTimeZoneMode == TIME_ZONE_ID_INVALID 
        mov sdwRv, -1
    .ENDIF       
    
    mov eax, sdwRv
    ret
    
CurrentUtcOffsetInHours ENDP 
;---------------------------------------
END