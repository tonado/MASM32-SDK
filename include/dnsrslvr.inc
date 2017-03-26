; --------------------------------------------------------------------------------------------------
;                          dnsrslvr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DNSRSLVR_INC
DNSRSLVR_INC equ <1>

ServiceMain PROTO STDCALL :DWORD,:DWORD
SvchostPushServiceGlobals PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file dnsrslvr.inc
  echo -------------------------------------------
ENDIF
