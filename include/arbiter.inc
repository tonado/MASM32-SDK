; --------------------------------------------------------------------------------------------------
;                           arbiter.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ARBITER_INC
ARBITER_INC equ <1>

ExAllocatePoolWithTag PROTO STDCALL :DWORD,:DWORD,:DWORD
ExFreePoolWithTag PROTO STDCALL :DWORD,:DWORD
IoGetDeviceProperty PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeGetCurrentIrql PROTO STDCALL
KeInitializeEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeSetEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file arbiter.inc
  echo ------------------------------------------
ENDIF
