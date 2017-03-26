; --------------------------------------------------------------------------------------------------
;                           lsadll.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LSADLL_INC
LSADLL_INC equ <1>

NtClose PROTO STDCALL :DWORD
NtOpenEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
NtWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
ZwClose PROTO STDCALL :DWORD
ZwConnectPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwFreeVirtualMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZwRequestWaitReplyPort PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file lsadll.inc
  echo -----------------------------------------
ENDIF
