.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\include\oleaut32.inc
INCLUDE DateTime.inc

ZeroMemory EQU <RtlZeroMemory>

.CODE
;---------------------------------------
StringToDateTime PROC pszDateTimeString:PTR BYTE, pdt:PTR DATETIME

    ; Returns: 0 = success, -1 = error

    LOCAL dblVarDate:REAL8
    LOCAL dwLen:DWORD
    LOCAL dwUniLen:DWORD
    LOCAL szwUnicodeBuffer[64]:WORD
    LOCAL stime:SYSTEMTIME
    
    INVOKE ZeroMemory, ADDR szwUnicodeBuffer, SIZEOF szwUnicodeBuffer ; This is required
    
    INVOKE lstrlen, pszDateTimeString
    mov dwLen, eax
    .IF eax < 8 ; string is too short
        mov eax, -1
        jmp @F
    .ENDIF
    
    mov eax, SIZEOF szwUnicodeBuffer
    shr eax, 1  ; divide by 2
    mov dwUniLen, eax
            
    INVOKE MultiByteToWideChar, CP_ACP,\
                                NULL,\
                                pszDateTimeString,\
                                dwLen,\
                                ADDR szwUnicodeBuffer,\
                                dwUniLen
                                
    .IF eax == 0
        mov eax, -1
        jmp @F
    .ENDIF                                
                          
    INVOKE VarDateFromStr, ADDR szwUnicodeBuffer,\
                           LOCALE_USER_DEFAULT,\
                           0,\
                           ADDR dblVarDate
           
    .IF eax != S_OK
        mov eax, -1
        jmp @F
    .ENDIF
        
    INVOKE VariantTimeToSystemTime, dblVarDate, ADDR stime
    INVOKE SystemTimeToFileTime, ADDR stime, pdt
        
    xor eax, eax
    
  @@:
  
    ret
    
StringToDateTime ENDP    
;---------------------------------------
END