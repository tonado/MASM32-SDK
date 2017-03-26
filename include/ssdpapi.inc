; --------------------------------------------------------------------------------------------------
;                           ssdpapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SSDPAPI_INC
SSDPAPI_INC equ <1>

CleanupCache PROTO STDCALL
DHDisableDeviceHost PROTO STDCALL
DHEnableDeviceHost PROTO STDCALL
DHSetICSInterfaces PROTO STDCALL :DWORD,:DWORD
DHSetICSOff PROTO STDCALL
DeregisterNotification PROTO STDCALL :DWORD
DeregisterService PROTO STDCALL :DWORD,:DWORD
DeregisterServiceByUSN PROTO STDCALL :DWORD,:DWORD
FindServices PROTO STDCALL :DWORD,:DWORD,:DWORD
FindServicesCallback PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindServicesCancel PROTO STDCALL :DWORD
FindServicesClose PROTO STDCALL :DWORD
FreeSsdpMessage PROTO STDCALL :DWORD
GetFirstService PROTO STDCALL :DWORD,:DWORD
GetNextService PROTO STDCALL :DWORD,:DWORD
RegisterNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterService PROTO STDCALL :DWORD,:DWORD
SsdpCleanup PROTO STDCALL
SsdpStartup PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ssdpapi.inc
  echo ------------------------------------------
ENDIF
