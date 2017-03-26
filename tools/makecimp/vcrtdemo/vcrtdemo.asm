
comment * ---------------------------------------------------------
        This example was written by Greg Lyon to demonstrate how to
        use some of the MSVCRT functions provided in the DLL.
        --------------------------------------------------------- *

    .486 
    .model flat, stdcall 
    option casemap :none
    
    include \masm32\include\windows.inc 
    include \masm32\include\kernel32.inc 
    includelib \masm32\lib\kernel32.lib
    
    include \masm32\macros\macros.asm
    
    include    \masm32\include\msvcrt.inc
    includelib \masm32\lib\msvcrt.lib
            
    main PROTO
    _difftime64 PROTO pTime1:PTR QWORD, pTime2:PTR QWORD, pDiff:PTR REAL8 
    WaitKeyCrt PROTO
       
    __timeb64 STRUCT 8
        time     QWORD   0
        millitm  WORD    0
        timezone SWORD   0
        dstflag  SWORD   0
    __timeb64 ENDS
    
    tm STRUCT 4
        tm_sec   SDWORD   0     ; seconds after the minute - [0,59]
        tm_min   SDWORD   0     ; minutes after the hour - [0,59]
        tm_hour  SDWORD   0     ; hours since midnight - [0,23]
        tm_mday  SDWORD   0     ; day of the month - [1,31]
        tm_mon   SDWORD   0     ; months since January - [0,11]
        tm_year  SDWORD   0     ; years since 1900
        tm_wday  SDWORD   0     ; days since Sunday - [0,6]
        tm_yday  SDWORD   0     ; days since January 1 - [0,365]
        tm_isdst SDWORD   0     ; daylight savings time flag
    tm ENDS
                                                   
.data 

    align 8
    time1     QWORD     0
    time2     QWORD     0
    diff      REAL8     0.0
    day       REAL8     86400.0  ; 60*60*24
    days      REAL8     0.0
    tstruct   __timeb64 <0>
    align 4
    hmodule   DWORD     0
    pxmas     DWORD     0
    ptzname   DWORD     0
    tmpbuf    BYTE      128 dup(0)
    ampm      BYTE      "AM", 0
    newline   BYTE      13, 10, 0
           
.code 

start:

    invoke main
    invoke WaitKeyCrt
    invoke crt__exit, 0

