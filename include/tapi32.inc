; --------------------------------------------------------------------------------------------------
;                           tapi32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TAPI32_INC
TAPI32_INC equ <1>

GetTapi16CallbackMsg PROTO STDCALL :DWORD,:DWORD
LAddrParamsInited PROTO STDCALL :DWORD
LOpenDialAsst PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LocWizardDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MMCAddProvider PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MMCConfigProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
MMCGetAvailableProviders PROTO STDCALL :DWORD,:DWORD
MMCGetDeviceFlags PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MMCGetLineInfo PROTO STDCALL :DWORD,:DWORD
MMCGetLineStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MMCGetPhoneInfo PROTO STDCALL :DWORD,:DWORD
MMCGetPhoneStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MMCGetProviderList PROTO STDCALL :DWORD,:DWORD
MMCGetServerConfig PROTO STDCALL :DWORD,:DWORD
MMCInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MMCRemoveProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
MMCSetLineInfo PROTO STDCALL :DWORD,:DWORD
MMCSetPhoneInfo PROTO STDCALL :DWORD,:DWORD
MMCSetServerConfig PROTO STDCALL :DWORD,:DWORD
MMCShutdown PROTO STDCALL :DWORD
NonAsyncEventThread PROTO STDCALL
TAPIWndProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TUISPIDLLCallback PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
internalConfig PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
internalCreateDefLocation PROTO STDCALL :DWORD

internalNewLocationW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  internalNewLocation equ <internalNewLocationW>
ENDIF

internalPerformance PROTO STDCALL :DWORD
internalRemoveLocation PROTO STDCALL :DWORD

internalRenameLocationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  internalRenameLocation equ <internalRenameLocationW>
ENDIF

lineAccept PROTO STDCALL :DWORD,:DWORD,:DWORD

lineAddProviderA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineAddProvider equ <lineAddProviderA>
ENDIF

lineAddProviderW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineAddProvider equ <lineAddProviderW>
ENDIF

lineAddToConference PROTO STDCALL :DWORD,:DWORD
lineAgentSpecific PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineAnswer PROTO STDCALL :DWORD,:DWORD,:DWORD

lineBlindTransferA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineBlindTransfer equ <lineBlindTransferA>
ENDIF

lineBlindTransferW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineBlindTransfer equ <lineBlindTransferW>
ENDIF

lineClose PROTO STDCALL :DWORD
lineCompleteCall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineCompleteTransfer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

lineConfigDialogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineConfigDialog equ <lineConfigDialogA>
ENDIF


lineConfigDialogEditA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineConfigDialogEdit equ <lineConfigDialogEditA>
ENDIF

lineConfigDialogEditW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineConfigDialogEdit equ <lineConfigDialogEditW>
ENDIF

lineConfigDialogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineConfigDialog equ <lineConfigDialogW>
ENDIF

lineConfigProvider PROTO STDCALL :DWORD,:DWORD

lineCreateAgentA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineCreateAgent equ <lineCreateAgentA>
ENDIF

lineCreateAgentSessionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineCreateAgentSession equ <lineCreateAgentSessionA>
ENDIF

lineCreateAgentSessionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineCreateAgentSession equ <lineCreateAgentSessionW>
ENDIF

lineCreateAgentW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineCreateAgent equ <lineCreateAgentW>
ENDIF

lineDeallocateCall PROTO STDCALL :DWORD
lineDevSpecific PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineDevSpecificFeature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

lineDialA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineDial equ <lineDialA>
ENDIF

lineDialW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineDial equ <lineDialW>
ENDIF

lineDrop PROTO STDCALL :DWORD,:DWORD,:DWORD

lineForwardA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineForward equ <lineForwardA>
ENDIF

lineForwardW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineForward equ <lineForwardW>
ENDIF


lineGatherDigitsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGatherDigits equ <lineGatherDigitsA>
ENDIF

lineGatherDigitsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGatherDigits equ <lineGatherDigitsW>
ENDIF


lineGenerateDigitsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGenerateDigits equ <lineGenerateDigitsA>
ENDIF

lineGenerateDigitsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGenerateDigits equ <lineGenerateDigitsW>
ENDIF

