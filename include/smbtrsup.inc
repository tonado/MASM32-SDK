; --------------------------------------------------------------------------------------------------
;                          smbtrsup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SMBTRSUP_INC
SMBTRSUP_INC equ <1>

ExAcquireResourceExclusiveLite PROTO STDCALL :DWORD,:DWORD
ExAllocatePoolWithTag PROTO STDCALL :DWORD,:DWORD,:DWORD
ExDeleteResourceLite PROTO STDCALL :DWORD
ExFreePoolWithTag PROTO STDCALL :DWORD,:DWORD
ExInitializeResourceLite PROTO STDCALL :DWORD
ExQueueWorkItem PROTO STDCALL :DWORD,:DWORD
IoGetCurrentProcess PROTO STDCALL
KeAttachProcess PROTO STDCALL :DWORD
KeDetachProcess PROTO STDCALL
KeGetCurrentIrql PROTO STDCALL
KeInitializeEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeInitializeSemaphore PROTO STDCALL :DWORD,:DWORD,:DWORD
KeInitializeSpinLock PROTO STDCALL :DWORD
KeReleaseSemaphore PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
KeResetEvent PROTO STDCALL :DWORD
KeSetEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
KeWaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
KeWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MmLockPagableDataSection PROTO STDCALL :DWORD
MmMapLockedPagesSpecifyCache PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MmUnlockPagableImageSection PROTO STDCALL :DWORD
ObReferenceObjectByHandle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PsCreateSystemThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PsTerminateSystemThread PROTO STDCALL :DWORD
RtlAddAccessAllowedAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlCreateAcl PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCreateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlCreateSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
RtlDestroyHeap PROTO STDCALL :DWORD
RtlFreeHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlSetDaclSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SeExports PROTO C :VARARG
ZwClose PROTO STDCALL :DWORD
ZwCreateEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwCreateSection PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwMapViewOfSection PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZwSetEvent PROTO STDCALL :DWORD,:DWORD
ZwWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file smbtrsup.inc
  echo -------------------------------------------
ENDIF
