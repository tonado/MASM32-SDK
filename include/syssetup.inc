; --------------------------------------------------------------------------------------------------
;                          syssetup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SYSSETUP_INC
SYSSETUP_INC equ <1>

AsrAddSifEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AsrAddSifEntry equ <AsrAddSifEntryA>
ENDIF

AsrAddSifEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AsrAddSifEntry equ <AsrAddSifEntryW>
ENDIF

AsrCreateStateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AsrCreateStateFile equ <AsrCreateStateFileA>
ENDIF

AsrCreateStateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AsrCreateStateFile equ <AsrCreateStateFileW>
ENDIF

AsrFreeContext PROTO STDCALL :DWORD
AsrRestorePlugPlayRegistryData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AsrpGetLocalDiskInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AsrpGetLocalVolumeInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AsrpRestoreNonCriticalDisksW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  AsrpRestoreNonCriticalDisks equ <AsrpRestoreNonCriticalDisksW>
ENDIF

CdromPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
ComputerClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateLocalAdminAccount PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateLocalAdminAccountEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreateLocalUserAccount PROTO STDCALL :DWORD,:DWORD,:DWORD
CriticalDeviceCoInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

DevInstallW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DevInstall equ <DevInstallW>
ENDIF

DeviceBayClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
DiskPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
DoInstallComponentInfs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EisaUpHalCoInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
EisaUpHalPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
GenerateName PROTO STDCALL :DWORD,:DWORD
HdcClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeSetupLog PROTO STDCALL :DWORD
InstallWindowsNt PROTO STDCALL :DWORD,:DWORD
InvokeExternalApplicationEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeyboardClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
LegacyDriverPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
MigrateExceptionPackages PROTO STDCALL :DWORD,:DWORD,:DWORD
MouseClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
NtApmClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
OpkCheckVersion PROTO STDCALL :DWORD,:DWORD
PS2MousePropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
PnPInitializationThread PROTO STDCALL :DWORD
PrepareForAudit PROTO STDCALL
RepairStartMenuItems PROTO STDCALL
ReportError PROTO C :VARARG
RunOEMExtraTasks PROTO STDCALL
ScsiClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
SetAccountsDomainSid PROTO STDCALL :DWORD,:DWORD
SetupAddOrRemoveTestCertificate PROTO STDCALL :DWORD,:DWORD
SetupChangeFontSize PROTO STDCALL :DWORD,:DWORD
SetupChangeLocale PROTO STDCALL :DWORD,:DWORD
SetupChangeLocaleEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCreateOptionalComponentsPage PROTO STDCALL :DWORD,:DWORD
SetupDestroyLanguageList PROTO STDCALL :DWORD,:DWORD
SetupDestroyPhoneList PROTO STDCALL
SetupEnumerateRegisteredOsComponents PROTO STDCALL :DWORD,:DWORD
SetupExtendPartition PROTO STDCALL :DWORD,:DWORD
SetupGetGeoOptions PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetupGetKeyboardOptions PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetupGetLocaleOptions PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetupGetProductType PROTO STDCALL :DWORD,:DWORD
SetupGetSetupInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetValidEula PROTO STDCALL :DWORD,:DWORD

SetupInfObjectInstallActionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupInfObjectInstallAction equ <SetupInfObjectInstallActionW>
ENDIF

SetupInstallCatalog PROTO STDCALL :DWORD
SetupMapTapiToIso PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupOobeBnk PROTO STDCALL :DWORD
SetupOobeCleanup PROTO STDCALL :DWORD
SetupOobeInitDebugLog PROTO STDCALL
SetupOobeInitPostServices PROTO STDCALL :DWORD
SetupOobeInitPreServices PROTO STDCALL :DWORD
SetupPidGen3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryRegisteredOsComponent PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupQueryRegisteredOsComponentsOrder PROTO STDCALL :DWORD,:DWORD
SetupReadPhoneList PROTO STDCALL :DWORD
SetupRegisterOsComponent PROTO STDCALL :DWORD,:DWORD
SetupSetAdminPassword PROTO STDCALL :DWORD,:DWORD
SetupSetDisplay PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupSetIntlOptions PROTO STDCALL :DWORD,:DWORD,:DWORD
SetupSetRegisteredOsComponentsOrder PROTO STDCALL :DWORD,:DWORD
SetupSetSetupInfo PROTO STDCALL :DWORD,:DWORD
SetupShellSettings PROTO STDCALL :DWORD,:DWORD
SetupStartService PROTO STDCALL :DWORD,:DWORD
SetupUnRegisterOsComponent PROTO STDCALL :DWORD
StorageCoInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SystemUpdateUserProfileDirectory PROTO STDCALL :DWORD
TapeClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
TapePropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
TerminateSetupLog PROTO STDCALL :DWORD
UpdatePnpDeviceDrivers PROTO STDCALL
UpgradePrinters PROTO STDCALL
ViewSetupActionLog PROTO STDCALL :DWORD,:DWORD,:DWORD
VolumeClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
pSetupDebugPrint PROTO C :VARARG
pSetuplogSfcError PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file syssetup.inc
  echo -------------------------------------------
ENDIF