lineGenerateTone PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lineGetAddressCapsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAddressCaps equ <lineGetAddressCapsA>
ENDIF

lineGetAddressCapsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAddressCaps equ <lineGetAddressCapsW>
ENDIF


lineGetAddressIDA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAddressID equ <lineGetAddressIDA>
ENDIF

lineGetAddressIDW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAddressID equ <lineGetAddressIDW>
ENDIF


lineGetAddressStatusA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAddressStatus equ <lineGetAddressStatusA>
ENDIF

lineGetAddressStatusW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAddressStatus equ <lineGetAddressStatusW>
ENDIF

lineGetAgentActivityListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAgentActivityList equ <lineGetAgentActivityListA>
ENDIF

lineGetAgentActivityListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAgentActivityList equ <lineGetAgentActivityListW>
ENDIF

lineGetAgentCapsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAgentCaps equ <lineGetAgentCapsA>
ENDIF

lineGetAgentCapsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAgentCaps equ <lineGetAgentCapsW>
ENDIF

lineGetAgentGroupListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAgentGroupList equ <lineGetAgentGroupListA>
ENDIF

lineGetAgentGroupListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAgentGroupList equ <lineGetAgentGroupListW>
ENDIF

lineGetAgentInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
lineGetAgentSessionInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
lineGetAgentSessionList PROTO STDCALL :DWORD,:DWORD,:DWORD

lineGetAgentStatusA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAgentStatus equ <lineGetAgentStatusA>
ENDIF

lineGetAgentStatusW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAgentStatus equ <lineGetAgentStatusW>
ENDIF


lineGetAppPriorityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetAppPriority equ <lineGetAppPriorityA>
ENDIF

lineGetAppPriorityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetAppPriority equ <lineGetAppPriorityW>
ENDIF


lineGetCallInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetCallInfo equ <lineGetCallInfoA>
ENDIF

lineGetCallInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lineGetCallInfo equ <lineGetCallInfoW>
ENDIF

lineGetCallStatus PROTO STDCALL :DWORD,:DWORD
lineGetConfRelatedCalls PROTO STDCALL :DWORD,:DWORD

lineGetCountryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetCountry equ <lineGetCountryA>
ENDIF

lineGetCountryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetCountry equ <lineGetCountryW>
ENDIF


lineGetDevCapsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetDevCaps equ <lineGetDevCapsA>
ENDIF

lineGetDevCapsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetDevCaps equ <lineGetDevCapsW>
ENDIF


lineGetDevConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetDevConfig equ <lineGetDevConfigA>
ENDIF

lineGetDevConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetDevConfig equ <lineGetDevConfigW>
ENDIF

lineGetGroupListA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetGroupList equ <lineGetGroupListA>
ENDIF

lineGetGroupListW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lineGetGroupList equ <lineGetGroupListW>
ENDIF


lineGetIDA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetID equ <lineGetIDA>
ENDIF

lineGetIDW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetID equ <lineGetIDW>
ENDIF


lineGetIconA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetIcon equ <lineGetIconA>
ENDIF

lineGetIconW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetIcon equ <lineGetIconW>
ENDIF


lineGetLineDevStatusA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetLineDevStatus equ <lineGetLineDevStatusA>
ENDIF

lineGetLineDevStatusW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lineGetLineDevStatus equ <lineGetLineDevStatusW>
ENDIF

lineGetMessage PROTO STDCALL :DWORD,:DWORD,:DWORD
lineGetNewCalls PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineGetNumRings PROTO STDCALL :DWORD,:DWORD,:DWORD

lineGetProviderListA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetProviderList equ <lineGetProviderListA>
ENDIF

lineGetProviderListW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lineGetProviderList equ <lineGetProviderListW>
ENDIF

lineGetProxyStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineGetQueueInfo PROTO STDCALL :DWORD,:DWORD,:DWORD

lineGetQueueListA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetQueueList equ <lineGetQueueListA>
ENDIF

lineGetQueueListW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetQueueList equ <lineGetQueueListW>
ENDIF


lineGetRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetRequest equ <lineGetRequestA>
ENDIF

lineGetRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetRequest equ <lineGetRequestW>
ENDIF

