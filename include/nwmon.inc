; --------------------------------------------------------------------------------------------------
;                            nwmon.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NWMON_INC
NWMON_INC equ <1>

AddPortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPort equ <AddPortW>
ENDIF

ClosePort PROTO STDCALL :DWORD

ConfigurePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConfigurePort equ <ConfigurePortW>
ENDIF

DeletePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePort equ <DeletePortW>
ENDIF

EndDocPort PROTO STDCALL :DWORD

EnumPortsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPorts equ <EnumPortsW>
ENDIF

InitializeMonitor PROTO STDCALL :DWORD
LibMain PROTO STDCALL :DWORD,:DWORD,:DWORD
OpenPort PROTO STDCALL :DWORD,:DWORD
ReadPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
StartDocPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WritePort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file nwmon.inc
  echo ----------------------------------------
ENDIF
