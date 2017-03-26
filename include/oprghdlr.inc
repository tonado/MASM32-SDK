; --------------------------------------------------------------------------------------------------
;                          oprghdlr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF OPRGHDLR_INC
OPRGHDLR_INC equ <1>

DeRegisterOpRegionHandler PROTO STDCALL :DWORD,:DWORD
RegisterOpRegionHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file oprghdlr.inc
  echo -------------------------------------------
ENDIF
