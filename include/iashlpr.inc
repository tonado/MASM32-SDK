; --------------------------------------------------------------------------------------------------
;                           iashlpr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF IASHLPR_INC
IASHLPR_INC equ <1>

AllocateAttributes PROTO STDCALL :DWORD,:DWORD
ConfigureIas PROTO STDCALL
DoRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FreeAttributes PROTO STDCALL :DWORD,:DWORD
InitializeIas PROTO STDCALL :DWORD
MemAllocIas PROTO STDCALL :DWORD
MemFreeIas PROTO STDCALL :DWORD
MemReallocIas PROTO STDCALL :DWORD,:DWORD
ShutdownIas PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file iashlpr.inc
  echo ------------------------------------------
ENDIF
