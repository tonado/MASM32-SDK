; --------------------------------------------------------------------------------------------------
;                          dnscrcli.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DNSCRCLI_INC
DNSCRCLI_INC equ <1>

RpcBindingFree PROTO STDCALL :DWORD

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

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file dnscrcli.inc
  echo -------------------------------------------
ENDIF
