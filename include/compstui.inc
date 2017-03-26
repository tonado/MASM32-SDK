; --------------------------------------------------------------------------------------------------
;                          compstui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF COMPSTUI_INC
COMPSTUI_INC equ <1>

CommonPropertySheetUIA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CommonPropertySheetUI equ <CommonPropertySheetUIA>
ENDIF

CommonPropertySheetUIW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CommonPropertySheetUI equ <CommonPropertySheetUIW>
ENDIF

GetCPSUIUserData PROTO STDCALL :DWORD
SetCPSUIUserData PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file compstui.inc
  echo -------------------------------------------
ENDIF
