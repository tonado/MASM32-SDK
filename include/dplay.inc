; --------------------------------------------------------------------------------------------------
;                            dplay.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DPLAY_INC
DPLAY_INC equ <1>

DirectPlayCreate PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectPlayEnumerate PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file dplay.inc
  echo ----------------------------------------
ENDIF
