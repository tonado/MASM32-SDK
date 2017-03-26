; --------------------------------------------------------------------------------------------------
;                          ntfrsapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTFRSAPI_INC
NTFRSAPI_INC equ <1>

NtFrsApiDestroyBackupRestore PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtFrsApiEnumBackupRestoreSets PROTO STDCALL :DWORD,:DWORD,:DWORD
NtFrsApiFinishedRestoringDirectory PROTO STDCALL :DWORD,:DWORD,:DWORD
NtFrsApiGetBackupRestoreSetDirectory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NtFrsApiGetBackupRestoreSetPaths PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtFrsApiGetBackupRestoreSets PROTO STDCALL :DWORD
NtFrsApiInitializeBackupRestore PROTO STDCALL :DWORD,:DWORD,:DWORD
NtFrsApiIsBackupRestoreSetASysvol PROTO STDCALL :DWORD,:DWORD,:DWORD
NtFrsApiRestoringDirectory PROTO STDCALL :DWORD,:DWORD,:DWORD

NtFrsApi_AbortDemotionW PROTO STDCALL
IFDEF __UNICODE__
  NtFrsApi_AbortDemotion equ <NtFrsApi_AbortDemotionW>
ENDIF

NtFrsApi_AbortPromotionW PROTO STDCALL
IFDEF __UNICODE__
  NtFrsApi_AbortPromotion equ <NtFrsApi_AbortPromotionW>
ENDIF

NtFrsApi_CommitDemotionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_CommitDemotion equ <NtFrsApi_CommitDemotionW>
ENDIF

NtFrsApi_CommitPromotionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_CommitPromotion equ <NtFrsApi_CommitPromotionW>
ENDIF

NtFrsApi_DeleteSysvolMember PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

NtFrsApi_Get_DsPollingIntervalW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_Get_DsPollingInterval equ <NtFrsApi_Get_DsPollingIntervalW>
ENDIF

NtFrsApi_InfoFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NtFrsApi_InfoFree equ <NtFrsApi_InfoFreeW>
ENDIF

NtFrsApi_InfoLineW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_InfoLine equ <NtFrsApi_InfoLineW>
ENDIF

NtFrsApi_InfoMoreW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NtFrsApi_InfoMore equ <NtFrsApi_InfoMoreW>
ENDIF

NtFrsApi_InfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_Info equ <NtFrsApi_InfoW>
ENDIF

NtFrsApi_Initialize PROTO STDCALL :DWORD,:DWORD,:DWORD

NtFrsApi_PrepareForDemotionUsingCredW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_PrepareForDemotionUsingCred equ <NtFrsApi_PrepareForDemotionUsingCredW>
ENDIF

NtFrsApi_PrepareForDemotionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NtFrsApi_PrepareForDemotion equ <NtFrsApi_PrepareForDemotionW>
ENDIF

NtFrsApi_PrepareForPromotionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NtFrsApi_PrepareForPromotion equ <NtFrsApi_PrepareForPromotionW>
ENDIF

NtFrsApi_Set_DsPollingIntervalW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_Set_DsPollingInterval equ <NtFrsApi_Set_DsPollingIntervalW>
ENDIF

NtFrsApi_StartDemotionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_StartDemotion equ <NtFrsApi_StartDemotionW>
ENDIF

NtFrsApi_StartPromotionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_StartPromotion equ <NtFrsApi_StartPromotionW>
ENDIF

NtFrsApi_WaitForDemotionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_WaitForDemotion equ <NtFrsApi_WaitForDemotionW>
ENDIF

NtFrsApi_WaitForPromotionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  NtFrsApi_WaitForPromotion equ <NtFrsApi_WaitForPromotionW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file ntfrsapi.inc
  echo -------------------------------------------
ENDIF
