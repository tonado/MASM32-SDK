; --------------------------------------------------------------------------------------------------
;                          npptools.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NPPTOOLS_INC
NPPTOOLS_INC equ <1>

ClearEventData PROTO C :VARARG
CreateBlob PROTO C :VARARG
CreateNPPInterface PROTO C :VARARG
DestroyBlob PROTO C :VARARG
DestroyNPPBlobTable PROTO C :VARARG
DuplicateBlob PROTO C :VARARG
FilterNPPBlob PROTO C :VARARG
FindOneOf PROTO C :VARARG
FindUnknownBlobCategories PROTO C :VARARG
FindUnknownBlobTags PROTO C :VARARG
GetBoolFromBlob PROTO C :VARARG
GetClassIDFromBlob PROTO C :VARARG
GetDwordFromBlob PROTO C :VARARG
GetMacAddressFromBlob PROTO C :VARARG
GetNPPAddressFilterFromBlob PROTO C :VARARG
GetNPPBlobFromUI PROTO C :VARARG
GetNPPBlobTable PROTO C :VARARG
GetNPPEtypeSapFilter PROTO C :VARARG
GetNPPMacTypeAsNumber PROTO C :VARARG
GetNPPPatternFilterFromBlob PROTO C :VARARG
GetNPPTriggerFromBlob PROTO C :VARARG
GetNetworkInfoFromBlob PROTO C :VARARG
GetStringFromBlob PROTO C :VARARG
GetStringsFromBlob PROTO C :VARARG
IsRemoteNPP PROTO C :VARARG
LockBlob PROTO C :VARARG
MarshalBlob PROTO C :VARARG
MergeBlob PROTO C :VARARG
NmAddUsedEntry PROTO STDCALL :DWORD,:DWORD
NmHeapAllocate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NmHeapFree PROTO STDCALL :DWORD,:DWORD
NmHeapReallocate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NmHeapSetMaxSize PROTO STDCALL :DWORD
NmHeapSize PROTO STDCALL :DWORD
NmRemoveUsedEntry PROTO STDCALL :DWORD,:DWORD
RaiseNMEvent PROTO C :VARARG
ReadBlobFromFile PROTO C :VARARG
RegCreateBlobKey PROTO C :VARARG
RegOpenBlobKey PROTO C :VARARG
ReleaseEventSystem PROTO STDCALL
RemoveFromBlob PROTO C :VARARG
SelectNPPBlobFromTable PROTO C :VARARG
SendEvent PROTO STDCALL :DWORD
SetBoolInBlob PROTO C :VARARG
SetClassIDInBlob PROTO C :VARARG
SetDwordInBlob PROTO C :VARARG
SetMacAddressInBlob PROTO C :VARARG
SetNPPAddressFilterInBlob PROTO C :VARARG
SetNPPEtypeSapFilter PROTO C :VARARG
SetNPPPatternFilterInBlob PROTO C :VARARG
SetNPPTriggerInBlob PROTO C :VARARG
SetNetworkInfoInBlob PROTO C :VARARG
SetStringInBlob PROTO C :VARARG
SubkeyExists PROTO C :VARARG
UnMarshalBlob PROTO C :VARARG
UnlockBlob PROTO C :VARARG
WriteBlobToFile PROTO C :VARARG
WriteCrackedBlobToFile PROTO STDCALL :DWORD,:DWORD
recursiveDeleteKey PROTO C :VARARG
  ; setKeyAndValue arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file npptools.inc
  echo -------------------------------------------
ENDIF
