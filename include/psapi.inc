; --------------------------------------------------------------------------------------------------
;                            psapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PSAPI_INC
PSAPI_INC equ <1>

EmptyWorkingSet PROTO STDCALL :DWORD
EnumDeviceDrivers PROTO STDCALL :DWORD,:DWORD,:DWORD

EnumPageFilesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPageFiles equ <EnumPageFilesA>
ENDIF

EnumPageFilesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumPageFiles equ <EnumPageFilesW>
ENDIF

EnumProcessModules PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
EnumProcesses PROTO STDCALL :DWORD,:DWORD,:DWORD

GetDeviceDriverBaseNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDeviceDriverBaseName equ <GetDeviceDriverBaseNameA>
ENDIF

GetDeviceDriverBaseNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDeviceDriverBaseName equ <GetDeviceDriverBaseNameW>
ENDIF

GetDeviceDriverFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDeviceDriverFileName equ <GetDeviceDriverFileNameA>
ENDIF

GetDeviceDriverFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDeviceDriverFileName equ <GetDeviceDriverFileNameW>
ENDIF

GetMappedFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetMappedFileName equ <GetMappedFileNameA>
ENDIF

GetMappedFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetMappedFileName equ <GetMappedFileNameW>
ENDIF

GetModuleBaseNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleBaseName equ <GetModuleBaseNameA>
ENDIF

GetModuleBaseNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetModuleBaseName equ <GetModuleBaseNameW>
ENDIF

GetModuleFileNameExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileNameEx equ <GetModuleFileNameExA>
ENDIF

GetModuleFileNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetModuleFileNameEx equ <GetModuleFileNameExW>
ENDIF

GetModuleInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetPerformanceInfo PROTO STDCALL :DWORD,:DWORD

GetProcessImageFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProcessImageFileName equ <GetProcessImageFileNameA>
ENDIF

GetProcessImageFileNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetProcessImageFileName equ <GetProcessImageFileNameW>
ENDIF

GetProcessMemoryInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
GetWsChanges PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeProcessForWsWatch PROTO STDCALL :DWORD
QueryWorkingSet PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file psapi.inc
  echo ----------------------------------------
ENDIF
