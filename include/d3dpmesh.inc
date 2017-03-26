; --------------------------------------------------------------------------------------------------
;                          d3dpmesh.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF D3DPMESH_INC
D3DPMESH_INC equ <1>

CreateD3DRMPMeshVisual PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file d3dpmesh.inc
  echo -------------------------------------------
ENDIF
