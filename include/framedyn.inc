; --------------------------------------------------------------------------------------------------
;                          framedyn.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF FRAMEDYN_INC
FRAMEDYN_INC equ <1>

DoCmd PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file framedyn.inc
  echo -------------------------------------------
ENDIF
