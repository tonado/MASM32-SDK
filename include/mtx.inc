; --------------------------------------------------------------------------------------------------
;                             mtx.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MTX_INC
MTX_INC equ <1>

GetObjectContext PROTO C :VARARG
MTSCreateActivity PROTO STDCALL :DWORD,:DWORD
  ; SafeRef arg type unknown

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file mtx.inc
  echo --------------------------------------
ENDIF
