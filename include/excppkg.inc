; --------------------------------------------------------------------------------------------------
;                           excppkg.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF EXCPPKG_INC
EXCPPKG_INC equ <1>

CoTaskMemFree PROTO STDCALL :DWORD

ExpandEnvironmentStringsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ExpandEnvironmentStrings equ <ExpandEnvironmentStringsW>
ENDIF

GetFileAttributesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesW>
ENDIF

GetLastError PROTO STDCALL
GetProcessHeap PROTO STDCALL
HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
IIDFromString PROTO STDCALL :DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegDeleteValueW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteValue equ <RegDeleteValueW>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

SetLastError PROTO STDCALL :DWORD
SetupCloseInfFile PROTO STDCALL :DWORD

SetupFindFirstLineW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupFindFirstLine equ <SetupFindFirstLineW>
ENDIF

SetupGetStringFieldW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetStringField equ <SetupGetStringFieldW>
ENDIF

SetupOpenInfFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupOpenInfFile equ <SetupOpenInfFileW>
ENDIF

StringFromIID PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file excppkg.inc
  echo ------------------------------------------
ENDIF
