; --------------------------------------------------------------------------------------------------
;                           stdunk.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF STDUNK_INC
STDUNK_INC equ <1>

ExFreePool PROTO STDCALL :DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file stdunk.inc
  echo -----------------------------------------
ENDIF
