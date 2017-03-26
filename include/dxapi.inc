; --------------------------------------------------------------------------------------------------
;                            dxapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DXAPI_INC
DXAPI_INC equ <1>

DxApi PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DxApiGetVersion PROTO STDCALL
DxApiInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DxAutoflipUpdate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DxEnableIRQ PROTO STDCALL :DWORD,:DWORD
DxLoseObject PROTO STDCALL :DWORD,:DWORD
DxUpdateCapture PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file dxapi.inc
  echo ----------------------------------------
ENDIF
