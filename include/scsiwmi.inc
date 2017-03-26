; --------------------------------------------------------------------------------------------------
;                           scsiwmi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCSIWMI_INC
SCSIWMI_INC equ <1>

ScsiPortMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
  ; ScsiPortNotification arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file scsiwmi.inc
  echo ------------------------------------------
ENDIF
