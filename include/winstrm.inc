; --------------------------------------------------------------------------------------------------
;                           winstrm.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINSTRM_INC
WINSTRM_INC equ <1>

OpenStream PROTO STDCALL :DWORD
getmsg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
poll PROTO STDCALL :DWORD,:DWORD,:DWORD
putmsg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
s_ioctl PROTO STDCALL :DWORD,:DWORD,:DWORD
s_open PROTO STDCALL :DWORD,:DWORD,:DWORD
s_perror PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file winstrm.inc
  echo ------------------------------------------
ENDIF
