.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc

Modulus MACRO v1:req, v2:req
    mov eax, v1 
    mov ecx, v2 
    xor edx,edx 
    div ecx 
    EXITM <edx> 
ENDM

.CODE

;---------------------------------------
IsLeapYear PROC dwYear:DWORD
; ***************************************************************************
; C code: return( (year % 400 == 0) || ( (year % 100) && (year % 4 == 0) ) );
; ***************************************************************************
        LOCAL c1:DWORD
        LOCAL c2:DWORD
        LOCAL c3:DWORD
   
         mov eax, Modulus(dwYear, 400)
         mov c1, eax
         mov eax, Modulus(dwYear, 100)
         mov c2, eax
         mov eax, Modulus(dwYear, 4)
         mov c3, eax
        .IF (c1 == 0) || ( (c2 != 0) && (c3 == 0) )    
            mov eax, 1
        .ELSE
            xor eax, eax
        .ENDIF
        ret
IsLeapYear ENDP
;---------------------------------------
END

