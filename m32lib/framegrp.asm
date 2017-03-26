; #########################################################################

      .386
      .model flat, stdcall
      option casemap :none   ; case sensitive

      include \masm32\include\windows.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc

      Frame3D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

FrameGrp proc hCtrl1:DWORD, hCtrl2:DWORD, step:DWORD, wdth:DWORD, direction:DWORD

    ; -------------------------------------------------------------
    ; This proc draws a frame bounded by the top left co-ordinates
    ; of the first control handle and the bottom right co-ordinates
    ; of the second control handle. It is used to draw frames around
    ; groups of controls.
    ;
    ; Parameters.
    ; 1 & 2 must be valid control handles.
    ; 3. step, the distance in pixels from the edge of the controls
    ;    to draw the frame.
    ; 4. wdth, the width of the frame in pixels.
    ; 5. direction, 0 = sunken frame, 1 = raised frame
    ; -------------------------------------------------------------

    LOCAL hParent   :DWORD
    LOCAL btn_hi    :DWORD
    LOCAL btn_lo    :DWORD
    LOCAL hDC       :DWORD

    LOCAL P1        :SDWORD
    LOCAL P2        :SDWORD
    LOCAL P3        :SDWORD
    LOCAL P4        :SDWORD

    LOCAL Rct     :RECT         ; Rectangle for GetWindowRect
    LOCAL Pt      :POINT        ; Point for ScreenToClient

    invoke GetWindowRect,hCtrl1,ADDR Rct      ; Put co-ordinates in Rct.

    mov eax, Rct.left           ; Put x & y co-ordinates
    mov Pt.x, eax               ; into Pt structure

    mov eax, Rct.top
    mov Pt.y, eax

    invoke GetParent,hCtrl1
    mov hParent, eax

    invoke GetDC,hParent
    mov hDC, eax

    invoke ScreenToClient,hParent,ADDR Pt    ; Convert to client co-ordinates.

    mov eax, Pt.x
    dec eax
    sub eax, step
    mov P1, eax

    mov eax, Pt.y
    dec eax
    sub eax, step
    mov P2, eax

    invoke GetWindowRect,hCtrl2,ADDR Rct      ; Put co-ordinates in Rct.

    mov eax, Rct.left           ; Put x & y co-ordinates
    mov Pt.x, eax               ; into Pt structure

    mov eax, Rct.top
    mov Pt.y, eax

    invoke ScreenToClient,hParent,ADDR Pt    ; Convert to client co-ordinates.

    mov eax, Rct.right
    sub eax, Rct.left
    add eax, Pt.x
    add eax, step
    mov P3, eax

    mov eax, Rct.bottom
    sub eax, Rct.top
    add eax, Pt.y
    add eax, step
    mov P4, eax

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

    invoke Frame3D,hDC,btn_lo,btn_hi,P1,P2,P3,P4,wdth

    invoke ReleaseDC,hParent,hDC

    ret

FrameGrp endp

; #########################################################################

end