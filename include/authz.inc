; --------------------------------------------------------------------------------------------------
;                            authz.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF AUTHZ_INC
AUTHZ_INC equ <1>

AuthzAccessCheck PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzAddSidsToContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzCachedAccessCheck PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzFreeAuditEvent PROTO STDCALL :DWORD
AuthzFreeContext PROTO STDCALL :DWORD
AuthzFreeHandle PROTO STDCALL :DWORD
AuthzFreeResourceManager PROTO STDCALL :DWORD
AuthzGetInformationFromContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromAuthzContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeObjectAccessAuditEvent PROTO C :VARARG
AuthzInitializeResourceManager PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzOpenObjectAudit PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthziLogAuditEvent PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file authz.inc
  echo ----------------------------------------
ENDIF
