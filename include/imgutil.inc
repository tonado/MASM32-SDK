; --------------------------------------------------------------------------------------------------
;                           imgutil.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF IMGUTIL_INC
IMGUTIL_INC equ <1>

ComputeInvCMAP PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreateDDrawSurfaceOnDIB PROTO STDCALL :DWORD,:DWORD
CreateMIMEMap PROTO STDCALL :DWORD
DecodeImage PROTO STDCALL :DWORD,:DWORD,:DWORD
DitherTo8 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetMaxMIMEIDBytes PROTO STDCALL :DWORD
IdentifyMIMEType PROTO STDCALL :DWORD,:DWORD,:DWORD
SniffStream PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file imgutil.inc
  echo ------------------------------------------
ENDIF
