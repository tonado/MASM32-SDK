; --------------------------------------------------------------------------------------------------
;                            tape.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TAPE_INC
TAPE_INC equ <1>

KeBugCheckEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeTickCount PROTO C :VARARG
TapeClassAllocateSrbBuffer PROTO STDCALL :DWORD,:DWORD
TapeClassCompareMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
TapeClassInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
TapeClassLiDiv PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TapeClassLogicalBlockToPhysicalBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TapeClassPhysicalBlockToLogicalBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
TapeClassZeroMemory PROTO STDCALL :DWORD,:DWORD
  ; TapeDebugPrint arg type unknown

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file tape.inc
  echo ---------------------------------------
ENDIF
