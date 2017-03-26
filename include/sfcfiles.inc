; --------------------------------------------------------------------------------------------------
;                          sfcfiles.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SFCFILES_INC
SFCFILES_INC equ <1>

SfcGetFiles PROTO STDCALL :DWORD,:DWORD
pSfcGetFilesList PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file sfcfiles.inc
  echo -------------------------------------------
ENDIF
