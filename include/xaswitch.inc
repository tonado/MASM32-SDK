; --------------------------------------------------------------------------------------------------
;                          xaswitch.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF XASWITCH_INC
XASWITCH_INC equ <1>

DeleteCriticalSection PROTO STDCALL :DWORD
EnterCriticalSection PROTO STDCALL :DWORD
FreeLibrary PROTO STDCALL :DWORD
GetProcAddress PROTO STDCALL :DWORD,:DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
LeaveCriticalSection PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

  ; msqlsrvxa1 arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file xaswitch.inc
  echo -------------------------------------------
ENDIF
