; --------------------------------------------------------------------------------------------------
;                           cryptui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CRYPTUI_INC
CRYPTUI_INC equ <1>

ACUIProviderInvokeUI PROTO STDCALL :DWORD
CryptUIDlgCertMgr PROTO STDCALL :DWORD
CryptUIDlgFreeCAContext PROTO STDCALL :DWORD

CryptUIDlgSelectCA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgSelectC equ <CryptUIDlgSelectCA>
ENDIF

CryptUIDlgSelectCertificateA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgSelectCertificate equ <CryptUIDlgSelectCertificateA>
ENDIF

CryptUIDlgSelectCertificateFromStore PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CryptUIDlgSelectCertificateW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CryptUIDlgSelectCertificate equ <CryptUIDlgSelectCertificateW>
ENDIF

CryptUIDlgSelectStoreA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgSelectStore equ <CryptUIDlgSelectStoreA>
ENDIF

CryptUIDlgSelectStoreW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CryptUIDlgSelectStore equ <CryptUIDlgSelectStoreW>
ENDIF

CryptUIDlgViewCRLA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgViewCRL equ <CryptUIDlgViewCRLA>
ENDIF

CryptUIDlgViewCRLW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CryptUIDlgViewCRL equ <CryptUIDlgViewCRLW>
ENDIF

CryptUIDlgViewCTLA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgViewCTL equ <CryptUIDlgViewCTLA>
ENDIF

CryptUIDlgViewCTLW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CryptUIDlgViewCTL equ <CryptUIDlgViewCTLW>
ENDIF

CryptUIDlgViewCertificateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIDlgViewCertificate equ <CryptUIDlgViewCertificateA>
ENDIF

CryptUIDlgViewCertificatePropertiesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIDlgViewCertificateProperties equ <CryptUIDlgViewCertificatePropertiesA>
ENDIF

CryptUIDlgViewCertificatePropertiesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIDlgViewCertificateProperties equ <CryptUIDlgViewCertificatePropertiesW>
ENDIF

CryptUIDlgViewCertificateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIDlgViewCertificate equ <CryptUIDlgViewCertificateW>
ENDIF

CryptUIDlgViewContext PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CryptUIDlgViewSignerInfoA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CryptUIDlgViewSignerInfo equ <CryptUIDlgViewSignerInfoA>
ENDIF

CryptUIDlgViewSignerInfoW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CryptUIDlgViewSignerInfo equ <CryptUIDlgViewSignerInfoW>
ENDIF

CryptUIFreeCertificatePropertiesPagesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIFreeCertificatePropertiesPages equ <CryptUIFreeCertificatePropertiesPagesA>
ENDIF

CryptUIFreeCertificatePropertiesPagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIFreeCertificatePropertiesPages equ <CryptUIFreeCertificatePropertiesPagesW>
ENDIF

CryptUIFreeViewSignaturesPagesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIFreeViewSignaturesPages equ <CryptUIFreeViewSignaturesPagesA>
ENDIF

CryptUIFreeViewSignaturesPagesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIFreeViewSignaturesPages equ <CryptUIFreeViewSignaturesPagesW>
ENDIF

CryptUIGetCertificatePropertiesPagesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIGetCertificatePropertiesPages equ <CryptUIGetCertificatePropertiesPagesA>
ENDIF

CryptUIGetCertificatePropertiesPagesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIGetCertificatePropertiesPages equ <CryptUIGetCertificatePropertiesPagesW>
ENDIF

CryptUIGetViewSignaturesPagesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CryptUIGetViewSignaturesPages equ <CryptUIGetViewSignaturesPagesA>
ENDIF

CryptUIGetViewSignaturesPagesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptUIGetViewSignaturesPages equ <CryptUIGetViewSignaturesPagesW>
ENDIF

CryptUIStartCertMgr PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizBuildCTL PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizCertRequest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizCreateCertRequestNoDS PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizDigitalSign PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizExport PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizFreeCertRequestNoDS PROTO STDCALL :DWORD
CryptUIWizFreeDigitalSignContext PROTO STDCALL :DWORD
CryptUIWizImport PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUIWizQueryCertRequestNoDS PROTO STDCALL :DWORD,:DWORD
CryptUIWizSubmitCertRequestNoDS PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnrollmentCOMObjectFactory_getInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_CryptUIProtect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
I_CryptUIProtectFailure PROTO STDCALL :DWORD,:DWORD,:DWORD
LocalEnroll PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LocalEnrollNoDS PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

RetrievePKCS7FromCA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RetrievePKCS7FromC equ <RetrievePKCS7FromCA>
ENDIF

WizardFree PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file cryptui.inc
  echo ------------------------------------------
ENDIF
