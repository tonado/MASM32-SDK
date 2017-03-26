; --------------------------------------------------------------------------------------------------
;                           snmpapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SNMPAPI_INC
SNMPAPI_INC equ <1>

SnmpSvcAddrIsIpx PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpSvcAddrToSocket PROTO STDCALL :DWORD,:DWORD
SnmpSvcGetEnterpriseOID PROTO STDCALL
SnmpSvcGetUptime PROTO STDCALL
SnmpSvcGetUptimeFromTime PROTO STDCALL :DWORD
SnmpSvcInitUptime PROTO STDCALL
SnmpSvcSetLogLevel PROTO STDCALL :DWORD
SnmpSvcSetLogType PROTO STDCALL :DWORD
SnmpTfxClose PROTO STDCALL :DWORD
SnmpTfxOpen PROTO STDCALL :DWORD,:DWORD
SnmpTfxQuery PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpUtilAnsiToUnicode PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpUtilAsnAnyCpy PROTO STDCALL :DWORD,:DWORD
SnmpUtilAsnAnyFree PROTO STDCALL :DWORD
SnmpUtilDbgPrint PROTO C :VARARG

SnmpUtilIdsToA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SnmpUtilIdsTo equ <SnmpUtilIdsToA>
ENDIF

SnmpUtilMemAlloc PROTO STDCALL :DWORD
SnmpUtilMemFree PROTO STDCALL :DWORD
SnmpUtilMemReAlloc PROTO STDCALL :DWORD,:DWORD
SnmpUtilOctetsCmp PROTO STDCALL :DWORD,:DWORD
SnmpUtilOctetsCpy PROTO STDCALL :DWORD,:DWORD
SnmpUtilOctetsFree PROTO STDCALL :DWORD
SnmpUtilOctetsNCmp PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpUtilOidAppend PROTO STDCALL :DWORD,:DWORD
SnmpUtilOidCmp PROTO STDCALL :DWORD,:DWORD
SnmpUtilOidCpy PROTO STDCALL :DWORD,:DWORD
SnmpUtilOidFree PROTO STDCALL :DWORD
SnmpUtilOidNCmp PROTO STDCALL :DWORD,:DWORD,:DWORD

SnmpUtilOidToA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SnmpUtilOidTo equ <SnmpUtilOidToA>
ENDIF

SnmpUtilPrintAsnAny PROTO STDCALL :DWORD
SnmpUtilPrintOid PROTO STDCALL :DWORD
SnmpUtilUTF8ToUnicode PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpUtilUnicodeToAnsi PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpUtilUnicodeToUTF8 PROTO STDCALL :DWORD,:DWORD,:DWORD
SnmpUtilVarBindCpy PROTO STDCALL :DWORD,:DWORD
SnmpUtilVarBindFree PROTO STDCALL :DWORD
SnmpUtilVarBindListCpy PROTO STDCALL :DWORD,:DWORD
SnmpUtilVarBindListFree PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file snmpapi.inc
  echo ------------------------------------------
ENDIF
