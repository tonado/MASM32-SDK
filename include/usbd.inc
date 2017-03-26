; --------------------------------------------------------------------------------------------------
;                            usbd.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF USBD_INC
USBD_INC equ <1>

USBD_AllocateDeviceName PROTO STDCALL :DWORD
USBD_CalculateUsbBandwidth PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_CompleteRequest PROTO STDCALL :DWORD,:DWORD
USBD_CreateConfigurationRequest PROTO STDCALL :DWORD,:DWORD
USBD_CreateConfigurationRequestEx PROTO STDCALL :DWORD,:DWORD
USBD_CreateDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBD_Debug_GetHeap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBD_Debug_LogEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBD_Debug_RetHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_Dispatch PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBD_FreeDeviceMutex PROTO STDCALL :DWORD
USBD_FreeDeviceName PROTO STDCALL :DWORD
USBD_GetDeviceInformation PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_GetInterfaceLength PROTO STDCALL :DWORD,:DWORD
USBD_GetPdoRegistryParameter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBD_GetSuspendPowerState PROTO STDCALL :DWORD
USBD_GetUSBDIVersion PROTO STDCALL :DWORD
USBD_InitializeDevice PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBD_MakePdoName PROTO STDCALL :DWORD,:DWORD
USBD_ParseConfigurationDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_ParseConfigurationDescriptorEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBD_ParseDescriptors PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
USBD_QueryBusTime PROTO STDCALL :DWORD,:DWORD
USBD_RegisterHcDeviceCapabilities PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_RegisterHcFilter PROTO STDCALL :DWORD,:DWORD
USBD_RegisterHostController PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
USBD_RemoveDevice PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_RestoreDevice PROTO STDCALL :DWORD,:DWORD,:DWORD
USBD_SetSuspendPowerState PROTO STDCALL :DWORD,:DWORD
USBD_WaitDeviceMutex PROTO STDCALL :DWORD

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file usbd.inc
  echo ---------------------------------------
ENDIF
