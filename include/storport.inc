; --------------------------------------------------------------------------------------------------
;                          storport.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF STORPORT_INC
STORPORT_INC equ <1>

KeBugCheckEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeTickCount PROTO C :VARARG
ScsiPortMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortNotification PROTO C :VARARG
StorPortBusy PROTO STDCALL :DWORD,:DWORD
StorPortCompleteRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortConvertUlongToPhysicalAddress PROTO STDCALL :DWORD
StorPortDebugPrint PROTO C :VARARG
StorPortDeviceBusy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortDeviceReady PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StorPortFreeDeviceBase PROTO STDCALL :DWORD,:DWORD
StorPortGetBusData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortGetDeviceBase PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortGetLogicalUnit PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StorPortGetPhysicalAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StorPortGetScatterGatherList PROTO STDCALL :DWORD,:DWORD
StorPortGetSrb PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortGetUncachedExtension PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortGetVirtualAddress PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StorPortLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortNotification PROTO C :VARARG
StorPortPause PROTO STDCALL :DWORD,:DWORD
StorPortPauseDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortReadPortBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadPortBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadPortBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadPortUchar PROTO STDCALL :DWORD
StorPortReadPortUlong PROTO STDCALL :DWORD
StorPortReadPortUshort PROTO STDCALL :DWORD
StorPortReadRegisterBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadRegisterBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadRegisterBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortReadRegisterUchar PROTO STDCALL :DWORD
StorPortReadRegisterUlong PROTO STDCALL :DWORD
StorPortReadRegisterUshort PROTO STDCALL :DWORD
StorPortReady PROTO STDCALL :DWORD
StorPortResume PROTO STDCALL :DWORD
StorPortResumeDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StorPortSetBusDataByOffset PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortStallExecution PROTO STDCALL :DWORD
StorPortSynchronizeAccess PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortValidateRange PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StorPortWritePortBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWritePortBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWritePortBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWritePortUchar PROTO STDCALL :DWORD,:DWORD
StorPortWritePortUlong PROTO STDCALL :DWORD,:DWORD
StorPortWritePortUshort PROTO STDCALL :DWORD,:DWORD
StorPortWriteRegisterBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWriteRegisterBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWriteRegisterBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
StorPortWriteRegisterUchar PROTO STDCALL :DWORD,:DWORD
StorPortWriteRegisterUlong PROTO STDCALL :DWORD,:DWORD
StorPortWriteRegisterUshort PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file storport.inc
  echo -------------------------------------------
ENDIF
