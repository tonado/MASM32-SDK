; --------------------------------------------------------------------------------------------------
;                           dlcapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DLCAPI_INC
DLCAPI_INC equ <1>

AcsLan PROTO STDCALL :DWORD,:DWORD
DlcCallDriver PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAdapterNameFromNumber PROTO STDCALL :DWORD,:DWORD
GetAdapterNumberFromName PROTO STDCALL :DWORD,:DWORD
NtAcsLan PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dlcapi.inc
  echo -----------------------------------------
ENDIF
