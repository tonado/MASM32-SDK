; ########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    
    include \MASM32\INCLUDE\gdi32.inc
    include \MASM32\INCLUDE\user32.inc

    .code

; ########################################################################

line proc hndl:DWORD,colr:DWORD,x1:DWORD,y1:DWORD,x2:DWORD,y2:DWORD

    LOCAL hDC     :DWORD
    LOCAL hPen    :DWORD
    LOCAL hPenOld :DWORD

    invoke GetDC,hndl
    mov hDC, eax

    invoke CreatePen,0,1,colr
    mov hPen, eax
  
    invoke SelectObject,hDC,hPen
    mov hPenOld, eax

    invoke MoveToEx,hDC,x1,y1,NULL

    invoke LineTo,hDC,x2,y2

    invoke SelectObject,hDC,hPenOld
    invoke DeleteObject,hPen

    ret

line endp

; ########################################################################

end