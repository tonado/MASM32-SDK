; --------------------------------------------------------------------------------------------------
;                           wmvcore.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WMVCORE_INC
WMVCORE_INC equ <1>

WMCreateBackupRestorer PROTO STDCALL :DWORD,:DWORD
WMCreateEditor PROTO STDCALL :DWORD
WMCreateIndexer PROTO STDCALL :DWORD
WMCreateProfileManager PROTO STDCALL :DWORD
WMCreateReader PROTO STDCALL :DWORD,:DWORD,:DWORD
WMCreateReaderPriv PROTO STDCALL :DWORD
WMCreateSyncReader PROTO STDCALL :DWORD,:DWORD,:DWORD
WMCreateWriter PROTO STDCALL :DWORD,:DWORD
WMCreateWriterFileSink PROTO STDCALL :DWORD
WMCreateWriterNetworkSink PROTO STDCALL :DWORD
WMCreateWriterPriv PROTO STDCALL :DWORD
WMCreateWriterPushSink PROTO STDCALL :DWORD
WMIsContentProtected PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file wmvcore.inc
  echo ------------------------------------------
ENDIF
