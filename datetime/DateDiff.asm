.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE DateTime.inc 

;.CONST
;      
;    ALIGN 8                  
;    qwDaysAsFileTime         QWORD 864000000000
;    qwHoursAsFileTime        QWORD  36000000000
;    qwMinutesAsFileTime      QWORD    600000000
;    qwSecondsAsFileTime      QWORD     10000000
;    qwMillisecondsAsFileTime QWORD        10000
        
.CODE        
    
DateDiff PROC pszInterval:PTR BYTE, pdt1:PTR DATETIME, pdt2:PTR DATETIME, plNumber:PTR SDWORD 

    ; pszInterval  = pointer to BYTE, interval type, "d" = days, "h" = hours, "m" = minutes, "s" = seconds 
    ; pdt1        = pointer to a DATETIME
    ; pdt2        = pointer to a DATETIME
    ; plNumber    = pointer to SDWORD, number of intervals
    ;
    ; Returns eax = 0 if no error, -1 if invalid interval
    ;
            
    LOCAL qwDif:QWORD
   
    mov ecx, pdt1
    mov edx, pdt2
        
    finit                   ; initialize FPU
    
;    ; compare Date1 with Date2
;    
;    fild    QWORD PTR [edx] ; st(0) = Date2
;    fild    QWORD PTR [ecx] ; st(0) = Date1, st(1) = Date2
;    fcompp                  ; compare st(0) with st(1) and pop both registers
;    fstsw   ax              ; retrieve comparison result in the AX register
;    fwait                   ; insure the previous instruction is completed
;    sahf                    ; transfer the condition codes to the CPU's flag register
;    jb      st0_less        ; only the C0 bit (CF flag) would be set if no error
;         
;st0_greater:                ; Date1 > Date2
;
;    ;Subtract Date2 from Date1 to calculate the number of 100-nanosecond intervals elapsed 
;    fild    QWORD PTR [ecx] ; Date 1
;    fild    QWORD PTR [edx] ; Date 2
;    fsub
;    fistp   qwDif
;    fwait
;            
;    jmp     convert
;            
;st0_less:                  ; Date2 > Date1

    ;Subtract Date1 from Date2 to calculate the difference
    fild    QWORD PTR [edx] ; Date 2
    fild    QWORD PTR [ecx] ; Date 1
    fsub
    fistp   qwDif           ; difference in 100-nanosecond intervals
    fwait
           
convert: 

    mov eax, pszInterval
    mov edx, plNumber
    fild qwDif
    .IF BYTE PTR [eax] == "d"
        ; convert difference to days
        fild qwDaysAsFileTime
    .ELSEIF BYTE PTR [eax] == "h"
        ; convert difference to hours
        fild qwHoursAsFileTime
    .ELSEIF BYTE PTR [eax] == "m"
        ; convert difference to minutes
        fild qwMinutesAsFileTime
    .ELSEIF BYTE PTR [eax] == "s"
        ; convert difference to seconds
        fild qwSecondsAsFileTime
    .ELSE
        ffree st(0)
        fwait
        mov SDWORD PTR [edx], 0
        mov eax, -1
        jmp @F
    .ENDIF
    
    fdiv
    fistp SDWORD PTR [edx]
    fwait
     
    xor eax, eax
    
  @@:
    ret
    
DateDiff ENDP


END