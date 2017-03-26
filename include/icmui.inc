; --------------------------------------------------------------------------------------------------
;                            icmui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ICMUI_INC
ICMUI_INC equ <1>

SetupColorMatchingA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetupColorMatching equ <SetupColorMatchingA>
ENDIF

SetupColorMatchingW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetupColorMatching equ <SetupColorMatchingW>
ENDIF

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file icmui.inc
  echo ----------------------------------------
ENDIF
