; --------------------------------------------------------------------------------------------------
;                          powrprof.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF POWRPROF_INC
POWRPROF_INC equ <1>

CallNtPowerInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CanUserWritePwrScheme PROTO STDCALL

DebugPrintA PROTO C :VARARG
IFNDEF __UNICODE__
  DebugPrint equ <DebugPrintA>
ENDIF

DeletePwrScheme PROTO STDCALL :DWORD
EnumPwrSchemes PROTO STDCALL :DWORD,:DWORD
GetActivePwrScheme PROTO STDCALL :DWORD
GetCurrentPowerPolicies PROTO STDCALL :DWORD,:DWORD
GetPwrCapabilities PROTO STDCALL :DWORD
GetPwrDiskSpindownRange PROTO STDCALL :DWORD,:DWORD
IsAdminOverrideActive PROTO STDCALL :DWORD
IsPwrHibernateAllowed PROTO STDCALL
IsPwrShutdownAllowed PROTO STDCALL
IsPwrSuspendAllowed PROTO STDCALL
LoadCurrentPwrScheme PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MergeLegacyPwrScheme PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ReadGlobalPwrPolicy PROTO STDCALL :DWORD
ReadProcessorPwrScheme PROTO STDCALL :DWORD,:DWORD
ReadPwrScheme PROTO STDCALL :DWORD,:DWORD
SetActivePwrScheme PROTO STDCALL :DWORD,:DWORD,:DWORD
SetSuspendState PROTO STDCALL :DWORD,:DWORD,:DWORD
ValidatePowerPolicies PROTO STDCALL :DWORD,:DWORD
WriteGlobalPwrPolicy PROTO STDCALL :DWORD
WriteProcessorPwrScheme PROTO STDCALL :DWORD,:DWORD
WritePwrScheme PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file powrprof.inc
  echo -------------------------------------------
ENDIF
