; --------------------------------------------------------------------------------------------------
;                           wiautil.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WIAUTIL_INC
WIAUTIL_INC equ <1>

AddAccessAllowedAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AllocateAndInitializeSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateMutexA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateMutex equ <CreateMutexA>
ENDIF

DebugBreak PROTO STDCALL

ExpandEnvironmentStringsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ExpandEnvironmentStrings equ <ExpandEnvironmentStringsA>
ENDIF

FlushFileBuffers PROTO STDCALL :DWORD

FormatMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FormatMessage equ <FormatMessageA>
ENDIF

FreeSid PROTO STDCALL :DWORD
GetCurrentThreadId PROTO STDCALL
GetLastError PROTO STDCALL
GetLengthSid PROTO STDCALL :DWORD
GetLocalTime PROTO STDCALL :DWORD

GetModuleFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameA>
ENDIF

GetProcessHeap PROTO STDCALL
HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeAcl PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD

LoadStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadString equ <LoadStringW>
ENDIF

MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

RegCloseKey PROTO STDCALL :DWORD

RegCreateKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExA>
ENDIF

RegOpenKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExA>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RegSetValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExA>
ENDIF

ReleaseMutex PROTO STDCALL :DWORD
SetFilePointerEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SysAllocString PROTO STDCALL :DWORD
SysFreeString PROTO STDCALL :DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_snprintf PROTO C :VARARG
_vsnprintf PROTO C :VARARG

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcpyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpy equ <lstrcpyA>
ENDIF

lstrcpyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpy equ <lstrcpyW>
ENDIF

lstrcpynA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpyn equ <lstrcpynA>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

sprintf PROTO C :VARARG
  ; strrchr arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file wiautil.inc
  echo ------------------------------------------
ENDIF
