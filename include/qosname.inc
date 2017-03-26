; --------------------------------------------------------------------------------------------------
;                           qosname.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF QOSNAME_INC
QOSNAME_INC equ <1>

WPUGetQOSTemplate PROTO STDCALL :DWORD,:DWORD,:DWORD
WSCInstallQOSTemplate PROTO STDCALL :DWORD,:DWORD,:DWORD
WSCRemoveQOSTemplate PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file qosname.inc
  echo ------------------------------------------
ENDIF
