; --------------------------------------------------------------------------------------------------
;                           ntquery.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTQUERY_INC
NTQUERY_INC equ <1>

BindIFilterFromStorage PROTO STDCALL :DWORD,:DWORD,:DWORD
BindIFilterFromStream PROTO STDCALL :DWORD,:DWORD,:DWORD
CIBuildQueryNode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIBuildQueryTree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CICreateCommand PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIGetGlobalPropertyList PROTO STDCALL :DWORD
CIMakeICommand PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIRestrictionToFullTree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIState PROTO STDCALL :DWORD,:DWORD,:DWORD
CITextToFullTree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToFullTreeEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToSelectTree PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToSelectTreeEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LoadIFilter PROTO STDCALL :DWORD,:DWORD,:DWORD

LocateCatalogsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LocateCatalogs equ <LocateCatalogsA>
ENDIF

LocateCatalogsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LocateCatalogs equ <LocateCatalogsW>
ENDIF

SetCatalogState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntquery.inc
  echo ------------------------------------------
ENDIF
