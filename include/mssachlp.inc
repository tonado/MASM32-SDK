; --------------------------------------------------------------------------------------------------
;                          mssachlp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSSACHLP_INC
MSSACHLP_INC equ <1>

CoTaskMemAlloc PROTO STDCALL :DWORD
CoTaskMemFree PROTO STDCALL :DWORD
DeleteCriticalSection PROTO STDCALL :DWORD
EnterCriticalSection PROTO STDCALL :DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD
LeaveCriticalSection PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file mssachlp.inc
  echo -------------------------------------------
ENDIF
