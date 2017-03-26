; --------------------------------------------------------------------------------------------------
;                          nia35det.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NIA35DET_INC
NIA35DET_INC equ <1>

FindAdapterHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file nia35det.inc
  echo -------------------------------------------
ENDIF