lineGetStatusMessages PROTO STDCALL :DWORD,:DWORD,:DWORD

lineGetTranslateCapsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineGetTranslateCaps equ <lineGetTranslateCapsA>
ENDIF

lineGetTranslateCapsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineGetTranslateCaps equ <lineGetTranslateCapsW>
ENDIF


lineHandoffA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineHandoff equ <lineHandoffA>
ENDIF

lineHandoffW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineHandoff equ <lineHandoffW>
ENDIF

lineHold PROTO STDCALL :DWORD
lineInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lineInitializeExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineInitializeEx equ <lineInitializeExA>
ENDIF

lineInitializeExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineInitializeEx equ <lineInitializeExW>
ENDIF


lineMakeCallA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineMakeCall equ <lineMakeCallA>
ENDIF

lineMakeCallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineMakeCall equ <lineMakeCallW>
ENDIF

lineMonitorDigits PROTO STDCALL :DWORD,:DWORD
lineMonitorMedia PROTO STDCALL :DWORD,:DWORD
lineMonitorTones PROTO STDCALL :DWORD,:DWORD,:DWORD
lineNegotiateAPIVersion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineNegotiateExtVersion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lineOpenA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineOpen equ <lineOpenA>
ENDIF

lineOpenW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineOpen equ <lineOpenW>
ENDIF


lineParkA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  linePark equ <lineParkA>
ENDIF

lineParkW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  linePark equ <lineParkW>
ENDIF


linePickupA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  linePickup equ <linePickupA>
ENDIF

linePickupW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  linePickup equ <linePickupW>
ENDIF


linePrepareAddToConferenceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  linePrepareAddToConference equ <linePrepareAddToConferenceA>
ENDIF

linePrepareAddToConferenceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  linePrepareAddToConference equ <linePrepareAddToConferenceW>
ENDIF

lineProxyMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineProxyResponse PROTO STDCALL :DWORD,:DWORD,:DWORD

lineRedirectA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineRedirect equ <lineRedirectA>
ENDIF

lineRedirectW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineRedirect equ <lineRedirectW>
ENDIF

lineRegisterRequestRecipient PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineReleaseUserUserInfo PROTO STDCALL :DWORD
lineRemoveFromConference PROTO STDCALL :DWORD
lineRemoveProvider PROTO STDCALL :DWORD,:DWORD
lineSecureCall PROTO STDCALL :DWORD
lineSendUserUserInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetAgentActivity PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetAgentGroup PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetAgentMeasurementPeriod PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetAgentSessionState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineSetAgentState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
lineSetAgentStateEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

lineSetAppPriorityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineSetAppPriority equ <lineSetAppPriorityA>
ENDIF

lineSetAppPriorityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineSetAppPriority equ <lineSetAppPriorityW>
ENDIF

lineSetAppSpecific PROTO STDCALL :DWORD,:DWORD
lineSetCallData PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetCallParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallPrivilege PROTO STDCALL :DWORD,:DWORD
lineSetCallQualityOfService PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallTreatment PROTO STDCALL :DWORD,:DWORD
lineSetCurrentLocation PROTO STDCALL :DWORD,:DWORD

lineSetDevConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineSetDevConfig equ <lineSetDevConfigA>
ENDIF

lineSetDevConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineSetDevConfig equ <lineSetDevConfigW>
ENDIF

lineSetLineDevStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetMediaControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetMediaMode PROTO STDCALL :DWORD,:DWORD
lineSetNumRings PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetQueueMeasurementPeriod PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetStatusMessages PROTO STDCALL :DWORD,:DWORD,:DWORD
lineSetTerminal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lineSetTollListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineSetTollList equ <lineSetTollListA>
ENDIF

lineSetTollListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineSetTollList equ <lineSetTollListW>
ENDIF


lineSetupConferenceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineSetupConference equ <lineSetupConferenceA>
ENDIF

lineSetupConferenceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineSetupConference equ <lineSetupConferenceW>
ENDIF


lineSetupTransferA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineSetupTransfer equ <lineSetupTransferA>
ENDIF

lineSetupTransferW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineSetupTransfer equ <lineSetupTransferW>
ENDIF

