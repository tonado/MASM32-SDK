; --------------------------------------------------------------------------------------------------
;                           mprsnap.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MPRSNAP_INC
MPRSNAP_INC equ <1>

MprConfigServerInstallPrivate PROTO STDCALL
MprConfigServerUnattendedInstall PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file mprsnap.inc
  echo ------------------------------------------
ENDIF
