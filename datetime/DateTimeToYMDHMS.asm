.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE DateTime.inc

.CODE
;---------------------------------------
DateTimeToYMDHMS PROC pdt:PTR DATETIME, pdwYear:PTR DWORD, pdwMonth:PTR DWORD, pdwDay:PTR DWORD, pdwHour:PTR DWORD, pdwMinute:PTR DWORD, pdwSecond:PTR DWORD

    LOCAL _st:SYSTEMTIME

    INVOKE FileTimeToSystemTime, pdt, ADDR _st
    .IF eax != 0
        
        mov eax, pdwYear
        movzx edx, _st.wYear
        mov DWORD PTR [eax], edx 
        
        mov eax, pdwMonth
        movzx edx, _st.wMonth
        mov DWORD PTR [eax], edx
        
        mov eax, pdwDay
        movzx edx, _st.wDay
        mov DWORD PTR [eax], edx
        
        mov eax, pdwHour
        movzx edx, _st.wHour
        mov DWORD PTR [eax], edx
        
        mov eax, pdwMinute
        movzx edx, _st.wMinute
        mov DWORD PTR [eax], edx
        
        mov eax, pdwSecond
        movzx edx, _st.wSecond
        mov DWORD PTR [eax], edx
        
        xor eax, eax
    .ELSE
        mov eax, -1
    .ENDIF
    ret
DateTimeToYMDHMS ENDP
;---------------------------------------

END