lineShutdown PROTO STDCALL :DWORD
lineSwapHold PROTO STDCALL :DWORD,:DWORD

lineTranslateAddressA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineTranslateAddress equ <lineTranslateAddressA>
ENDIF

lineTranslateAddressW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineTranslateAddress equ <lineTranslateAddressW>
ENDIF


lineTranslateDialogA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineTranslateDialog equ <lineTranslateDialogA>
ENDIF

lineTranslateDialogW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineTranslateDialog equ <lineTranslateDialogW>
ENDIF

lineUncompleteCall PROTO STDCALL :DWORD,:DWORD
lineUnhold PROTO STDCALL :DWORD

lineUnparkA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lineUnpark equ <lineUnparkA>
ENDIF

lineUnparkW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lineUnpark equ <lineUnparkW>
ENDIF

phoneClose PROTO STDCALL :DWORD

phoneConfigDialogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneConfigDialog equ <phoneConfigDialogA>
ENDIF

phoneConfigDialogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneConfigDialog equ <phoneConfigDialogW>
ENDIF

phoneDevSpecific PROTO STDCALL :DWORD,:DWORD,:DWORD

phoneGetButtonInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneGetButtonInfo equ <phoneGetButtonInfoA>
ENDIF

phoneGetButtonInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneGetButtonInfo equ <phoneGetButtonInfoW>
ENDIF

phoneGetData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

phoneGetDevCapsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneGetDevCaps equ <phoneGetDevCapsA>
ENDIF

phoneGetDevCapsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneGetDevCaps equ <phoneGetDevCapsW>
ENDIF

phoneGetDisplay PROTO STDCALL :DWORD,:DWORD
phoneGetGain PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneGetHookSwitch PROTO STDCALL :DWORD,:DWORD

phoneGetIDA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneGetID equ <phoneGetIDA>
ENDIF

phoneGetIDW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneGetID equ <phoneGetIDW>
ENDIF


phoneGetIconA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneGetIcon equ <phoneGetIconA>
ENDIF

phoneGetIconW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneGetIcon equ <phoneGetIconW>
ENDIF

phoneGetLamp PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneGetMessage PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneGetRing PROTO STDCALL :DWORD,:DWORD,:DWORD

phoneGetStatusA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  phoneGetStatus equ <phoneGetStatusA>
ENDIF

phoneGetStatusMessages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

phoneGetStatusW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  phoneGetStatus equ <phoneGetStatusW>
ENDIF

phoneGetVolume PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

phoneInitializeExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneInitializeEx equ <phoneInitializeExA>
ENDIF

phoneInitializeExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneInitializeEx equ <phoneInitializeExW>
ENDIF

phoneNegotiateAPIVersion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneNegotiateExtVersion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneOpen PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

phoneSetButtonInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  phoneSetButtonInfo equ <phoneSetButtonInfoA>
ENDIF

phoneSetButtonInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  phoneSetButtonInfo equ <phoneSetButtonInfoW>
ENDIF

phoneSetData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
phoneSetDisplay PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneSetGain PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneSetHookSwitch PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneSetLamp PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneSetRing PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneSetStatusMessages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
phoneSetVolume PROTO STDCALL :DWORD,:DWORD,:DWORD
phoneShutdown PROTO STDCALL :DWORD

tapiGetLocationInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  tapiGetLocationInfo equ <tapiGetLocationInfoA>
ENDIF

tapiGetLocationInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  tapiGetLocationInfo equ <tapiGetLocationInfoW>
ENDIF

tapiRequestDrop PROTO STDCALL :DWORD,:DWORD

tapiRequestMakeCallA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  tapiRequestMakeCall equ <tapiRequestMakeCallA>
ENDIF

tapiRequestMakeCallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  tapiRequestMakeCall equ <tapiRequestMakeCallW>
ENDIF


tapiRequestMediaCallA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  tapiRequestMediaCall equ <tapiRequestMediaCallA>
ENDIF

tapiRequestMediaCallW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  tapiRequestMediaCall equ <tapiRequestMediaCallW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file tapi32.inc
  echo -----------------------------------------
ENDIF
