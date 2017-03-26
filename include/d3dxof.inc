; --------------------------------------------------------------------------------------------------
;                           d3dxof.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF D3DXOF_INC
D3DXOF_INC equ <1>

DirectXFileCreate PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file d3dxof.inc
  echo -----------------------------------------
ENDIF
