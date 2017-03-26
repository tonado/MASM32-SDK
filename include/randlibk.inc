; --------------------------------------------------------------------------------------------------
;                          randlibk.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RANDLIBK_INC
RANDLIBK_INC equ <1>

ExAcquireResourceExclusiveLite PROTO STDCALL :DWORD,:DWORD
ExAllocatePoolWithTag PROTO STDCALL :DWORD,:DWORD,:DWORD
ExDeleteResourceLite PROTO STDCALL :DWORD
ExFreePoolWithTag PROTO STDCALL :DWORD,:DWORD
ExInitializeResourceLite PROTO STDCALL :DWORD
KeEnterCriticalRegion PROTO STDCALL
KeGetCurrentIrql PROTO STDCALL
KeLeaveCriticalRegion PROTO STDCALL
KeNumberProcessors PROTO C :VARARG
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZwClose PROTO STDCALL :DWORD
ZwCreateKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwQuerySystemInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZwQueryValueKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwSetValueKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file randlibk.inc
  echo -------------------------------------------
ENDIF
