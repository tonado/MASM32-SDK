; --------------------------------------------------------------------------------------------------
;                           comsvcs.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF COMSVCS_INC
COMSVCS_INC equ <1>

CoCreateActivity PROTO STDCALL :DWORD,:DWORD,:DWORD
CoCreateStdTrustable PROTO STDCALL :DWORD,:DWORD,:DWORD
CoEnterServiceDomain PROTO STDCALL :DWORD
CoLeaveServiceDomain PROTO STDCALL :DWORD
CoLoadServices PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CoVerifyTrust PROTO STDCALL :DWORD,:DWORD,:DWORD
ComSvcsExceptionFilter PROTO STDCALL :DWORD,:DWORD,:DWORD
ComSvcsLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateActivityInMTA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateActivityInMT equ <CreateActivityInMTA>
ENDIF

DispManGetContext PROTO STDCALL :DWORD,:DWORD
DllUnregisterServerWeReallyMeanIt PROTO STDCALL
GetObjectContext PROTO C :VARARG
GetTrkSvrObject PROTO STDCALL :DWORD,:DWORD
MTSCreateActivity PROTO STDCALL :DWORD,:DWORD

MiniDumpW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MiniDump equ <MiniDumpW>
ENDIF

RecycleSurrogate PROTO C :VARARG
  ; SafeRef arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file comsvcs.inc
  echo ------------------------------------------
ENDIF
