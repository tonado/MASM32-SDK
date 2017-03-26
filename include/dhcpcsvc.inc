; --------------------------------------------------------------------------------------------------
;                          dhcpcsvc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DHCPCSVC_INC
DHCPCSVC_INC equ <1>

DhcpAcquireParameters PROTO STDCALL :DWORD
DhcpAcquireParametersByBroadcast PROTO STDCALL :DWORD
DhcpCApiCleanup PROTO STDCALL
DhcpCApiInitialize PROTO STDCALL :DWORD
DhcpDeRegisterOptions PROTO STDCALL :DWORD
DhcpDeRegisterParamChange PROTO STDCALL :DWORD,:DWORD,:DWORD
DhcpDelPersistentRequestParams PROTO STDCALL :DWORD,:DWORD
DhcpEnumClasses PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DhcpFallbackRefreshParams PROTO STDCALL :DWORD
DhcpHandlePnPEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpLeaseIpAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpLeaseIpAddressEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpNotifyConfigChange PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpNotifyConfigChangeEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpNotifyMediaReconnected PROTO STDCALL :DWORD
DhcpOpenGlobalEvent PROTO STDCALL
DhcpPersistentRequestParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpQueryHWInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRegisterOptions PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DhcpRegisterParamChange PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpReleaseIpAddressLease PROTO STDCALL :DWORD,:DWORD
DhcpReleaseIpAddressLeaseEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DhcpReleaseParameters PROTO STDCALL :DWORD
DhcpRemoveDNSRegistrations PROTO STDCALL
DhcpRenewIpAddressLease PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DhcpRenewIpAddressLeaseEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRequestOptions PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRequestParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpStaticRefreshParams PROTO STDCALL :DWORD
DhcpUndoRequestParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
McastApiCleanup PROTO STDCALL
McastApiStartup PROTO STDCALL :DWORD
McastEnumerateScopes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
McastGenUID PROTO STDCALL :DWORD
McastReleaseAddress PROTO STDCALL :DWORD,:DWORD,:DWORD
McastRenewAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
McastRequestAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ServiceMain PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file dhcpcsvc.inc
  echo -------------------------------------------
ENDIF
