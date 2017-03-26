; --------------------------------------------------------------------------------------------------
;                           sisbkup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SISBKUP_INC
SISBKUP_INC equ <1>

SisCSFilesToBackupForLink PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SisCreateBackupStructure PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SisCreateRestoreStructure PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SisFreeAllocatedMemory PROTO STDCALL :DWORD
SisFreeBackupStructure PROTO STDCALL :DWORD
SisFreeRestoreStructure PROTO STDCALL :DWORD
SisRestoredCommonStoreFile PROTO STDCALL :DWORD,:DWORD
SisRestoredLink PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file sisbkup.inc
  echo ------------------------------------------
ENDIF
