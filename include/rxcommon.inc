; --------------------------------------------------------------------------------------------------
;                          rxcommon.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RXCOMMON_INC
RXCOMMON_INC equ <1>

isdigit PROTO C :VARARG
wcscat PROTO C :VARARG
wcscpy PROTO C :VARARG
  ; wcslen arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file rxcommon.inc
  echo -------------------------------------------
ENDIF
