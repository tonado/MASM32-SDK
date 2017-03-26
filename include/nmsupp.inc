; --------------------------------------------------------------------------------------------------
;                           nmsupp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NMSUPP_INC
NMSUPP_INC equ <1>

AdjustOperatorPrecedence PROTO STDCALL :DWORD
AllocMemory PROTO STDCALL :DWORD
AllocObject PROTO STDCALL :DWORD
AndExpression PROTO STDCALL :DWORD,:DWORD
BhAllocSystemMemory PROTO STDCALL :DWORD
BhFreeSystemMemory PROTO STDCALL :DWORD
BhGetLastError PROTO STDCALL
BhGetWindowsVersion PROTO STDCALL
BhGlobalTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
BhKillTimer PROTO STDCALL :DWORD
BhSetLastError PROTO STDCALL :DWORD
BhSetTimer PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateObjectHeap PROTO STDCALL :DWORD,:DWORD
CreatePassword PROTO STDCALL :DWORD
DestroyObjectHeap PROTO STDCALL :DWORD
DestroyPassword PROTO STDCALL :DWORD
FreeMemory PROTO STDCALL :DWORD
FreeObject PROTO STDCALL :DWORD,:DWORD
GetObjectHeapSize PROTO STDCALL :DWORD
GrowObjectHeap PROTO STDCALL :DWORD,:DWORD
InitializeExpression PROTO STDCALL :DWORD
InitializePattern PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IsDaytona PROTO STDCALL
MemorySize PROTO STDCALL :DWORD
NegatePattern PROTO STDCALL :DWORD
NormalizeAddress PROTO STDCALL :DWORD
NormalizeAddressTable PROTO STDCALL :DWORD
OrExpression PROTO STDCALL :DWORD,:DWORD
PurgeObjectHeap PROTO STDCALL :DWORD
ReallocMemory PROTO STDCALL :DWORD,:DWORD
TestMemory PROTO STDCALL :DWORD
ValidatePassword PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file nmsupp.inc
  echo -----------------------------------------
ENDIF
