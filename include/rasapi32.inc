; --------------------------------------------------------------------------------------------------
;                          rasapi32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RASAPI32_INC
RASAPI32_INC equ <1>

DDMGetPhonebookInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DwCloneEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
DwDeleteSubEntry PROTO STDCALL :DWORD,:DWORD,:DWORD
DwEnumEntriesForAllUsers PROTO STDCALL :DWORD,:DWORD,:DWORD
DwEnumEntryDetails PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DwRasRefreshKerbScCreds PROTO STDCALL :DWORD
DwRasUninitialize PROTO STDCALL
RasAutoDialSharedConnection PROTO STDCALL
RasAutodialAddressToNetwork PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAutodialEntryToNetwork PROTO STDCALL :DWORD,:DWORD,:DWORD
RasClearConnectionStatistics PROTO STDCALL :DWORD
RasClearLinkStatistics PROTO STDCALL :DWORD,:DWORD

RasConnectionNotificationA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasConnectionNotification equ <RasConnectionNotificationA>
ENDIF

RasConnectionNotificationW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasConnectionNotification equ <RasConnectionNotificationW>
ENDIF

RasCreatePhonebookEntryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasCreatePhonebookEntry equ <RasCreatePhonebookEntryA>
ENDIF

RasCreatePhonebookEntryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasCreatePhonebookEntry equ <RasCreatePhonebookEntryW>
ENDIF

RasDeleteEntryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasDeleteEntry equ <RasDeleteEntryA>
ENDIF

RasDeleteEntryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasDeleteEntry equ <RasDeleteEntryW>
ENDIF

RasDeleteSubEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasDeleteSubEntry equ <RasDeleteSubEntryA>
ENDIF

RasDeleteSubEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasDeleteSubEntry equ <RasDeleteSubEntryW>
ENDIF

RasDialA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasDial equ <RasDialA>
ENDIF

RasDialW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasDial equ <RasDialW>
ENDIF

RasDialWow PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

RasEditPhonebookEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEditPhonebookEntry equ <RasEditPhonebookEntryA>
ENDIF

RasEditPhonebookEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEditPhonebookEntry equ <RasEditPhonebookEntryW>
ENDIF

RasEnumAutodialAddressesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEnumAutodialAddresses equ <RasEnumAutodialAddressesA>
ENDIF

RasEnumAutodialAddressesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEnumAutodialAddresses equ <RasEnumAutodialAddressesW>
ENDIF

RasEnumConnectionsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEnumConnections equ <RasEnumConnectionsA>
ENDIF

RasEnumConnectionsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEnumConnections equ <RasEnumConnectionsW>
ENDIF

RasEnumConnectionsWow PROTO STDCALL :DWORD,:DWORD,:DWORD

RasEnumDevicesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEnumDevices equ <RasEnumDevicesA>
ENDIF

RasEnumDevicesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEnumDevices equ <RasEnumDevicesW>
ENDIF

RasEnumEntriesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEnumEntries equ <RasEnumEntriesA>
ENDIF

RasEnumEntriesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEnumEntries equ <RasEnumEntriesW>
ENDIF

RasEnumEntriesWow PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

RasFreeEapUserIdentityA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RasFreeEapUserIdentity equ <RasFreeEapUserIdentityA>
ENDIF

RasFreeEapUserIdentityW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RasFreeEapUserIdentity equ <RasFreeEapUserIdentityW>
ENDIF

RasGetAutodialAddressA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetAutodialAddress equ <RasGetAutodialAddressA>
ENDIF

RasGetAutodialAddressW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetAutodialAddress equ <RasGetAutodialAddressW>
ENDIF

RasGetAutodialEnableA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetAutodialEnable equ <RasGetAutodialEnableA>
ENDIF

RasGetAutodialEnableW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasGetAutodialEnable equ <RasGetAutodialEnableW>
ENDIF

RasGetAutodialParamA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetAutodialParam equ <RasGetAutodialParamA>
ENDIF

RasGetAutodialParamW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetAutodialParam equ <RasGetAutodialParamW>
ENDIF

RasGetConnectResponse PROTO STDCALL :DWORD,:DWORD

