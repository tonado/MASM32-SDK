; --------------------------------------------------------------------------------------------------
;                            aclui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ACLUI_INC
ACLUI_INC equ <1>

CreateSecurityPage PROTO STDCALL :DWORD
EditSecurity PROTO STDCALL :DWORD,:DWORD
  ; IID_ISecurityInformation arg type unknown

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file aclui.inc
  echo ----------------------------------------
ENDIF
