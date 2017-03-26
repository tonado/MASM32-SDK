; --------------------------------------------------------------------------------------------------
;                           basesrv.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF BASESRV_INC
BASESRV_INC equ <1>

BaseSetProcessCreateNotify PROTO STDCALL :DWORD
BaseSrvNewObDirAcls PROTO C :VARARG
BaseSrvNlsLogon PROTO STDCALL :DWORD
BaseSrvNlsUpdateRegistryCache PROTO STDCALL :DWORD,:DWORD
ServerDllInitialization PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file basesrv.inc
  echo ------------------------------------------
ENDIF
