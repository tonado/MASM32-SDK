; --------------------------------------------------------------------------------------------------
;                           ntlsapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTLSAPI_INC
NTLSAPI_INC equ <1>

NtLSFreeHandle PROTO C :VARARG

NtLicenseRequestA PROTO C :VARARG
IFNDEF __UNICODE__
  NtLicenseRequest equ <NtLicenseRequestA>
ENDIF

  ; NtLicenseRequestW arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntlsapi.inc
  echo ------------------------------------------
ENDIF
