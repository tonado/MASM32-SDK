; --------------------------------------------------------------------------------------------------
;                          dflayout.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DFLAYOUT_INC
DFLAYOUT_INC equ <1>

StgOpenLayoutDocfile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file dflayout.inc
  echo -------------------------------------------
ENDIF
