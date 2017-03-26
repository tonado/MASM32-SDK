; --------------------------------------------------------------------------------------------------
;                           ksuser.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF KSUSER_INC
KSUSER_INC equ <1>

KsCreateAllocator PROTO STDCALL :DWORD,:DWORD,:DWORD
KsCreateClock PROTO STDCALL :DWORD,:DWORD,:DWORD
KsCreatePin PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
KsCreateTopologyNode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file ksuser.inc
  echo -----------------------------------------
ENDIF
