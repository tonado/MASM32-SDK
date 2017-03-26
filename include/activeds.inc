; --------------------------------------------------------------------------------------------------
;                          activeds.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ACTIVEDS_INC
ACTIVEDS_INC equ <1>

ADsBuildEnumerator PROTO STDCALL :DWORD,:DWORD
ADsBuildVarArrayInt PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsBuildVarArrayStr PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsDecodeBinaryData PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsEncodeBinaryData PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsEnumerateNext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ADsFreeEnumerator PROTO STDCALL :DWORD
ADsGetLastError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ADsGetObject PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsOpenObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ADsSetLastError PROTO STDCALL :DWORD,:DWORD,:DWORD
AdsFreeAdsValues PROTO STDCALL :DWORD,:DWORD
AdsTypeToPropVariant2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdsTypeToPropVariant PROTO STDCALL :DWORD,:DWORD,:DWORD
AllocADsMem PROTO STDCALL :DWORD
AllocADsStr PROTO STDCALL :DWORD
BinarySDToSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConvertSecDescriptorToVariant PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConvertSecurityDescriptorToSecDes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FreeADsMem PROTO STDCALL :DWORD
FreeADsStr PROTO STDCALL :DWORD
PropVariantToAdsType2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PropVariantToAdsType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ReallocADsMem PROTO STDCALL :DWORD,:DWORD,:DWORD
ReallocADsStr PROTO STDCALL :DWORD,:DWORD
SecurityDescriptorToBinarySD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file activeds.inc
  echo -------------------------------------------
ENDIF
