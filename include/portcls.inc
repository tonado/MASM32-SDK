; --------------------------------------------------------------------------------------------------
;                           portcls.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PORTCLS_INC
PORTCLS_INC equ <1>

PcAcquireFormatResources PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PcAddAdapterDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcAddContentHandlers PROTO STDCALL :DWORD,:DWORD,:DWORD
PcAddToEventTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcAddToPropertyTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcCaptureFormat PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PcCompleteIrp PROTO STDCALL :DWORD,:DWORD,:DWORD
PcCompletePendingEventRequest PROTO STDCALL :DWORD,:DWORD
PcCompletePendingPropertyRequest PROTO STDCALL :DWORD,:DWORD
PcCreateContentMixed PROTO STDCALL :DWORD,:DWORD,:DWORD
PcCreateSubdeviceDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcDeleteSubdeviceDescriptor PROTO STDCALL :DWORD
PcDestroyContent PROTO STDCALL :DWORD
PcDispatchIrp PROTO STDCALL :DWORD,:DWORD
PcDmaMasterDescription PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcDmaSlaveDescription PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcForwardContentToDeviceObject PROTO STDCALL :DWORD,:DWORD,:DWORD
PcForwardContentToFileObject PROTO STDCALL :DWORD,:DWORD
PcForwardContentToInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
PcForwardIrpSynchronous PROTO STDCALL :DWORD,:DWORD
PcFreeEventTable PROTO STDCALL :DWORD
PcFreePropertyTable PROTO STDCALL :DWORD
PcGenerateEventDeferredRoutine PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PcGenerateEventList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcGetContentRights PROTO STDCALL :DWORD,:DWORD
PcGetDeviceProperty PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcGetTimeInterval PROTO STDCALL :DWORD,:DWORD
PcHandleDisableEventWithTable PROTO STDCALL :DWORD,:DWORD
PcHandleEnableEventWithTable PROTO STDCALL :DWORD,:DWORD
PcHandlePropertyWithTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PcInitializeAdapterDriver PROTO STDCALL :DWORD,:DWORD,:DWORD
PcNewDmaChannel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcNewInterruptSync PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcNewMiniport PROTO STDCALL :DWORD,:DWORD
PcNewPort PROTO STDCALL :DWORD,:DWORD
PcNewRegistryKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcNewResourceList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcNewResourceSublist PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcNewServiceGroup PROTO STDCALL :DWORD,:DWORD
PcPinPropertyHandler PROTO STDCALL :DWORD,:DWORD,:DWORD
PcRegisterAdapterPowerManagement PROTO STDCALL :DWORD,:DWORD
PcRegisterIoTimeout PROTO STDCALL :DWORD,:DWORD,:DWORD
PcRegisterPhysicalConnection PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcRegisterPhysicalConnectionFromExternal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcRegisterPhysicalConnectionToExternal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PcRegisterSubdevice PROTO STDCALL :DWORD,:DWORD,:DWORD
PcRequestNewPowerState PROTO STDCALL :DWORD,:DWORD
PcTerminateConnection PROTO STDCALL :DWORD,:DWORD,:DWORD
PcUnregisterIoTimeout PROTO STDCALL :DWORD,:DWORD,:DWORD
PcValidateConnectRequest PROTO STDCALL :DWORD,:DWORD,:DWORD
PcVerifyFilterIsReady PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file portcls.inc
  echo ------------------------------------------
ENDIF
