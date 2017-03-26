; --------------------------------------------------------------------------------------------------
;                           winfax.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINFAX_INC
WINFAX_INC equ <1>

FaxAbort PROTO STDCALL :DWORD,:DWORD
FaxAccessCheck PROTO STDCALL :DWORD,:DWORD
FaxClose PROTO STDCALL :DWORD

FaxCompleteJobParamsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxCompleteJobParams equ <FaxCompleteJobParamsA>
ENDIF

FaxCompleteJobParamsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxCompleteJobParams equ <FaxCompleteJobParamsW>
ENDIF

FaxConnectFaxServerA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxConnectFaxServer equ <FaxConnectFaxServerA>
ENDIF

FaxConnectFaxServerW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxConnectFaxServer equ <FaxConnectFaxServerW>
ENDIF

FaxEnableRoutingMethodA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxEnableRoutingMethod equ <FaxEnableRoutingMethodA>
ENDIF

FaxEnableRoutingMethodW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxEnableRoutingMethod equ <FaxEnableRoutingMethodW>
ENDIF

FaxEnumGlobalRoutingInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxEnumGlobalRoutingInfo equ <FaxEnumGlobalRoutingInfoA>
ENDIF

FaxEnumGlobalRoutingInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxEnumGlobalRoutingInfo equ <FaxEnumGlobalRoutingInfoW>
ENDIF

FaxEnumJobsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxEnumJobs equ <FaxEnumJobsA>
ENDIF

FaxEnumJobsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxEnumJobs equ <FaxEnumJobsW>
ENDIF

FaxEnumPortsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxEnumPorts equ <FaxEnumPortsA>
ENDIF

FaxEnumPortsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxEnumPorts equ <FaxEnumPortsW>
ENDIF

FaxEnumRoutingMethodsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxEnumRoutingMethods equ <FaxEnumRoutingMethodsA>
ENDIF

FaxEnumRoutingMethodsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxEnumRoutingMethods equ <FaxEnumRoutingMethodsW>
ENDIF

FaxFreeBuffer PROTO STDCALL :DWORD

FaxGetConfigurationA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetConfiguration equ <FaxGetConfigurationA>
ENDIF

FaxGetConfigurationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetConfiguration equ <FaxGetConfigurationW>
ENDIF

FaxGetDeviceStatusA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetDeviceStatus equ <FaxGetDeviceStatusA>
ENDIF

FaxGetDeviceStatusW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetDeviceStatus equ <FaxGetDeviceStatusW>
ENDIF

FaxGetJobA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetJob equ <FaxGetJobA>
ENDIF

FaxGetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetJob equ <FaxGetJobW>
ENDIF

FaxGetLoggingCategoriesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetLoggingCategories equ <FaxGetLoggingCategoriesA>
ENDIF

FaxGetLoggingCategoriesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetLoggingCategories equ <FaxGetLoggingCategoriesW>
ENDIF

FaxGetPageData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

FaxGetPortA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetPort equ <FaxGetPortA>
ENDIF

FaxGetPortW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetPort equ <FaxGetPortW>
ENDIF

FaxGetRoutingInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxGetRoutingInfo equ <FaxGetRoutingInfoA>
ENDIF

FaxGetRoutingInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxGetRoutingInfo equ <FaxGetRoutingInfoW>
ENDIF

FaxInitializeEventQueue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxOpenPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

FaxPrintCoverPageA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxPrintCoverPage equ <FaxPrintCoverPageA>
ENDIF

FaxPrintCoverPageW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxPrintCoverPage equ <FaxPrintCoverPageW>
ENDIF

FaxRegisterRoutingExtensionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxRegisterRoutingExtension equ <FaxRegisterRoutingExtensionW>
ENDIF

FaxRegisterServiceProviderW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxRegisterServiceProvider equ <FaxRegisterServiceProviderW>
ENDIF

FaxSendDocumentA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSendDocument equ <FaxSendDocumentA>
ENDIF

FaxSendDocumentForBroadcastA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSendDocumentForBroadcast equ <FaxSendDocumentForBroadcastA>
ENDIF

FaxSendDocumentForBroadcastW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxSendDocumentForBroadcast equ <FaxSendDocumentForBroadcastW>
ENDIF

FaxSendDocumentW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxSendDocument equ <FaxSendDocumentW>
ENDIF

FaxSetConfigurationA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetConfiguration equ <FaxSetConfigurationA>
ENDIF

FaxSetConfigurationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetConfiguration equ <FaxSetConfigurationW>
ENDIF

FaxSetGlobalRoutingInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetGlobalRoutingInfo equ <FaxSetGlobalRoutingInfoA>
ENDIF

FaxSetGlobalRoutingInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetGlobalRoutingInfo equ <FaxSetGlobalRoutingInfoW>
ENDIF

FaxSetJobA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetJob equ <FaxSetJobA>
ENDIF

FaxSetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetJob equ <FaxSetJobW>
ENDIF

FaxSetLoggingCategoriesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetLoggingCategories equ <FaxSetLoggingCategoriesA>
ENDIF

FaxSetLoggingCategoriesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetLoggingCategories equ <FaxSetLoggingCategoriesW>
ENDIF

FaxSetPortA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetPort equ <FaxSetPortA>
ENDIF

FaxSetPortW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetPort equ <FaxSetPortW>
ENDIF

FaxSetRoutingInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxSetRoutingInfo equ <FaxSetRoutingInfoA>
ENDIF

FaxSetRoutingInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxSetRoutingInfo equ <FaxSetRoutingInfoW>
ENDIF

FaxStartPrintJobA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FaxStartPrintJob equ <FaxStartPrintJobA>
ENDIF

FaxStartPrintJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FaxStartPrintJob equ <FaxStartPrintJobW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file winfax.inc
  echo -----------------------------------------
ENDIF
