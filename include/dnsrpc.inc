; --------------------------------------------------------------------------------------------------
;                           dnsrpc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DNSRPC_INC
DNSRPC_INC equ <1>

CoCreateInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInitialize PROTO STDCALL :DWORD
CoInitializeSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoSetProxyBlanket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoUninitialize PROTO STDCALL
FileTimeToSystemTime PROTO STDCALL :DWORD,:DWORD

GetComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerName equ <GetComputerNameA>
ENDIF

GetComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerName equ <GetComputerNameW>
ENDIF

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetLastError PROTO STDCALL

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

InterlockedIncrement PROTO STDCALL :DWORD
RpcBindingFree PROTO STDCALL :DWORD

RpcBindingFromStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingFromStringBinding equ <RpcBindingFromStringBindingW>
ENDIF

RpcBindingSetAuthInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoA>
ENDIF

RpcStringBindingComposeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcStringBindingCompose equ <RpcStringBindingComposeW>
ENDIF

RpcStringFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcStringFree equ <RpcStringFreeW>
ENDIF

SafeArrayAccessData PROTO STDCALL :DWORD,:DWORD
SafeArrayCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
SafeArrayDestroy PROTO STDCALL :DWORD
SafeArrayGetElement PROTO STDCALL :DWORD,:DWORD,:DWORD
SafeArrayGetLBound PROTO STDCALL :DWORD,:DWORD,:DWORD
SafeArrayGetUBound PROTO STDCALL :DWORD,:DWORD,:DWORD
SafeArrayPutElement PROTO STDCALL :DWORD,:DWORD,:DWORD
SafeArrayUnaccessData PROTO STDCALL :DWORD
SetLastError PROTO STDCALL :DWORD
Sleep PROTO STDCALL :DWORD
SysAllocString PROTO STDCALL :DWORD
SysFreeString PROTO STDCALL :DWORD
SystemTimeToTzSpecificLocalTime PROTO STDCALL :DWORD,:DWORD,:DWORD
VariantClear PROTO STDCALL :DWORD
VariantCopy PROTO STDCALL :DWORD,:DWORD
VariantInit PROTO STDCALL :DWORD
WSAGetLastError PROTO STDCALL
WSAStartup PROTO STDCALL :DWORD,:DWORD
_itoa PROTO C :VARARG
_ltow PROTO C :VARARG
_stricmp PROTO C :VARARG
_ultow PROTO C :VARARG
_wcsicmp PROTO C :VARARG
_wtoi64 PROTO C :VARARG
ctime PROTO C :VARARG
free PROTO C :VARARG
getprotobynumber PROTO STDCALL :DWORD
getservbyport PROTO STDCALL :DWORD,:DWORD
htons PROTO STDCALL :DWORD
inet_addr PROTO STDCALL :DWORD
inet_ntoa PROTO STDCALL :DWORD
malloc PROTO C :VARARG
printf PROTO C :VARARG
realloc PROTO C :VARARG
sprintf PROTO C :VARARG
strchr PROTO C :VARARG
strncpy PROTO C :VARARG
swprintf PROTO C :VARARG
wcscat PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncpy PROTO C :VARARG
  ; wsprintfW arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dnsrpc.inc
  echo -----------------------------------------
ENDIF
