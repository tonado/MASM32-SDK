; --------------------------------------------------------------------------------------------------
;                             tdi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TDI_INC
TDI_INC equ <1>

CTEAllocateString PROTO STDCALL :DWORD,:DWORD
CTEBlock PROTO STDCALL :DWORD
CTEBlockWithTracker PROTO STDCALL :DWORD,:DWORD,:DWORD
CTEInitEvent PROTO STDCALL :DWORD,:DWORD
CTEInitString PROTO STDCALL :DWORD,:DWORD
CTEInitTimer PROTO STDCALL :DWORD
CTEInitialize PROTO STDCALL
CTEInsertBlockTracker PROTO STDCALL :DWORD,:DWORD
CTELogEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CTERemoveBlockTracker PROTO STDCALL :DWORD
CTEScheduleCriticalEvent PROTO STDCALL :DWORD,:DWORD
CTEScheduleDelayedEvent PROTO STDCALL :DWORD,:DWORD
CTEScheduleEvent PROTO STDCALL :DWORD,:DWORD
CTESignal PROTO STDCALL :DWORD,:DWORD
CTEStartTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CTESystemUpTime PROTO STDCALL
TdiBuildNetbiosAddress PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiBuildNetbiosAddressEa PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiCopyBufferToMdl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiCopyBufferToMdlWithReservedMappingAtDpcLevel PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TdiCopyMdlChainToMdlChain PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiCopyMdlToBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultChainedRcvDatagramHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultChainedRcvExpeditedHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultChainedReceiveHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultConnectHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultDisconnectHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultErrorHandler PROTO STDCALL :DWORD,:DWORD
TdiDefaultRcvDatagramHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultRcvExpeditedHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultReceiveHandler PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiDefaultSendPossibleHandler PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiDeregisterAddressChangeHandler PROTO STDCALL :DWORD
TdiDeregisterDeviceObject PROTO STDCALL :DWORD
TdiDeregisterNetAddress PROTO STDCALL :DWORD
TdiDeregisterNotificationHandler PROTO STDCALL :DWORD
TdiDeregisterPnPHandlers PROTO STDCALL :DWORD
TdiDeregisterProvider PROTO STDCALL :DWORD
TdiEnumerateAddresses PROTO STDCALL :DWORD
TdiInitialize PROTO STDCALL
TdiMapUserRequest PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiMatchPdoWithChainedReceiveContext PROTO STDCALL :DWORD,:DWORD
TdiOpenNetbiosAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TdiPnPPowerComplete PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiPnPPowerRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TdiProviderReady PROTO STDCALL :DWORD
TdiRegisterAddressChangeHandler PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiRegisterDeviceObject PROTO STDCALL :DWORD,:DWORD
TdiRegisterNetAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TdiRegisterNotificationHandler PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiRegisterPnPHandlers PROTO STDCALL :DWORD,:DWORD,:DWORD
TdiRegisterProvider PROTO STDCALL :DWORD,:DWORD
TdiReturnChainedReceives PROTO STDCALL :DWORD,:DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file tdi.inc
  echo --------------------------------------
ENDIF
