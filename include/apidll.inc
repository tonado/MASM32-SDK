; --------------------------------------------------------------------------------------------------
;                           apidll.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF APIDLL_INC
APIDLL_INC equ <1>

ApiDllEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
  ; _penter arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file apidll.inc
  echo -----------------------------------------
ENDIF
