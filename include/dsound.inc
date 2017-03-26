; --------------------------------------------------------------------------------------------------
;                           dsound.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DSOUND_INC
DSOUND_INC equ <1>

DirectSoundCaptureCreate8 PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectSoundCaptureCreate PROTO STDCALL :DWORD,:DWORD,:DWORD

DirectSoundCaptureEnumerateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateA>
ENDIF

DirectSoundCaptureEnumerateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateW>
ENDIF

DirectSoundCreate8 PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectSoundCreate PROTO STDCALL :DWORD,:DWORD,:DWORD

DirectSoundEnumerateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DirectSoundEnumerate equ <DirectSoundEnumerateA>
ENDIF

DirectSoundEnumerateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DirectSoundEnumerate equ <DirectSoundEnumerateW>
ENDIF

DirectSoundFullDuplexCreate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetDeviceID PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dsound.inc
  echo -----------------------------------------
ENDIF
