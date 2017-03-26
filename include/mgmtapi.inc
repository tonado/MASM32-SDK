; --------------------------------------------------------------------------------------------------
;                           mgmtapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MGMTAPI_INC
MGMTAPI_INC equ <1>

SnmpMgrClose PROTO STDCALL :DWORD
SnmpMgrCtl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrGetTrap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrGetTrapEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrOidToStr PROTO STDCALL :DWORD,:DWORD
SnmpMgrOpen PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrStrToOid PROTO STDCALL :DWORD,:DWORD
SnmpMgrTrapListen PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file mgmtapi.inc
  echo ------------------------------------------
ENDIF
