; ########################################################################

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

      include \MASM32\INCLUDE\gdi32.inc

      NULL equ <0>

    .code

; ########################################################################

Frame3D proc hDC:DWORD,btn_hi:DWORD,btn_lo:DWORD,
             tx:DWORD, ty:DWORD, lx:DWORD, ly:DWORD,bdrWid:DWORD

  ; ------------------
  ; Example usage code
  ; ------------------

  ; LOCAL btn_hi   :DWORD
  ; LOCAL btn_lo   :DWORD

  ; invoke GetSysColor,COLOR_BTNHIGHLIGHT
  ; mov btn_hi, eax

  ; invoke GetSysColor,COLOR_BTNSHADOW
  ; mov btn_lo, eax

  ; invoke Frame3D,hDC,btn_lo,btn_hi,50,50,150,100,2
  ; invoke Frame3D,hDC,btn_hi,btn_lo,47,47,153,103,2
  ; --------------------------------

    LOCAL hPen     :DWORD
    LOCAL hPen2    :DWORD
    LOCAL hpenOld  :DWORD

    invoke CreatePen,0,1,btn_hi
    mov hPen, eax
  
    invoke SelectObject,hDC,hPen
    mov hpenOld, eax

    ; ------------------------------------
    ; Save copy of parameters for 2nd loop
    ; ------------------------------------
    push tx
    push ty
    push lx
    push ly
    push bdrWid

    ; ------------

       lpOne:

        invoke MoveToEx,hDC,tx,ty,NULL
        invoke LineTo,hDC,lx,ty

        invoke MoveToEx,hDC,tx,ty,NULL
        invoke LineTo,hDC,tx,ly

        dec tx
        dec ty
        inc lx
        inc ly

        dec bdrWid
        cmp bdrWid, 0
        je lp1Out
        jmp lpOne
      lp1Out:

    ; ------------
    invoke CreatePen,0,1,btn_lo
    mov hPen2, eax
    invoke SelectObject,hDC,hPen2
    mov hPen, eax
    invoke DeleteObject,hPen
    ; ------------

    pop bdrWid
    pop ly
    pop lx
    pop ty
    pop tx

       lpTwo:

        invoke MoveToEx,hDC,tx,ly,NULL
        invoke LineTo,hDC,lx,ly

        invoke MoveToEx,hDC,lx,ty,NULL
        inc ly        
        invoke LineTo,hDC,lx,ly
        dec ly

        dec tx
        dec ty
        inc lx
        inc ly

        dec bdrWid
        cmp bdrWid, 0
        je lp2Out
        jmp lpTwo
      lp2Out:

    ; ------------
    invoke SelectObject,hDC,hpenOld
    invoke DeleteObject,hPen2

    ret

Frame3D endp

; #########################################################################

end