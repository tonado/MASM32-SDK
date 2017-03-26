; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\comdlg32.inc
    include \MASM32\INCLUDE\user32.inc

    .code

; #########################################################################

FontDialog proc hWin:DWORD, lf:DWORD, fStyle:DWORD

  ; ---------------------------------
  ; hWin   = parent handle
  ; lf     = ADDR LOGFONT structure
  ; fstyle = font listing style flags
  ; styles are ORed for required results
  ; Font flags are found in the CHOOSEFONT
  ; reference.
  ;
  ; If eax returns zero, cancel was
  ; pressed. If selection is made,
  ; return in eax is non zero and
  ; LOGFONT structure is filled
  ; with font information.
  ; ---------------------------------

    LOCAL hDC   :DWORD
    LOCAL cf    :CHOOSEFONT

    invoke GetDC,hWin
    push eax
    mov hDC, eax

    mov cf.lStructSize,     sizeof CHOOSEFONT
    push hWin
    pop cf.hWndOwner
    pop eax
    mov cf.hDC,             eax
    push lf
    pop cf.lpLogFont
    mov cf.iPointSize,      0
    push fStyle                 ; font listing style flags
    pop cf.Flags
    mov cf.rgbColors,       0
    mov cf.lCustData,       0
    mov cf.lpfnHook,        0
    mov cf.lpTemplateName,  0
    mov cf.hInstance,       0
    mov cf.lpszStyle,       0
    mov cf.nFontType,       0
    mov cf.Alignment,       0
    mov cf.nSizeMin,        0
    mov cf.nSizeMax,        0

    invoke ChooseFont,ADDR cf
    push eax
    invoke ReleaseDC,hWin,hDC
    pop eax

    ret

FontDialog endp

; #########################################################################

end