; --------------------------------------------------------------------------------------------------
;                          feclient.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF FECLIENT_INC
FECLIENT_INC equ <1>

FeClientInitialize PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file feclient.inc
  echo -------------------------------------------
ENDIF
