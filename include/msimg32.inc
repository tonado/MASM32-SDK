; --------------------------------------------------------------------------------------------------
;                           msimg32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSIMG32_INC
MSIMG32_INC equ <1>

AlphaBlend PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GradientFill PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TransparentBlt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file msimg32.inc
  echo ------------------------------------------
ENDIF
