.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\include\DateTime.inc
INCLUDE \masm32\macros\macros.asm

ZeroMemory EQU <RtlZeroMemory>

.CODE
;---------------------------------------
YMDHMSToDateTime PROC dwYear:DWORD, dwMonth:DWORD, dwDay:DWORD, dwHour:DWORD, dwMinute:DWORD, dwSecond:DWORD, pdt:PTR DATETIME

    LOCAL _st:SYSTEMTIME
    
    INVOKE ZeroMemory, ADDR _st, SIZEOF _st
    mov eax, dwYear
    mov _st.wYear, ax
    mov eax, dwMonth
    mov _st.wMonth, ax
    mov eax, dwDay
    mov _st.wDay, ax
    mov eax, dwHour
    mov _st.wHour, ax
    mov eax, dwMinute
    mov _st.wMinute, ax
    mov eax, dwSecond
    mov _st.wSecond, ax
    INVOKE SystemTimeToFileTime, ADDR _st, pdt
    .IF eax == 0
        mov eax, -1
    .ELSE
        xor eax, eax    
    .ENDIF
    ret
YMDHMSToDateTime ENDP
;---------------------------------------
END