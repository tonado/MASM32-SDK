; --------------------------------------------------------------------------------------------------
;                           miglib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MIGLIB_INC
MIGLIB_INC equ <1>

BeginUpdateResourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  BeginUpdateResource equ <BeginUpdateResourceA>
ENDIF

BeginUpdateResourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  BeginUpdateResource equ <BeginUpdateResourceW>
ENDIF

CharLowerA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CharLower equ <CharLowerA>
ENDIF

CharLowerBuffA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CharLowerBuff equ <CharLowerBuffA>
ENDIF

CharLowerBuffW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CharLowerBuff equ <CharLowerBuffW>
ENDIF

CharLowerW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CharLower equ <CharLowerW>
ENDIF

CloseHandle PROTO STDCALL :DWORD
CoCreateInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInitialize PROTO STDCALL :DWORD
CoUninitialize PROTO STDCALL

CreateDCA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDC equ <CreateDCA>
ENDIF

CreateDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryA>
ENDIF

CreateDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryW>
ENDIF

CreateEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateEvent equ <CreateEventA>
ENDIF

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingA>
ENDIF

CreateFileMappingW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingW>
ENDIF

CreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFile equ <CreateFileW>
ENDIF

CreateFontIndirectA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CreateFontIndirect equ <CreateFontIndirectA>
ENDIF

CreateProcessA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateProcess equ <CreateProcessA>
ENDIF

CreateThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DebugBreak PROTO STDCALL
DeleteCriticalSection PROTO STDCALL :DWORD
DeleteDC PROTO STDCALL :DWORD

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeleteFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteFile equ <DeleteFileW>
ENDIF

DeleteObject PROTO STDCALL :DWORD
DeviceIoControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DosDateTimeToFileTime PROTO STDCALL :DWORD,:DWORD,:DWORD

EndUpdateResourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EndUpdateResource equ <EndUpdateResourceA>
ENDIF

EnterCriticalSection PROTO STDCALL :DWORD

EnumResourceNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumResourceNames equ <EnumResourceNamesA>
ENDIF

EnumResourceNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumResourceNames equ <EnumResourceNamesW>
ENDIF

EnumResourceTypesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumResourceTypes equ <EnumResourceTypesW>
ENDIF

ExitProcess PROTO STDCALL :DWORD
FileTimeToDosDateTime PROTO STDCALL :DWORD,:DWORD,:DWORD
FileTimeToLocalFileTime PROTO STDCALL :DWORD,:DWORD
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

FindResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindResource equ <FindResourceW>
ENDIF

FlushFileBuffers PROTO STDCALL :DWORD

FormatMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FormatMessage equ <FormatMessageA>
ENDIF

FormatMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FormatMessage equ <FormatMessageW>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
GetACP PROTO STDCALL

GetCurrentDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryA>
ENDIF

GetCurrentDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetCurrentDirectory equ <GetCurrentDirectoryW>
ENDIF

GetCurrentThreadId PROTO STDCALL

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetDateFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDateFormat equ <GetDateFormatW>
ENDIF

GetDiskFreeSpaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceA>
ENDIF

GetDiskFreeSpaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDiskFreeSpace equ <GetDiskFreeSpaceW>
ENDIF

GetDriveTypeA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetDriveType equ <GetDriveTypeA>
ENDIF

GetDriveTypeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetDriveType equ <GetDriveTypeW>
ENDIF

GetEnvironmentVariableA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetEnvironmentVariable equ <GetEnvironmentVariableA>
ENDIF

GetEnvironmentVariableW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetEnvironmentVariable equ <GetEnvironmentVariableW>
ENDIF

GetFileAttributesA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesA>
ENDIF

GetFileAttributesExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFileAttributesEx equ <GetFileAttributesExA>
ENDIF

GetFileAttributesExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFileAttributesEx equ <GetFileAttributesExW>
ENDIF

GetFileAttributesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesW>
ENDIF

GetFileSize PROTO STDCALL :DWORD,:DWORD
GetFocus PROTO STDCALL

GetFullPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameA>
ENDIF

GetFullPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetFullPathName equ <GetFullPathNameW>
ENDIF

GetLastError PROTO STDCALL
GetLogicalDrives PROTO STDCALL
GetMailslotInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetPrivateProfileIntA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileInt equ <GetPrivateProfileIntA>
ENDIF

GetPrivateProfileIntW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrivateProfileInt equ <GetPrivateProfileIntW>
ENDIF

GetPrivateProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrivateProfileString equ <GetPrivateProfileStringA>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetProcessHeap PROTO STDCALL

GetShortPathNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetShortPathName equ <GetShortPathNameA>
ENDIF

GetShortPathNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetShortPathName equ <GetShortPathNameW>
ENDIF

GetSystemDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemDirectory equ <GetSystemDirectoryA>
ENDIF

GetSystemMetrics PROTO STDCALL :DWORD

GetTempFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempFileName equ <GetTempFileNameA>
ENDIF

GetTempPathA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempPath equ <GetTempPathA>
ENDIF

GetTextMetricsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTextMetrics equ <GetTextMetricsA>
ENDIF

GetThreadLocale PROTO STDCALL
GetTickCount PROTO STDCALL

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

GetTimeFormatW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatW>
ENDIF

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

GetVolumeInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumeInformation equ <GetVolumeInformationW>
ENDIF

GetVolumeNameForVolumeMountPointW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumeNameForVolumeMountPoint equ <GetVolumeNameForVolumeMountPointW>
ENDIF

GetWindowRect PROTO STDCALL :DWORD,:DWORD

GetWindowTextA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetWindowText equ <GetWindowTextA>
ENDIF

GetWindowTextW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowText equ <GetWindowTextW>
ENDIF

GetWindowsDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryA>
ENDIF

GetWindowsDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryW>
ENDIF

GlobalAlloc PROTO STDCALL :DWORD,:DWORD
HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSize PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapValidate PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InitializeSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
IsBadWritePtr PROTO STDCALL :DWORD,:DWORD
IsDBCSLeadByte PROTO STDCALL :DWORD
IsWindow PROTO STDCALL :DWORD
LeaveCriticalSection PROTO STDCALL :DWORD

LoadCursorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadCursor equ <LoadCursorA>
ENDIF

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LoadLibraryExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExA>
ENDIF

LoadLibraryExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExW>
ENDIF

LoadResource PROTO STDCALL :DWORD,:DWORD
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFileTimeToFileTime PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
LockResource PROTO STDCALL :DWORD
MapViewOfFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

MessageBoxA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MessageBox equ <MessageBoxA>
ENDIF

MessageBoxW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MessageBox equ <MessageBoxW>
ENDIF

MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OemToCharBuffA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OemToCharBuff equ <OemToCharBuffA>
ENDIF

OpenEventA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenEvent equ <OpenEventA>
ENDIF

OpenFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenFileMapping equ <OpenFileMappingA>
ENDIF

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

RegCreateKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExA>
ENDIF

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegDeleteKeyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyA>
ENDIF

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegEnumKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegEnumKey equ <RegEnumKeyA>
ENDIF

RegEnumKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumKey equ <RegEnumKeyW>
ENDIF

RegEnumValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegEnumValue equ <RegEnumValueA>
ENDIF

RegEnumValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumValue equ <RegEnumValueW>
ENDIF

RegOpenKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExA>
ENDIF

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegQueryInfoKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryInfoKey equ <RegQueryInfoKeyA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RemoveDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryA>
ENDIF

RemoveDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RemoveDirectory equ <RemoveDirectoryW>
ENDIF

SearchPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SearchPath equ <SearchPathA>
ENDIF

SearchPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SearchPath equ <SearchPathW>
ENDIF

SelectObject PROTO STDCALL :DWORD,:DWORD

SetCurrentDirectoryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryA>
ENDIF

SetCurrentDirectoryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetCurrentDirectory equ <SetCurrentDirectoryW>
ENDIF

SetCursor PROTO STDCALL :DWORD
SetEndOfFile PROTO STDCALL :DWORD
SetErrorMode PROTO STDCALL :DWORD
SetEvent PROTO STDCALL :DWORD

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
SetLastError PROTO STDCALL :DWORD
SetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetThreadLocale PROTO STDCALL :DWORD
SetWindowPos PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetWindowTextA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetWindowText equ <SetWindowTextA>
ENDIF

SetWindowTextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetWindowText equ <SetWindowTextW>
ENDIF

SetupCloseInfFile PROTO STDCALL :DWORD
SetupCloseLog PROTO STDCALL

SetupDecompressOrCopyFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileW>
ENDIF

SetupFindFirstLineA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupFindFirstLine equ <SetupFindFirstLineA>
ENDIF

SetupFindFirstLineW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupFindFirstLine equ <SetupFindFirstLineW>
ENDIF

SetupFindNextLine PROTO STDCALL :DWORD,:DWORD

