; --------------------------------------------------------------------------------------------------
;                             nt.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NT_INC
NT_INC equ <1>

NtTerminateProcess PROTO STDCALL :DWORD,:DWORD
RtlAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlNormalizeProcessParams PROTO STDCALL :DWORD
RtlUnicodeStringToAnsiString PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------
  echo WARNING duplicate include file nt.inc
  echo -------------------------------------
ENDIF
