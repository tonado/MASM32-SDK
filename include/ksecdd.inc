; --------------------------------------------------------------------------------------------------
;                           ksecdd.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF KSECDD_INC
KSECDD_INC equ <1>

AcceptSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AcquireCredentialsHandleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AcquireCredentialsHandle equ <AcquireCredentialsHandleW>
ENDIF

AddCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddCredentials equ <AddCredentialsW>
ENDIF

ApplyControlToken PROTO STDCALL :DWORD,:DWORD
CredMarshalTargetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
DeleteSecurityContext PROTO STDCALL :DWORD
EfsDecryptFek PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EfsGenerateKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

EnumerateSecurityPackagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumerateSecurityPackages equ <EnumerateSecurityPackagesW>
ENDIF

ExportSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FreeContextBuffer PROTO STDCALL :DWORD
FreeCredentialsHandle PROTO STDCALL :DWORD
GenerateDirEfs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GenerateSessionKey PROTO STDCALL :DWORD
GetSecurityUserInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
ImpersonateSecurityContext PROTO STDCALL :DWORD

ImportSecurityContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImportSecurityContext equ <ImportSecurityContextW>
ENDIF

InitSecurityInterfaceW PROTO STDCALL
IFDEF __UNICODE__
  InitSecurityInterface equ <InitSecurityInterfaceW>
ENDIF

InitializeSecurityContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InitializeSecurityContext equ <InitializeSecurityContextW>
ENDIF

KSecRegisterSecurityProvider PROTO STDCALL :DWORD,:DWORD
KSecValidateBuffer PROTO STDCALL :DWORD,:DWORD
LsaEnumerateLogonSessions PROTO STDCALL :DWORD,:DWORD
LsaGetLogonSessionData PROTO STDCALL :DWORD,:DWORD
MakeSignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MapSecurityError PROTO STDCALL :DWORD

QueryContextAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryContextAttributes equ <QueryContextAttributesW>
ENDIF

QueryCredentialsAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryCredentialsAttributes equ <QueryCredentialsAttributesW>
ENDIF

QuerySecurityContextToken PROTO STDCALL :DWORD,:DWORD

QuerySecurityPackageInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  QuerySecurityPackageInfo equ <QuerySecurityPackageInfoW>
ENDIF

RevertSecurityContext PROTO STDCALL :DWORD
SealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SecLookupAccountName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SecLookupAccountSid PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SecMakeSPN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SecMakeSPNEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SecSetPagingMode PROTO STDCALL :DWORD
UnsealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VerifySignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file ksecdd.inc
  echo -----------------------------------------
ENDIF
