.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE DateTime.inc

NULL EQU 0

.CODE
;---------------------------------------
CopyDateTime PROC USES esi edi pdtSource:PTR DATETIME, pdtDest:PTR DATETIME
    .IF (pdtSource == NULL) || (pdtDest == NULL)
        mov eax, -1
        jmp @F
    .ENDIF    
    mov esi, pdtSource
    mov edi, pdtDest
    mov eax, DWORD PTR [esi+0]
    mov edx, DWORD PTR [esi+4]
    mov DWORD PTR [edi+0], eax
    mov DWORD PTR [edi+4], edx
    xor eax, eax
  @@:  
    ret
CopyDateTime ENDP
;---------------------------------------
END