; --------------------------------------------------------------------------------------------------
;                           kerbcli.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF KERBCLI_INC
KERBCLI_INC equ <1>

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
RtlInitString PROTO STDCALL :DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file kerbcli.inc
  echo ------------------------------------------
ENDIF
