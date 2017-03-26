; ########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive
    
    include \MASM32\INCLUDE\gdi32.inc
    include \MASM32\INCLUDE\user32.inc

    .code

; ########################################################################

circle proc hndl:DWORD,colr:DWORD,tx:DWORD,ty:DWORD,lx:DWORD,ly:DWORD

    LOCAL hDC     :DWORD
    LOCAL hPen    :DWORD
    LOCAL hPenOld :DWORD

    invoke GetDC,hndl
    mov hDC, eax

    invoke CreatePen,0,1,colr
    mov hPen, eax
  
    invoke SelectObject,hDC,hPen
    mov hPenOld, eax

    invoke Arc,hDC,tx,ty,lx,ly,0,0,0,0

    invoke SelectObject,hDC,hPenOld
    invoke DeleteObject,hPen

    ret

circle endp

; ########################################################################

end