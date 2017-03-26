; --------------------------------------------------------------------------------------------------
;                          batmeter.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF BATMETER_INC
BATMETER_INC equ <1>

BatMeterCapabilities PROTO STDCALL :DWORD
CreateBatMeter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DestroyBatMeter PROTO STDCALL :DWORD
PowerCapabilities PROTO STDCALL
UpdateBatMeter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file batmeter.inc
  echo -------------------------------------------
ENDIF
