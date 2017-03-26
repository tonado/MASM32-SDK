; --------------------------------------------------------------------------------------------------
;                          ntdsetup.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTDSETUP_INC
NTDSETUP_INC equ <1>

NtdsDemote PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtdsFreeDnsRRInfo PROTO STDCALL :DWORD
NtdsGetDefaultDnsName PROTO STDCALL :DWORD,:DWORD
NtdsInstall PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NtdsInstallCancel PROTO STDCALL
NtdsInstallReplicateFull PROTO STDCALL :DWORD,:DWORD,:DWORD
NtdsInstallShutdown PROTO STDCALL
NtdsInstallUndo PROTO STDCALL
NtdsPrepareForDemotion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtdsPrepareForDemotionUndo PROTO STDCALL
NtdsPrepareForDsUpgrade PROTO STDCALL :DWORD,:DWORD
NtdsSetReplicaMachineAccount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtdspConfigRegistry PROTO STDCALL :DWORD,:DWORD
NtdspDNStoRFC1779Name PROTO STDCALL :DWORD,:DWORD,:DWORD
NtdspFindSite PROTO STDCALL :DWORD,:DWORD
NtdspValidateInstallParameters PROTO STDCALL :DWORD
NtdspVerifyDsEnvironment PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file ntdsetup.inc
  echo -------------------------------------------
ENDIF
