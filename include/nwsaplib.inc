; --------------------------------------------------------------------------------------------------
;                          nwsaplib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NWSAPLIB_INC
NWSAPLIB_INC equ <1>

NtClose PROTO STDCALL :DWORD
NtConnectPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtRequestWaitReplyPort PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file nwsaplib.inc
  echo -------------------------------------------
ENDIF
