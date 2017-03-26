; --------------------------------------------------------------------------------------------------
;                           rpcutil.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RPCUTIL_INC
RPCUTIL_INC equ <1>

EnterCriticalSection PROTO STDCALL :DWORD

GetComputerNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerNameEx equ <GetComputerNameExW>
ENDIF

GetComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerName equ <GetComputerNameW>
ENDIF

I_RpcMapWin32Status PROTO STDCALL :DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InitializeSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
LeaveCriticalSection PROTO STDCALL :DWORD
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
LocalHandle PROTO STDCALL :DWORD
LocalReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
LocalSize PROTO STDCALL :DWORD
NtClose PROTO STDCALL :DWORD
NtOpenKey PROTO STDCALL :DWORD,:DWORD,:DWORD
NtQuerySecurityObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcBindingFree PROTO STDCALL :DWORD

RpcBindingFromStringBindingW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcBindingFromStringBinding equ <RpcBindingFromStringBindingW>
ENDIF

RpcMgmtStopServerListening PROTO STDCALL :DWORD
RpcMgmtWaitServerListen PROTO STDCALL
RpcServerListen PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerRegisterIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUnregisterIf PROTO STDCALL :DWORD,:DWORD,:DWORD
RpcServerUnregisterIfEx PROTO STDCALL :DWORD,:DWORD,:DWORD

RpcServerUseProtseqEpW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcServerUseProtseqEp equ <RpcServerUseProtseqEpW>
ENDIF

RpcStringBindingComposeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcStringBindingCompose equ <RpcStringBindingComposeW>
ENDIF

RpcStringFreeW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RpcStringFree equ <RpcStringFreeW>
ENDIF

RtlAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlCompareUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlFreeHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlGetAce PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlGetDaclSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlQueryInformationAcl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetSecurityDescriptorDacl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file rpcutil.inc
  echo ------------------------------------------
ENDIF
