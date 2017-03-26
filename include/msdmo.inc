; --------------------------------------------------------------------------------------------------
;                            msdmo.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSDMO_INC
MSDMO_INC equ <1>

DMOEnum PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DMOGetName PROTO STDCALL :DWORD,:DWORD
DMOGetTypes PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DMOGuidToStrA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DMOGuidToStr equ <DMOGuidToStrA>
ENDIF

DMOGuidToStrW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DMOGuidToStr equ <DMOGuidToStrW>
ENDIF

DMORegister PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DMOStrToGuidA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DMOStrToGuid equ <DMOStrToGuidA>
ENDIF

DMOStrToGuidW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DMOStrToGuid equ <DMOStrToGuidW>
ENDIF

DMOUnregister PROTO STDCALL :DWORD,:DWORD
MoCopyMediaType PROTO STDCALL :DWORD,:DWORD
MoCreateMediaType PROTO STDCALL :DWORD,:DWORD
MoDeleteMediaType PROTO STDCALL :DWORD
MoDuplicateMediaType PROTO STDCALL :DWORD,:DWORD
MoFreeMediaType PROTO STDCALL :DWORD
MoInitMediaType PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file msdmo.inc
  echo ----------------------------------------
ENDIF
