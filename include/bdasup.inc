; --------------------------------------------------------------------------------------------------
;                           bdasup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF BDASUP_INC
BDASUP_INC equ <1>

BdaCheckChanges PROTO STDCALL :DWORD
BdaCommitChanges PROTO STDCALL :DWORD
BdaCreateFilterFactory PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaCreateFilterFactoryEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
BdaCreatePin PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaCreateTopology PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaDeletePin PROTO STDCALL :DWORD,:DWORD
BdaFilterFactoryUpdateCacheData PROTO STDCALL :DWORD,:DWORD
BdaGetChangeState PROTO STDCALL :DWORD,:DWORD
BdaInitFilter PROTO STDCALL :DWORD,:DWORD
BdaMethodCreatePin PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaMethodCreateTopology PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaMethodDeletePin PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyGetControllingPinId PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyGetPinControl PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyNodeDescriptors PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyNodeEvents PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyNodeMethods PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyNodeProperties PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyNodeTypes PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyPinTypes PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaPropertyTemplateConnections PROTO STDCALL :DWORD,:DWORD,:DWORD
BdaStartChanges PROTO STDCALL :DWORD
BdaUninitFilter PROTO STDCALL :DWORD
BdaValidateNodeProperty PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file bdasup.inc
  echo -----------------------------------------
ENDIF