main  PROC uses edi

    invoke crt__tzset
    invoke crt_printf, SADD(13,10,"64-bit Date and Time Functions - C Run-time Library",13,10)
    invoke crt__strtime, OFFSET tmpbuf
    invoke crt_printf, SADD(" OS time:                            %s",13,10), OFFSET tmpbuf
    invoke crt__strdate, OFFSET tmpbuf 
    invoke crt_printf, SADD(" OS date:                            %s",13,10), OFFSET tmpbuf
    invoke crt__time64, OFFSET time1
    invoke crt_printf, SADD(" Time in seconds since UTC 1/1/1970: %I64u",13,10), OFFSET time1
    invoke crt__ctime64, OFFSET time1
    invoke crt_printf, SADD(" Time and date string:               %s"), eax
    invoke crt__gmtime64, OFFSET time1
    invoke crt_asctime, eax
    invoke crt_printf, SADD(" Coordinated universal time:         %s"), eax 
    invoke crt__localtime64, OFFSET time1
    mov edx, (tm PTR [eax]).tm_hour
    .if edx >= 12
        push eax
        push edx
        invoke crt_strcpy, OFFSET ampm, SADD("PM")
        pop edx
        pop eax
        sub edx, 12
        mov (tm PTR [eax]).tm_hour, edx
    .endif  
    mov edx, (tm PTR [eax]).tm_hour
    .if edx == 0 
        mov (tm PTR [eax]).tm_hour, 12
    .endif
    invoke crt_asctime, eax
    add eax, 11
    invoke crt_printf, SADD( " 12-hour time:                       %.8s %s",13,10), eax, OFFSET ampm
    invoke crt__ftime64, OFFSET tstruct
    movsx eax, tstruct.millitm  
    invoke crt_printf, SADD(" Plus milliseconds:                  %u",13,10), eax
    xor edx, edx
    movsx eax, tstruct.timezone
    mov ecx, 60
    div ecx
    invoke crt_printf, SADD(" Zone difference in hours from UTC:  %u",13,10), eax
    mov eax, crt__tzname
    .if tstruct.dstflag == 0
        mov edx, [eax+0]  
        mov ptzname, edx 
    .else
        mov edx, [eax+4]  
        mov ptzname, edx 
    .endif
    invoke crt_printf, SADD(" Time zone name:                     %s",13,10), ptzname
        invoke crt_printf, SADD( " Daylight savings:                   ")
    movsx eax, tstruct.dstflag
    .if eax == 0
        invoke crt_printf, SADD("False",13,10)
    .else
        invoke crt_printf, SADD("True",13,10)
    .endif 
    invoke crt__localtime64, OFFSET time1
    invoke crt_strftime, OFFSET tmpbuf, SIZEOF tmpbuf, SADD("%A, %B %d, %Y"), eax
    invoke crt_printf, SADD(" Today is:                           %s",13,10), OFFSET tmpbuf
    invoke crt__localtime64, OFFSET time1
    mov edx, 11                     ; December
    mov (tm PTR [eax]).tm_mon, edx
    mov edx, 25                     ; 25th
    mov (tm PTR [eax]).tm_mday, edx
    mov edx, 12                     ; 12:00 noon   
    mov (tm PTR [eax]).tm_hour, edx
    mov edx, 0
    mov (tm PTR [eax]).tm_min, edx
    mov edx, 0
    mov (tm PTR [eax]).tm_sec, edx
    mov edx, 0
    mov (tm PTR [eax]).tm_wday, edx
    mov edx, 0
    mov (tm PTR [eax]).tm_yday, edx
    mov edx, 0
    mov (tm PTR [eax]).tm_isdst, edx
    mov pxmas, eax
    invoke crt__mktime64, eax
    mov SDWORD PTR [time2+0], eax
    mov SDWORD PTR [time2+4], edx
    .if eax != -1 && edx != -1
        invoke crt_strftime, OFFSET tmpbuf, SIZEOF tmpbuf, SADD("%A, %B %d, %Y"), pxmas
        invoke crt_printf, SADD(" Christmas this year:                %s",13,10), OFFSET tmpbuf
   .endif
    invoke _difftime64, OFFSET time1, OFFSET time2, OFFSET diff
    finit
    fld diff
    fld day
    fdiv
    fstp days
    invoke crt_printf, SADD(" Days until Christmas:               %.0lf",13,10), days
    ret
main  ENDP 

_difftime64 PROC pTime1:PTR QWORD, pTime2:PTR QWORD, pDiff:PTR REAL8 
    ; MS Visual C Run-time Library does not have a _difftime64 function so... 
    mov     eax, pTime1
    mov     edx, pTime2
    finit                   ; initialize FPU
    ; compare Time1 with Time2
    fild    QWORD PTR [edx] ; st(0) = Time2
    fild    QWORD PTR [eax] ; st(0) = Time1, st(1) = Time2
    fcompp                  ; compare st(0) with st(1) and pop both registers
    fstsw   ax              ; retrieve comparison result in the AX register
    fwait                   ; insure the previous instruction is completed
    sahf                    ; transfer the condition codes to the CPU's flag register
    jb      st0_less        ; only the C0 bit (CF flag) would be set if no error
st0_greater:                ; Time1 > Time2
    ;Subtract Time2 from Time1 to calculate the number of seconds difference 
    mov     eax, pTime1
    mov     edx, pTime2
    fild    QWORD PTR [eax]
    fild    QWORD PTR [edx]
    fsub
    mov     eax, pDiff
    fstp    REAL8 PTR [eax]
    fwait
    jmp     @F
 st0_less:                  ; Time2 > Time1
    ;Subtract Time1 from Time2 to calculate the number of seconds difference
    mov     eax, pTime2
    mov     edx, pTime1
    fild    QWORD PTR [eax]
    fild    QWORD PTR [edx]
    fsub
    mov     eax, pDiff
    fstp    REAL8 PTR [eax] 
    fwait
@@:
    ret
_difftime64 ENDP

WaitKeyCrt PROC 
    invoke crt_printf, SADD(13,10,"Press any key to continue...")
    invoke crt__getch
    .if (eax == 0) || (eax == 0E0h)
        invoke crt__getch
    .endif
    invoke crt_printf, OFFSET newline    
    ret
WaitKeyCrt ENDP

END start 
