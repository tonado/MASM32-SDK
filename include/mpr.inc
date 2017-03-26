; --------------------------------------------------------------------------------------------------
;                             mpr.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MPR_INC
MPR_INC equ <1>

MultinetGetConnectionPerformanceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceA>
ENDIF

MultinetGetConnectionPerformanceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceW>
ENDIF

WNetAddConnection2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetAddConnection2 equ <WNetAddConnection2A>
ENDIF

WNetAddConnection2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetAddConnection2 equ <WNetAddConnection2W>
ENDIF

WNetAddConnection3A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetAddConnection3 equ <WNetAddConnection3A>
ENDIF

WNetAddConnection3W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetAddConnection3 equ <WNetAddConnection3W>
ENDIF

WNetAddConnectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetAddConnection equ <WNetAddConnectionA>
ENDIF

WNetAddConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetAddConnection equ <WNetAddConnectionW>
ENDIF

WNetCancelConnection2A PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetCancelConnection2 equ <WNetCancelConnection2A>
ENDIF

WNetCancelConnection2W PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetCancelConnection2 equ <WNetCancelConnection2W>
ENDIF

WNetCancelConnectionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  WNetCancelConnection equ <WNetCancelConnectionA>
ENDIF

WNetCancelConnectionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  WNetCancelConnection equ <WNetCancelConnectionW>
ENDIF

WNetCloseEnum PROTO STDCALL :DWORD

WNetConnectionDialog1A PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  WNetConnectionDialog1 equ <WNetConnectionDialog1A>
ENDIF

WNetConnectionDialog1W PROTO STDCALL :DWORD
IFDEF __UNICODE__
  WNetConnectionDialog1 equ <WNetConnectionDialog1W>
ENDIF

WNetConnectionDialog PROTO STDCALL :DWORD,:DWORD

WNetDisconnectDialog1A PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  WNetDisconnectDialog1 equ <WNetDisconnectDialog1A>
ENDIF

WNetDisconnectDialog1W PROTO STDCALL :DWORD
IFDEF __UNICODE__
  WNetDisconnectDialog1 equ <WNetDisconnectDialog1W>
ENDIF

WNetDisconnectDialog PROTO STDCALL :DWORD,:DWORD

WNetEnumResourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetEnumResource equ <WNetEnumResourceA>
ENDIF

WNetEnumResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetEnumResource equ <WNetEnumResourceW>
ENDIF

WNetGetConnectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetConnection equ <WNetGetConnectionA>
ENDIF

WNetGetConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetConnection equ <WNetGetConnectionW>
ENDIF

WNetGetLastErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetLastError equ <WNetGetLastErrorA>
ENDIF

WNetGetLastErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetLastError equ <WNetGetLastErrorW>
ENDIF

WNetGetNetworkInformationA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetNetworkInformation equ <WNetGetNetworkInformationA>
ENDIF

WNetGetNetworkInformationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetNetworkInformation equ <WNetGetNetworkInformationW>
ENDIF

WNetGetProviderNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetProviderName equ <WNetGetProviderNameA>
ENDIF

WNetGetProviderNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetProviderName equ <WNetGetProviderNameW>
ENDIF

WNetGetResourceInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetResourceInformation equ <WNetGetResourceInformationA>
ENDIF

WNetGetResourceInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetResourceInformation equ <WNetGetResourceInformationW>
ENDIF

WNetGetResourceParentA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetResourceParent equ <WNetGetResourceParentA>
ENDIF

WNetGetResourceParentW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetResourceParent equ <WNetGetResourceParentW>
ENDIF

WNetGetUniversalNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetUniversalName equ <WNetGetUniversalNameA>
ENDIF

WNetGetUniversalNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetUniversalName equ <WNetGetUniversalNameW>
ENDIF

WNetGetUserA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetGetUser equ <WNetGetUserA>
ENDIF

WNetGetUserW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetGetUser equ <WNetGetUserW>
ENDIF

WNetOpenEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetOpenEnum equ <WNetOpenEnumA>
ENDIF

WNetOpenEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetOpenEnum equ <WNetOpenEnumW>
ENDIF

WNetSetLastErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetSetLastError equ <WNetSetLastErrorA>
ENDIF

WNetSetLastErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetSetLastError equ <WNetSetLastErrorW>
ENDIF

WNetUseConnectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WNetUseConnection equ <WNetUseConnectionA>
ENDIF

WNetUseConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WNetUseConnection equ <WNetUseConnectionW>
ENDIF

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file mpr.inc
  echo --------------------------------------
ENDIF
