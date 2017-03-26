; --------------------------------------------------------------------------------------------------
;                           mobsync.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MOBSYNC_INC
MOBSYNC_INC equ <1>

RunDllRegister PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SyncMgrResolveConflictA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SyncMgrResolveConflict equ <SyncMgrResolveConflictA>
ENDIF

SyncMgrResolveConflictW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SyncMgrResolveConflict equ <SyncMgrResolveConflictW>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file mobsync.inc
  echo ------------------------------------------
ENDIF
