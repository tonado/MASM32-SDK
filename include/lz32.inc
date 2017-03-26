; --------------------------------------------------------------------------------------------------
;                            lz32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LZ32_INC
LZ32_INC equ <1>

CopyLZFile PROTO STDCALL :DWORD,:DWORD

GetExpandedNameA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetExpandedName equ <GetExpandedNameA>
ENDIF

GetExpandedNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetExpandedName equ <GetExpandedNameW>
ENDIF

LZClose PROTO STDCALL :DWORD
LZCloseFile PROTO STDCALL :DWORD
LZCopy PROTO STDCALL :DWORD,:DWORD

LZCreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LZCreateFile equ <LZCreateFileW>
ENDIF

LZDone PROTO STDCALL
LZInit PROTO STDCALL :DWORD

LZOpenFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LZOpenFile equ <LZOpenFileA>
ENDIF

LZOpenFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LZOpenFile equ <LZOpenFileW>
ENDIF

LZRead PROTO STDCALL :DWORD,:DWORD,:DWORD
LZSeek PROTO STDCALL :DWORD,:DWORD,:DWORD
LZStart PROTO STDCALL

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file lz32.inc
  echo ---------------------------------------
ENDIF
