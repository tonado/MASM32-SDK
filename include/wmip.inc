; --------------------------------------------------------------------------------------------------
;                            wmip.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WMIP_INC
WMIP_INC equ <1>

CloseTrace PROTO STDCALL :DWORD,:DWORD

ControlTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ControlTrace equ <ControlTraceA>
ENDIF

ControlTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ControlTrace equ <ControlTraceW>
ENDIF

CreateTraceInstanceId PROTO STDCALL :DWORD,:DWORD
EnableTrace PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTraceEnableFlags PROTO STDCALL :DWORD,:DWORD
GetTraceEnableLevel PROTO STDCALL :DWORD,:DWORD
GetTraceLoggerHandle PROTO STDCALL :DWORD

OpenTraceA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OpenTrace equ <OpenTraceA>
ENDIF

OpenTraceW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OpenTrace equ <OpenTraceW>
ENDIF

ProcessTrace PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

QueryAllTracesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryAllTraces equ <QueryAllTracesA>
ENDIF

QueryAllTracesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryAllTraces equ <QueryAllTracesW>
ENDIF

RegisterTraceGuidsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterTraceGuids equ <RegisterTraceGuidsA>
ENDIF

RegisterTraceGuidsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegisterTraceGuids equ <RegisterTraceGuidsW>
ENDIF

RemoveTraceCallback PROTO STDCALL :DWORD
SetTraceCallback PROTO STDCALL :DWORD,:DWORD

StartTraceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StartTrace equ <StartTraceA>
ENDIF

StartTraceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartTrace equ <StartTraceW>
ENDIF

TraceEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
TraceEventInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UnregisterTraceGuids PROTO STDCALL :DWORD,:DWORD
WmiCloseBlock PROTO STDCALL :DWORD

WmiDevInstToInstanceNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiDevInstToInstanceName equ <WmiDevInstToInstanceNameA>
ENDIF

WmiDevInstToInstanceNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiDevInstToInstanceName equ <WmiDevInstToInstanceNameW>
ENDIF

WmiEnumerateGuids PROTO STDCALL :DWORD,:DWORD

WmiExecuteMethodA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiExecuteMethod equ <WmiExecuteMethodA>
ENDIF

WmiExecuteMethodW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiExecuteMethod equ <WmiExecuteMethodW>
ENDIF

WmiFileHandleToInstanceNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiFileHandleToInstanceName equ <WmiFileHandleToInstanceNameA>
ENDIF

WmiFileHandleToInstanceNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiFileHandleToInstanceName equ <WmiFileHandleToInstanceNameW>
ENDIF

WmiFreeBuffer PROTO STDCALL :DWORD

WmiMofEnumerateResourcesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiMofEnumerateResources equ <WmiMofEnumerateResourcesA>
ENDIF

WmiMofEnumerateResourcesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiMofEnumerateResources equ <WmiMofEnumerateResourcesW>
ENDIF

WmiNotificationRegistrationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiNotificationRegistration equ <WmiNotificationRegistrationA>
ENDIF

WmiNotificationRegistrationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiNotificationRegistration equ <WmiNotificationRegistrationW>
ENDIF

WmiOpenBlock PROTO STDCALL :DWORD,:DWORD,:DWORD

WmiQueryAllDataA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiQueryAllData equ <WmiQueryAllDataA>
ENDIF

WmiQueryAllDataW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiQueryAllData equ <WmiQueryAllDataW>
ENDIF

WmiQueryGuidInformation PROTO STDCALL :DWORD,:DWORD

WmiQuerySingleInstanceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiQuerySingleInstance equ <WmiQuerySingleInstanceA>
ENDIF

WmiQuerySingleInstanceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiQuerySingleInstance equ <WmiQuerySingleInstanceW>
ENDIF

WmiSetSingleInstanceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiSetSingleInstance equ <WmiSetSingleInstanceA>
ENDIF

WmiSetSingleInstanceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiSetSingleInstance equ <WmiSetSingleInstanceW>
ENDIF

WmiSetSingleItemA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WmiSetSingleItem equ <WmiSetSingleItemA>
ENDIF

WmiSetSingleItemW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WmiSetSingleItem equ <WmiSetSingleItemW>
ENDIF

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file wmip.inc
  echo ---------------------------------------
ENDIF
