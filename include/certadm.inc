; --------------------------------------------------------------------------------------------------
;                           certadm.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CERTADM_INC
CERTADM_INC equ <1>

CertSrvBackupClose PROTO STDCALL :DWORD
CertSrvBackupEnd PROTO STDCALL :DWORD
CertSrvBackupFree PROTO STDCALL :DWORD

CertSrvBackupGetBackupLogsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvBackupGetBackupLogs equ <CertSrvBackupGetBackupLogsW>
ENDIF

CertSrvBackupGetDatabaseNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvBackupGetDatabaseNames equ <CertSrvBackupGetDatabaseNamesW>
ENDIF

CertSrvBackupGetDynamicFileListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvBackupGetDynamicFileList equ <CertSrvBackupGetDynamicFileListW>
ENDIF

CertSrvBackupOpenFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvBackupOpenFile equ <CertSrvBackupOpenFileW>
ENDIF

CertSrvBackupPrepareW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvBackupPrepare equ <CertSrvBackupPrepareW>
ENDIF

CertSrvBackupRead PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CertSrvBackupTruncateLogs PROTO STDCALL :DWORD

CertSrvIsServerOnlineW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvIsServerOnline equ <CertSrvIsServerOnlineW>
ENDIF

CertSrvRestoreEnd PROTO STDCALL :DWORD

CertSrvRestoreGetDatabaseLocationsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvRestoreGetDatabaseLocations equ <CertSrvRestoreGetDatabaseLocationsW>
ENDIF

CertSrvRestorePrepareW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvRestorePrepare equ <CertSrvRestorePrepareW>
ENDIF

CertSrvRestoreRegisterComplete PROTO STDCALL :DWORD,:DWORD
CertSrvRestoreRegisterThroughFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CertSrvRestoreRegisterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvRestoreRegister equ <CertSrvRestoreRegisterW>
ENDIF

CertSrvServerControlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CertSrvServerControl equ <CertSrvServerControlW>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file certadm.inc
  echo ------------------------------------------
ENDIF
