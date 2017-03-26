; --------------------------------------------------------------------------------------------------
;                           ksproxy.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF KSPROXY_INC
KSPROXY_INC equ <1>

KsGetMediaType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
KsGetMediaTypeCount PROTO STDCALL :DWORD,:DWORD,:DWORD
KsGetMultiplePinFactoryItems PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
KsOpenDefaultDevice PROTO STDCALL :DWORD,:DWORD,:DWORD
KsResolveRequiredAttributes PROTO STDCALL :DWORD,:DWORD
KsSynchronousDeviceControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ksproxy.inc
  echo ------------------------------------------
ENDIF
