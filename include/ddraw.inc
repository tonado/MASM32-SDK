; --------------------------------------------------------------------------------------------------
;                            ddraw.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DDRAW_INC
DDRAW_INC equ <1>

DDGetAttachedSurfaceLcl PROTO STDCALL :DWORD,:DWORD,:DWORD
DDInternalLock PROTO STDCALL :DWORD,:DWORD
DDInternalUnlock PROTO STDCALL :DWORD
DSoundHelp PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectDrawCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectDrawCreateClipper PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectDrawCreateEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

DirectDrawEnumerateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DirectDrawEnumerate equ <DirectDrawEnumerateA>
ENDIF

DirectDrawEnumerateExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DirectDrawEnumerateEx equ <DirectDrawEnumerateExA>
ENDIF

DirectDrawEnumerateExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DirectDrawEnumerateEx equ <DirectDrawEnumerateExW>
ENDIF

DirectDrawEnumerateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DirectDrawEnumerate equ <DirectDrawEnumerateW>
ENDIF

GetDDSurfaceLocal PROTO STDCALL :DWORD,:DWORD,:DWORD
GetSurfaceFromDC PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file ddraw.inc
  echo ----------------------------------------
ENDIF
