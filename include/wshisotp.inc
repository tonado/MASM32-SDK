; --------------------------------------------------------------------------------------------------
;                          wshisotp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WSHISOTP_INC
WSHISOTP_INC equ <1>

WSHEnumProtocols PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WSHGetSockaddrType PROTO STDCALL :DWORD,:DWORD,:DWORD
WSHGetSocketInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSHGetWildcardSockaddr PROTO STDCALL :DWORD,:DWORD,:DWORD
WSHGetWinsockMapping PROTO STDCALL :DWORD,:DWORD
WSHNotify PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSHOpenSocket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSHSetSocketInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file wshisotp.inc
  echo -------------------------------------------
ENDIF
