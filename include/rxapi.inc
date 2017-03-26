; --------------------------------------------------------------------------------------------------
;                            rxapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RXAPI_INC
RXAPI_INC equ <1>

NtClose PROTO STDCALL :DWORD
NtOpenProcessToken PROTO STDCALL :DWORD,:DWORD,:DWORD
NtQueryInformationToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlConvertUiListToApiList PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCopyLuid PROTO STDCALL :DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlNtStatusToDosError PROTO STDCALL :DWORD
RtlUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_strupr PROTO C :VARARG
_wcsicmp PROTO C :VARARG
gmtime PROTO C :VARARG
memmove PROTO C :VARARG
wcscat PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcslen PROTO C :VARARG
  ; wcsncpy arg type unknown

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file rxapi.inc
  echo ----------------------------------------
ENDIF
