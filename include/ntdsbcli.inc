; --------------------------------------------------------------------------------------------------
;                          ntdsbcli.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTDSBCLI_INC
NTDSBCLI_INC equ <1>

DllEntryPoint PROTO STDCALL :DWORD,:DWORD,:DWORD
DsBackupClose PROTO STDCALL :DWORD
DsBackupEnd PROTO STDCALL :DWORD
DsBackupFree PROTO STDCALL :DWORD

DsBackupGetBackupLogsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBackupGetBackupLogs equ <DsBackupGetBackupLogsA>
ENDIF

DsBackupGetBackupLogsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBackupGetBackupLogs equ <DsBackupGetBackupLogsW>
ENDIF

DsBackupGetDatabaseNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBackupGetDatabaseNames equ <DsBackupGetDatabaseNamesA>
ENDIF

DsBackupGetDatabaseNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBackupGetDatabaseNames equ <DsBackupGetDatabaseNamesW>
ENDIF

DsBackupOpenFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBackupOpenFile equ <DsBackupOpenFileA>
ENDIF

DsBackupOpenFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBackupOpenFile equ <DsBackupOpenFileW>
ENDIF

DsBackupPrepareA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBackupPrepare equ <DsBackupPrepareA>
ENDIF

DsBackupPrepareW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBackupPrepare equ <DsBackupPrepareW>
ENDIF

DsBackupRead PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DsBackupTruncateLogs PROTO STDCALL :DWORD

DsIsNTDSOnlineA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsIsNTDSOnline equ <DsIsNTDSOnlineA>
ENDIF

DsIsNTDSOnlineW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsIsNTDSOnline equ <DsIsNTDSOnlineW>
ENDIF

DsRestoreCheckExpiryToken PROTO STDCALL :DWORD,:DWORD
DsRestoreEnd PROTO STDCALL :DWORD

DsRestoreGetDatabaseLocationsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsRestoreGetDatabaseLocations equ <DsRestoreGetDatabaseLocationsA>
ENDIF

DsRestoreGetDatabaseLocationsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsRestoreGetDatabaseLocations equ <DsRestoreGetDatabaseLocationsW>
ENDIF

DsRestorePrepareA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsRestorePrepare equ <DsRestorePrepareA>
ENDIF

DsRestorePrepareW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsRestorePrepare equ <DsRestorePrepareW>
ENDIF

DsRestoreRegisterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsRestoreRegister equ <DsRestoreRegisterA>
ENDIF

DsRestoreRegisterComplete PROTO STDCALL :DWORD,:DWORD

DsRestoreRegisterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsRestoreRegister equ <DsRestoreRegisterW>
ENDIF

DsSetAuthIdentityA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsSetAuthIdentity equ <DsSetAuthIdentityA>
ENDIF

DsSetAuthIdentityW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsSetAuthIdentity equ <DsSetAuthIdentityW>
ENDIF

DsSetCurrentBackupLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsSetCurrentBackupLog equ <DsSetCurrentBackupLogA>
ENDIF

DsSetCurrentBackupLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsSetCurrentBackupLog equ <DsSetCurrentBackupLogW>
ENDIF

I_DsCheckBackupLogs PROTO STDCALL :DWORD

I_DsRestoreW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  I_DsRestore equ <I_DsRestoreW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file ntdsbcli.inc
  echo -------------------------------------------
ENDIF
