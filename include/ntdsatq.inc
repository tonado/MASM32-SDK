; --------------------------------------------------------------------------------------------------
;                           ntdsatq.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTDSATQ_INC
NTDSATQ_INC equ <1>

AllocCacheDumpStatsToHtml PROTO STDCALL :DWORD,:DWORD
AtqAddAsyncHandle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AtqBandwidthGetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqBandwidthSetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqClearStatistics PROTO STDCALL
AtqCloseEndpoint PROTO STDCALL :DWORD
AtqCloseFileHandle PROTO STDCALL :DWORD
AtqCloseSocket PROTO STDCALL :DWORD,:DWORD
AtqContextGetInfo PROTO STDCALL :DWORD,:DWORD
AtqContextSetInfo2 PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqContextSetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqCreateBandwidthInfo PROTO STDCALL
AtqCreateEndpoint PROTO STDCALL :DWORD,:DWORD
AtqEndpointGetInfo PROTO STDCALL :DWORD,:DWORD
AtqEndpointSetInfo2 PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqEndpointSetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqFreeBandwidthInfo PROTO STDCALL :DWORD
AtqFreeContext PROTO STDCALL :DWORD,:DWORD
AtqGetAcceptExAddrs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AtqGetDatagramAddrs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AtqGetInfo PROTO STDCALL :DWORD
AtqGetStatistics PROTO STDCALL :DWORD
AtqInitialize PROTO STDCALL :DWORD
AtqPostCompletionStatus PROTO STDCALL :DWORD,:DWORD
AtqReadDirChanges PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AtqReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AtqReadSocket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AtqSetInfo2 PROTO STDCALL :DWORD,:DWORD
AtqSetInfo PROTO STDCALL :DWORD,:DWORD
AtqSpudInitialized PROTO STDCALL
AtqStartEndpoint PROTO STDCALL :DWORD
AtqStopAndCloseEndpoint PROTO STDCALL :DWORD,:DWORD,:DWORD
AtqStopEndpoint PROTO STDCALL :DWORD
AtqSyncWsaSend PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AtqTerminate PROTO STDCALL
AtqTransmitFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AtqWriteDatagramSocket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AtqWriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AtqWriteSocket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntdsatq.inc
  echo ------------------------------------------
ENDIF
