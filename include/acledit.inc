; --------------------------------------------------------------------------------------------------
;                           acledit.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ACLEDIT_INC
ACLEDIT_INC equ <1>

DllMain PROTO STDCALL :DWORD,:DWORD,:DWORD

FMExtensionProcW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FMExtensionProc equ <FMExtensionProcW>
ENDIF

SedDiscretionaryAclEditor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SedSystemAclEditor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SedTakeOwnership PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file acledit.inc
  echo ------------------------------------------
ENDIF
