; --------------------------------------------------------------------------------------------------
;                            wow32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WOW32_INC
WOW32_INC equ <1>

CopyDropFilesFrom16 PROTO STDCALL :DWORD
CopyDropFilesFrom32 PROTO STDCALL :DWORD
GetCommHandle PROTO STDCALL :DWORD
GetCommShadowMSR PROTO STDCALL :DWORD
W32Dispatch PROTO STDCALL
W32HungAppNotifyThread PROTO STDCALL :DWORD
W32Init PROTO STDCALL :DWORD
WOW32DriverCallback PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOW32ResolveHandle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOW32ResolveMemory PROTO STDCALL :DWORD
WOWCallback16 PROTO STDCALL :DWORD,:DWORD
WOWCallback16Ex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOWDirectedYield16 PROTO STDCALL :DWORD
WOWFreeMetafile PROTO STDCALL :DWORD
WOWGetVDMPointer PROTO STDCALL :DWORD,:DWORD,:DWORD
WOWGetVDMPointerFix PROTO STDCALL :DWORD,:DWORD,:DWORD
WOWGetVDMPointerUnfix PROTO STDCALL :DWORD
WOWGlobalAlloc16 PROTO STDCALL :DWORD,:DWORD
WOWGlobalAllocLock16 PROTO STDCALL :DWORD,:DWORD,:DWORD
WOWGlobalFree16 PROTO STDCALL :DWORD
WOWGlobalLock16 PROTO STDCALL :DWORD
WOWGlobalLockSize16 PROTO STDCALL :DWORD,:DWORD
WOWGlobalUnlock16 PROTO STDCALL :DWORD
WOWGlobalUnlockFree16 PROTO STDCALL :DWORD
WOWHandle16 PROTO STDCALL :DWORD,:DWORD
WOWHandle32 PROTO STDCALL :DWORD,:DWORD
WOWUseMciavi16 PROTO STDCALL
WOWYield16 PROTO STDCALL

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file wow32.inc
  echo ----------------------------------------
ENDIF
