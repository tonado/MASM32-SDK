.586
.MODEL FLAT,STDCALL
OPTION CASEMAP:NONE

INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
INCLUDE \masm32\include\user32.inc
INCLUDE \masm32\include\advapi32.inc
INCLUDE \masm32\include\msvcrt.inc
INCLUDE \masm32\include\masm32.inc
INCLUDE \masm32\include\DateTime.inc

INCLUDE \masm32\macros\macros.asm

INCLUDELIB \masm32\lib\kernel32.lib
INCLUDELIB \masm32\lib\user32.lib
INCLUDELIB \masm32\lib\advapi32.lib
INCLUDELIB \masm32\lib\msvcrt.lib
INCLUDELIB \masm32\lib\masm32.lib
INCLUDELIB \masm32\lib\DateTime.lib

TzInit PROTO

DEBUG       EQU FALSE

GREATER     EQU 1
EQUAL       EQU 0
LESS        EQU -1

ofszKey     EQU   0
ofszDisplay EQU  64
ofszStd     EQU 144
ofszDlt     EQU 208
ofszMapID   EQU 272
ofdwIndex   EQU 288
ofbTZI      EQU 292

cbszKey     EQU 64          
cbszDisplay EQU 80
cbszStd     EQU 64
cbszDlt     EQU 64
cbszMapID   EQU 16
cbdwIndex   EQU 4
cbbTZI      EQU SIZEOF TZI

TZI  STRUCT
     Bias         SDWORD      ?
     StandardBias SDWORD      ?
     DaylightBias SDWORD      ?
     StandardDate SYSTEMTIME <?>
     DaylightDate SYSTEMTIME <?>
TZI ENDS

REGTZI STRUCT
     szKey      BYTE 64 DUP(?)
     szDisplay  BYTE 80 DUP(?)
     szStd      BYTE 64 DUP(?)
     szDlt      BYTE 64 DUP(?)
     szMapID    BYTE 16 DUP(?)
     dwIndex    DWORD ?
     bTZI       TZI  <?>
REGTZI ENDS 

.DATA

    ;Globals
    dwNumSubKeys    DWORD 0
    hHeap           DWORD 0

.CODE
start:

    call main
    inkey SADD("Press any key to exit ... ")
    INVOKE ExitProcess, eax
    
