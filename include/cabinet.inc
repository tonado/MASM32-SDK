; --------------------------------------------------------------------------------------------------
;                           cabinet.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CABINET_INC
CABINET_INC equ <1>

DeleteExtractedFiles PROTO STDCALL :DWORD
DllGetVersion PROTO STDCALL :DWORD
Extract PROTO STDCALL :DWORD,:DWORD
FCIAddFile PROTO C :VARARG
FCICreate PROTO C :VARARG
FCIDestroy PROTO C :VARARG
FCIFlushCabinet PROTO C :VARARG
FCIFlushFolder PROTO C :VARARG
FDICopy PROTO C :VARARG
FDICreate PROTO C :VARARG
FDIDestroy PROTO C :VARARG
FDIIsCabinet PROTO C :VARARG
FDITruncateCabinet PROTO C :VARARG
GetDllVersion PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file cabinet.inc
  echo ------------------------------------------
ENDIF
