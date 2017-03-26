; --------------------------------------------------------------------------------------------------
;                          schannel.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCHANNEL_INC
SCHANNEL_INC equ <1>

AcceptSecurityContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

AcquireCredentialsHandleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AcquireCredentialsHandle equ <AcquireCredentialsHandleA>
ENDIF

AcquireCredentialsHandleW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AcquireCredentialsHandle equ <AcquireCredentialsHandleW>
ENDIF

ApplyControlToken PROTO STDCALL :DWORD,:DWORD
CloseSslPerformanceData PROTO STDCALL
CollectSslPerformanceData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CompleteAuthToken PROTO STDCALL :DWORD,:DWORD
DeleteSecurityContext PROTO STDCALL :DWORD

EnumerateSecurityPackagesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  EnumerateSecurityPackages equ <EnumerateSecurityPackagesA>
ENDIF

EnumerateSecurityPackagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  EnumerateSecurityPackages equ <EnumerateSecurityPackagesW>
ENDIF

FreeContextBuffer PROTO STDCALL :DWORD
FreeCredentialsHandle PROTO STDCALL :DWORD
ImpersonateSecurityContext PROTO STDCALL :DWORD

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

MakeSignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OpenSslPerformanceData PROTO STDCALL :DWORD

QueryContextAttributesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  QueryContextAttributes equ <QueryContextAttributesA>
ENDIF

QueryContextAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryContextAttributes equ <QueryContextAttributesW>
ENDIF

QuerySecurityPackageInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  QuerySecurityPackageInfo equ <QuerySecurityPackageInfoA>
ENDIF

QuerySecurityPackageInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  QuerySecurityPackageInfo equ <QuerySecurityPackageInfoW>
ENDIF

RevertSecurityContext PROTO STDCALL :DWORD
SealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SpLsaModeInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SpUserModeInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SslCrackCertificate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SslEmptyCacheA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SslEmptyCache equ <SslEmptyCacheA>
ENDIF

SslEmptyCacheW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SslEmptyCache equ <SslEmptyCacheW>
ENDIF

SslFreeCertificate PROTO STDCALL :DWORD
SslGenerateKeyPair PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SslGenerateRandomBits PROTO STDCALL :DWORD,:DWORD
SslGetMaximumKeySize PROTO STDCALL :DWORD
SslLoadCertificate PROTO STDCALL :DWORD,:DWORD,:DWORD
UnsealMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
VerifySignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file schannel.inc
  echo -------------------------------------------
ENDIF