main PROC 

    LOCAL dwThreadID:DWORD
    LOCAL dwIndex:DWORD
    LOCAL dwIsDSTObserved:DWORD
    LOCAL dwIsDSTNow:DWORD
    LOCAL lBias:SDWORD
    LOCAL lStandardBias:SDWORD
    LOCAL lDaylightBias:SDWORD
    LOCAL lTotalBias:SDWORD    
    LOCAL lCompareLocalDaylight:SDWORD
    LOCAL lCompareLocalStandard:SDWORD 
    LOCAL lCompareDaylightStandard:SDWORD     
    LOCAL pTzArray:PTR REGTZI
    LOCAL pTZI:PTR TZI
    LOCAL pszKey:PTR BYTE
    LOCAL pszDisplay:PTR BYTE
    LOCAL pszStd:PTR BYTE
    LOCAL pszDlt:PTR BYTE
    LOCAL pszMapID:PTR BYTE
    LOCAL hThread:HANDLE    
    LOCAL stUtc:SYSTEMTIME
    LOCAL stStandardDate:SYSTEMTIME
    LOCAL stDaylightDate:SYSTEMTIME  
    LOCAL dtStandardDate:DATETIME
    LOCAL dtDaylightDate:DATETIME
    LOCAL dtUtc:DATETIME
    LOCAL dtLocalStandard:DATETIME
    LOCAL dtLocal:DATETIME    
    LOCAL szBuffer[256]:BYTE    
    LOCAL szLocalDateTime[128]:BYTE

    IF DEBUG
        INVOKE lstrcpy, ADDR szBuffer, SADD(13,10,"Loading timezone information from the registry in a separate thread ...",13,10)
        INVOKE StdOut, ADDR szBuffer
    ENDIF
    
    INVOKE CreateThread, NULL, 0, ADDR TzInit, NULL, 0, ADDR dwThreadID
    .IF eax == 0
        mov eax, -1
        jmp done 
    .ELSE
        mov hThread, eax
    .ENDIF

    IF DEBUG
        INVOKE lstrcpy, ADDR szBuffer, SADD(13,10,"Back to main thread ...",13,10)
        INVOKE StdOut, ADDR szBuffer
    ENDIF     
   
    INVOKE WaitForSingleObject, hThread, INFINITE

    INVOKE GetExitCodeThread, hThread, ADDR pTzArray

    INVOKE CloseHandle, hThread
           
    .IF pTzArray == NULL
        INVOKE lstrcpy, ADDR szBuffer, SADD(13,10,"Error loading timezone information!",13,10,13,10)
        INVOKE StdOut, ADDR szBuffer
        mov eax, -1
    .ELSE
        IF DEBUG
            INVOKE lstrcpy, ADDR szBuffer, SADD(13,10,"Timezone information loaded successfully",13,10,13,10)
            INVOKE StdOut, ADDR szBuffer
            INVOKE wsprintf, ADDR szBuffer, SADD("Number of timezones = %u",13,10), dwNumSubKeys
            INVOKE StdOut, ADDR szBuffer
            INVOKE lstrcpy, ADDR szBuffer, SADD(13,10)
            INVOKE StdOut, ADDR szBuffer
        ENDIF    
        
        INVOKE GetSystemTime, ADDR stUtc
        INVOKE SystemTimeToFileTime, ADDR stUtc, ADDR dtUtc
              
        mov ecx, 0  ; counter
        
        .REPEAT
            mov eax, SIZEOF REGTZI
            mul ecx 
            mov edx, pTzArray
            add edx, eax
            mov pszKey, edx 
            add edx, SIZEOF REGTZI.szKey
            mov pszDisplay, edx
            add edx, SIZEOF REGTZI.szDisplay
            mov pszStd, edx
            add edx, SIZEOF REGTZI.szStd
            mov pszDlt, edx
            add edx, SIZEOF REGTZI.szDlt
            mov pszMapID, edx
            add edx, SIZEOF REGTZI.szMapID
            mov eax, DWORD PTR [edx]
            mov dwIndex, eax
            add edx, SIZEOF REGTZI.dwIndex
            mov pTZI, edx
            mov eax, SDWORD PTR [edx]
            mov lBias, eax
            add edx, SIZEOF TZI.Bias
            mov eax, SDWORD PTR [edx]
            mov lStandardBias, eax
            add edx, SIZEOF TZI.StandardBias
            mov eax, SDWORD PTR [edx]
            mov lDaylightBias, eax
            add edx, SIZEOF TZI.DaylightBias
            
            push ecx
            
            push edx           
            INVOKE crt_memcpy, ADDR stStandardDate, edx, SIZEOF SYSTEMTIME
            pop edx
            
            add edx, SIZEOF TZI.StandardDate

            INVOKE crt_memcpy, ADDR stDaylightDate, edx, SIZEOF SYSTEMTIME
            
            ; We have the data - work with it
                       
            ; Get the local Standard Time for the Time Zone
            mov eax, lBias
            add eax, lStandardBias
            neg eax
            mov lTotalBias, eax
            INVOKE DateAdd, SADD("m"), ADDR lTotalBias, ADDR dtUtc, ADDR dtLocalStandard
         
            .IF (stStandardDate.wMonth == 0) && (stDaylightDate.wMonth == 0) 
                ; DST is not observed
                mov dwIsDSTObserved, FALSE
                mov dwIsDSTNow, FALSE
                INVOKE CopyDateTime, ADDR dtLocalStandard, ADDR dtLocal
            .ELSE  
                ; DST is observed
                mov dwIsDSTObserved, TRUE
                .IF stStandardDate.wYear == 0 
                    ; member wYear is zero - date is relative
                    mov ax, stUtc.wYear
                    mov stStandardDate.wYear, ax
                    INVOKE TziDateToDateTime, ADDR stStandardDate, ADDR dtStandardDate
                 .ELSE  
                    ; member wYear filled - date is absolute
                    INVOKE SystemTimeToFileTime, ADDR stStandardDate, ADDR dtStandardDate
                .ENDIF                
                .IF stDaylightDate.wYear == 0 
                    ; member wYear is zero - date is relative
                    mov ax, stUtc.wYear
                    mov stDaylightDate.wYear, ax                
                    INVOKE TziDateToDateTime, ADDR stDaylightDate, ADDR dtDaylightDate
                .ELSE  
                    ; member wYear filled - date is absolute
                    INVOKE SystemTimeToFileTime, ADDR stDaylightDate, ADDR dtDaylightDate
                .ENDIF
                
                ; Compare dtDaylight to dtStandardDate
                INVOKE CompareDateTime, ADDR dtDaylightDate, ADDR dtStandardDate
                mov lCompareDaylightStandard, eax                
                
                ; Compare dtLocalStandard to dtDaylightDate
                INVOKE CompareDateTime, ADDR dtLocalStandard, ADDR dtDaylightDate 
                mov lCompareLocalDaylight, eax
                
                ; Compare dtLocalStandard to dtStandardDate
                INVOKE CompareDateTime, ADDR dtLocalStandard, ADDR dtStandardDate 
                mov lCompareLocalStandard, eax
               
                .IF SDWORD PTR lCompareDaylightStandard == LESS  
                    ; dtDaylightDate < dtStandardDate = Northern Hemisphere                  
                    .IF ((SDWORD PTR lCompareLocalDaylight == GREATER) || (SDWORD PTR lCompareLocalDaylight == EQUAL)) && (SDWORD PTR lCompareLocalStandard == LESS)  
                        ; if( (dtLocalStandard >= dtDaylightDate) AND (dtLocalStandard < dtStandardDate) )
                        ; it's DST now                           
                        mov dwIsDSTNow, TRUE
                    .ELSE  ; it's not DST now
                        mov dwIsDSTNow, FALSE
                    .ENDIF
                .ELSEIF SDWORD PTR lCompareDaylightStandard == GREATER   
                    ; dtDaylightDate > dtStandardDate = Southern Hemisphere
                    .IF ((SDWORD PTR lCompareLocalStandard == GREATER) || (SDWORD PTR lCompareLocalStandard == EQUAL)) && (SDWORD PTR lCompareLocalDaylight == LESS)
                        ; if( (dtLocalStandard >= dtStandardDate) AND (dtLocalStandard < dtDaylightDate) )
                        ; it's not DST now
                        mov dwIsDSTNow, FALSE
                    .ELSE  ; it's DST now
                        mov dwIsDSTNow, TRUE
                    .ENDIF
                .ELSEIF SDWORD PTR lCompareDaylightStandard == EQUAL
                    ; lCompareDaylightStandard == 0 or lCompareDaylightStandard == -2
                    ; Error
                    INVOKE StdOut, SADD("Error: DaylightDate == StandardDate",13,10)
                    mov dwIsDSTNow, FALSE
                .ELSE
                    INVOKE StdOut, SADD("Error: calling CompareQwordsUnsigned()",13,10)
                    mov dwIsDSTNow, FALSE  
                .ENDIF
            .ENDIF
            
            .IF (dwIsDSTObserved == FALSE) || (dwIsDSTNow == FALSE)  
                ; it's not DST now or DST is not observed
                INVOKE CopyDateTime, ADDR dtLocalStandard, ADDR dtLocal
            .ELSE 
                ; it's DST now
                mov eax, lBias
                add eax, lDaylightBias
                neg eax 
                mov lTotalBias, eax
                INVOKE DateAdd, SADD("m"), ADDR lTotalBias, ADDR dtUtc, ADDR dtLocal 
            .ENDIF                                
                                        
            INVOKE StdOut, pszKey
            INVOKE StdOut, SADD(13,10)        
            INVOKE StdOut, pszDisplay
            INVOKE StdOut, SADD(13,10)
            .IF dwIsDSTObserved == FALSE
                INVOKE StdOut, SADD("DST is not observed",13,10)
            .ELSE  ; dwIsDSTObserved == TRUE    
                .IF dwIsDSTNow == FALSE
                    INVOKE StdOut, SADD("DST is not in effect",13,10)
                .ELSE  ; dwIsDSTNow == TRUE
                    INVOKE StdOut, SADD("DST is in effect",13,10)  
                .ENDIF
                IF DEBUG
                    INVOKE DateTimeToString, ADDR dtDaylightDate, ADDR szLocalDateTime
                    INVOKE StdOut, ADDR szLocalDateTime
                    INVOKE StdOut, SADD(13,10)
                    INVOKE DateTimeToString, ADDR dtStandardDate, ADDR szLocalDateTime
                    INVOKE StdOut, ADDR szLocalDateTime
                    INVOKE StdOut, SADD(13,10)                
                ENDIF                        
            .ENDIF   
            INVOKE DateTimeToString, ADDR dtLocal, ADDR szLocalDateTime
            INVOKE StdOut, ADDR szLocalDateTime
            INVOKE StdOut, SADD(13,10)
            INVOKE StdOut, SADD(13,10)
            
            pop ecx
            
            inc ecx
                   
        .UNTIL ecx >= dwNumSubKeys
        
        INVOKE HeapFree, hHeap, NULL, pTzArray
        mov eax, 0
    .ENDIF

  done:

    ret

