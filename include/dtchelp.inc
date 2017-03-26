; --------------------------------------------------------------------------------------------------
;                           dtchelp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DTCHELP_INC
DTCHELP_INC equ <1>

FreeLibrary PROTO STDCALL :DWORD

GetLocaleInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetLocaleInfo equ <GetLocaleInfoA>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetUserDefaultLCID PROTO STDCALL
InterlockedCompareExchange PROTO STDCALL :DWORD,:DWORD,:DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

  ; wsprintfA arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file dtchelp.inc
  echo ------------------------------------------
ENDIF
