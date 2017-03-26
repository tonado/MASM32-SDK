; --------------------------------------------------------------------------------------------------
;                          mcdsrv32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MCDSRV32_INC
MCDSRV32_INC equ <1>

MCDEngEscFilter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MCDEngInit PROTO STDCALL :DWORD,:DWORD
MCDEngInitEx PROTO STDCALL :DWORD,:DWORD,:DWORD
MCDEngSetMemStatus PROTO STDCALL :DWORD,:DWORD
MCDEngUninit PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file mcdsrv32.inc
  echo -------------------------------------------
ENDIF
