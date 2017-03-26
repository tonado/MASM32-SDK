; --------------------------------------------------------------------------------------------------
;                          scrnsave.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCRNSAVE_INC
SCRNSAVE_INC equ <1>

CharNextA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CharNext equ <CharNextA>
ENDIF

CreateWindowExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExA>
ENDIF

DefWindowProcA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DefWindowProc equ <DefWindowProcA>
ENDIF

DialogBoxParamA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DialogBoxParam equ <DialogBoxParamA>
ENDIF

DispatchMessageA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DispatchMessage equ <DispatchMessageA>
ENDIF

ExitProcess PROTO STDCALL :DWORD

FindWindowA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FindWindow equ <FindWindowA>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
GetClientRect PROTO STDCALL :DWORD,:DWORD
GetClipBox PROTO STDCALL :DWORD,:DWORD

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
  GetCommandLine equ <GetCommandLineA>
ENDIF

GetCursorPos PROTO STDCALL :DWORD
GetDC PROTO STDCALL :DWORD
GetForegroundWindow PROTO STDCALL

GetMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetMessage equ <GetMessageA>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetParent PROTO STDCALL :DWORD
GetProcAddress PROTO STDCALL :DWORD,:DWORD

GetStartupInfoA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoA>
ENDIF

GetStockObject PROTO STDCALL :DWORD
GetSystemMetrics PROTO STDCALL :DWORD
GetTickCount PROTO STDCALL

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

InitCommonControlsEx PROTO STDCALL :DWORD
IsWindow PROTO STDCALL :DWORD

LoadIconA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadIcon equ <LoadIconA>
ENDIF

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

PeekMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PeekMessage equ <PeekMessageA>
ENDIF

PostMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PostMessage equ <PostMessageA>
ENDIF

PostQuitMessage PROTO STDCALL :DWORD
RegCloseKey PROTO STDCALL :DWORD

RegOpenKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegisterClassA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RegisterClass equ <RegisterClassA>
ENDIF

RegisterWindowMessageA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RegisterWindowMessage equ <RegisterWindowMessageA>
ENDIF

ReleaseDC PROTO STDCALL :DWORD,:DWORD

SendMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SendMessage equ <SendMessageA>
ENDIF

SetCursor PROTO STDCALL :DWORD
SetForegroundWindow PROTO STDCALL :DWORD
Sleep PROTO STDCALL :DWORD

SystemParametersInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SystemParametersInfo equ <SystemParametersInfoA>
ENDIF

TranslateMessage PROTO STDCALL :DWORD
UnhandledExceptionFilter PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file scrnsave.inc
  echo -------------------------------------------
ENDIF
