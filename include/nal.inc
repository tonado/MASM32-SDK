; --------------------------------------------------------------------------------------------------
;                             nal.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NAL_INC
NAL_INC equ <1>

AllocNetworkBuffer PROTO STDCALL :DWORD,:DWORD
CancelTransmit PROTO STDCALL :DWORD,:DWORD
ClearStatistics PROTO STDCALL :DWORD
CloseNetwork PROTO STDCALL :DWORD,:DWORD
CompactNetworkBuffer PROTO STDCALL :DWORD
ContinueCapturing PROTO STDCALL :DWORD
DestroyNetworkID PROTO STDCALL :DWORD
EnumNetworks PROTO STDCALL
FreeNetworkBuffer PROTO STDCALL :DWORD
GetBufferSize PROTO STDCALL :DWORD
GetBufferTimeStamp PROTO STDCALL :DWORD,:DWORD
GetBufferTotalBytesCaptured PROTO STDCALL :DWORD
GetBufferTotalFramesCaptured PROTO STDCALL :DWORD
GetNetworkBuffer PROTO STDCALL :DWORD
GetNetworkCallback PROTO STDCALL :DWORD
GetNetworkFrame PROTO STDCALL :DWORD,:DWORD
GetNetworkID PROTO STDCALL :DWORD
GetNetworkInfo PROTO STDCALL :DWORD
GetNetworkInstanceData PROTO STDCALL :DWORD
GetReconnectInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NetworkProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenNetwork PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PauseCapturing PROTO STDCALL :DWORD
QueryNetworkStatus PROTO STDCALL :DWORD,:DWORD
SetNetworkBuffer PROTO STDCALL :DWORD,:DWORD
SetNetworkCallback PROTO STDCALL :DWORD,:DWORD
SetNetworkFilter PROTO STDCALL :DWORD,:DWORD,:DWORD
SetNetworkInstanceData PROTO STDCALL :DWORD,:DWORD
SetReconnectInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupNetwork PROTO STDCALL :DWORD,:DWORD
StartCapturing PROTO STDCALL :DWORD,:DWORD
StationQuery PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StopCapturing PROTO STDCALL :DWORD
TransmitQueue PROTO STDCALL :DWORD,:DWORD
TransmitSpecialFrame PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file nal.inc
  echo --------------------------------------
ENDIF