RasGetConnectStatusA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetConnectStatus equ <RasGetConnectStatusA>
ENDIF

RasGetConnectStatusW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasGetConnectStatus equ <RasGetConnectStatusW>
ENDIF

RasGetConnectStatusWow PROTO STDCALL :DWORD,:DWORD
RasGetConnectionStatistics PROTO STDCALL :DWORD,:DWORD

RasGetCountryInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetCountryInfo equ <RasGetCountryInfoA>
ENDIF

RasGetCountryInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasGetCountryInfo equ <RasGetCountryInfoW>
ENDIF

RasGetCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetCredentials equ <RasGetCredentialsA>
ENDIF

RasGetCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetCredentials equ <RasGetCredentialsW>
ENDIF

RasGetCustomAuthDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetCustomAuthData equ <RasGetCustomAuthDataA>
ENDIF

RasGetCustomAuthDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetCustomAuthData equ <RasGetCustomAuthDataW>
ENDIF

RasGetEapUserDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetEapUserData equ <RasGetEapUserDataA>
ENDIF

RasGetEapUserDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetEapUserData equ <RasGetEapUserDataW>
ENDIF

RasGetEapUserIdentityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetEapUserIdentity equ <RasGetEapUserIdentityA>
ENDIF

RasGetEapUserIdentityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetEapUserIdentity equ <RasGetEapUserIdentityW>
ENDIF

RasGetEntryDialParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetEntryDialParams equ <RasGetEntryDialParamsA>
ENDIF

RasGetEntryDialParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetEntryDialParams equ <RasGetEntryDialParamsW>
ENDIF

RasGetEntryHrasconnA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetEntryHrasconn equ <RasGetEntryHrasconnA>
ENDIF

RasGetEntryHrasconnW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetEntryHrasconn equ <RasGetEntryHrasconnW>
ENDIF

RasGetEntryPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetEntryProperties equ <RasGetEntryPropertiesA>
ENDIF

RasGetEntryPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetEntryProperties equ <RasGetEntryPropertiesW>
ENDIF

RasGetErrorStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetErrorString equ <RasGetErrorStringA>
ENDIF

RasGetErrorStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetErrorString equ <RasGetErrorStringW>
ENDIF

RasGetErrorStringWow PROTO STDCALL :DWORD,:DWORD,:DWORD
RasGetHport PROTO STDCALL :DWORD
RasGetLinkStatistics PROTO STDCALL :DWORD,:DWORD,:DWORD

RasGetProjectionInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetProjectionInfo equ <RasGetProjectionInfoA>
ENDIF

RasGetProjectionInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetProjectionInfo equ <RasGetProjectionInfoW>
ENDIF

RasGetSubEntryHandleA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetSubEntryHandle equ <RasGetSubEntryHandleA>
ENDIF

RasGetSubEntryHandleW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetSubEntryHandle equ <RasGetSubEntryHandleW>
ENDIF

RasGetSubEntryPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasGetSubEntryProperties equ <RasGetSubEntryPropertiesA>
ENDIF

RasGetSubEntryPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasGetSubEntryProperties equ <RasGetSubEntryPropertiesW>
ENDIF

RasHangUpA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RasHangUp equ <RasHangUpA>
ENDIF

RasHangUpW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RasHangUp equ <RasHangUpW>
ENDIF

RasHangUpWow PROTO STDCALL :DWORD
RasInvokeEapUI PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RasIsRouterConnection PROTO STDCALL :DWORD
RasIsSharedConnection PROTO STDCALL :DWORD,:DWORD
RasQueryRedialOnLinkFailure PROTO STDCALL :DWORD,:DWORD,:DWORD
RasQuerySharedAutoDial PROTO STDCALL :DWORD
RasQuerySharedConnection PROTO STDCALL :DWORD

RasRenameEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasRenameEntry equ <RasRenameEntryA>
ENDIF

RasRenameEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasRenameEntry equ <RasRenameEntryW>
ENDIF

