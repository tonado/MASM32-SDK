; --------------------------------------------------------------------------------------------------
;                          srclient.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SRCLIENT_INC
SRCLIENT_INC equ <1>

CreateSnapshot PROTO STDCALL :DWORD
DisableFIFO PROTO STDCALL :DWORD
DisableSR PROTO STDCALL :DWORD
EnableFIFO PROTO STDCALL
EnableSR PROTO STDCALL :DWORD
EnableSREx PROTO STDCALL :DWORD,:DWORD
ResetSR PROTO STDCALL :DWORD
RestoreSnapshot PROTO STDCALL :DWORD
SRCompress PROTO STDCALL :DWORD
SRFifo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SRFreeze PROTO STDCALL :DWORD
SRNotify PROTO STDCALL :DWORD,:DWORD,:DWORD
SRPrintState PROTO STDCALL
SRRegisterSnapshotCallback PROTO STDCALL :DWORD
SRRemoveRestorePoint PROTO STDCALL :DWORD

SRSetRestorePointA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SRSetRestorePoint equ <SRSetRestorePointA>
ENDIF

SRSetRestorePointW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SRSetRestorePoint equ <SRSetRestorePointW>
ENDIF

SRSwitchLog PROTO STDCALL
SRUnregisterSnapshotCallback PROTO STDCALL :DWORD
SRUpdateDSSize PROTO STDCALL :DWORD,:DWORD,:DWORD

SRUpdateMonitoredListA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SRUpdateMonitoredList equ <SRUpdateMonitoredListA>
ENDIF

SRUpdateMonitoredListW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SRUpdateMonitoredList equ <SRUpdateMonitoredListW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file srclient.inc
  echo -------------------------------------------
ENDIF