main ENDP 
;-------------------------------------------------------------------------------------     
; -------------------------------------------------------------------------------------
; TzInit
; Reads Time Zone Information from Registry for all Time Zones 
;  into an array of REGTZI structures.
; Returns a pointer to the array of structures or 0 if failed. 
; Don't forget to call HeapFree() when done using it.    
; -------------------------------------------------------------------------------------

;TZI  STRUCT
;     Bias         SDWORD      ?
;     StandardBias SDWORD      ?
;     DaylightBias SDWORD      ?
;     StandardDate SYSTEMTIME <?>
;     DaylightDate SYSTEMTIME <?>
;TZI ENDS

;REGTZI STRUCT
;     szKey      BYTE 64 DUP(?)
;     szDisplay  BYTE 80 DUP(?)
;     szStd      BYTE 64 DUP(?)
;     szDlt      BYTE 64 DUP(?)
;     szMapID    BYTE 16 DUP(?)
;     dwIndex    DWORD ?       
;     bTZI       TZI  <?>      
;REGTZI ENDS 

TzInit PROC

    LOCAL szTziKey[56]:BYTE
    LOCAL szDisplay[8]:BYTE
    LOCAL szStd[4]:BYTE
    LOCAL szDlt[4]:BYTE
    LOCAL szMapID[6]:BYTE
    LOCAL szIndex[6]:BYTE
    LOCAL szTZI[4]:BYTE

    ALIGN 4
    LOCAL OS:OSVERSIONINFO

    ALIGN 4
    LOCAL pREGTZI:DWORD     ;PTR REGTZI

    LOCAL hKey1:DWORD
    LOCAL hKey2:DWORD
    LOCAL dwSize:DWORD
    LOCAL dwMemsize:DWORD
    LOCAL pLocTZI:DWORD     ;PTR REGTZI
    LOCAl pKey:DWORD        ;PTR VOID  
    
    LOCAL retv:SDWORD

    mov retv, 0
    
    mov OS.dwOSVersionInfoSize, SIZEOF OSVERSIONINFO

    INVOKE GetVersionEx, ADDR OS
        
    mov edx, OS.dwPlatformId
    .IF edx == VER_PLATFORM_WIN32_NT
        INVOKE lstrcpy, ADDR szTziKey, SADD("SOFTWARE\Microsoft\Windows NT\CurrentVersion\Time Zones") ; Windows NT, 2000 or XP
    .ELSE
        INVOKE lstrcpy, ADDR szTziKey, SADD("SOFTWARE\Microsoft\Windows\CurrentVersion\Time Zones")    ; Windows 9x or ME
    .ENDIF

    ; Open the registry key
    INVOKE RegOpenKeyEx, HKEY_LOCAL_MACHINE, ADDR szTziKey, NULL, KEY_READ, ADDR hKey1
    .IF eax
        mov retv, 0
        jmp done
    .ENDIF

    ; Get info for the registry key
    INVOKE RegQueryInfoKey, hKey1, NULL, NULL, NULL, ADDR dwNumSubKeys, NULL, NULL, NULL, NULL, NULL, NULL, NULL
    .IF eax
        INVOKE RegCloseKey, hKey1
        mov retv, 0
        jmp done
    .ENDIF

    mov eax, SIZEOF REGTZI
    mov ecx, dwNumSubKeys
    mul ecx
    mov dwMemsize, eax 

    INVOKE GetProcessHeap
    mov hHeap, eax
    INVOKE HeapAlloc, hHeap, HEAP_ZERO_MEMORY, dwMemsize
    mov pREGTZI, eax 

    ; Loop through all the keys for "Time Zones" and store in an array of structures
    mov ecx, 0

  @@:          
    cmp ecx, dwNumSubKeys
    jae @F

    push ecx
  
    mov eax, SIZEOF REGTZI  
    mul ecx
    add eax, pREGTZI
    mov pLocTZI, eax      ;pLocTZI = pREGTZI + (ecx * SIZEOF REGTZI)
    add eax, ofszKey
    mov pKey, eax

    push cbszKey 
    pop  dwSize

    pop ecx
    push ecx
    ;                    IN     IN       OUT      IN/OUT
    ;                    hKey,  dwIndex, lpName,  lpcName,     lpReserved, lpClass, lpcClass, lpftLastWriteTime   
    INVOKE RegEnumKeyEx, hKey1, ecx,     pKey,     ADDR dwSize, NULL,       NULL,    NULL,     NULL
    .IF eax == ERROR_SUCCESS
        pop ecx
        inc ecx
    .ELSEIF eax == ERROR_NO_MORE_ITEMS
        pop ecx
        mov ecx, dwNumSubKeys
    .ELSE
        INVOKE RegCloseKey, hKey1
        pop ecx
        mov retv, 0
        jmp done
    .ENDIF

    jmp @B

  @@: 

    mov ecx, 0    

  @@:          
    cmp ecx, dwNumSubKeys
    jae @F

    push ecx

    mov eax, SIZEOF REGTZI
    mul ecx
    add eax, pREGTZI
    mov pLocTZI, eax      ;pLocTZI = pREGTZI + (ecx * SIZEOF REGTZI)
    add eax, ofszKey
    mov pKey, eax

    ; Open the registry key
    INVOKE RegOpenKeyEx, hKey1, pKey, NULL, KEY_READ, ADDR hKey2
    .IF eax
        pop ecx
        mov retv, 0
        jmp done
    .ENDIF

    INVOKE lstrcpy, ADDR szDisplay, SADD("Display")

    push cbszDisplay
    pop  dwSize

    ; Get the "Display" string
    mov eax, pLocTZI
    add eax, ofszDisplay
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szDisplay, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        INVOKE RegCloseKey, hKey2
        INVOKE RegCloseKey, hKey1
        pop ecx
        mov retv, 0
        jmp done
    .ENDIF

    INVOKE lstrcpy, ADDR szStd, SADD("Std")

    push cbszStd
    pop  dwSize

    ; Get the "Std" (Standard) name
    mov eax, pLocTZI
    add eax, ofszStd
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szStd, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        .IF eax == 2  ; If a time zone key was created with Microsoft's TZEDIT.EXE it won't have this string value.
           mov eax, pLocTZI
           mov BYTE PTR [eax+ofszStd], 0
        .ELSE
            INVOKE RegCloseKey, hKey2
            INVOKE RegCloseKey, hKey1
            pop ecx
            mov retv, 0
            jmp done
        .ENDIF
    .ENDIF

    INVOKE lstrcpy, ADDR szDlt, SADD("Dlt")

    push cbszDlt
    pop  dwSize

    ; Get the "Dlt" (Daylight) name
    mov eax, pLocTZI
    add eax, ofszDlt
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szDlt, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        INVOKE RegCloseKey, hKey2
        INVOKE RegCloseKey, hKey1
        pop ecx
        mov retv, 0
        jmp done
    .ENDIF

    INVOKE lstrcpy, ADDR szMapID, SADD("MapID")

    push cbszMapID
    pop dwSize

    ; Get the "MapID"
    mov eax, pLocTZI
    add eax, ofszMapID
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szMapID, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        .IF eax == 2  ; This value does not exist in Vista.
                      ; If a time zone key was created with Microsoft's TZEDIT.EXE it won't have this string value.
           mov eax, pLocTZI
           mov BYTE PTR [eax+ofszMapID], 0
        .ELSE
            INVOKE RegCloseKey, hKey2
            INVOKE RegCloseKey, hKey1
            pop ecx
            mov retv, 0
            jmp done
        .ENDIF
    .ENDIF

    INVOKE lstrcpy, ADDR szIndex, SADD("Index")

    push cbdwIndex
    pop dwSize

    ; Get the "Index"
    mov eax, pLocTZI
    add eax, ofdwIndex
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szIndex, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        .IF eax == 2  ; This value does not exist in Vista. This value may not exist in Windows 9x, ME.
                      ; If a time zone key was created with Microsoft's TZEDIT.EXE it won't have this DWORD value. 
            mov eax, pLocTZI
            mov DWORD PTR [eax+ofdwIndex], 0
        .ELSE
            INVOKE RegCloseKey, hKey2
            INVOKE RegCloseKey, hKey1
            pop ecx
            mov retv, 0
            jmp done
        .ENDIF
    .ENDIF

    INVOKE lstrcpy, ADDR szTZI, SADD("TZI")

    push cbbTZI
    pop dwSize

    ; Get the TZI structure
    mov eax, pLocTZI
    add eax, ofbTZI
    mov pKey, eax
    INVOKE RegQueryValueEx, hKey2, ADDR szTZI, NULL, NULL, pKey, ADDR dwSize
    .IF eax
        INVOKE RegCloseKey, hKey2
        INVOKE RegCloseKey, hKey1
        pop ecx
        mov retv, 0
        jmp done
    .ENDIF

    INVOKE RegCloseKey, hKey2

    pop ecx
    inc ecx
    jmp @B

  @@:

    ; Close the registry
    INVOKE RegCloseKey, hKey1

    mov eax, pREGTZI
    mov retv, eax
    
  done:  

    mov eax, retv
    ret
    
TzInit ENDP

END start
       