SetupFindNextMatchLineA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupFindNextMatchLine equ <SetupFindNextMatchLineA>
ENDIF

SetupFindNextMatchLineW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupFindNextMatchLine equ <SetupFindNextMatchLineW>
ENDIF

SetupGetBinaryField PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFieldCount PROTO STDCALL :DWORD
SetupGetIntField PROTO STDCALL :DWORD,:DWORD,:DWORD

SetupGetLineByIndexA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetLineByIndex equ <SetupGetLineByIndexA>
ENDIF

SetupGetLineByIndexW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetLineByIndex equ <SetupGetLineByIndexW>
ENDIF

SetupGetLineTextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetLineText equ <SetupGetLineTextA>
ENDIF

SetupGetLineTextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetLineText equ <SetupGetLineTextW>
ENDIF

SetupGetMultiSzFieldA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetMultiSzField equ <SetupGetMultiSzFieldA>
ENDIF

SetupGetMultiSzFieldW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetMultiSzField equ <SetupGetMultiSzFieldW>
ENDIF

SetupGetStringFieldA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupGetStringField equ <SetupGetStringFieldA>
ENDIF

SetupGetStringFieldW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupGetStringField equ <SetupGetStringFieldW>
ENDIF

SetupIterateCabinetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetupIterateCabinet equ <SetupIterateCabinetW>
ENDIF

SetupLogErrorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetupLogError equ <SetupLogErrorA>
ENDIF

SetupLogErrorW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetupLogError equ <SetupLogErrorW>
ENDIF

SetupOpenAppendInfFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupOpenAppendInfFile equ <SetupOpenAppendInfFileA>
ENDIF

SetupOpenInfFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetupOpenInfFile equ <SetupOpenInfFileA>
ENDIF

SetupOpenLog PROTO STDCALL :DWORD
SizeofResource PROTO STDCALL :DWORD,:DWORD
Sleep PROTO STDCALL :DWORD
TerminateProcess PROTO STDCALL :DWORD,:DWORD
UnmapViewOfFile PROTO STDCALL :DWORD

UpdateResourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UpdateResource equ <UpdateResourceA>
ENDIF

UpdateResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UpdateResource equ <UpdateResourceW>
ENDIF

WaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_gcvt PROTO C :VARARG
_iob PROTO C :VARARG
_ismbcprint PROTO C :VARARG
_ismbcspace PROTO C :VARARG
_mbbtombc PROTO C :VARARG
_mbctolower PROTO C :VARARG
_mbschr PROTO C :VARARG
_mbscmp PROTO C :VARARG
_mbscpy PROTO C :VARARG
_mbsdec PROTO C :VARARG
_mbsicmp PROTO C :VARARG
_mbsinc PROTO C :VARARG
_mbslen PROTO C :VARARG
_mbslwr PROTO C :VARARG
_mbsncmp PROTO C :VARARG
_mbsncpy PROTO C :VARARG
_mbsnextc PROTO C :VARARG
_mbsnicmp PROTO C :VARARG
_mbsrchr PROTO C :VARARG
_mbsstr PROTO C :VARARG
_pctype PROTO C :VARARG
_setmbcp PROTO C :VARARG
_snprintf PROTO C :VARARG
_snwprintf PROTO C :VARARG
_splitpath PROTO C :VARARG
_ultoa PROTO C :VARARG
_ultow PROTO C :VARARG
_vsnprintf PROTO C :VARARG
_vsnwprintf PROTO C :VARARG
_wcsicmp PROTO C :VARARG
_wcslwr PROTO C :VARARG
_wcsnicmp PROTO C :VARARG
_wsplitpath PROTO C :VARARG
atoi PROTO C :VARARG
fprintf PROTO C :VARARG
fwprintf PROTO C :VARARG
isalpha PROTO C :VARARG
isspace PROTO C :VARARG
iswctype PROTO C :VARARG

lstrcpynA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpyn equ <lstrcpynA>
ENDIF

memmove PROTO C :VARARG
printf PROTO C :VARARG
setlocale PROTO C :VARARG
strchr PROTO C :VARARG
swprintf PROTO C :VARARG
tolower PROTO C :VARARG
towlower PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcscspn PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncmp PROTO C :VARARG
wcsncpy PROTO C :VARARG
wcsrchr PROTO C :VARARG
wcsstr PROTO C :VARARG

wsprintfA PROTO C :VARARG
IFNDEF __UNICODE__
  wsprintf equ <wsprintfA>
ENDIF

  ; wsprintfW arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file miglib.inc
  echo -----------------------------------------
ENDIF
