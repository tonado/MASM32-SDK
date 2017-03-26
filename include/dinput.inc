; --------------------------------------------------------------------------------------------------
;                           dinput.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DINPUT_INC
DINPUT_INC equ <1>

DirectInputCreateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DirectInputCreate equ <DirectInputCreateA>
ENDIF

DirectInputCreateEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DirectInputCreateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DirectInputCreate equ <DirectInputCreateW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dinput.inc
  echo -----------------------------------------
ENDIF
