; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\user32.inc
    include \MASM32\INCLUDE\comdlg32.inc

    .code

; #########################################################################

PrintDialog proc hWin:DWORD,lppd:DWORD,flags:DWORD

  ; ------------------------------------------------------------------
  ; Parameters
  ; 1. hWin  = parent handle
  ; 2. lppd  = address of PRINTDLG to receive info
  ; 3. flags = additional styes from the PRINTDLG reference material
  ;
  ; EXAMPLE: invoke PrintDialog,hWin,ADDR pd,PD_SHOWHELP
  ; ------------------------------------------------------------------

    LOCAL pd:PRINTDLG

    mov pd.lStructSize,             sizeof PRINTDLG
    push hWin
    pop pd.hWndOwner
    mov pd.hDevMode,                0
    mov pd.hDevNames,               0
    mov pd.hDC,                     0
    mov eax, flags
    or  eax, PD_PAGENUMS    ; "or" default value with extra flags
    mov pd.Flags, eax
    mov pd.nFromPage,               1
    mov pd.nToPage,                 1
    mov pd.nMinPage,                0
    mov pd.nMaxPage,                65535
    mov pd.nCopies,                 1
    mov pd.hInstance,               0
    mov pd.lCustData,               0
    mov pd.lpfnPrintHook,           0
    mov pd.lpfnSetupHook,           0
    mov pd.lpPrintTemplateName,     0
    mov pd.lpPrintSetupTemplateName,0
    mov pd.hPrintTemplate,          0
    mov pd.hSetupTemplate,          0

    invoke PrintDlg,ADDR pd.lStructSize
    push eax

    mov ecx, sizeof PRINTDLG
    lea esi, pd
    mov edi, lppd
    rep movsb

    pop eax
    ret

PrintDialog endp

; #########################################################################

end