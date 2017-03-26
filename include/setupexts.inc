; --------------------------------------------------------------------------------------------------
;                          setupexts.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SETUPEXTS_INC
SETUPEXTS_INC equ <1>

error PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
gle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
help PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
infdump PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ocm PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
qcontext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
queue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
space PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_st PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
stfind PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
version PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
winntflags PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
winntstr PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------------
  echo WARNING duplicate include file setupexts.inc
  echo --------------------------------------------
ENDIF
