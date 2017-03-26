; --------------------------------------------------------------------------------------------------
;                           version.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF VERSION_INC
VERSION_INC equ <1>

GetFileVersionInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileVersionInfo equ <GetFileVersionInfoA>
ENDIF

GetFileVersionInfoSizeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileVersionInfoSize equ <GetFileVersionInfoSizeA>
ENDIF

GetFileVersionInfoSizeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetFileVersionInfoSize equ <GetFileVersionInfoSizeW>
ENDIF

GetFileVersionInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFileVersionInfo equ <GetFileVersionInfoW>
ENDIF

VerFindFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerFindFile equ <VerFindFileA>
ENDIF

VerFindFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerFindFile equ <VerFindFileW>
ENDIF

VerInstallFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerInstallFile equ <VerInstallFileA>
ENDIF

VerInstallFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerInstallFile equ <VerInstallFileW>
ENDIF

VerQueryValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerQueryValue equ <VerQueryValueA>
ENDIF

VerQueryValueIndexA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  VerQueryValueIndex equ <VerQueryValueIndexA>
ENDIF

VerQueryValueIndexW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerQueryValueIndex equ <VerQueryValueIndexW>
ENDIF

VerQueryValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerQueryValue equ <VerQueryValueW>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file version.inc
  echo ------------------------------------------
ENDIF
