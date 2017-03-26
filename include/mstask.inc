; --------------------------------------------------------------------------------------------------
;                           mstask.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSTASK_INC
MSTASK_INC equ <1>

ConvertAtJobsToTasks PROTO STDCALL
GetNetScheduleAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
NetrJobAdd PROTO STDCALL :DWORD,:DWORD,:DWORD
NetrJobDel PROTO STDCALL :DWORD,:DWORD,:DWORD
NetrJobEnum PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NetrJobGetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
SAGetAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SAGetNSAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
SASetAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SASetNSAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
SetNetScheduleAccountInformation PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file mstask.inc
  echo -----------------------------------------
ENDIF
