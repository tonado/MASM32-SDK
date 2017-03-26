; --------------------------------------------------------------------------------------------------
;                           wmilib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WMILIB_INC
WMILIB_INC equ <1>

WmiCompleteRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WmiFireEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WmiSystemControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file wmilib.inc
  echo -----------------------------------------
ENDIF
