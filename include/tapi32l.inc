; --------------------------------------------------------------------------------------------------
;                           tapi32l.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TAPI32L_INC
TAPI32L_INC equ <1>

GetProcAddress PROTO STDCALL :DWORD,:DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

RegCloseKey PROTO STDCALL :DWORD

RegOpenKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

wvsprintfA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  wvsprintf equ <wvsprintfA>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file tapi32l.inc
  echo ------------------------------------------
ENDIF
