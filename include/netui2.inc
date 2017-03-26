; --------------------------------------------------------------------------------------------------
;                           netui2.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NETUI2_INC
NETUI2_INC equ <1>

BltCCWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
BltDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
BltWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CloseUserBrowser PROTO STDCALL :DWORD
EnumUserBrowserSelection PROTO STDCALL :DWORD,:DWORD,:DWORD
OpenUserBrowser PROTO STDCALL :DWORD
ShellDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file netui2.inc
  echo -----------------------------------------
ENDIF
