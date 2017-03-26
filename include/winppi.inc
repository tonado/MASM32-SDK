; --------------------------------------------------------------------------------------------------
;                           winppi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINPPI_INC
WINPPI_INC equ <1>

CancelDC PROTO STDCALL :DWORD

CreateDCA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDC equ <CreateDCA>
ENDIF

CreateDCW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateDC equ <CreateDCW>
ENDIF

DeleteDC PROTO STDCALL :DWORD
GdiDeleteSpoolFileHandle PROTO STDCALL :DWORD
GdiEndDocEMF PROTO STDCALL :DWORD
GdiEndPageEMF PROTO STDCALL :DWORD,:DWORD
GdiGetDC PROTO STDCALL :DWORD
GdiGetDevmodeForPage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GdiGetPageCount PROTO STDCALL :DWORD
GdiGetPageHandle PROTO STDCALL :DWORD,:DWORD,:DWORD
GdiGetSpoolFileHandle PROTO STDCALL :DWORD,:DWORD,:DWORD
GdiGetSpoolMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GdiInitSpool PROTO STDCALL
GdiPlayEMF PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GdiPlayPageEMF PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GdiPlayPrivatePageEMF PROTO STDCALL :DWORD,:DWORD,:DWORD
GdiQueryFonts PROTO STDCALL :DWORD,:DWORD,:DWORD
GdiResetDCEMF PROTO STDCALL :DWORD,:DWORD
GdiStartDocEMF PROTO STDCALL :DWORD,:DWORD
GdiStartPageEMF PROTO STDCALL :DWORD
GetCharWidthInfo PROTO STDCALL :DWORD,:DWORD
GetDeviceCaps PROTO STDCALL :DWORD,:DWORD
GetWorldTransform PROTO STDCALL :DWORD,:DWORD
ModifyWorldTransform PROTO STDCALL :DWORD,:DWORD,:DWORD

ResetDCA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ResetDC equ <ResetDCA>
ENDIF

ResetDCW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ResetDC equ <ResetDCW>
ENDIF

SetGraphicsMode PROTO STDCALL :DWORD,:DWORD
SetWorldTransform PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file winppi.inc
  echo -----------------------------------------
ENDIF
