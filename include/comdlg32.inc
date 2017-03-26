; --------------------------------------------------------------------------------------------------
;                          comdlg32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF COMDLG32_INC
COMDLG32_INC equ <1>

ChooseColorA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  ChooseColor equ <ChooseColorA>
ENDIF

ChooseColorW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  ChooseColor equ <ChooseColorW>
ENDIF

ChooseFontA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  ChooseFont equ <ChooseFontA>
ENDIF

ChooseFontW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  ChooseFont equ <ChooseFontW>
ENDIF

CommDlgExtendedError PROTO STDCALL

FindTextA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  FindText equ <FindTextA>
ENDIF

FindTextW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  FindText equ <FindTextW>
ENDIF

FormatCharDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

GetFileTitleA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileTitle equ <GetFileTitleA>
ENDIF

GetFileTitleW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFileTitle equ <GetFileTitleW>
ENDIF

GetOpenFileNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetOpenFileName equ <GetOpenFileNameA>
ENDIF

GetOpenFileNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetOpenFileName equ <GetOpenFileNameW>
ENDIF

GetSaveFileNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetSaveFileName equ <GetSaveFileNameA>
ENDIF

GetSaveFileNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetSaveFileName equ <GetSaveFileNameW>
ENDIF

LoadAlterBitmap PROTO STDCALL :DWORD,:DWORD,:DWORD

PageSetupDlgA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PageSetupDlg equ <PageSetupDlgA>
ENDIF

PageSetupDlgW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PageSetupDlg equ <PageSetupDlgW>
ENDIF

PrintDlgA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PrintDlg equ <PrintDlgA>
ENDIF

PrintDlgExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PrintDlgEx equ <PrintDlgExA>
ENDIF

PrintDlgExW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PrintDlgEx equ <PrintDlgExW>
ENDIF

PrintDlgW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PrintDlg equ <PrintDlgW>
ENDIF

ReplaceTextA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  ReplaceText equ <ReplaceTextA>
ENDIF

ReplaceTextW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  ReplaceText equ <ReplaceTextW>
ENDIF

Ssync_ANSI_UNICODE_Struct_For_WOW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  Ssync_ANSI_UNICODE_Struct_For_WO equ <Ssync_ANSI_UNICODE_Struct_For_WOW>
ENDIF

WantArrows PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
dwLBSubclass PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
dwOKSubclass PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file comdlg32.inc
  echo -------------------------------------------
ENDIF
