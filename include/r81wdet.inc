; --------------------------------------------------------------------------------------------------
;                           r81wdet.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF R81WDET_INC
R81WDET_INC equ <1>

FindAdapterHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file r81wdet.inc
  echo ------------------------------------------
ENDIF
