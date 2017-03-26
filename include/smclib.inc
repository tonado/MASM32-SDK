; --------------------------------------------------------------------------------------------------
;                           smclib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SMCLIB_INC
SMCLIB_INC equ <1>

SmartcardAcquireRemoveLock PROTO STDCALL :DWORD
SmartcardAcquireRemoveLockWithTag PROTO STDCALL :DWORD,:DWORD
SmartcardCreateLink PROTO STDCALL :DWORD,:DWORD
SmartcardDeviceControl PROTO STDCALL :DWORD,:DWORD
SmartcardExit PROTO STDCALL :DWORD
SmartcardGetDebugLevel PROTO STDCALL
SmartcardInitialize PROTO STDCALL :DWORD
SmartcardInitializeCardCapabilities PROTO STDCALL :DWORD
SmartcardInvertData PROTO STDCALL :DWORD,:DWORD
SmartcardLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SmartcardRawReply PROTO STDCALL :DWORD
SmartcardRawRequest PROTO STDCALL :DWORD
SmartcardReleaseRemoveLock PROTO STDCALL :DWORD
SmartcardReleaseRemoveLockAndWait PROTO STDCALL :DWORD
SmartcardReleaseRemoveLockWithTag PROTO STDCALL :DWORD,:DWORD
SmartcardSetDebugLevel PROTO STDCALL :DWORD
SmartcardT0Reply PROTO STDCALL :DWORD
SmartcardT0Request PROTO STDCALL :DWORD
SmartcardT1Reply PROTO STDCALL :DWORD
SmartcardT1Request PROTO STDCALL :DWORD
SmartcardUpdateCardCapabilities PROTO STDCALL :DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file smclib.inc
  echo -----------------------------------------
ENDIF
