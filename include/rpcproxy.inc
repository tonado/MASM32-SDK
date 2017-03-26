; --------------------------------------------------------------------------------------------------
;                          rpcproxy.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RPCPROXY_INC
RPCPROXY_INC equ <1>

GetExtensionVersion PROTO STDCALL :DWORD
GetFilterVersion PROTO STDCALL :DWORD
HttpExtensionProc PROTO STDCALL :DWORD
HttpFilterProc PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file rpcproxy.inc
  echo -------------------------------------------
ENDIF