RasScriptExecute PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasScriptGetEventCode PROTO STDCALL :DWORD
RasScriptGetIpAddress PROTO STDCALL :DWORD,:DWORD
RasScriptInit PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasScriptReceive PROTO STDCALL :DWORD,:DWORD,:DWORD
RasScriptSend PROTO STDCALL :DWORD,:DWORD,:DWORD
RasScriptTerm PROTO STDCALL :DWORD

RasSetAutodialAddressA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetAutodialAddress equ <RasSetAutodialAddressA>
ENDIF

RasSetAutodialAddressW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetAutodialAddress equ <RasSetAutodialAddressW>
ENDIF

RasSetAutodialEnableA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetAutodialEnable equ <RasSetAutodialEnableA>
ENDIF

RasSetAutodialEnableW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasSetAutodialEnable equ <RasSetAutodialEnableW>
ENDIF

RasSetAutodialParamA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetAutodialParam equ <RasSetAutodialParamA>
ENDIF

RasSetAutodialParamW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetAutodialParam equ <RasSetAutodialParamW>
ENDIF

RasSetCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetCredentials equ <RasSetCredentialsA>
ENDIF

RasSetCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetCredentials equ <RasSetCredentialsW>
ENDIF

RasSetCustomAuthDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetCustomAuthData equ <RasSetCustomAuthDataA>
ENDIF

RasSetCustomAuthDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetCustomAuthData equ <RasSetCustomAuthDataW>
ENDIF

RasSetEapUserDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetEapUserData equ <RasSetEapUserDataA>
ENDIF

RasSetEapUserDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetEapUserData equ <RasSetEapUserDataW>
ENDIF

RasSetEntryDialParamsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetEntryDialParams equ <RasSetEntryDialParamsA>
ENDIF

RasSetEntryDialParamsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetEntryDialParams equ <RasSetEntryDialParamsW>
ENDIF

RasSetEntryPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetEntryProperties equ <RasSetEntryPropertiesA>
ENDIF

RasSetEntryPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetEntryProperties equ <RasSetEntryPropertiesW>
ENDIF

RasSetOldPassword PROTO STDCALL :DWORD,:DWORD
RasSetSharedAutoDial PROTO STDCALL :DWORD

RasSetSubEntryPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasSetSubEntryProperties equ <RasSetSubEntryPropertiesA>
ENDIF

RasSetSubEntryPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasSetSubEntryProperties equ <RasSetSubEntryPropertiesW>
ENDIF

RasValidateEntryNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasValidateEntryName equ <RasValidateEntryNameA>
ENDIF

RasValidateEntryNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasValidateEntryName equ <RasValidateEntryNameW>
ENDIF

RasfileClose PROTO STDCALL :DWORD
RasfileDeleteLine PROTO STDCALL :DWORD
RasfileFindFirstLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileFindLastLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileFindMarkedLine PROTO STDCALL :DWORD,:DWORD
RasfileFindNextKeyLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileFindNextLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileFindPrevLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileFindSectionLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileGetKeyValueFields PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileGetLine PROTO STDCALL :DWORD
RasfileGetLineMark PROTO STDCALL :DWORD
RasfileGetLineText PROTO STDCALL :DWORD,:DWORD
RasfileGetLineType PROTO STDCALL :DWORD
RasfileGetSectionName PROTO STDCALL :DWORD,:DWORD
RasfileInsertLine PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfileLoad PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RasfileLoadInfo PROTO STDCALL :DWORD,:DWORD
RasfilePutKeyValueFields PROTO STDCALL :DWORD,:DWORD,:DWORD
RasfilePutLineMark PROTO STDCALL :DWORD,:DWORD
RasfilePutLineText PROTO STDCALL :DWORD,:DWORD
RasfilePutSectionName PROTO STDCALL :DWORD,:DWORD
RasfileWrite PROTO STDCALL :DWORD,:DWORD
SharedAccessResponseListToString PROTO STDCALL :DWORD,:DWORD
SharedAccessResponseStringToList PROTO STDCALL :DWORD,:DWORD,:DWORD
UnInitializeRAS PROTO STDCALL

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file rasapi32.inc
  echo -------------------------------------------
ENDIF
