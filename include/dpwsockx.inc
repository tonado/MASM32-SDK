; --------------------------------------------------------------------------------------------------
;                          dpwsockx.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DPWSOCKX_INC
DPWSOCKX_INC equ <1>

DPWS_BuildIPMessageHeader PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DPWS_GetEnumPort PROTO STDCALL :DWORD,:DWORD
SPInit PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file dpwsockx.inc
  echo -------------------------------------------
ENDIF
