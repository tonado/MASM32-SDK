; --------------------------------------------------------------------------------------------------
;                          hidclass.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF HIDCLASS_INC
HIDCLASS_INC equ <1>

HidNotifyPresence PROTO STDCALL :DWORD,:DWORD
HidRegisterMinidriver PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file hidclass.inc
  echo -------------------------------------------
ENDIF
