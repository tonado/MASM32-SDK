; --------------------------------------------------------------------------------------------------
;                           mswsock.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSWSOCK_INC
MSWSOCK_INC equ <1>

AcceptEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

EnumProtocolsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumProtocols equ <EnumProtocolsA>
ENDIF

EnumProtocolsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumProtocols equ <EnumProtocolsW>
ENDIF

GetAcceptExSockaddrs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetAddressByNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetAddressByName equ <GetAddressByNameA>
ENDIF

GetAddressByNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAddressByName equ <GetAddressByNameW>
ENDIF

GetNameByTypeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNameByType equ <GetNameByTypeA>
ENDIF

GetNameByTypeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNameByType equ <GetNameByTypeW>
ENDIF

GetServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetService equ <GetServiceA>
ENDIF

GetServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetService equ <GetServiceW>
ENDIF

GetTypeByNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTypeByName equ <GetTypeByNameA>
ENDIF

GetTypeByNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetTypeByName equ <GetTypeByNameW>
ENDIF

MigrateWinsockConfiguration PROTO STDCALL :DWORD,:DWORD,:DWORD
NPLoadNameSpaces PROTO STDCALL :DWORD,:DWORD,:DWORD

SetServiceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetService equ <SetServiceA>
ENDIF

SetServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetService equ <SetServiceW>
ENDIF

TransmitFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSARecvEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
dn_expand PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
getnetbyname PROTO STDCALL :DWORD
inet_network PROTO STDCALL :DWORD
rcmd PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rexec PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rresvport PROTO STDCALL :DWORD
s_perror PROTO STDCALL :DWORD,:DWORD
sethostname PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file mswsock.inc
  echo ------------------------------------------
ENDIF
