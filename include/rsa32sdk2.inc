; --------------------------------------------------------------------------------------------------
;                          rsa32sdk2.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RSA32SDK2_INC
RSA32SDK2_INC equ <1>

RtlMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------------
  echo WARNING duplicate include file rsa32sdk2.inc
  echo --------------------------------------------
ENDIF
