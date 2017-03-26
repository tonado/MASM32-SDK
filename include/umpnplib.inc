; --------------------------------------------------------------------------------------------------
;                          umpnplib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF UMPNPLIB_INC
UMPNPLIB_INC equ <1>

CloseHandle PROTO STDCALL :DWORD

CreateEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateEvent equ <CreateEventW>
ENDIF

CreateMutexW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateMutex equ <CreateMutexW>
ENDIF

RegCloseKey PROTO STDCALL :DWORD

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegEnumKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumKeyEx equ <RegEnumKeyExW>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegQueryInfoKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryInfoKey equ <RegQueryInfoKeyW>
ENDIF

SetEvent PROTO STDCALL :DWORD

lstrcpyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpy equ <lstrcpyW>
ENDIF

lstrcpynW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpyn equ <lstrcpynW>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

  ; wsprintfW arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file umpnplib.inc
  echo -------------------------------------------
ENDIF
