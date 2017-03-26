; --------------------------------------------------------------------------------------------------
;                           sporder.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SPORDER_INC
SPORDER_INC equ <1>

WSCWriteNameSpaceOrder PROTO STDCALL :DWORD,:DWORD
WSCWriteProviderOrder PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file sporder.inc
  echo ------------------------------------------
ENDIF
