; --------------------------------------------------------------------------------------------------
;                          nlmonlib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NLMONLIB_INC
NLMONLIB_INC equ <1>

CloseHandle PROTO STDCALL :DWORD

CreateEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateEvent equ <CreateEventW>
ENDIF

CreateThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeleteCriticalSection PROTO STDCALL :DWORD
EnterCriticalSection PROTO STDCALL :DWORD
GetLastError PROTO STDCALL
GetTickCount PROTO STDCALL
InitializeCriticalSection PROTO STDCALL :DWORD
LeaveCriticalSection PROTO STDCALL :DWORD
RtlCompareUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
SetEvent PROTO STDCALL :DWORD
TerminateThread PROTO STDCALL :DWORD,:DWORD
WaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
printf PROTO C :VARARG
wcscpy PROTO C :VARARG
  ; wcslen arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file nlmonlib.inc
  echo -------------------------------------------
ENDIF
