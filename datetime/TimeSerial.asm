.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\DateTime.inc
INCLUDE \masm32\macros\macros.asm

.CODE

TimeSerial PROC lHours:SDWORD, lMinutes:SDWORD, lSeconds:SDWORD, pdt:PTR DATETIME
    mov eax, pdt
    mov DWORD PTR [eax+0], 0
    mov DWORD PTR [eax+4], 0
    INVOKE DateAdd, SADD("h"), ADDR lHours, pdt, pdt
    INVOKE DateAdd, SADD("m"), ADDR lMinutes, pdt, pdt
    INVOKE DateAdd, SADD("s"), ADDR lSeconds, pdt, pdt
    ret
TimeSerial ENDP

END
