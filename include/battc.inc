; --------------------------------------------------------------------------------------------------
;                            battc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF BATTC_INC
BATTC_INC equ <1>

BatteryClassInitializeDevice PROTO STDCALL :DWORD,:DWORD
BatteryClassIoctl PROTO STDCALL :DWORD,:DWORD
BatteryClassQueryWmiDataBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BatteryClassStatusNotify PROTO STDCALL :DWORD
BatteryClassSystemControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BatteryClassUnload PROTO STDCALL :DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file battc.inc
  echo ----------------------------------------
ENDIF
