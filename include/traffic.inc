; --------------------------------------------------------------------------------------------------
;                           traffic.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TRAFFIC_INC
TRAFFIC_INC equ <1>

TcAddClassMap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcAddFilter PROTO STDCALL :DWORD,:DWORD,:DWORD
TcAddFlow PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcCloseInterface PROTO STDCALL :DWORD
TcDeleteFilter PROTO STDCALL :DWORD
TcDeleteFlow PROTO STDCALL :DWORD
TcDeregisterClient PROTO STDCALL :DWORD
TcEnumerateFlows PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcEnumerateInterfaces PROTO STDCALL :DWORD,:DWORD,:DWORD

TcGetFlowNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TcGetFlowName equ <TcGetFlowNameA>
ENDIF

TcGetFlowNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TcGetFlowName equ <TcGetFlowNameW>
ENDIF

TcModifyFlow PROTO STDCALL :DWORD,:DWORD

TcOpenInterfaceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TcOpenInterface equ <TcOpenInterfaceA>
ENDIF

TcOpenInterfaceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TcOpenInterface equ <TcOpenInterfaceW>
ENDIF

TcQueryFlowA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TcQueryFlow equ <TcQueryFlowA>
ENDIF

TcQueryFlowW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TcQueryFlow equ <TcQueryFlowW>
ENDIF

TcQueryInterface PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcRegisterClient PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

TcSetFlowA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TcSetFlow equ <TcSetFlowA>
ENDIF

TcSetFlowW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TcSetFlow equ <TcSetFlowW>
ENDIF

TcSetInterface PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file traffic.inc
  echo ------------------------------------------
ENDIF
