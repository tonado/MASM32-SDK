; --------------------------------------------------------------------------------------------------
;                           ntlanui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTLANUI_INC
NTLANUI_INC equ <1>

DllMain PROTO STDCALL :DWORD,:DWORD,:DWORD
I_SystemFocusDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NPGetPropertyText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NPPropertyDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ServerBrowseDialogA0 PROTO STDCALL :DWORD,:DWORD,:DWORD
ShareCreate PROTO STDCALL :DWORD
ShareManage PROTO STDCALL :DWORD,:DWORD
ShareStop PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntlanui.inc
  echo ------------------------------------------
ENDIF
