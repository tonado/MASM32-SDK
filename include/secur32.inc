; --------------------------------------------------------------------------------------------------
;                           secur32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SECUR32_INC
SECUR32_INC equ <1>

AcceptSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AcquireCredentialsHandleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AcquireCredentialsHandle equ <AcquireCredentialsHandleA>
ENDIF

AcquireCredentialsHandleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AcquireCredentialsHandle equ <AcquireCredentialsHandleW>
ENDIF

AddCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddCredentials equ <AddCredentialsA>
ENDIF

AddCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddCredentials equ <AddCredentialsW>
ENDIF

AddSecurityPackageA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  AddSecurityPackage equ <AddSecurityPackageA>
ENDIF

AddSecurityPackageW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  AddSecurityPackage equ <AddSecurityPackageW>
ENDIF

ApplyControlToken PROTO STDCALL :DWORD,:DWORD
CompleteAuthToken PROTO STDCALL :DWORD,:DWORD
DecryptMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DeleteSecurityContext PROTO STDCALL :DWORD

DeleteSecurityPackageA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteSecurityPackage equ <DeleteSecurityPackageA>
ENDIF

DeleteSecurityPackageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteSecurityPackage equ <DeleteSecurityPackageW>
ENDIF

EncryptMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

EnumerateSecurityPackagesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumerateSecurityPackages equ <EnumerateSecurityPackagesA>
ENDIF

EnumerateSecurityPackagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumerateSecurityPackages equ <EnumerateSecurityPackagesW>
ENDIF

ExportSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FreeContextBuffer PROTO STDCALL :DWORD
FreeCredentialsHandle PROTO STDCALL :DWORD

GetComputerObjectNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetComputerObjectName equ <GetComputerObjectNameA>
ENDIF

GetComputerObjectNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerObjectName equ <GetComputerObjectNameW>
ENDIF

GetUserNameExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserNameEx equ <GetUserNameExA>
ENDIF

GetUserNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUserNameEx equ <GetUserNameExW>
ENDIF

ImpersonateSecurityContext PROTO STDCALL :DWORD

ImportSecurityContextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ImportSecurityContext equ <ImportSecurityContextA>
ENDIF

ImportSecurityContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ImportSecurityContext equ <ImportSecurityContextW>
ENDIF

InitSecurityInterfaceA PROTO STDCALL
IFNDEF __UNICODE__
  InitSecurityInterface equ <InitSecurityInterfaceA>
ENDIF

InitSecurityInterfaceW PROTO STDCALL
IFDEF __UNICODE__
  InitSecurityInterface equ <InitSecurityInterfaceW>
ENDIF

InitializeSecurityContextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InitializeSecurityContext equ <InitializeSecurityContextA>
ENDIF

InitializeSecurityContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InitializeSecurityContext equ <InitializeSecurityContextW>
ENDIF

LsaCallAuthenticationPackage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaConnectUntrusted PROTO STDCALL :DWORD
LsaDeregisterLogonProcess PROTO STDCALL :DWORD
LsaEnumerateLogonSessions PROTO STDCALL :DWORD,:DWORD
LsaFreeReturnBuffer PROTO STDCALL :DWORD
LsaGetLogonSessionData PROTO STDCALL :DWORD,:DWORD
LsaLogonUser PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupAuthenticationPackage PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaRegisterLogonProcess PROTO STDCALL :DWORD,:DWORD,:DWORD
LsaRegisterPolicyChangeNotification PROTO STDCALL :DWORD,:DWORD
LsaUnregisterPolicyChangeNotification PROTO STDCALL :DWORD,:DWORD
MakeSignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

QueryContextAttributesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryContextAttributes equ <QueryContextAttributesA>
ENDIF

QueryContextAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryContextAttributes equ <QueryContextAttributesW>
ENDIF

QueryCredentialsAttributesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryCredentialsAttributes equ <QueryCredentialsAttributesA>
ENDIF

QueryCredentialsAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryCredentialsAttributes equ <QueryCredentialsAttributesW>
ENDIF

QuerySecurityContextToken PROTO STDCALL :DWORD,:DWORD

QuerySecurityPackageInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  QuerySecurityPackageInfo equ <QuerySecurityPackageInfoA>
ENDIF

QuerySecurityPackageInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  QuerySecurityPackageInfo equ <QuerySecurityPackageInfoW>
ENDIF

RevertSecurityContext PROTO STDCALL :DWORD
SaslAcceptSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SaslEnumerateProfilesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SaslEnumerateProfiles equ <SaslEnumerateProfilesA>
ENDIF

SaslEnumerateProfilesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SaslEnumerateProfiles equ <SaslEnumerateProfilesW>
ENDIF

SaslGetProfilePackageA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SaslGetProfilePackage equ <SaslGetProfilePackageA>
ENDIF

SaslGetProfilePackageW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SaslGetProfilePackage equ <SaslGetProfilePackageW>
ENDIF

SaslIdentifyPackageA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SaslIdentifyPackage equ <SaslIdentifyPackageA>
ENDIF

SaslIdentifyPackageW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SaslIdentifyPackage equ <SaslIdentifyPackageW>
ENDIF

SaslInitializeSecurityContextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SaslInitializeSecurityContext equ <SaslInitializeSecurityContextA>
ENDIF

SaslInitializeSecurityContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SaslInitializeSecurityContext equ <SaslInitializeSecurityContextW>
ENDIF

SealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetContextAttributesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetContextAttributes equ <SetContextAttributesA>
ENDIF

SetContextAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetContextAttributes equ <SetContextAttributesW>
ENDIF

TranslateNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  TranslateName equ <TranslateNameA>
ENDIF

TranslateNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  TranslateName equ <TranslateNameW>
ENDIF

UnsealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VerifySignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file secur32.inc
  echo ------------------------------------------
ENDIF
