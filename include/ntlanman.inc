; --------------------------------------------------------------------------------------------------
;                          ntlanman.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTLANMAN_INC
NTLANMAN_INC equ <1>

DllMain PROTO STDCALL :DWORD,:DWORD,:DWORD
I_SystemFocusDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsDfsPathEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NPAddConnection3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NPAddConnection3ForCSCAgent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NPAddConnection PROTO STDCALL :DWORD,:DWORD,:DWORD
NPCancelConnectionForCSCAgent PROTO STDCALL :DWORD,:DWORD
NPCloseEnum PROTO STDCALL :DWORD
NPFormatNetworkName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NPGetConnection3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NPGetConnectionPerformance PROTO STDCALL :DWORD,:DWORD
NPGetDirectoryType PROTO STDCALL :DWORD,:DWORD,:DWORD
NPGetReconnectFlags PROTO STDCALL :DWORD,:DWORD
NPGetResourceInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NPGetResourceParent PROTO STDCALL :DWORD,:DWORD,:DWORD
NPGetUser PROTO STDCALL :DWORD,:DWORD,:DWORD
ServerBrowseDialogA0 PROTO STDCALL :DWORD,:DWORD,:DWORD
ShareAsDialogA0 PROTO STDCALL :DWORD,:DWORD,:DWORD
ShareCreate PROTO STDCALL :DWORD
ShareManage PROTO STDCALL :DWORD,:DWORD
ShareStop PROTO STDCALL :DWORD
StopShareDialogA0 PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file ntlanman.inc
  echo -------------------------------------------
ENDIF
