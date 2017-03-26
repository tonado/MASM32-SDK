; --------------------------------------------------------------------------------------------------
;                          logonsrv.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LOGONSRV_INC
LOGONSRV_INC equ <1>

DsGetDcCloseW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsGetDcClose equ <DsGetDcCloseW>
ENDIF

DsGetDcNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetDcName equ <DsGetDcNameA>
ENDIF

DsGetDcNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetDcName equ <DsGetDcNameW>
ENDIF

DsGetDcNameWithAccountA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetDcNameWithAccount equ <DsGetDcNameWithAccountA>
ENDIF

DsGetDcNameWithAccountW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetDcNameWithAccount equ <DsGetDcNameWithAccountW>
ENDIF

DsGetDcNextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetDcNext equ <DsGetDcNextA>
ENDIF

DsGetDcNextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetDcNext equ <DsGetDcNextW>
ENDIF

DsGetDcOpenA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetDcOpen equ <DsGetDcOpenA>
ENDIF

DsGetDcOpenW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetDcOpen equ <DsGetDcOpenW>
ENDIF

NetApiBufferFree PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file logonsrv.inc
  echo -------------------------------------------
ENDIF
