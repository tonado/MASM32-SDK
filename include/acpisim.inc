; --------------------------------------------------------------------------------------------------
;                           acpisim.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ACPISIM_INC
ACPISIM_INC equ <1>

ExAllocatePoolWithTag PROTO STDCALL :DWORD,:DWORD,:DWORD
ExFreePoolWithTag PROTO STDCALL :DWORD,:DWORD
IoAcquireRemoveLockEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IoAllocateDriverObjectExtension PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IoAttachDeviceToDeviceStack PROTO STDCALL :DWORD,:DWORD
IoCreateDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IoDeleteDevice PROTO STDCALL :DWORD
IoDetachDevice PROTO STDCALL :DWORD
IoGetDriverObjectExtension PROTO STDCALL :DWORD,:DWORD
IoInitializeRemoveLockEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IoRegisterDeviceInterface PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IoReleaseRemoveLockEx PROTO STDCALL :DWORD,:DWORD,:DWORD
IoSetDeviceInterfaceState PROTO STDCALL :DWORD,:DWORD
KeInitializeEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeResetEvent PROTO STDCALL :DWORD
KeSetEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PoCallDriver PROTO STDCALL :DWORD,:DWORD
PoRequestPowerIrp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PoSetPowerState PROTO STDCALL :DWORD,:DWORD,:DWORD
PoStartNextPowerIrp PROTO STDCALL :DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlFreeUnicodeString PROTO STDCALL :DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file acpisim.inc
  echo ------------------------------------------
ENDIF
