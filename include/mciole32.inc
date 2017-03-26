; --------------------------------------------------------------------------------------------------
;                          mciole32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MCIOLE32_INC
MCIOLE32_INC equ <1>

DllCreate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllCreateFromClip PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllCreateFromFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllCreateFromTemplate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllCreateLinkFromClip PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllCreateLinkFromFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllLoadFromStream PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetMessageHook PROTO STDCALL :DWORD,:DWORD,:DWORD
InstallHook PROTO STDCALL :DWORD,:DWORD
OleQueryObjPos PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RemoveHook PROTO STDCALL

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file mciole32.inc
  echo -------------------------------------------
ENDIF
