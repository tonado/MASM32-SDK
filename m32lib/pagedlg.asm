; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\comdlg32.inc

    .code

; #########################################################################

PageSetupDialog proc hWin:DWORD, lppsd  :DWORD,   style:DWORD,
                                 lMargin:DWORD, tMargin:DWORD,
                                 rMargin:DWORD, bMargin:DWORD

    ; Parameters.
    ; ~~~~~~~~~~
    ; 1. hWin    = Parent window handle.
    ; 2. lppsd   = address of PAGESETUPDLG structure for return parameters
    ; 3. style   = Default is 0, else styles from PAGESETUPDLG reference.
    ; 4. lMargin = 0 defaults to 500, inch = 1000 
    ; 4. tMargin = 0 defaults to 500, inch = 1000 
    ; 4. rMargin = 0 defaults to 500, inch = 1000 
    ; 4. bMargin = 0 defaults to 500, inch = 1000 

    ; EXAMPLE : invoke PageSetupDialog,hWin,ADDR psd,0,1000,750,1000,750

    LOCAL psd :PAGESETUPDLG

    mov eax, style
    .if eax == 0
      mov eax, PSD_DEFAULTMINMARGINS or PSD_MARGINS or \
               PSD_INTHOUSANDTHSOFINCHES                 ; default styles
      mov style, eax
    .endif

    mov eax, lMargin
    .if eax == 0
      mov eax, 500
      mov lMargin, eax
    .endif

    mov eax, tMargin
    .if eax == 0
      mov eax, 500
      mov tMargin, eax
    .endif

    mov eax, rMargin
    .if eax == 0
      mov eax, 500
      mov rMargin, eax
    .endif

    mov eax, bMargin
    .if eax == 0
      mov eax, 500
      mov bMargin, eax
    .endif

    mov psd.lStructSize,                sizeof PAGESETUPDLG
    push hWin
    pop psd.hwndOwner
    mov psd.hDevMode,                   0
    mov psd.hDevNames,                  0
    mov eax, style
    mov psd.flags,                      eax
    mov psd.ptPaperSize.x,              0
    mov psd.ptPaperSize.y,              0
    mov psd.rtMinMargin.left,           0
    mov psd.rtMinMargin.top,            0
    mov psd.rtMinMargin.right,          0
    mov psd.rtMinMargin.bottom,         0

    push lMargin
    pop psd.rtMargin.left

    push tMargin
    pop psd.rtMargin.top

    push rMargin
    pop psd.rtMargin.right

    push bMargin
    pop psd.rtMargin.bottom

    mov psd.hInstance,                  0
    mov psd.lCustData,                  0
    mov psd.lpfnPageSetupHook,          0
    mov psd.lpfnPagePaintHook,          0
    mov psd.lpPageSetupTemplateName,    0
    mov psd.hPageSetupTemplate,         0

    invoke PageSetupDlg,ADDR psd
    push eax

    mov ecx, sizeof PAGESETUPDLG
    lea esi, psd
    mov edi, lppsd
    rep movsb

    pop eax
    ret

PageSetupDialog endp

; #########################################################################

end