; --------------------------------------------------------------------------------------------------
;                           lvcodek.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LVCODEK_INC
LVCODEK_INC equ <1>

CodecOpen PROTO STDCALL :DWORD
DllUnload PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file lvcodek.inc
  echo ------------------------------------------
ENDIF
