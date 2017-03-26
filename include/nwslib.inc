; --------------------------------------------------------------------------------------------------
;                           nwslib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NWSLIB_INC
NWSLIB_INC equ <1>

CloseNcpSrvPerformanceData PROTO STDCALL
CollectNcpSrvPerformanceData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreateNewSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
JobRightsMapping PROTO C :VARARG
MapNwRightsToNTAccess PROTO STDCALL :DWORD,:DWORD,:DWORD
MapSpecificToGeneric PROTO STDCALL :DWORD,:DWORD
NwAddRight PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NwCheckTrusteeRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NwRemoveRight PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NwScanTrustees PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenNcpSrvPerformanceData PROTO STDCALL :DWORD
  ; PrintRightsMapping arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file nwslib.inc
  echo -----------------------------------------
ENDIF
