; --------------------------------------------------------------------------------------------------
;                           scesrv.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCESRV_INC
SCESRV_INC equ <1>

ScesrvInitializeServer PROTO STDCALL :DWORD
ScesrvTerminateServer PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file scesrv.inc
  echo -----------------------------------------
ENDIF
