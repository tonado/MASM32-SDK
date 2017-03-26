;-------------------------------------------------------------------------------
;  BitmapFromMemory.ASM
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

HIMETRIC_INCH       EQU     2540

.code
;-------------------------------------------------------------------------------
align 4

_MemCopy proc public uses esi edi Source:PTR BYTE,Dest:PTR BYTE,ln:DWORD

    ; ---------------------------------------------------------
    ; Copy ln bytes of memory from Source buffer to Dest buffer
    ;      ~~                      ~~~~~~           ~~~~
    ; USAGE:
    ; invoke _MemCopy,ADDR Source,ADDR Dest,4096
    ;
    ; NOTE: Dest buffer must be at least as large as the source
    ;       buffer otherwise a page fault will be generated.
    ; ---------------------------------------------------------

    cld
    mov esi, [Source]
    mov edi, [Dest]
    mov ecx, [ln]

    shr ecx, 2
    rep movsd

    mov ecx, [ln]
    and ecx, 3
    rep movsb

    ret

_MemCopy endp

BitmapFromMemory  PROC  pMemory:DWORD, dwFileSize:DWORD

    LOCAL hResource:DWORD,  pGlobal:DWORD,      pStream:DWORD
    LOCAL hImage:DWORD,     pPicture:DWORD,     hBitmap:DWORD

   ;invoke CoInitialize, NULL
    mov pStream, NULL
    mov pPicture, NULL    ; NULL pointers for later use
    invoke CoTaskMemAlloc, dwFileSize   ; copy picture into task memory
    .if !eax
        ; oops! we didn't get the memory
        ; the last error code was set for us, and EAX is zero, so just return
        ret
    .endif
    mov pGlobal, eax
    invoke _MemCopy, pMemory, pGlobal, dwFileSize

    ; create a stream for the picture object's creator
    invoke CreateStreamOnHGlobal, pGlobal, TRUE, ADDR pStream
    or eax,eax
    jz @f 
    invoke CoTaskMemFree,pGlobal
    xor eax,eax
    ret
   
@@:
    invoke OleLoadPicture, pStream, NULL, TRUE, ADDR IID_IPicture, ADDR pPicture
    or eax,eax
    jz @f
    mov eax, pStream
    call release_pStream
    xor eax,eax
    ret

@@:   
    ; now we are ready to get the hBipmap, we farm this out for reuseability
    invoke BitmapFromPicture, pPicture
    mov hBitmap, eax  

    mov eax, pStream
    call release_pStream

    mov eax, pPicture
    call release_pPicture

    mov eax, hBitmap                ; hBitmap is our return value, stuff it

    ret                             ; we're all done

BitmapFromMemory ENDP

; release the stream
release_pStream PROC
    push eax
    mov eax, [eax]
    call [eax].IPicture.Release   
    ret
release_pStream ENDP

; release the Picture object
release_pPicture PROC
    push eax
    mov eax, [eax]
    call [eax].IPicture.Release   
    ret
release_pPicture ENDP

END 