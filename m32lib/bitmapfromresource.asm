;-------------------------------------------------------------------------------
;  BitmapFromResource.ASM
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

szImage             BYTE    "IMAGE", 0

.code
;-------------------------------------------------------------------------------
BitmapFromResource  PROC hModule: dword, ResNumber:DWORD
    LOCAL hResource:DWORD,  dwFileSize:DWORD, hImage:DWORD

    ; get a resource handle (address) and resource length from the executable
    invoke FindResource, hModule, ResNumber, ADDR szImage
    or eax,eax
    jnz @f
    invoke SetLastError, ERROR_FILE_NOT_FOUND
    xor eax,eax
    ret
@@:
    mov hResource, eax
    invoke LoadResource, hModule, eax
    invoke LockResource, eax
    mov hImage, eax
    invoke SizeofResource, hModule, hResource
    mov dwFileSize, eax
    .IF dwFileSize      ; we use the resource size to determine if we got a
                        ; legit image file to open
        invoke BitmapFromMemory, hImage, dwFileSize
    .ELSE
        invoke SetLastError, ERROR_FILE_NOT_FOUND
        xor eax,eax
    .ENDIF

    ; everything's been done for us now, just return
    ret                     ; we're all done

BitmapFromResource  ENDP    
;-------------------------------------------------------------------------------
END 
