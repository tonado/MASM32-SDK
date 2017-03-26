; --------------------------------------------------------------------------------------------------
;                           inseng.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF INSENG_INC
INSENG_INC equ <1>

CheckForVersionConflict PROTO STDCALL
CheckTrust PROTO STDCALL :DWORD,:DWORD,:DWORD
CheckTrustEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DownloadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetICifFileFromFile PROTO STDCALL :DWORD,:DWORD
GetICifRWFileFromFile PROTO STDCALL :DWORD,:DWORD
PurgeDownloadDirectory PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file inseng.inc
  echo -----------------------------------------
ENDIF
