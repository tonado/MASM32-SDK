; --------------------------------------------------------------------------------------------------
;                            sdbus.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SDBUS_INC
SDBUS_INC equ <1>

IoAllocateIrp PROTO STDCALL :DWORD,:DWORD
IoBuildSynchronousFsdRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IoFreeIrp PROTO STDCALL :DWORD
IoGetAttachedDeviceReference PROTO STDCALL :DWORD
KeInitializeEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeSetEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file sdbus.inc
  echo ----------------------------------------
ENDIF
