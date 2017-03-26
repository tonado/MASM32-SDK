.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE

;---------------------------------------
GetUtcDateTime PROC pdt:PTR DATETIME 

    LOCAL _st:SYSTEMTIME
    LOCAL ft:FILETIME

    INVOKE GetSystemTime, ADDR _st
    INVOKE SystemTimeToFileTime, ADDR _st, ADDR ft

    mov eax, pdt
    mov edx, DWORD PTR [ft+0]
    mov DWORD PTR [eax+0], edx
    mov edx, DWORD PTR [ft+4]
    mov DWORD ptr [eax+4], edx
    
    xor eax, eax
    ret

GetUtcDateTime ENDP
;---------------------------------------

END