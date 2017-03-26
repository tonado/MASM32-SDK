; --------------------------------------------------------------------------------------------------
;                           hcaport.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF HCAPORT_INC
HCAPORT_INC equ <1>

HcaportAllocateCommonBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HcaportAllocateMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HcaportClearAllBits PROTO STDCALL :DWORD
HcaportClearBits PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportCompareMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportConnectInterrupt PROTO STDCALL :DWORD
HcaportCopyMemory PROTO C :VARARG
HcaportFindClearBitsAndSet PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportFreeCommonBuffer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HcaportFreeMemory PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HcaportInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportInitializeBitMap PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
HcaportPrint PROTO C :VARARG
HcaportQueryAdapterRegistryDirect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HcaportQueryAdapterRegistryKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HcaportTranslateVirtualAddress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HcaportZeroMemory PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file hcaport.inc
  echo ------------------------------------------
ENDIF
