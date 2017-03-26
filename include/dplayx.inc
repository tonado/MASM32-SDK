; --------------------------------------------------------------------------------------------------
;                           dplayx.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DPLAYX_INC
DPLAYX_INC equ <1>

DirectPlayCreate PROTO STDCALL :DWORD,:DWORD,:DWORD

DirectPlayEnumerateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DirectPlayEnumerate equ <DirectPlayEnumerateA>
ENDIF

DirectPlayEnumerateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DirectPlayEnumerate equ <DirectPlayEnumerateW>
ENDIF

DirectPlayLobbyCreateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DirectPlayLobbyCreate equ <DirectPlayLobbyCreateA>
ENDIF

DirectPlayLobbyCreateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DirectPlayLobbyCreate equ <DirectPlayLobbyCreateW>
ENDIF

  ; gdwDPlaySPRefCount arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dplayx.inc
  echo -----------------------------------------
ENDIF
