; --------------------------------------------------------------------------------------------------
;                             sti.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF STI_INC
STI_INC equ <1>

MigrateRegisteredSTIAppsForWIAEvents PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RegSTIforWia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

StiCreateInstanceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StiCreateInstance equ <StiCreateInstanceA>
ENDIF

StiCreateInstanceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StiCreateInstance equ <StiCreateInstanceW>
ENDIF

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file sti.inc
  echo --------------------------------------
ENDIF
