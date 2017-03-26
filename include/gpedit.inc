; --------------------------------------------------------------------------------------------------
;                           gpedit.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF GPEDIT_INC
GPEDIT_INC equ <1>

BrowseForGPO PROTO STDCALL :DWORD
CreateGPOLink PROTO STDCALL :DWORD,:DWORD,:DWORD
CreateRSOPQuery PROTO STDCALL :DWORD,:DWORD
DeleteAllGPOLinks PROTO STDCALL :DWORD
DeleteGPOLink PROTO STDCALL :DWORD,:DWORD
ExportRSoPData PROTO STDCALL :DWORD,:DWORD
FreeRSOPQuery PROTO STDCALL :DWORD
FreeRSOPQueryResults PROTO STDCALL :DWORD,:DWORD
ImportRSoPData PROTO STDCALL :DWORD,:DWORD
RunRSOPQuery PROTO STDCALL :DWORD,:DWORD,:DWORD
SetSysvolSecurityFromDSSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file gpedit.inc
  echo -----------------------------------------
ENDIF
