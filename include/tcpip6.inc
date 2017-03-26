; --------------------------------------------------------------------------------------------------
;                           tcpip6.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TCPIP6_INC
TCPIP6_INC equ <1>

AdjustPacketBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
DestroyInterface PROTO STDCALL :DWORD
IPv6DisableFirewallHook PROTO STDCALL :DWORD
IPv6EnableFirewallHook PROTO STDCALL :DWORD
IPv6GetBestRouteInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IPv6ObtainPacketData PROTO STDCALL :DWORD,:DWORD,:DWORD
IPv6Receive PROTO STDCALL :DWORD
IPv6ReceiveComplete PROTO STDCALL
IPv6SendComplete PROTO STDCALL :DWORD,:DWORD,:DWORD
ReleaseInterface PROTO STDCALL :DWORD
RestartLinkLayerMulticast PROTO STDCALL :DWORD,:DWORD
SetInterfaceLinkStatus PROTO STDCALL :DWORD,:DWORD
UndoAdjustPacketBuffer PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file tcpip6.inc
  echo -----------------------------------------
ENDIF
