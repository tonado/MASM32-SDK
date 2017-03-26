; --------------------------------------------------------------------------------------------------
;                          vccomsup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF VCCOMSUP_INC
VCCOMSUP_INC equ <1>

CreateErrorInfo PROTO STDCALL :DWORD
GetErrorInfo PROTO STDCALL :DWORD,:DWORD
GetLastError PROTO STDCALL
LocalFree PROTO STDCALL :DWORD
MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetErrorInfo PROTO STDCALL :DWORD,:DWORD
SysAllocString PROTO STDCALL :DWORD
VariantChangeType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VariantClear PROTO STDCALL :DWORD
VariantInit PROTO STDCALL :DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file vccomsup.inc
  echo -------------------------------------------
ENDIF
