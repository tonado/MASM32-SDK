; --------------------------------------------------------------------------------------------------
;                           nddeapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NDDEAPI_INC
NDDEAPI_INC equ <1>

NDdeGetErrorStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeGetErrorString equ <NDdeGetErrorStringA>
ENDIF

NDdeGetErrorStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeGetErrorString equ <NDdeGetErrorStringW>
ENDIF

NDdeGetShareSecurityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeGetShareSecurity equ <NDdeGetShareSecurityA>
ENDIF

NDdeGetShareSecurityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeGetShareSecurity equ <NDdeGetShareSecurityW>
ENDIF

NDdeGetTrustedShareA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeGetTrustedShare equ <NDdeGetTrustedShareA>
ENDIF

NDdeGetTrustedShareW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeGetTrustedShare equ <NDdeGetTrustedShareW>
ENDIF

NDdeIsValidAppTopicListA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  NDdeIsValidAppTopicList equ <NDdeIsValidAppTopicListA>
ENDIF

NDdeIsValidAppTopicListW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NDdeIsValidAppTopicList equ <NDdeIsValidAppTopicListW>
ENDIF

NDdeIsValidShareNameA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  NDdeIsValidShareName equ <NDdeIsValidShareNameA>
ENDIF

NDdeIsValidShareNameW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  NDdeIsValidShareName equ <NDdeIsValidShareNameW>
ENDIF

NDdeSetShareSecurityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeSetShareSecurity equ <NDdeSetShareSecurityA>
ENDIF

NDdeSetShareSecurityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeSetShareSecurity equ <NDdeSetShareSecurityW>
ENDIF

NDdeSetTrustedShareA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeSetTrustedShare equ <NDdeSetTrustedShareA>
ENDIF

NDdeSetTrustedShareW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeSetTrustedShare equ <NDdeSetTrustedShareW>
ENDIF

NDdeShareAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeShareAdd equ <NDdeShareAddA>
ENDIF

NDdeShareAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeShareAdd equ <NDdeShareAddW>
ENDIF

NDdeShareDelA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeShareDel equ <NDdeShareDelA>
ENDIF

NDdeShareDelW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeShareDel equ <NDdeShareDelW>
ENDIF

NDdeShareEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeShareEnum equ <NDdeShareEnumA>
ENDIF

NDdeShareEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeShareEnum equ <NDdeShareEnumW>
ENDIF

NDdeShareGetInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeShareGetInfo equ <NDdeShareGetInfoA>
ENDIF

NDdeShareGetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeShareGetInfo equ <NDdeShareGetInfoW>
ENDIF

NDdeShareSetInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeShareSetInfo equ <NDdeShareSetInfoA>
ENDIF

NDdeShareSetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeShareSetInfo equ <NDdeShareSetInfoW>
ENDIF

NDdeSpecialCommandA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeSpecialCommand equ <NDdeSpecialCommandA>
ENDIF

NDdeSpecialCommandW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeSpecialCommand equ <NDdeSpecialCommandW>
ENDIF

NDdeTrustedShareEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  NDdeTrustedShareEnum equ <NDdeTrustedShareEnumA>
ENDIF

NDdeTrustedShareEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  NDdeTrustedShareEnum equ <NDdeTrustedShareEnumW>
ENDIF

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file nddeapi.inc
  echo ------------------------------------------
ENDIF
