;-------------------------------------------------------------------------------
;  BitmapFromFile.asm
;
;  Image file loading routines for the MASM32 library
;
;  This source and assosciated binary code is 
;  Copyright © 2001 by M Stoller Enterprises
;
;  Written by Ernest Murphy
;
;  Not for commercial reproduction. No fee whatsoever may be imposed for 
;  transfering this file. Source files may be coppied only for educational use
;  on a free basis.
;
;  Binary object files may be included in any work be it private, public or
;  a commercial application without payment necessary, however, it would be
;  appreciated to add a note to the effect "certain routines used in this program
;  were produced by Ernest Murphy" in the program documentation. Burried deep in 
;  the help file is just fine.
;
;  There is no 'LZW' code contained in these routines.
;
;  Corrections have been made to this module by
;  f0dder, El_Choni, lamer, KetilO, QvasiModo and Vortex.
;
;-------------------------------------------------------------------------------
.486
.model flat,stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
include \masm32\include\gdi32.inc
include \masm32\include\comctl32.inc
include \masm32\include\ole32.inc
include \masm32\include\oleaut32.inc

.data
BitmapFromPicture	PROTO   :DWORD

sIID_IPicture       TEXTEQU <{07BF80980H, 0BF32H, 0101AH,   \
                             {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
                             
IID_IPicture        GUID    sIID_IPicture

IPicture STRUCT
    ; IUnknown methods
    QueryInterface          DWORD   ?
    AddRef                  DWORD   ?
    Release                 DWORD   ?
    ; IPicture methods
    get_Handle              DWORD   ?
    get_hPal                DWORD   ?
    get_Type                DWORD   ?
    get_Width               DWORD   ?
    get_Height              DWORD   ?
    Render                  DWORD   ?	
    set_hPal                DWORD   ?
    get_CurDC               DWORD   ?
    SelectPicture           DWORD   ?
    get_KeepOriginalFormat  DWORD   ?
    put_KeepOriginalFormat  DWORD   ?
    PictureChanged          DWORD   ?
    SaveAsFile              DWORD   ?
    get_Attributes          DWORD   ?
IPicture ENDS

.code
;-------------------------------------------------------------------------------
BitmapFromFile PROC public pszFileName:DWORD
    LOCAL pwszFileName:DWORD, dwLength:DWORD, pPicture:DWORD, hNewBmp:DWORD

   ;invoke CoInitialize, NULL
    mov pPicture, NULL    ; NULL pointer for later use

    ; first, we need the filename in Unicode
    invoke lstrlen, pszFileName
    mov dwLength, eax
    inc dwLength
    rol eax, 1      ; double eax
    add eax, 2      ; allow for trailing zero
    invoke CoTaskMemAlloc, eax
    .IF !eax
        ; we didn't get the memory
        invoke SetLastError, ERROR_NOT_ENOUGH_MEMORY
        xor eax,eax
        ret
    .ENDIF
    mov pwszFileName, eax

    invoke MultiByteToWideChar, CP_ACP, 0, pszFileName, -1, pwszFileName, dwLength
    ; now we can create out picture object
    invoke OleLoadPicturePath, pwszFileName, NULL, NULL, NULL, ADDR IID_IPicture, ADDR pPicture
    .IF  eax > 80000000H  ; hresult failed
        ; we didn't get the file to open, assume bad filename
        invoke CoTaskMemFree,pwszFileName
        invoke SetLastError, ERROR_FILE_NOT_FOUND
        xor eax,eax
        ret
    .ENDIF

    ; now we are ready to get the hBipmap, we farm this out for reuseability
    invoke BitmapFromPicture, pPicture
    mov hNewBmp, eax
    ;invoke CoUninitialize           ; all done with COM

    mov eax, pPicture
    push eax
    mov eax, [eax]
    call [eax].IPicture.Release   

    invoke CoTaskMemFree,pwszFileName

    mov eax, hNewBmp    ; hBitmap is our return value, stuff it

    ret                 ; we're all done

BitmapFromFile ENDP                

END