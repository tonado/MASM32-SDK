; --------------------------------------------------------------------------------------------------
;                          delayload.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DELAYLOAD_INC
DELAYLOAD_INC equ <1>

FreeLibrary PROTO STDCALL :DWORD
GetLastError PROTO STDCALL
GetProcAddress PROTO STDCALL :DWORD,:DWORD
InterlockedExchange PROTO STDCALL :DWORD,:DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
RaiseException PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------------
  echo WARNING duplicate include file delayload.inc
  echo --------------------------------------------
ENDIF
