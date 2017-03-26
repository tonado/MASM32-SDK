; --------------------------------------------------------------------------------------------------
;                            iprop.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF IPROP_INC
IPROP_INC equ <1>

FmtIdToPropStgName PROTO STDCALL :DWORD,:DWORD
FreePropVariantArray PROTO STDCALL :DWORD,:DWORD
PropStgNameToFmtId PROTO STDCALL :DWORD,:DWORD
PropVariantClear PROTO STDCALL :DWORD
PropVariantCopy PROTO STDCALL :DWORD,:DWORD
StgCreatePropSetStg PROTO STDCALL :DWORD,:DWORD,:DWORD
StgCreatePropStg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StgOpenPropStg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file iprop.inc
  echo ----------------------------------------
ENDIF
