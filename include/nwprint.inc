; --------------------------------------------------------------------------------------------------
;                           nwprint.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NWPRINT_INC
NWPRINT_INC equ <1>

ClosePrintProcessor PROTO STDCALL :DWORD
ControlPrintProcessor PROTO STDCALL :DWORD,:DWORD

EnumPrintProcessorDatatypesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesW>
ENDIF

InstallPrintProcessor PROTO STDCALL :DWORD
OpenPrintProcessor PROTO STDCALL :DWORD,:DWORD
PrintDocumentOnPrintProcessor PROTO STDCALL :DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file nwprint.inc
  echo ------------------------------------------
ENDIF
