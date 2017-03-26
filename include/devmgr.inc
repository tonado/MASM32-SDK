; --------------------------------------------------------------------------------------------------
;                           devmgr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DEVMGR_INC
DEVMGR_INC equ <1>

DeviceCreateHardwarePage PROTO STDCALL :DWORD,:DWORD
DeviceCreateHardwarePageEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file devmgr.inc
  echo -----------------------------------------
ENDIF
