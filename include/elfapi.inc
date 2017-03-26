; --------------------------------------------------------------------------------------------------
;                           elfapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ELFAPI_INC
ELFAPI_INC equ <1>

GetComputerNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerName equ <GetComputerNameA>
ENDIF

GetComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerName equ <GetComputerNameW>
ENDIF

GetLastError PROTO STDCALL
I_RpcMapWin32Status PROTO STDCALL :DWORD
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
NtQuerySystemTime PROTO STDCALL :DWORD

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

RtlAdjustPrivilege PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlAnsiStringToUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlFreeUnicodeString PROTO STDCALL :DWORD
RtlInitAnsiString PROTO STDCALL :DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlTimeToSecondsSince1970 PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file elfapi.inc
  echo -----------------------------------------
ENDIF
