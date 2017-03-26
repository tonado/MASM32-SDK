; --------------------------------------------------------------------------------------------------
;                           winsta.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINSTA_INC
WINSTA_INC equ <1>

LogonIdFromWinStationNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LogonIdFromWinStationName equ <LogonIdFromWinStationNameA>
ENDIF

LogonIdFromWinStationNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogonIdFromWinStationName equ <LogonIdFromWinStationNameW>
ENDIF

RemoteAssistancePrepareSystemRestore PROTO STDCALL :DWORD
ServerGetInternetConnectorStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
ServerLicensingClose PROTO STDCALL :DWORD
ServerLicensingDeactivateCurrentPolicy PROTO STDCALL :DWORD
ServerLicensingFreePolicyInformation PROTO STDCALL :DWORD
ServerLicensingGetAvailablePolicyIds PROTO STDCALL :DWORD,:DWORD,:DWORD
ServerLicensingGetPolicy PROTO STDCALL :DWORD,:DWORD

ServerLicensingGetPolicyInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ServerLicensingGetPolicyInformation equ <ServerLicensingGetPolicyInformationA>
ENDIF

ServerLicensingGetPolicyInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ServerLicensingGetPolicyInformation equ <ServerLicensingGetPolicyInformationW>
ENDIF

ServerLicensingLoadPolicy PROTO STDCALL :DWORD,:DWORD

ServerLicensingOpenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  ServerLicensingOpen equ <ServerLicensingOpenA>
ENDIF

ServerLicensingOpenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  ServerLicensingOpen equ <ServerLicensingOpenW>
ENDIF

ServerLicensingSetPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD
ServerLicensingUnloadPolicy PROTO STDCALL :DWORD,:DWORD

ServerQueryInetConnectorInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ServerQueryInetConnectorInformation equ <ServerQueryInetConnectorInformationA>
ENDIF

ServerQueryInetConnectorInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ServerQueryInetConnectorInformation equ <ServerQueryInetConnectorInformationW>
ENDIF

ServerSetInternetConnectorStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationActivateLicense PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WinStationAutoReconnect PROTO STDCALL :DWORD
WinStationBroadcastSystemMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinStationCheckLoopBack PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WinStationCloseServer PROTO STDCALL :DWORD

WinStationConnectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationConnect equ <WinStationConnectA>
ENDIF

WinStationConnectCallback PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WinStationConnectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationConnect equ <WinStationConnectW>
ENDIF

WinStationDisconnect PROTO STDCALL :DWORD,:DWORD,:DWORD

WinStationEnumerateA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationEnumerate equ <WinStationEnumerateA>
ENDIF

WinStationEnumerateLicenses PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationEnumerateProcesses PROTO STDCALL :DWORD,:DWORD

WinStationEnumerateW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationEnumerate equ <WinStationEnumerateW>
ENDIF

WinStationEnumerate_IndexedA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationEnumerate_Indexed equ <WinStationEnumerate_IndexedA>
ENDIF

WinStationEnumerate_IndexedW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationEnumerate_Indexed equ <WinStationEnumerate_IndexedW>
ENDIF

WinStationFreeGAPMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationFreeMemory PROTO STDCALL :DWORD
WinStationGenerateLicense PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WinStationGetAllProcesses PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

WinStationGetLanAdapterNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationGetLanAdapterName equ <WinStationGetLanAdapterNameA>
ENDIF

WinStationGetLanAdapterNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationGetLanAdapterName equ <WinStationGetLanAdapterNameW>
ENDIF

WinStationGetMachinePolicy PROTO STDCALL :DWORD,:DWORD
WinStationGetProcessSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinStationGetTermSrvCountersValue PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationInstallLicense PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationIsHelpAssistantSession PROTO STDCALL :DWORD,:DWORD

WinStationNameFromLogonIdA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationNameFromLogonId equ <WinStationNameFromLogonIdA>
ENDIF

WinStationNameFromLogonIdW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationNameFromLogonId equ <WinStationNameFromLogonIdW>
ENDIF

WinStationNtsdDebug PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WinStationOpenServerA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  WinStationOpenServer equ <WinStationOpenServerA>
ENDIF

WinStationOpenServerW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  WinStationOpenServer equ <WinStationOpenServerW>
ENDIF

WinStationQueryInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationQueryInformation equ <WinStationQueryInformationA>
ENDIF

WinStationQueryInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationQueryInformation equ <WinStationQueryInformationW>
ENDIF

WinStationQueryLicense PROTO STDCALL :DWORD,:DWORD,:DWORD

WinStationQueryLogonCredentialsW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  WinStationQueryLogonCredentials equ <WinStationQueryLogonCredentialsW>
ENDIF

WinStationQueryUpdateRequired PROTO STDCALL :DWORD,:DWORD
WinStationRegisterConsoleNotification PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationRemoveLicense PROTO STDCALL :DWORD,:DWORD,:DWORD

WinStationRenameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationRename equ <WinStationRenameA>
ENDIF

WinStationRenameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationRename equ <WinStationRenameW>
ENDIF

WinStationRequestSessionsList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WinStationReset PROTO STDCALL :DWORD,:DWORD,:DWORD

WinStationSendMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationSendMessage equ <WinStationSendMessageA>
ENDIF

WinStationSendMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationSendMessage equ <WinStationSendMessageW>
ENDIF

WinStationSendWindowMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinStationServerPing PROTO STDCALL :DWORD

WinStationSetInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WinStationSetInformation equ <WinStationSetInformationA>
ENDIF

WinStationSetInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WinStationSetInformation equ <WinStationSetInformationW>
ENDIF

WinStationSetPoolCount PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationShadow PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinStationShadowStop PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationShutdownSystem PROTO STDCALL :DWORD,:DWORD
WinStationTerminateProcess PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationUnRegisterConsoleNotification PROTO STDCALL :DWORD,:DWORD
WinStationVirtualOpen PROTO STDCALL :DWORD,:DWORD,:DWORD
WinStationWaitSystemEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
_NWLogonQueryAdmin PROTO STDCALL :DWORD,:DWORD,:DWORD
_NWLogonSetAdmin PROTO STDCALL :DWORD,:DWORD,:DWORD
_WinStationAnnoyancePopup PROTO STDCALL :DWORD,:DWORD
_WinStationBeepOpen PROTO STDCALL :DWORD
_WinStationBreakPoint PROTO STDCALL :DWORD,:DWORD,:DWORD
_WinStationCallback PROTO STDCALL :DWORD,:DWORD,:DWORD
_WinStationCheckForApplicationName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WinStationFUSCanRemoteUserDisconnect PROTO STDCALL :DWORD,:DWORD,:DWORD
_WinStationGetApplicationInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
_WinStationNotifyDisconnectPipe PROTO STDCALL
_WinStationNotifyLogoff PROTO STDCALL
_WinStationNotifyLogon PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WinStationNotifyNewSession PROTO STDCALL :DWORD,:DWORD
_WinStationReInitializeSecurity PROTO STDCALL :DWORD
_WinStationReadRegistry PROTO STDCALL :DWORD
_WinStationShadowTarget PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WinStationShadowTargetSetup PROTO STDCALL :DWORD,:DWORD
_WinStationUpdateClientCachedCredentials PROTO STDCALL :DWORD,:DWORD
_WinStationUpdateSettings PROTO STDCALL :DWORD,:DWORD,:DWORD
_WinStationUpdateUserConfig PROTO STDCALL :DWORD
_WinStationWaitForConnect PROTO STDCALL

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file winsta.inc
  echo -----------------------------------------
ENDIF
