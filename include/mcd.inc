; --------------------------------------------------------------------------------------------------
;                             mcd.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MCD_INC
MCD_INC equ <1>

ChangerClassAllocatePool PROTO STDCALL :DWORD,:DWORD
ChangerClassDebugPrint PROTO C :VARARG
ChangerClassFreePool PROTO STDCALL :DWORD
ChangerClassInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
ChangerClassSendSrbSynchronous PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file mcd.inc
  echo --------------------------------------
ENDIF
