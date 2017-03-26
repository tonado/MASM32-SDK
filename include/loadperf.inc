; --------------------------------------------------------------------------------------------------
;                          loadperf.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LOADPERF_INC
LOADPERF_INC equ <1>

BackupPerfRegistryToFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BackupPerfRegistryToFile equ <BackupPerfRegistryToFileW>
ENDIF

InstallPerfDllA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InstallPerfDll equ <InstallPerfDllA>
ENDIF

InstallPerfDllW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InstallPerfDll equ <InstallPerfDllW>
ENDIF

LoadMofFromInstalledServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LoadMofFromInstalledService equ <LoadMofFromInstalledServiceA>
ENDIF

LoadMofFromInstalledServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadMofFromInstalledService equ <LoadMofFromInstalledServiceW>
ENDIF

LoadPerfCounterTextStringsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadPerfCounterTextStrings equ <LoadPerfCounterTextStringsA>
ENDIF

LoadPerfCounterTextStringsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LoadPerfCounterTextStrings equ <LoadPerfCounterTextStringsW>
ENDIF

RestorePerfRegistryFromFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RestorePerfRegistryFromFile equ <RestorePerfRegistryFromFileW>
ENDIF

SetServiceAsTrustedA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetServiceAsTrusted equ <SetServiceAsTrustedA>
ENDIF

SetServiceAsTrustedW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetServiceAsTrusted equ <SetServiceAsTrustedW>
ENDIF

UnloadPerfCounterTextStringsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UnloadPerfCounterTextStrings equ <UnloadPerfCounterTextStringsA>
ENDIF

UnloadPerfCounterTextStringsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UnloadPerfCounterTextStrings equ <UnloadPerfCounterTextStringsW>
ENDIF

UpdatePerfNameFilesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UpdatePerfNameFiles equ <UpdatePerfNameFilesA>
ENDIF

UpdatePerfNameFilesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UpdatePerfNameFiles equ <UpdatePerfNameFilesW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file loadperf.inc
  echo -------------------------------------------
ENDIF
