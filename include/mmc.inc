; --------------------------------------------------------------------------------------------------
;                             mmc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MMC_INC
MMC_INC equ <1>

CallNextHookEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CoCreateInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInitialize PROTO STDCALL :DWORD
CoUninitialize PROTO STDCALL

FindWindowExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindWindowEx equ <FindWindowExW>
ENDIF

GetClassLongW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetClassLong equ <GetClassLongW>
ENDIF

GetCurrentProcessId PROTO STDCALL
GetCurrentThreadId PROTO STDCALL

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

GetWindowLongW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowLong equ <GetWindowLongW>
ENDIF

GetWindowThreadProcessId PROTO STDCALL :DWORD,:DWORD
GlobalFree PROTO STDCALL :DWORD
IsBadReadPtr PROTO STDCALL :DWORD,:DWORD

SendMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SendMessage equ <SendMessageW>
ENDIF

SetWindowsHookExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetWindowsHookEx equ <SetWindowsHookExW>
ENDIF

UnhookWindowsHookEx PROTO STDCALL :DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file mmc.inc
  echo --------------------------------------
ENDIF
