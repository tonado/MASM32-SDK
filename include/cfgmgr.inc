; --------------------------------------------------------------------------------------------------
;                           cfgmgr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CFGMGR_INC
CFGMGR_INC equ <1>

AdjustTokenPrivileges PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CharUpperBuffW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CharUpperBuff equ <CharUpperBuffW>
ENDIF

CharUpperW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CharUpper equ <CharUpperW>
ENDIF

CloseHandle PROTO STDCALL :DWORD
CloseServiceHandle PROTO STDCALL :DWORD
DeleteCriticalSection PROTO STDCALL :DWORD
EnterCriticalSection PROTO STDCALL :DWORD
FreeLibrary PROTO STDCALL :DWORD

GetComputerNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerNameEx equ <GetComputerNameExW>
ENDIF

GetCurrentProcess PROTO STDCALL
GetCurrentProcessId PROTO STDCALL
GetCurrentThread PROTO STDCALL
GetLastError PROTO STDCALL
GetProcAddress PROTO STDCALL :DWORD,:DWORD

GetWindowTextW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowText equ <GetWindowTextW>
ENDIF

GetWindowThreadProcessId PROTO STDCALL :DWORD,:DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
LeaveCriticalSection PROTO STDCALL :DWORD

LoadLibraryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LoadLibrary equ <LoadLibraryW>
ENDIF

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD

LookupPrivilegeValueW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupPrivilegeValue equ <LookupPrivilegeValueW>
ENDIF

OpenEventW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenEvent equ <OpenEventW>
ENDIF

OpenProcess PROTO STDCALL :DWORD,:DWORD,:DWORD
OpenProcessToken PROTO STDCALL :DWORD,:DWORD,:DWORD

OpenSCManagerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenSCManager equ <OpenSCManagerW>
ENDIF

OpenServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenService equ <OpenServiceW>
ENDIF

OpenThreadToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
QueryServiceStatus PROTO STDCALL :DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegConnectRegistryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegConnectRegistry equ <RegConnectRegistryW>
ENDIF

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegEnumKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumKeyEx equ <RegEnumKeyExW>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

ReleaseMutex PROTO STDCALL :DWORD

RpcBindingFromStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingFromStringBinding equ <RpcBindingFromStringBindingW>
ENDIF

RpcStringBindingComposeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcStringBindingCompose equ <RpcStringBindingComposeW>
ENDIF

RpcStringFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcStringFree equ <RpcStringFreeW>
ENDIF

RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlMultiByteToUnicodeN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlMultiByteToUnicodeSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteSize PROTO STDCALL :DWORD,:DWORD,:DWORD
SetLastError PROTO STDCALL :DWORD
Sleep PROTO STDCALL :DWORD
WaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD

lstrcatW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcat equ <lstrcatW>
ENDIF

lstrcmpiW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcmpi equ <lstrcmpiW>
ENDIF

lstrcpyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpy equ <lstrcpyW>
ENDIF

lstrcpynW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpyn equ <lstrcpynW>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

memmove PROTO C :VARARG
  ; wsprintfW arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file cfgmgr.inc
  echo -----------------------------------------
ENDIF
