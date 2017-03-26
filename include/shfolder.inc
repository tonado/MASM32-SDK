; --------------------------------------------------------------------------------------------------
;                          shfolder.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SHFOLDER_INC
SHFOLDER_INC equ <1>

SHGetFolderPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SHGetFolderPath equ <SHGetFolderPathA>
ENDIF

SHGetFolderPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SHGetFolderPath equ <SHGetFolderPathW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file shfolder.inc
  echo -------------------------------------------
ENDIF
