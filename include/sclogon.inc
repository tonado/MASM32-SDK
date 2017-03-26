; --------------------------------------------------------------------------------------------------
;                           sclogon.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCLOGON_INC
SCLOGON_INC equ <1>

CertAddCertificateContextToStore PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CertCloseStore PROTO STDCALL :DWORD,:DWORD
CertCreateCertificateContext PROTO STDCALL :DWORD,:DWORD,:DWORD
CertFreeCertificateContext PROTO STDCALL :DWORD
CertGetCertificateContextProperty PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CertOpenStore PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CertSetCertificateContextProperty PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CryptAcquireContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptAcquireContext equ <CryptAcquireContextW>
ENDIF

CryptCreateHash PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDecrypt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDecryptMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDeriveKey PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptDestroyHash PROTO STDCALL :DWORD
CryptDestroyKey PROTO STDCALL :DWORD
CryptEncrypt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptEncryptMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGenRandom PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptGetHashParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetKeyParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetProvParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptGetUserKey PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptHashData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptImportPublicKeyInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptReleaseContext PROTO STDCALL :DWORD,:DWORD
CryptSetHashParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptSetProvParam PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CryptSignHashW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptSignHash equ <CryptSignHashW>
ENDIF

CryptSignMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptVerifyMessageSignature PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CryptVerifySignatureW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptVerifySignature equ <CryptVerifySignatureW>
ENDIF

DeregisterEventSource PROTO STDCALL :DWORD

FormatMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FormatMessage equ <FormatMessageW>
ENDIF

GetACP PROTO STDCALL
GetLastError PROTO STDCALL
LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

RegCloseKey PROTO STDCALL :DWORD

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

RegisterEventSourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegisterEventSource equ <RegisterEventSourceW>
ENDIF

ReportEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReportEvent equ <ReportEventW>
ENDIF

RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetLastError PROTO STDCALL :DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

lstrcpyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpy equ <lstrcpyA>
ENDIF

lstrcpyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpy equ <lstrcpyW>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

swprintf PROTO C :VARARG
vsprintf PROTO C :VARARG
wcslen PROTO C :VARARG
  ; wsprintfW arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file sclogon.inc
  echo ------------------------------------------
ENDIF
