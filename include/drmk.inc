; --------------------------------------------------------------------------------------------------
;                            drmk.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DRMK_INC
DRMK_INC equ <1>

DrmAddContentHandlers PROTO STDCALL :DWORD,:DWORD,:DWORD
DrmCreateContentMixed PROTO STDCALL :DWORD,:DWORD,:DWORD
DrmDestroyContent PROTO STDCALL :DWORD
DrmForwardContentToDeviceObject PROTO STDCALL :DWORD,:DWORD,:DWORD
DrmForwardContentToFileObject PROTO STDCALL :DWORD,:DWORD
DrmForwardContentToInterface PROTO STDCALL :DWORD,:DWORD,:DWORD
DrmGetContentRights PROTO STDCALL :DWORD,:DWORD
DrmGetFilterDescriptor PROTO STDCALL :DWORD

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file drmk.inc
  echo ---------------------------------------
ENDIF
