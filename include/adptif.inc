; --------------------------------------------------------------------------------------------------
;                           adptif.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ADPTIF_INC
ADPTIF_INC equ <1>

CreateSocketPort PROTO STDCALL :DWORD
DeleteSocketPort PROTO STDCALL :DWORD
FwBindFwInterfaceToAdapter PROTO STDCALL :DWORD,:DWORD
FwConnectionRequestFailed PROTO STDCALL :DWORD
FwCreateInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
FwDeleteInterface PROTO STDCALL :DWORD
FwDisableFwInterface PROTO STDCALL :DWORD
FwEnableFwInterface PROTO STDCALL :DWORD
FwGetInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
FwGetNotificationResult PROTO STDCALL :DWORD,:DWORD
FwGetStaticNetbiosNames PROTO STDCALL :DWORD,:DWORD,:DWORD
FwIsStarted PROTO STDCALL :DWORD
FwNotifyConnectionRequest PROTO STDCALL :DWORD,:DWORD,:DWORD
FwSetInterface PROTO STDCALL :DWORD,:DWORD
FwSetStaticNetbiosNames PROTO STDCALL :DWORD,:DWORD,:DWORD
FwStart PROTO STDCALL :DWORD,:DWORD
FwStop PROTO STDCALL
FwUnbindFwInterfaceFromAdapter PROTO STDCALL :DWORD
FwUpdateConfig PROTO STDCALL :DWORD
FwUpdateRouteTable PROTO STDCALL :DWORD,:DWORD,:DWORD

GetAdapterNameFromMacAddrW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAdapterNameFromMacAddr equ <GetAdapterNameFromMacAddrW>
ENDIF

GetAdapterNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAdapterName equ <GetAdapterNameW>
ENDIF

GetFilters PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxAdjustIoCompletionParams PROTO STDCALL :DWORD,:DWORD,:DWORD
IpxCreateAdapterConfigurationPort PROTO STDCALL :DWORD,:DWORD
IpxDeleteAdapterConfigurationPort PROTO STDCALL :DWORD
IpxDoesRouteExist PROTO STDCALL :DWORD,:DWORD
IpxGetAdapterConfig PROTO STDCALL :DWORD,:DWORD
IpxGetAdapterList PROTO STDCALL :DWORD,:DWORD,:DWORD
IpxGetOverlappedResult PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedAdapterConfigurationStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedCompletionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxPostQueuedCompletionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IpxRecvPacket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxSendPacket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxWanCreateAdapterConfigurationPort PROTO STDCALL :DWORD,:DWORD
IpxWanQueryInactivityTimer PROTO STDCALL :DWORD,:DWORD,:DWORD
IpxWanSetAdapterConfiguration PROTO STDCALL :DWORD,:DWORD
ServiceMain PROTO STDCALL :DWORD,:DWORD
SetFilters PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file adptif.inc
  echo -----------------------------------------
ENDIF
