; --------------------------------------------------------------------------------------------------
;                          scsiport.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCSIPORT_INC
SCSIPORT_INC equ <1>

KeBugCheckEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeTickCount PROTO C :VARARG
ScsiDebugPrint PROTO C :VARARG
ScsiPortCompleteRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortConvertPhysicalAddressToUlong PROTO STDCALL :DWORD,:DWORD
ScsiPortConvertUlongToPhysicalAddress PROTO STDCALL :DWORD
ScsiPortFlushDma PROTO STDCALL :DWORD
ScsiPortFreeDeviceBase PROTO STDCALL :DWORD,:DWORD
ScsiPortGetBusData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortGetDeviceBase PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortGetLogicalUnit PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ScsiPortGetPhysicalAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ScsiPortGetSrb PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortGetUncachedExtension PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortGetVirtualAddress PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ScsiPortIoMapTransfer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ScsiPortLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortNotification PROTO C :VARARG
ScsiPortQuerySystemTime PROTO STDCALL :DWORD
ScsiPortReadPortBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadPortBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadPortBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadPortUchar PROTO STDCALL :DWORD
ScsiPortReadPortUlong PROTO STDCALL :DWORD
ScsiPortReadPortUshort PROTO STDCALL :DWORD
ScsiPortReadRegisterBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadRegisterBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadRegisterBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortReadRegisterUchar PROTO STDCALL :DWORD
ScsiPortReadRegisterUlong PROTO STDCALL :DWORD
ScsiPortReadRegisterUshort PROTO STDCALL :DWORD
ScsiPortSetBusDataByOffset PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortStallExecution PROTO STDCALL :DWORD
ScsiPortValidateRange PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScsiPortWritePortBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWritePortBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWritePortBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWritePortUchar PROTO STDCALL :DWORD,:DWORD
ScsiPortWritePortUlong PROTO STDCALL :DWORD,:DWORD
ScsiPortWritePortUshort PROTO STDCALL :DWORD,:DWORD
ScsiPortWriteRegisterBufferUchar PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWriteRegisterBufferUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWriteRegisterBufferUshort PROTO STDCALL :DWORD,:DWORD,:DWORD
ScsiPortWriteRegisterUchar PROTO STDCALL :DWORD,:DWORD
ScsiPortWriteRegisterUlong PROTO STDCALL :DWORD,:DWORD
ScsiPortWriteRegisterUshort PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file scsiport.inc
  echo -------------------------------------------
ENDIF
