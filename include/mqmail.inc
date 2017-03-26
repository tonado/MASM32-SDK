; --------------------------------------------------------------------------------------------------
;                           mqmail.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MQMAIL_INC
MQMAIL_INC equ <1>

CharNextExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CharNextEx equ <CharNextExA>
ENDIF

CloseHandle PROTO STDCALL :DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeregisterEventSource PROTO STDCALL :DWORD
FileTimeToLocalFileTime PROTO STDCALL :DWORD,:DWORD
FileTimeToSystemTime PROTO STDCALL :DWORD,:DWORD

FormatMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FormatMessage equ <FormatMessageA>
ENDIF

GetLastError PROTO STDCALL
GetLocalTime PROTO STDCALL :DWORD

GetModuleFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameA>
ENDIF

GetModuleFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameW>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetSystemTimeAsFileTime PROTO STDCALL :DWORD

GetTempFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempFileName equ <GetTempFileNameA>
ENDIF

GetTempPathA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempPath equ <GetTempPathA>
ENDIF

GetTimeZoneInformation PROTO STDCALL :DWORD

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

GlobalAlloc PROTO STDCALL :DWORD,:DWORD
GlobalFree PROTO STDCALL :DWORD
GlobalLock PROTO STDCALL :DWORD
GlobalUnlock PROTO STDCALL :DWORD
IsBadReadPtr PROTO STDCALL :DWORD,:DWORD
IsBadWritePtr PROTO STDCALL :DWORD,:DWORD
IsDBCSLeadByteEx PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

OutputDebugStringW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringW>
ENDIF

ReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

RegisterEventSourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegisterEventSource equ <RegisterEventSourceW>
ENDIF

ReportEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReportEvent equ <ReportEventW>
ENDIF

SetFilePointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SystemTimeToFileTime PROTO STDCALL :DWORD,:DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcmpiA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcmpi equ <lstrcmpiA>
ENDIF

lstrcpyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpy equ <lstrcpyA>
ENDIF

lstrcpynA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpyn equ <lstrcpynA>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file mqmail.inc
  echo -----------------------------------------
ENDIF
