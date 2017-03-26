; --------------------------------------------------------------------------------------------------
;                           randlib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RANDLIB_INC
RANDLIB_INC equ <1>

CloseHandle PROTO STDCALL :DWORD
DeviceIoControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerName equ <GetComputerNameA>
ENDIF

GetCurrentProcessId PROTO STDCALL
GetCurrentThreadId PROTO STDCALL

GetDiskFreeSpaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceA>
ENDIF

GetLocalTime PROTO STDCALL :DWORD

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetTickCount PROTO STDCALL

GetUserNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserName equ <GetUserNameA>
ENDIF

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

GlobalMemoryStatus PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

QueryPerformanceCounter PROTO STDCALL :DWORD
RegCloseKey PROTO STDCALL :DWORD

RegCreateKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegSetValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExA>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file randlib.inc
  echo ------------------------------------------
ENDIF
