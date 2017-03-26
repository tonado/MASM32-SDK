; --------------------------------------------------------------------------------------------------
;                            imm32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF IMM32_INC
IMM32_INC equ <1>

ImmAssociateContext PROTO STDCALL :DWORD,:DWORD
ImmAssociateContextEx PROTO STDCALL :DWORD,:DWORD,:DWORD

ImmConfigureIMEA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmConfigureIME equ <ImmConfigureIMEA>
ENDIF

ImmConfigureIMEW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmConfigureIME equ <ImmConfigureIMEW>
ENDIF

ImmCreateContext PROTO STDCALL
ImmCreateIMCC PROTO STDCALL :DWORD
ImmCreateSoftKeyboard PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ImmDestroyContext PROTO STDCALL :DWORD
ImmDestroyIMCC PROTO STDCALL :DWORD
ImmDestroySoftKeyboard PROTO STDCALL :DWORD
ImmDisableIME PROTO STDCALL :DWORD
ImmDisableTextFrameService PROTO STDCALL :DWORD
ImmEnumInputContext PROTO STDCALL :DWORD,:DWORD,:DWORD

ImmEnumRegisterWordA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmEnumRegisterWord equ <ImmEnumRegisterWordA>
ENDIF

ImmEnumRegisterWordW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmEnumRegisterWord equ <ImmEnumRegisterWordW>
ENDIF

ImmEscapeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmEscape equ <ImmEscapeA>
ENDIF

ImmEscapeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmEscape equ <ImmEscapeW>
ENDIF

ImmGenerateMessage PROTO STDCALL :DWORD

ImmGetCandidateListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetCandidateList equ <ImmGetCandidateListA>
ENDIF

ImmGetCandidateListCountA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetCandidateListCount equ <ImmGetCandidateListCountA>
ENDIF

ImmGetCandidateListCountW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetCandidateListCount equ <ImmGetCandidateListCountW>
ENDIF

ImmGetCandidateListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetCandidateList equ <ImmGetCandidateListW>
ENDIF

ImmGetCandidateWindow PROTO STDCALL :DWORD,:DWORD,:DWORD

ImmGetCompositionFontA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetCompositionFont equ <ImmGetCompositionFontA>
ENDIF

ImmGetCompositionFontW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetCompositionFont equ <ImmGetCompositionFontW>
ENDIF

ImmGetCompositionStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetCompositionString equ <ImmGetCompositionStringA>
ENDIF

ImmGetCompositionStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetCompositionString equ <ImmGetCompositionStringW>
ENDIF

ImmGetCompositionWindow PROTO STDCALL :DWORD,:DWORD
ImmGetContext PROTO STDCALL :DWORD

ImmGetConversionListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetConversionList equ <ImmGetConversionListA>
ENDIF

ImmGetConversionListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetConversionList equ <ImmGetConversionListW>
ENDIF

ImmGetConversionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
ImmGetDefaultIMEWnd PROTO STDCALL :DWORD

ImmGetDescriptionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetDescription equ <ImmGetDescriptionA>
ENDIF

ImmGetDescriptionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetDescription equ <ImmGetDescriptionW>
ENDIF

ImmGetGuideLineA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetGuideLine equ <ImmGetGuideLineA>
ENDIF

ImmGetGuideLineW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetGuideLine equ <ImmGetGuideLineW>
ENDIF

ImmGetHotKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ImmGetIMCCLockCount PROTO STDCALL :DWORD
ImmGetIMCCSize PROTO STDCALL :DWORD
ImmGetIMCLockCount PROTO STDCALL :DWORD

ImmGetIMEFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetIMEFileName equ <ImmGetIMEFileNameA>
ENDIF

ImmGetIMEFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetIMEFileName equ <ImmGetIMEFileNameW>
ENDIF

ImmGetImeMenuItemsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetImeMenuItems equ <ImmGetImeMenuItemsA>
ENDIF

ImmGetImeMenuItemsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetImeMenuItems equ <ImmGetImeMenuItemsW>
ENDIF

ImmGetOpenStatus PROTO STDCALL :DWORD
ImmGetProperty PROTO STDCALL :DWORD,:DWORD

ImmGetRegisterWordStyleA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleA>
ENDIF

ImmGetRegisterWordStyleW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleW>
ENDIF

ImmGetStatusWindowPos PROTO STDCALL :DWORD,:DWORD
ImmGetVirtualKey PROTO STDCALL :DWORD

ImmInstallIMEA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ImmInstallIME equ <ImmInstallIMEA>
ENDIF

ImmInstallIMEW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ImmInstallIME equ <ImmInstallIMEW>
ENDIF

ImmIsIME PROTO STDCALL :DWORD

ImmIsUIMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmIsUIMessage equ <ImmIsUIMessageA>
ENDIF

ImmIsUIMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmIsUIMessage equ <ImmIsUIMessageW>
ENDIF

ImmLockIMC PROTO STDCALL :DWORD
ImmLockIMCC PROTO STDCALL :DWORD
ImmNotifyIME PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ImmReSizeIMCC PROTO STDCALL :DWORD,:DWORD

ImmRegisterWordA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmRegisterWord equ <ImmRegisterWordA>
ENDIF

ImmRegisterWordW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmRegisterWord equ <ImmRegisterWordW>
ENDIF

ImmReleaseContext PROTO STDCALL :DWORD,:DWORD

ImmRequestMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmRequestMessage equ <ImmRequestMessageA>
ENDIF

ImmRequestMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmRequestMessage equ <ImmRequestMessageW>
ENDIF

ImmSetCandidateWindow PROTO STDCALL :DWORD,:DWORD

ImmSetCompositionFontA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ImmSetCompositionFont equ <ImmSetCompositionFontA>
ENDIF

ImmSetCompositionFontW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ImmSetCompositionFont equ <ImmSetCompositionFontW>
ENDIF

ImmSetCompositionStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmSetCompositionString equ <ImmSetCompositionStringA>
ENDIF

ImmSetCompositionStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmSetCompositionString equ <ImmSetCompositionStringW>
ENDIF

ImmSetCompositionWindow PROTO STDCALL :DWORD,:DWORD
ImmSetConversionStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
ImmSetHotKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ImmSetOpenStatus PROTO STDCALL :DWORD,:DWORD
ImmSetStatusWindowPos PROTO STDCALL :DWORD,:DWORD
ImmShowSoftKeyboard PROTO STDCALL :DWORD,:DWORD
ImmSimulateHotKey PROTO STDCALL :DWORD,:DWORD
ImmUnlockIMC PROTO STDCALL :DWORD
ImmUnlockIMCC PROTO STDCALL :DWORD

ImmUnregisterWordA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImmUnregisterWord equ <ImmUnregisterWordA>
ENDIF

ImmUnregisterWordW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImmUnregisterWord equ <ImmUnregisterWordW>
ENDIF

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file imm32.inc
  echo ----------------------------------------
ENDIF
