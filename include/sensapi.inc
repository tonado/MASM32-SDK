; --------------------------------------------------------------------------------------------------
;                           sensapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SENSAPI_INC
SENSAPI_INC equ <1>

IsDestinationReachableA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  IsDestinationReachable equ <IsDestinationReachableA>
ENDIF

IsDestinationReachableW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  IsDestinationReachable equ <IsDestinationReachableW>
ENDIF

IsNetworkAlive PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file sensapi.inc
  echo ------------------------------------------
ENDIF
