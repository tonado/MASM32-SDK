; --------------------------------------------------------------------------------------------------
;                            libc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LIBC_INC
LIBC_INC equ <1>

Beep PROTO STDCALL :DWORD,:DWORD
CloseHandle PROTO STDCALL :DWORD

CompareStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CompareString equ <CompareStringA>
ENDIF

CompareStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CompareString equ <CompareStringW>
ENDIF

CreateDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryA>
ENDIF

CreateDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryW>
ENDIF

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFile equ <CreateFileW>
ENDIF

CreatePipe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateProcessA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateProcess equ <CreateProcessA>
ENDIF

CreateProcessW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateProcess equ <CreateProcessW>
ENDIF

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeleteFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteFile equ <DeleteFileW>
ENDIF

DisableThreadLibraryCalls PROTO STDCALL :DWORD
DuplicateHandle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

EnumSystemLocalesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumSystemLocales equ <EnumSystemLocalesA>
ENDIF

ExitProcess PROTO STDCALL :DWORD
FileTimeToLocalFileTime PROTO STDCALL :DWORD,:DWORD
FileTimeToSystemTime PROTO STDCALL :DWORD,:DWORD
FindClose PROTO STDCALL :DWORD

FindFirstFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstFile equ <FindFirstFileA>
ENDIF

FindFirstFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstFile equ <FindFirstFileW>
ENDIF

FindNextFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextFile equ <FindNextFileA>
ENDIF

FindNextFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindNextFile equ <FindNextFileW>
ENDIF

FlushFileBuffers PROTO STDCALL :DWORD

FreeEnvironmentStringsA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  FreeEnvironmentStrings equ <FreeEnvironmentStringsA>
ENDIF

FreeEnvironmentStringsW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  FreeEnvironmentStrings equ <FreeEnvironmentStringsW>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
GetACP PROTO STDCALL
GetCPInfo PROTO STDCALL :DWORD,:DWORD

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
  GetCommandLine equ <GetCommandLineA>
ENDIF

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
  GetCommandLine equ <GetCommandLineW>
ENDIF

GetConsoleCP PROTO STDCALL
GetConsoleMode PROTO STDCALL :DWORD,:DWORD
GetConsoleOutputCP PROTO STDCALL

GetCurrentDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryA>
ENDIF

GetCurrentDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryW>
ENDIF

GetCurrentProcess PROTO STDCALL
GetCurrentProcessId PROTO STDCALL

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetDiskFreeSpaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceA>
ENDIF

GetDriveTypeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetDriveType equ <GetDriveTypeA>
ENDIF

GetDriveTypeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetDriveType equ <GetDriveTypeW>
ENDIF


GetEnvironmentStringsW PROTO STDCALL
IFDEF __UNICODE__
  GetEnvironmentStrings equ <GetEnvironmentStringsW>
ENDIF

GetExitCodeProcess PROTO STDCALL :DWORD,:DWORD

GetFileAttributesA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesA>
ENDIF

GetFileAttributesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesW>
ENDIF

GetFileInformationByHandle PROTO STDCALL :DWORD,:DWORD
GetFileType PROTO STDCALL :DWORD

GetFullPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameA>
ENDIF

GetFullPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameW>
ENDIF

GetLastError PROTO STDCALL
GetLocalTime PROTO STDCALL :DWORD

GetLocaleInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetLocaleInfo equ <GetLocaleInfoA>
ENDIF

GetLocaleInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetLocaleInfo equ <GetLocaleInfoW>
ENDIF

GetLogicalDrives PROTO STDCALL

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

GetNumberOfConsoleInputEvents PROTO STDCALL :DWORD,:DWORD
GetOEMCP PROTO STDCALL
GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetProcessHeap PROTO STDCALL

GetStartupInfoA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoA>
ENDIF

GetStartupInfoW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoW>
ENDIF

GetStdHandle PROTO STDCALL :DWORD

GetStringTypeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStringType equ <GetStringTypeA>
ENDIF

GetStringTypeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStringType equ <GetStringTypeW>
ENDIF

GetSystemInfo PROTO STDCALL :DWORD
GetSystemTimeAsFileTime PROTO STDCALL :DWORD

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

GetTimeZoneInformation PROTO STDCALL :DWORD
GetUserDefaultLCID PROTO STDCALL

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapCompact PROTO STDCALL :DWORD,:DWORD
HeapCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapDestroy PROTO STDCALL :DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSize PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapValidate PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapWalk PROTO STDCALL :DWORD,:DWORD
InterlockedExchange PROTO STDCALL :DWORD,:DWORD
IsBadCodePtr PROTO STDCALL :DWORD
IsBadReadPtr PROTO STDCALL :DWORD,:DWORD
IsBadWritePtr PROTO STDCALL :DWORD,:DWORD
IsDBCSLeadByteEx PROTO STDCALL :DWORD,:DWORD
IsValidCodePage PROTO STDCALL :DWORD
IsValidLocale PROTO STDCALL :DWORD,:DWORD

LCMapStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LCMapString equ <LCMapStringA>
ENDIF

LCMapStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LCMapString equ <LCMapStringW>
ENDIF

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LocalFileTimeToFileTime PROTO STDCALL :DWORD,:DWORD
LockFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

MoveFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFile equ <MoveFileA>
ENDIF

MoveFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MoveFile equ <MoveFileW>
ENDIF

MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

PeekConsoleInputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PeekConsoleInput equ <PeekConsoleInputA>
ENDIF

PeekNamedPipe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RaiseException PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ReadConsoleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsole equ <ReadConsoleA>
ENDIF

ReadConsoleInputA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ReadConsoleInput equ <ReadConsoleInputA>
ENDIF

ReadConsoleInputW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsoleInput equ <ReadConsoleInputW>
ENDIF

ReadConsoleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReadConsole equ <ReadConsoleW>
ENDIF

ReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

RemoveDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryA>
ENDIF

RemoveDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryW>
ENDIF

SetConsoleCtrlHandler PROTO STDCALL :DWORD,:DWORD
SetConsoleMode PROTO STDCALL :DWORD,:DWORD

SetCurrentDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryA>
ENDIF

SetCurrentDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryW>
ENDIF

SetEndOfFile PROTO STDCALL :DWORD

SetEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetEnvironmentVariable equ <SetEnvironmentVariableA>
ENDIF

SetEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetEnvironmentVariable equ <SetEnvironmentVariableW>
ENDIF

SetErrorMode PROTO STDCALL :DWORD

SetFileAttributesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetFileAttributes equ <SetFileAttributesA>
ENDIF

SetFileAttributesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetFileAttributes equ <SetFileAttributesW>
ENDIF

SetFilePointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetFileTime PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetHandleCount PROTO STDCALL :DWORD
SetLocalTime PROTO STDCALL :DWORD
SetStdHandle PROTO STDCALL :DWORD,:DWORD
SetUnhandledExceptionFilter PROTO STDCALL :DWORD
Sleep PROTO STDCALL :DWORD
SystemTimeToFileTime PROTO STDCALL :DWORD,:DWORD
UnhandledExceptionFilter PROTO STDCALL :DWORD
UnlockFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VirtualAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualFree PROTO STDCALL :DWORD,:DWORD,:DWORD
VirtualProtect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VirtualQuery PROTO STDCALL :DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

WriteConsoleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WriteConsole equ <WriteConsoleA>
ENDIF

WriteConsoleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WriteConsole equ <WriteConsoleW>
ENDIF

WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file libc.inc
  echo ---------------------------------------
ENDIF
