; --------------------------------------------------------------------------------------------------
;                          msrating.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSRATING_INC
MSRATING_INC equ <1>

ChangeSupervisorPassword PROTO STDCALL :DWORD,:DWORD
ClickedOnPRF PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClickedOnRAT PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RatingAccessDeniedDialog2 PROTO STDCALL :DWORD,:DWORD,:DWORD
RatingAccessDeniedDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RatingAddPropertyPages PROTO STDCALL :DWORD,:DWORD,:DWORD
RatingCheckUserAccess PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RatingCustomAddRatingHelper PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RatingCustomAddRatingSystem PROTO STDCALL :DWORD,:DWORD
RatingCustomCrackData PROTO STDCALL :DWORD,:DWORD,:DWORD
RatingCustomDeleteCrackedData PROTO STDCALL :DWORD
RatingCustomInit PROTO STDCALL :DWORD
RatingCustomRemoveRatingHelper PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RatingCustomSetDefaultBureau PROTO STDCALL :DWORD
RatingCustomSetUserOptions PROTO STDCALL :DWORD,:DWORD
RatingEnable PROTO STDCALL :DWORD,:DWORD,:DWORD
RatingEnabledQuery PROTO STDCALL
RatingFreeDetails PROTO STDCALL :DWORD
RatingInit PROTO STDCALL
RatingObtainCancel PROTO STDCALL :DWORD
RatingObtainQuery PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RatingSetupUI PROTO STDCALL :DWORD,:DWORD
VerifySupervisorPassword PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file msrating.inc
  echo -------------------------------------------
ENDIF
