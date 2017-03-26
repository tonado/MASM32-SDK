; --------------------------------------------------------------------------------------------------
;                           stream.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF STREAM_INC
STREAM_INC equ <1>

StreamClassAbortOutstandingRequests PROTO STDCALL :DWORD,:DWORD,:DWORD
StreamClassCallAtNewPriority PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StreamClassCompleteRequestAndMarkQueueReady PROTO STDCALL :DWORD
StreamClassDebugAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StreamClassDebugPrint PROTO C :VARARG
StreamClassDeviceNotification PROTO C :VARARG
StreamClassFilterReenumerateStreams PROTO STDCALL :DWORD,:DWORD
StreamClassGetDmaBuffer PROTO STDCALL :DWORD
StreamClassGetNextEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StreamClassGetPhysicalAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StreamClassLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StreamClassPnPAddDeviceWorker PROTO STDCALL :DWORD,:DWORD,:DWORD
StreamClassQueryMasterClock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StreamClassQueryMasterClockSync PROTO STDCALL :DWORD,:DWORD
StreamClassReadWriteConfig PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StreamClassReenumerateStreams PROTO STDCALL :DWORD,:DWORD
StreamClassRegisterAdapter PROTO STDCALL :DWORD,:DWORD,:DWORD
StreamClassRegisterFilterWithNoKSPins PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StreamClassScheduleTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
  ; StreamClassStreamNotification arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file stream.inc
  echo -----------------------------------------
ENDIF
