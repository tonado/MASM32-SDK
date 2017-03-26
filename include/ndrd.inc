; --------------------------------------------------------------------------------------------------
;                            ndrd.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NDRD_INC
NDRD_INC equ <1>

b PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_bp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
help PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
km PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
kol PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
kp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sb PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sd PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sm PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
smd PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file ndrd.inc
  echo ---------------------------------------
ENDIF
