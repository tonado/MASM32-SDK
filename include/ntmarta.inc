; --------------------------------------------------------------------------------------------------
;                           ntmarta.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTMARTA_INC
NTMARTA_INC equ <1>

AccConvertAccessMaskToActrlAccess PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AccConvertAccessToSD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccConvertAccessToSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccConvertAclToAccess PROTO STDCALL :DWORD,:DWORD,:DWORD
AccConvertSDToAccess PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccGetAccessForTrustee PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccGetExplicitEntries PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccLookupAccountName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccLookupAccountSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AccLookupAccountTrustee PROTO STDCALL :DWORD,:DWORD,:DWORD
AccProvCancelOperation PROTO STDCALL :DWORD
AccProvGetAccessInfoPerObjectType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvGetAllRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvGetCapabilities PROTO STDCALL :DWORD,:DWORD
AccProvGetOperationResults PROTO STDCALL :DWORD,:DWORD,:DWORD
AccProvGetTrusteesAccess PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AccProvGrantAccessRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleGetAccessInfoPerObjectType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleGetAllRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleGetTrusteesAccess PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleIsAccessAudited PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleIsObjectAccessible PROTO STDCALL :DWORD,:DWORD
AccProvHandleRevokeAccessRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleRevokeAuditRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvHandleSetAccessRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvIsAccessAudited PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvIsObjectAccessible PROTO STDCALL :DWORD,:DWORD
AccProvRevokeAccessRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvRevokeAuditRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccProvSetAccessRights PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccSetEntriesInAList PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EventGuidToName PROTO STDCALL :DWORD,:DWORD,:DWORD
EventNameFree PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntmarta.inc
  echo ------------------------------------------
ENDIF
