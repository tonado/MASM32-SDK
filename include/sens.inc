; --------------------------------------------------------------------------------------------------
;                            sens.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SENS_INC
SENS_INC equ <1>

SensNotifyNetconEvent PROTO STDCALL :DWORD
SensNotifyRasEvent PROTO STDCALL :DWORD
SensNotifyWinlogonEvent PROTO STDCALL :DWORD

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file sens.inc
  echo ---------------------------------------
ENDIF
