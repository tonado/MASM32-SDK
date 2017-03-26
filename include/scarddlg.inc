; --------------------------------------------------------------------------------------------------
;                          scarddlg.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCARDDLG_INC
SCARDDLG_INC equ <1>

GetOpenCardNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetOpenCardName equ <GetOpenCardNameA>
ENDIF

GetOpenCardNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetOpenCardName equ <GetOpenCardNameW>
ENDIF

SCardDlgExtendedError PROTO STDCALL

SCardUIDlgSelectCardA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SCardUIDlgSelectCard equ <SCardUIDlgSelectCardA>
ENDIF

SCardUIDlgSelectCardW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SCardUIDlgSelectCard equ <SCardUIDlgSelectCardW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file scarddlg.inc
  echo -------------------------------------------
ENDIF
