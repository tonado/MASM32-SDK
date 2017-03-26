; --------------------------------------------------------------------------------------------------
;                          mobsyncp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MOBSYNCP_INC
MOBSYNCP_INC equ <1>

DisplayOptions PROTO STDCALL :DWORD
MobsyncGetClassObject PROTO STDCALL :DWORD,:DWORD
RegGetHandlerRegistrationInfo PROTO STDCALL :DWORD,:DWORD
RegGetHandlerTopLevelKey PROTO STDCALL :DWORD
RegGetProgressDetailsState PROTO STDCALL :DWORD,:DWORD,:DWORD
RegGetSchedConnectionName PROTO STDCALL :DWORD,:DWORD,:DWORD
RegGetSchedSyncSettings PROTO STDCALL :DWORD,:DWORD
RegGetSyncItemSettings PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegGetSyncSettings PROTO STDCALL :DWORD,:DWORD
RegQueryLoadHandlerOnEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
RegRemoveManualSyncSettings PROTO STDCALL :DWORD
RegSchedHandlerItemsChecked PROTO STDCALL :DWORD,:DWORD,:DWORD
RegSetProgressDetailsState PROTO STDCALL :DWORD,:DWORD,:DWORD
RegSetSyncItemSettings PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegSetUserDefaults PROTO STDCALL
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
  echo -------------------------------------------
  echo WARNING duplicate include file mobsyncp.inc
  echo -------------------------------------------
ENDIF
