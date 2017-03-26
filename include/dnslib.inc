; --------------------------------------------------------------------------------------------------
;                           dnslib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DNSLIB_INC
DNSLIB_INC equ <1>

AddAccessAllowedAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AllocConsole PROTO STDCALL
CloseHandle PROTO STDCALL :DWORD

CompareStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CompareString equ <CompareStringA>
ENDIF

CompareStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CompareString equ <CompareStringW>
ENDIF

CreateEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateEvent equ <CreateEventA>
ENDIF

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

DebugBreak PROTO STDCALL
DeleteCriticalSection PROTO STDCALL :DWORD
EnterCriticalSection PROTO STDCALL :DWORD
FlushFileBuffers PROTO STDCALL :DWORD
FreeLibrary PROTO STDCALL :DWORD
GetConsoleScreenBufferInfo PROTO STDCALL :DWORD,:DWORD
GetCurrentProcess PROTO STDCALL
GetCurrentProcessId PROTO STDCALL
GetCurrentThread PROTO STDCALL
GetCurrentThreadId PROTO STDCALL

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetLastError PROTO STDCALL
GetLengthSid PROTO STDCALL :DWORD
GetLocalTime PROTO STDCALL :DWORD

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetSidSubAuthority PROTO STDCALL :DWORD,:DWORD
GetSidSubAuthorityCount PROTO STDCALL :DWORD
GetStdHandle PROTO STDCALL :DWORD
GetTickCount PROTO STDCALL

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

GetTokenInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImpersonateLoggedOnUser PROTO STDCALL :DWORD
InitializeAcl PROTO STDCALL :DWORD,:DWORD,:DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InitializeSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD

LCMapStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LCMapString equ <LCMapStringW>
ENDIF

LeaveCriticalSection PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LoadLibraryExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExW>
ENDIF

LoadStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadString equ <LoadStringW>
ENDIF

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
LocalReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD

LogonUserW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogonUser equ <LogonUserW>
ENDIF

MoveFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFileEx equ <MoveFileExA>
ENDIF

MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenProcessToken PROTO STDCALL :DWORD,:DWORD,:DWORD
OpenThreadToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

ReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCreateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlDeleteCriticalSection PROTO STDCALL :DWORD
RtlDestroyHeap PROTO STDCALL :DWORD
RtlFreeHeap PROTO STDCALL :DWORD,:DWORD,:DWORD

RtlIpv6AddressToStringA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RtlIpv6AddressToString equ <RtlIpv6AddressToStringA>
ENDIF

RtlIpv6AddressToStringW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RtlIpv6AddressToString equ <RtlIpv6AddressToStringW>
ENDIF

RtlIpv6StringToAddressA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RtlIpv6StringToAddress equ <RtlIpv6StringToAddressA>
ENDIF

RtlIpv6StringToAddressExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RtlIpv6StringToAddressEx equ <RtlIpv6StringToAddressExW>
ENDIF

RtlIpv6StringToAddressW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RtlIpv6StringToAddress equ <RtlIpv6StringToAddressW>
ENDIF

RtlReAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetConsoleScreenBufferSize PROTO STDCALL :DWORD,:DWORD
SetEvent PROTO STDCALL :DWORD
SetLastError PROTO STDCALL :DWORD
SetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
Sleep PROTO STDCALL :DWORD
UuidCreateSequential PROTO STDCALL :DWORD
WSAGetLastError PROTO STDCALL
WSAStartup PROTO STDCALL :DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_snprintf PROTO C :VARARG
_strlwr PROTO C :VARARG
_strnicmp PROTO C :VARARG
_strupr PROTO C :VARARG
_vsnprintf PROTO C :VARARG
atoi PROTO C :VARARG
getprotobyname PROTO STDCALL :DWORD
getprotobynumber PROTO STDCALL :DWORD
getservbyport PROTO STDCALL :DWORD,:DWORD
gmtime PROTO C :VARARG
htonl PROTO STDCALL :DWORD
htons PROTO STDCALL :DWORD
inet_addr PROTO STDCALL :DWORD
inet_ntoa PROTO STDCALL :DWORD
isdigit PROTO C :VARARG
ntohl PROTO STDCALL :DWORD
ntohs PROTO STDCALL :DWORD
printf PROTO C :VARARG
sprintf PROTO C :VARARG
sscanf PROTO C :VARARG
strncmp PROTO C :VARARG
strncpy PROTO C :VARARG
strtok PROTO C :VARARG
strtol PROTO C :VARARG
strtoul PROTO C :VARARG
swprintf PROTO C :VARARG
time PROTO C :VARARG
wcscat PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncpy PROTO C :VARARG
wcstok PROTO C :VARARG
wcstoul PROTO C :VARARG
  ; wsprintfW arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dnslib.inc
  echo -----------------------------------------
ENDIF
