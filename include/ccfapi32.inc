; --------------------------------------------------------------------------------------------------
;                          ccfapi32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CCFAPI32_INC
CCFAPI32_INC equ <1>

CCFCertificateEnterUI PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CCFCertificateRemoveUI PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NoCertificateEnter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NoCertificateRemove PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file ccfapi32.inc
  echo -------------------------------------------
ENDIF
