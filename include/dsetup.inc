; --------------------------------------------------------------------------------------------------
;                           dsetup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DSETUP_INC
DSETUP_INC equ <1>

DirectXDeviceDriverSetupA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DirectXDeviceDriverSetup equ <DirectXDeviceDriverSetupA>
ENDIF

DirectXDeviceDriverSetupW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DirectXDeviceDriverSetup equ <DirectXDeviceDriverSetupW>
ENDIF

DirectXLoadString PROTO STDCALL :DWORD,:DWORD,:DWORD

DirectXRegisterApplicationA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DirectXRegisterApplication equ <DirectXRegisterApplicationA>
ENDIF

DirectXRegisterApplicationW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DirectXRegisterApplication equ <DirectXRegisterApplicationW>
ENDIF

DirectXSetupA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DirectXSetup equ <DirectXSetupA>
ENDIF

DirectXSetupCallback PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectXSetupGetFileVersion PROTO STDCALL :DWORD,:DWORD,:DWORD
DirectXSetupGetVersion PROTO STDCALL :DWORD,:DWORD
DirectXSetupIsEng PROTO STDCALL
DirectXSetupIsJapan PROTO STDCALL
DirectXSetupIsJapanNec PROTO STDCALL
DirectXSetupSetCallback PROTO STDCALL :DWORD

DirectXSetupShowEULA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DirectXSetupShowEUL equ <DirectXSetupShowEULA>
ENDIF

DirectXSetupW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DirectXSetup equ <DirectXSetupW>
ENDIF

DirectXUnRegisterApplication PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dsetup.inc
  echo -----------------------------------------
ENDIF
