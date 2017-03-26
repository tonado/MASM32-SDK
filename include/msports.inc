; --------------------------------------------------------------------------------------------------
;                           msports.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSPORTS_INC
MSPORTS_INC equ <1>

ComDBClaimNextFreePort PROTO STDCALL :DWORD,:DWORD
ComDBClaimPort PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ComDBClose PROTO STDCALL :DWORD
ComDBGetCurrentPortUsage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ComDBOpen PROTO STDCALL :DWORD
ComDBReleasePort PROTO STDCALL :DWORD,:DWORD
ComDBResizeDatabase PROTO STDCALL :DWORD,:DWORD
ParallelPortPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD
PortsClassInstaller PROTO STDCALL :DWORD,:DWORD,:DWORD
SerialDisplayAdvancedSettings PROTO STDCALL :DWORD,:DWORD,:DWORD
SerialPortPropPageProvider PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file msports.inc
  echo ------------------------------------------
ENDIF
