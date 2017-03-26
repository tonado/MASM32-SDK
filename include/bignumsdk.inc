; --------------------------------------------------------------------------------------------------
;                          bignumsdk.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF BIGNUMSDK_INC
BIGNUMSDK_INC equ <1>

GetSystemInfo PROTO STDCALL :DWORD
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD

ELSE
  echo --------------------------------------------
  echo WARNING duplicate include file bignumsdk.inc
  echo --------------------------------------------
ENDIF
