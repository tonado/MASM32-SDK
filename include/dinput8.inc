; --------------------------------------------------------------------------------------------------
;                           dinput8.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DINPUT8_INC
DINPUT8_INC equ <1>

DirectInput8Create PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file dinput8.inc
  echo ------------------------------------------
ENDIF
