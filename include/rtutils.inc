; --------------------------------------------------------------------------------------------------
;                           rtutils.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RTUTILS_INC
RTUTILS_INC equ <1>

CreateWaitEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateWaitEventBinding PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateWaitTimer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DeRegisterWaitEventBinding PROTO STDCALL :DWORD
DeRegisterWaitEventBindingSelf PROTO STDCALL :DWORD
DeRegisterWaitEventsTimers PROTO STDCALL :DWORD,:DWORD
DeRegisterWaitEventsTimersSelf PROTO STDCALL :DWORD,:DWORD
DebugPrintWaitWorkerThreads PROTO STDCALL :DWORD

LogErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LogError equ <LogErrorA>
ENDIF

LogErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogError equ <LogErrorW>
ENDIF

LogEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LogEvent equ <LogEventA>
ENDIF

LogEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LogEvent equ <LogEventW>
ENDIF

MprSetupProtocolEnum PROTO STDCALL :DWORD,:DWORD,:DWORD
MprSetupProtocolFree PROTO STDCALL :DWORD
QueueWorkItem PROTO STDCALL :DWORD,:DWORD,:DWORD
RegisterWaitEventBinding PROTO STDCALL :DWORD
RegisterWaitEventsTimers PROTO STDCALL :DWORD,:DWORD
RouterAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

RouterGetErrorStringA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RouterGetErrorString equ <RouterGetErrorStringA>
ENDIF

RouterGetErrorStringW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RouterGetErrorString equ <RouterGetErrorStringW>
ENDIF

RouterLogDeregisterA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RouterLogDeregister equ <RouterLogDeregisterA>
ENDIF

RouterLogDeregisterW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RouterLogDeregister equ <RouterLogDeregisterW>
ENDIF

RouterLogEventA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RouterLogEvent equ <RouterLogEventA>
ENDIF

RouterLogEventDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RouterLogEventData equ <RouterLogEventDataA>
ENDIF

RouterLogEventDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RouterLogEventData equ <RouterLogEventDataW>
ENDIF

RouterLogEventExA PROTO C :VARARG
IFNDEF __UNICODE__
  RouterLogEventEx equ <RouterLogEventExA>
ENDIF

RouterLogEventExW PROTO C :VARARG
IFDEF __UNICODE__
  RouterLogEventEx equ <RouterLogEventExW>
ENDIF

RouterLogEventStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RouterLogEventString equ <RouterLogEventStringA>
ENDIF

RouterLogEventStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RouterLogEventString equ <RouterLogEventStringW>
ENDIF

RouterLogEventValistExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RouterLogEventValistEx equ <RouterLogEventValistExA>
ENDIF

RouterLogEventValistExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RouterLogEventValistEx equ <RouterLogEventValistExW>
ENDIF

RouterLogEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RouterLogEvent equ <RouterLogEventW>
ENDIF

RouterLogRegisterA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RouterLogRegister equ <RouterLogRegisterA>
ENDIF

RouterLogRegisterW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RouterLogRegister equ <RouterLogRegisterW>
ENDIF

SetIoCompletionProc PROTO STDCALL :DWORD,:DWORD

TraceDeregisterA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  TraceDeregister equ <TraceDeregisterA>
ENDIF

TraceDeregisterExA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  TraceDeregisterEx equ <TraceDeregisterExA>
ENDIF

TraceDeregisterExW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  TraceDeregisterEx equ <TraceDeregisterExW>
ENDIF

TraceDeregisterW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  TraceDeregister equ <TraceDeregisterW>
ENDIF

TraceDumpExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TraceDumpEx equ <TraceDumpExA>
ENDIF

TraceDumpExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TraceDumpEx equ <TraceDumpExW>
ENDIF

TraceGetConsoleA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  TraceGetConsole equ <TraceGetConsoleA>
ENDIF

TraceGetConsoleW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  TraceGetConsole equ <TraceGetConsoleW>
ENDIF

TracePrintfA PROTO C :VARARG
IFNDEF __UNICODE__
  TracePrintf equ <TracePrintfA>
ENDIF

TracePrintfExA PROTO C :VARARG
IFNDEF __UNICODE__
  TracePrintfEx equ <TracePrintfExA>
ENDIF

TracePrintfExW PROTO C :VARARG
IFDEF __UNICODE__
  TracePrintfEx equ <TracePrintfExW>
ENDIF

TracePrintfW PROTO C :VARARG
IFDEF __UNICODE__
  TracePrintf equ <TracePrintfW>
ENDIF

TracePutsExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TracePutsEx equ <TracePutsExA>
ENDIF

TracePutsExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TracePutsEx equ <TracePutsExW>
ENDIF

TraceRegisterExA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  TraceRegisterEx equ <TraceRegisterExA>
ENDIF

TraceRegisterExW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  TraceRegisterEx equ <TraceRegisterExW>
ENDIF

TraceVprintfExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TraceVprintfEx equ <TraceVprintfExA>
ENDIF

TraceVprintfExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TraceVprintfEx equ <TraceVprintfExW>
ENDIF

UpdateWaitTimer PROTO STDCALL :DWORD,:DWORD
WTFreeEvent PROTO STDCALL :DWORD
WTFreeTimer PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file rtutils.inc
  echo ------------------------------------------
ENDIF
