; --------------------------------------------------------------------------------------------------
;                           newdev.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NEWDEV_INC
NEWDEV_INC equ <1>

ClientSideInstallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ClientSideInstall equ <ClientSideInstallW>
ENDIF

DevInstallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DevInstall equ <DevInstallW>
ENDIF

InstallDevInst PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
InstallDevInstEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InstallNewDevice PROTO STDCALL :DWORD,:DWORD,:DWORD
InstallSelectedDevice PROTO STDCALL :DWORD,:DWORD,:DWORD
InstallSelectedDriver PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InstallWindowsUpdateDriver PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RollbackDriver PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

UpdateDriverForPlugAndPlayDevicesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UpdateDriverForPlugAndPlayDevices equ <UpdateDriverForPlugAndPlayDevicesA>
ENDIF

UpdateDriverForPlugAndPlayDevicesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UpdateDriverForPlugAndPlayDevices equ <UpdateDriverForPlugAndPlayDevicesW>
ENDIF

WindowsUpdateDriverSearchingPolicyUi PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file newdev.inc
  echo -----------------------------------------
ENDIF
