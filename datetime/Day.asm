.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
Day PROC pdt:PTR DATETIME

    LOCAL _st:SYSTEMTIME
    
    INVOKE FileTimeToSystemTime, pdt, ADDR _st
    .IF eax == 0
        mov eax, -1
    .ELSE
        movzx eax, _st.wDay        
    .ENDIF        
    ret
Day ENDP
;---------------------------------------
END