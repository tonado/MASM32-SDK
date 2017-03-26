; #########################################################################

      .386
      .model flat, stdcall
      option casemap :none   ; case sensitive

      include \masm32\include\windows.inc
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      
      Frame3D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

FrameWindow proc hndle:DWORD, step:DWORD, wid:DWORD, direction:DWORD

  ; -------------------------------------------------------------
  ; This proc is used for framing the client area of a window.
  ; Parameters.
  ; 1. The handle of the window.
  ; 2. step, the distance from the inside edge of the client area
  ;    in pixels to draw the frame
  ; 3. wid, the width of the frame in pixels.
  ; 4. direction, 0 = sunken frame, 1 = raised frame.
  ; -------------------------------------------------------------

    LOCAL btn_hi    :DWORD
    LOCAL btn_lo    :DWORD
    LOCAL hDC       :DWORD
    LOCAL Rct       :RECT

    invoke GetDC,hndle
    mov hDC, eax

    invoke GetClientRect,hndle,ADDR Rct

    mov eax, step
    mov edx, wid

    add eax, edx

    add Rct.left,   eax
    add Rct.top,    eax
    inc eax
    sub Rct.right,  eax
    sub Rct.bottom, eax

    invoke GetSysColor,COLOR_BTNHIGHLIGHT
    mov btn_hi, eax

    invoke GetSysColor,COLOR_BTNSHADOW
    mov btn_lo, eax

    .if direction == 1
      mov eax, btn_lo
      mov ecx, btn_hi
      mov btn_lo, ecx
      mov btn_hi, eax
    .endif

    invoke Frame3D,hDC,btn_lo,btn_hi,
                   Rct.left,
                   Rct.top,Rct.right,Rct.bottom,wid

    invoke ReleaseDC,hndle,hDC

    ret

FrameWindow endp

; #########################################################################

end