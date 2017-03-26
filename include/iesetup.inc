; --------------------------------------------------------------------------------------------------
;                           iesetup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF IESETUP_INC
IESETUP_INC equ <1>

FixIE PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file iesetup.inc
  echo ------------------------------------------
ENDIF
