; --------------------------------------------------------------------------------------------------
;                          appmgmts.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF APPMGMTS_INC
APPMGMTS_INC equ <1>

CsCreateClassStore PROTO STDCALL :DWORD
CsEnumApps PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CsGetAppCategories PROTO STDCALL :DWORD
CsGetClassAccess PROTO STDCALL :DWORD
CsGetClassStore PROTO STDCALL :DWORD,:DWORD
CsGetClassStorePath PROTO STDCALL :DWORD,:DWORD
CsRegisterAppCategory PROTO STDCALL :DWORD
CsUnregisterAppCategory PROTO STDCALL :DWORD
GenerateGroupPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IID_IClassAdmin PROTO C :VARARG
ProcessGroupPolicyObjectsEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReleaseAppCategoryInfoList PROTO STDCALL :DWORD
ReleasePackageDetail PROTO STDCALL :DWORD
ReleasePackageInfo PROTO STDCALL :DWORD
ServiceMain PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file appmgmts.inc
  echo -------------------------------------------
ENDIF
