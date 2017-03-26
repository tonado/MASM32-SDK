; --------------------------------------------------------------------------------------------------
;                           msv1_0.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSV1_0_INC
MSV1_0_INC equ <1>

LsaApCallPackage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaApCallPackagePassthrough PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaApCallPackageUntrusted PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaApInitializePackage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaApLogonTerminated PROTO STDCALL :DWORD
LsaApLogonUserEx2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Msv1_0ExportSubAuthenticationRoutine PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Msv1_0SubAuthenticationPresent PROTO STDCALL :DWORD
MsvGetLogonAttemptCount PROTO STDCALL
MsvSamLogoff PROTO STDCALL :DWORD,:DWORD,:DWORD
MsvSamValidate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsvValidateTarget PROTO STDCALL :DWORD,:DWORD,:DWORD
SpInitialize PROTO STDCALL :DWORD,:DWORD,:DWORD
SpInstanceInit PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file msv1_0.inc
  echo -----------------------------------------
ENDIF
