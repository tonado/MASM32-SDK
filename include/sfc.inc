; --------------------------------------------------------------------------------------------------
;                             sfc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SFC_INC
SFC_INC equ <1>


SRSetRestorePointA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SRSetRestorePoint equ <SRSetRestorePointA>
ENDIF

SRSetRestorePointW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SRSetRestorePoint equ <SRSetRestorePointW>
ENDIF

SfcClose PROTO STDCALL :DWORD
SfcConnectToServer PROTO STDCALL :DWORD
SfcFileException PROTO STDCALL :DWORD,:DWORD,:DWORD
SfcGetNextProtectedFile PROTO STDCALL :DWORD,:DWORD
SfcInitProt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SfcInitiateScan PROTO STDCALL :DWORD,:DWORD
SfcInstallProtectedFiles PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SfcIsFileProtected PROTO STDCALL :DWORD,:DWORD
SfcTerminateWatcherThread PROTO STDCALL
SfcWLEventLogoff PROTO STDCALL :DWORD
SfcWLEventLogon PROTO STDCALL :DWORD
SfpDeleteCatalog PROTO STDCALL :DWORD,:DWORD
SfpInstallCatalog PROTO STDCALL :DWORD,:DWORD,:DWORD
SfpVerifyFile PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file sfc.inc
  echo --------------------------------------
ENDIF
