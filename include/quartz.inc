; --------------------------------------------------------------------------------------------------
;                           quartz.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF QUARTZ_INC
QUARTZ_INC equ <1>

AMGetErrorTextA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AMGetErrorText equ <AMGetErrorTextA>
ENDIF

AMGetErrorTextW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AMGetErrorText equ <AMGetErrorTextW>
ENDIF

AmpFactorToDB PROTO STDCALL :DWORD
DBToAmpFactor PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file quartz.inc
  echo -----------------------------------------
ENDIF
