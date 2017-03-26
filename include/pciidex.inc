; --------------------------------------------------------------------------------------------------
;                           pciidex.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PCIIDEX_INC
PCIIDEX_INC equ <1>

PciIdeXDebugPrint PROTO C :VARARG
PciIdeXGetBusData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PciIdeXInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PciIdeXSetBusData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file pciidex.inc
  echo ------------------------------------------
ENDIF
