; --------------------------------------------------------------------------------------------------
;                           nibcdet.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NIBCDET_INC
NIBCDET_INC equ <1>

FindAdapterHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file nibcdet.inc
  echo ------------------------------------------
ENDIF
