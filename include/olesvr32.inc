; --------------------------------------------------------------------------------------------------
;                          olesvr32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF OLESVR32_INC
OLESVR32_INC equ <1>

DeleteClientInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
DocWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
EnumForTerminate PROTO STDCALL :DWORD,:DWORD,:DWORD
FindItemWnd PROTO STDCALL :DWORD,:DWORD
ItemCallBack PROTO STDCALL :DWORD,:DWORD,:DWORD
ItemWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OleBlockServer PROTO STDCALL :DWORD
OleQueryServerVersion PROTO STDCALL
OleRegisterServer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleRegisterServerDoc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OleRenameServerDoc PROTO STDCALL :DWORD,:DWORD
OleRevertServerDoc PROTO STDCALL :DWORD
OleRevokeObject PROTO STDCALL :DWORD
OleRevokeServer PROTO STDCALL :DWORD
OleRevokeServerDoc PROTO STDCALL :DWORD
OleSavedServerDoc PROTO STDCALL :DWORD
OleUnblockServer PROTO STDCALL :DWORD,:DWORD
SendDataMsg PROTO STDCALL :DWORD,:DWORD,:DWORD
SendRenameMsg PROTO STDCALL :DWORD,:DWORD,:DWORD
SrvrWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TerminateClients PROTO STDCALL :DWORD,:DWORD,:DWORD
TerminateDocClients PROTO STDCALL :DWORD,:DWORD,:DWORD
WEP PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file olesvr32.inc
  echo -------------------------------------------
ENDIF
