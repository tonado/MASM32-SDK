.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE DateTime.inc

.CONST
        
    ALIGN 8
    qwDaysAsFileTime      QWORD 864000000000
    qwHoursAsFileTime     QWORD  36000000000
    qwMinutesAsFileTime   QWORD    600000000
    qwSecondsAsFileTime   QWORD     10000000
 
.CODE

DateAdd PROC pszInterval:PTR BYTE, plNumber:PTR SDWORD, pdt1:PTR DATETIME, pdt2:PTR DATETIME

    ; Parameters:
    ;  pszInterval = pointer to BYTE, "d" = days, "h" = hours, "m" = minutes, "s" = seconds
    ;  plNumber    = pointer to SDWORD, number of intervals to add, negative OK
    ;  pdt1        = pointer to DATETIME to add to
    ;  pdt2        = pointer to DATETIME for result
    ;
    ; Returns eax  = 0 if no error, 1 if invalid interval  
    ; 
                   
    mov eax, pszInterval
    mov ecx, pdt1
    mov edx, pdt2
    
    finit
    .IF BYTE PTR [eax] == "d"
        fild qwDaysAsFileTime
    .ELSEIF BYTE PTR [eax] == "h"
        fild qwHoursAsFileTime
    .ELSEIF BYTE PTR [eax] == "m"
        fild qwMinutesAsFileTime
    .ELSEIF BYTE PTR [eax] == "s"
        fild qwSecondsAsFileTime
    .ELSE
        fldz
        fistp QWORD PTR [edx]
        fwait
        mov eax, 1
        jmp @F
    .ENDIF    
    
    mov eax, plNumber
    fild SDWORD  PTR [eax]
    fmul
             
    fild QWORD PTR [ecx]     
    fadd
        
    fistp QWORD PTR [edx]
    fwait
             
    xor eax, eax
             
  @@:
    ret   
    
DateAdd ENDP 

END