; --------------------------------------------------------------------------------------------------
;                           dsuiext.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DSUIEXT_INC
DSUIEXT_INC equ <1>

CheckDsPolicy PROTO STDCALL :DWORD,:DWORD

DsBrowseForContainerA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DsBrowseForContainer equ <DsBrowseForContainerA>
ENDIF

DsBrowseForContainerW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsBrowseForContainer equ <DsBrowseForContainerW>
ENDIF

DsGetFriendlyClassName PROTO STDCALL :DWORD,:DWORD,:DWORD
DsGetIcon PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FormatDirectoryName PROTO STDCALL :DWORD,:DWORD,:DWORD
FormatMsgBox PROTO C :VARARG
FormatMsgResource PROTO C :VARARG
GetArrayContents PROTO STDCALL :DWORD,:DWORD,:DWORD
GetDisplayNameFromADsPath PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetStringElementA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStringElement equ <GetStringElementA>
ENDIF

GetStringElementW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStringElement equ <GetStringElementW>
ENDIF

LocalAllocStringA2W PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LocalAllocStringA2 equ <LocalAllocStringA2W>
ENDIF

LocalAllocStringA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LocalAllocString equ <LocalAllocStringA>
ENDIF

LocalAllocStringLenA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LocalAllocStringLen equ <LocalAllocStringLenA>
ENDIF

LocalAllocStringLenW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LocalAllocStringLen equ <LocalAllocStringLenW>
ENDIF

LocalAllocStringW2A PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LocalAllocStringW2 equ <LocalAllocStringW2A>
ENDIF

LocalAllocStringW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LocalAllocString equ <LocalAllocStringW>
ENDIF

LocalFreeStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LocalFreeString equ <LocalFreeStringA>
ENDIF

LocalFreeStringW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LocalFreeString equ <LocalFreeStringW>
ENDIF

LocalQueryStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LocalQueryString equ <LocalQueryStringA>
ENDIF

LocalQueryStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LocalQueryString equ <LocalQueryStringW>
ENDIF

ObjectClassFromSearchColumn PROTO STDCALL :DWORD,:DWORD

PutStringElementA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PutStringElement equ <PutStringElementA>
ENDIF

PutStringElementW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PutStringElement equ <PutStringElementW>
ENDIF

ShowDirectoryUI PROTO STDCALL

StringDPA_AppendStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StringDPA_AppendString equ <StringDPA_AppendStringA>
ENDIF

StringDPA_AppendStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StringDPA_AppendString equ <StringDPA_AppendStringW>
ENDIF

StringDPA_DeleteString PROTO STDCALL :DWORD,:DWORD
StringDPA_Destroy PROTO STDCALL :DWORD

StringDPA_InsertStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StringDPA_InsertString equ <StringDPA_InsertStringA>
ENDIF

StringDPA_InsertStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StringDPA_InsertString equ <StringDPA_InsertStringW>
ENDIF

StringFromSearchColumn PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file dsuiext.inc
  echo ------------------------------------------
ENDIF
