; --------------------------------------------------------------------------------------------------
;                          htmlhelp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF HTMLHELP_INC
HTMLHELP_INC equ <1>

GetProcAddress PROTO STDCALL :DWORD,:DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
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

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file htmlhelp.inc
  echo -------------------------------------------
ENDIF
