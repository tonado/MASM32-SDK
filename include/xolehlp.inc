; --------------------------------------------------------------------------------------------------
;                           xolehlp.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF XOLEHLP_INC
XOLEHLP_INC equ <1>

DtcGetTransactionManagerC PROTO C :VARARG

DtcGetTransactionManagerExA PROTO C :VARARG
IFNDEF __UNICODE__
  DtcGetTransactionManagerEx equ <DtcGetTransactionManagerExA>
ENDIF

  ; DtcGetTransactionManagerExW arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file xolehlp.inc
  echo ------------------------------------------
ENDIF
