; --------------------------------------------------------------------------------------------------
;                           dsprop.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DSPROP_INC
DSPROP_INC equ <1>

ADsPropCheckIfWritable PROTO STDCALL :DWORD,:DWORD
ADsPropCreateNotifyObj PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsPropGetInitInfo PROTO STDCALL :DWORD,:DWORD
ADsPropSendErrorMessage PROTO STDCALL :DWORD,:DWORD
ADsPropSetHwnd PROTO STDCALL :DWORD,:DWORD
ADsPropSetHwndWithTitle PROTO STDCALL :DWORD,:DWORD,:DWORD
ADsPropShowErrorDialog PROTO STDCALL :DWORD,:DWORD
BringSheetToForeground PROTO STDCALL :DWORD,:DWORD
IsSheetAlreadyUp PROTO STDCALL :DWORD
PostADsPropSheet PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file dsprop.inc
  echo -----------------------------------------
ENDIF
