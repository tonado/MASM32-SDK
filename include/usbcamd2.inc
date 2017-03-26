; --------------------------------------------------------------------------------------------------
;                          usbcamd2.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF USBCAMD2_INC
USBCAMD2_INC equ <1>

USBCAMD_AdapterReceivePacket PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_ControlVendorCommand PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_Debug_LogEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_DriverEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_GetRegistryKeyValue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_InitializeNewInterface PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBCAMD_SelectAlternateInterface PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file usbcamd2.inc
  echo -------------------------------------------
ENDIF
