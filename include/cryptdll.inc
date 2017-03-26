; --------------------------------------------------------------------------------------------------
;                          cryptdll.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CRYPTDLL_INC
CRYPTDLL_INC equ <1>

CDBuildIntegrityVect PROTO STDCALL :DWORD,:DWORD
CDBuildVect PROTO STDCALL :DWORD,:DWORD
CDFindCommonCSystem PROTO STDCALL :DWORD,:DWORD,:DWORD
CDFindCommonCSystemWithKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CDGenerateRandomBits PROTO STDCALL :DWORD,:DWORD
CDLocateCSystem PROTO STDCALL :DWORD,:DWORD
CDLocateCheckSum PROTO STDCALL :DWORD,:DWORD
CDLocateRng PROTO STDCALL :DWORD,:DWORD
CDRegisterCSystem PROTO STDCALL :DWORD
CDRegisterCheckSum PROTO STDCALL :DWORD
CDRegisterRng PROTO STDCALL :DWORD
MD5Final PROTO STDCALL :DWORD
MD5Init PROTO STDCALL :DWORD
MD5Update PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file cryptdll.inc
  echo -------------------------------------------
ENDIF
