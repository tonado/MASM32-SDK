.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\macros\macros.asm
INCLUDE DateTime.inc 

.CODE
;---------------------------------------
; This procedure converts a relative datetime (from a TZI registry key) in SYSTEMTIME format to a DATETIME
;---------------------------------------
TziDateToDateTime PROC USES esi edi pst:PTR SYSTEMTIME, pdt:PTR DATETIME

    ALIGN 8
    LOCAL dtTemp:DATETIME
    LOCAL dwYear:DWORD
    LOCAL dwMonth:DWORD
    LOCAL dwDay:DWORD
    LOCAL dwDayOfWeek:DWORD    
    LOCAL dwHour:DWORD
    LOCAL dwMinute:DWORD
    LOCAL dwSecond:DWORD
    LOCAL dwFirstDayOfWeek:DWORD
    LOCAL dwTziFirstDayOfWeek:DWORD
    LOCAL dwDaysInMonth:DWORD
    LOCAL sdwNumber:SDWORD
    
    ASSUME esi:PTR SYSTEMTIME
    mov esi, pst
    
    movzx eax, [esi].wYear
    mov dwYear, eax
    
    movzx eax, [esi].wMonth
    mov dwMonth, eax
    
    movzx eax, [esi].wDay
    mov dwDay, eax
    
    movzx eax, [esi].wDayOfWeek
    mov dwDayOfWeek, eax
    
    movzx eax, [esi].wHour
    mov dwHour, eax
    
    movzx eax, [esi].wMinute
    mov dwMinute, eax
    
    movzx eax, [esi].wSecond
    mov dwSecond, eax            
    
    ASSUME esi:NOTHING
    
    INVOKE YMDHMSToDateTime, dwYear, dwMonth, 1, dwHour, dwMinute, dwSecond, ADDR dtTemp
    .IF eax != 0
        mov eax, -1
    .ELSE
        INVOKE DayOfWeek, ADDR dtTemp
        mov dwFirstDayOfWeek, eax
        mov eax, dwDayOfWeek
        mov dwTziFirstDayOfWeek, eax
        .IF dwFirstDayOfWeek != eax
            mov eax, dwTziFirstDayOfWeek
            .IF dwFirstDayOfWeek < eax
                mov eax, dwTziFirstDayOfWeek
                sub eax, dwFirstDayOfWeek
                mov sdwNumber, eax
                INVOKE DateAdd, SADD("d"), ADDR sdwNumber, ADDR dtTemp, ADDR dtTemp   
            .ELSE
                mov eax, dwTziFirstDayOfWeek
                sub eax, dwFirstDayOfWeek
                add eax, 7
                mov sdwNumber, eax            
                INVOKE DateAdd, SADD("d"), ADDR sdwNumber, ADDR dtTemp, ADDR dtTemp
            .ENDIF
        .ENDIF
        .IF dwDay > 1
            mov eax, dwDay
            dec eax
            mov edx, 7
            mul edx
            mov sdwNumber, eax
            INVOKE DateAdd, SADD("d"), ADDR sdwNumber, ADDR dtTemp, ADDR dtTemp
        .ENDIF
        INVOKE CopyDateTime, ADDR dtTemp, pdt
        xor eax, eax
    .ENDIF    
    ret    
TziDateToDateTime ENDP

END
