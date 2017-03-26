; --------------------------------------------------------------------------------------------------
;                           ptilink.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PTILINK_INC
PTILINK_INC equ <1>

PtiCleanup PROTO STDCALL :DWORD
PtiInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
PtiIsReadPending PROTO STDCALL :DWORD
PtiPortNameFromPortId PROTO STDCALL :DWORD,:DWORD
PtiQueryDeviceStatus PROTO STDCALL :DWORD,:DWORD
PtiQueryMaxReadSize PROTO STDCALL
PtiRead PROTO STDCALL :DWORD
PtiRegisterCallbacks PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PtiWrite PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ptilink.inc
  echo ------------------------------------------
ENDIF
