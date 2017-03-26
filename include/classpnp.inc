; --------------------------------------------------------------------------------------------------
;                          classpnp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CLASSPNP_INC
CLASSPNP_INC equ <1>

ClassAcquireChildLock PROTO STDCALL :DWORD
ClassAcquireRemoveLockEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClassAsynchronousCompletion PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassBuildRequest PROTO STDCALL :DWORD,:DWORD
ClassCheckMediaState PROTO STDCALL :DWORD
ClassClaimDevice PROTO STDCALL :DWORD,:DWORD
ClassCleanupMediaChangeDetection PROTO STDCALL :DWORD
ClassCompleteRequest PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassCreateDeviceObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassDebugPrint PROTO C :VARARG
ClassDeleteSrbLookasideList PROTO STDCALL :DWORD
ClassDeviceControl PROTO STDCALL :DWORD,:DWORD
ClassDisableMediaChangeDetection PROTO STDCALL :DWORD
ClassEnableMediaChangeDetection PROTO STDCALL :DWORD
ClassFindModePage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClassForwardIrpSynchronous PROTO STDCALL :DWORD,:DWORD
ClassGetDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassGetDeviceParameter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClassGetDriverExtension PROTO STDCALL :DWORD
ClassGetVpb PROTO STDCALL :DWORD
ClassInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassInitializeEx PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassInitializeMediaChangeDetection PROTO STDCALL :DWORD,:DWORD
ClassInitializeSrbLookasideList PROTO STDCALL :DWORD,:DWORD
ClassInitializeTestUnitPolling PROTO STDCALL :DWORD,:DWORD
ClassInternalIoControl PROTO STDCALL :DWORD,:DWORD
ClassInterpretSenseInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassInvalidateBusRelations PROTO STDCALL :DWORD
ClassIoComplete PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassIoCompleteAssociated PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassMarkChildMissing PROTO STDCALL :DWORD,:DWORD
ClassMarkChildrenMissing PROTO STDCALL :DWORD
ClassModeSense PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClassNotifyFailurePredicted PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassQueryTimeOutRegistryValue PROTO STDCALL :DWORD
ClassReadDriveCapacity PROTO STDCALL :DWORD
ClassReleaseChildLock PROTO STDCALL :DWORD
ClassReleaseQueue PROTO STDCALL :DWORD
ClassReleaseRemoveLock PROTO STDCALL :DWORD,:DWORD
ClassRemoveDevice PROTO STDCALL :DWORD,:DWORD
ClassResetMediaChangeTimer PROTO STDCALL :DWORD
ClassScanForSpecial PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassSendDeviceIoControlSynchronous PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassSendIrpSynchronous PROTO STDCALL :DWORD,:DWORD
ClassSendSrbAsynchronous PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassSendSrbSynchronous PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassSendStartUnit PROTO STDCALL :DWORD
ClassSetDeviceParameter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClassSetFailurePredictionPoll PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassSetMediaChangeState PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassSignalCompletion PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassSpinDownPowerHandler PROTO STDCALL :DWORD,:DWORD
ClassSplitRequest PROTO STDCALL :DWORD,:DWORD,:DWORD
ClassStopUnitPowerHandler PROTO STDCALL :DWORD,:DWORD
ClassUpdateInformationInRegistry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassWmiCompleteRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClassWmiFireEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file classpnp.inc
  echo -------------------------------------------
ENDIF
