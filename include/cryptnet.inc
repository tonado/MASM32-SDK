; --------------------------------------------------------------------------------------------------
;                          cryptnet.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CRYPTNET_INC
CRYPTNET_INC equ <1>

CryptGetObjectUrl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptInstallCancelRetrieval PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CryptRetrieveObjectByUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlA>
ENDIF

CryptRetrieveObjectByUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlW>
ENDIF

CryptUninstallCancelRetrieval PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file cryptnet.inc
  echo -------------------------------------------
ENDIF
