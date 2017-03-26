; --------------------------------------------------------------------------------------------------
;                          asycfilt.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ASYCFILT_INC
ASYCFILT_INC equ <1>

FilterCreateInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file asycfilt.inc
  echo -------------------------------------------
ENDIF
