; --------------------------------------------------------------------------------------------------
;                          twain_32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF TWAIN_32_INC
TWAIN_32_INC equ <1>

AboutDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ChooseDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DSM_Entry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InfoHook PROTO STDCALL :DWORD,:DWORD,:DWORD
WGDlgProc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file twain_32.inc
  echo -------------------------------------------
ENDIF
