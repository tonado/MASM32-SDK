; --------------------------------------------------------------------------------------------------
;                          scrnsavw.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SCRNSAVW_INC
SCRNSAVW_INC equ <1>

CharNextW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  CharNext equ <CharNextW>
ENDIF

CreateWindowExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExW>
ENDIF

DefWindowProcW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DefWindowProc equ <DefWindowProcW>
ENDIF

DialogBoxParamW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DialogBoxParam equ <DialogBoxParamW>
ENDIF

DispatchMessageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DispatchMessage equ <DispatchMessageW>
ENDIF

ExitProcess PROTO STDCALL :DWORD

FindWindowW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FindWindow equ <FindWindowW>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
GetClientRect PROTO STDCALL :DWORD,:DWORD
GetClipBox PROTO STDCALL :DWORD,:DWORD

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
  GetCommandLine equ <GetCommandLineW>
ENDIF

GetCursorPos PROTO STDCALL :DWORD
GetDC PROTO STDCALL :DWORD
GetForegroundWindow PROTO STDCALL

GetMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetMessage equ <GetMessageW>
ENDIF

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

GetParent PROTO STDCALL :DWORD
GetProcAddress PROTO STDCALL :DWORD,:DWORD

GetStartupInfoW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetStartupInfo equ <GetStartupInfoW>
ENDIF

GetStockObject PROTO STDCALL :DWORD
GetSystemMetrics PROTO STDCALL :DWORD
GetTickCount PROTO STDCALL

GetVersionExW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetVersionEx equ <GetVersionExW>
ENDIF

InitCommonControlsEx PROTO STDCALL :DWORD
IsWindow PROTO STDCALL :DWORD

LoadIconW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LoadIcon equ <LoadIconW>
ENDIF

LoadLibraryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LoadLibrary equ <LoadLibraryW>
ENDIF

PeekMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PeekMessage equ <PeekMessageW>
ENDIF

PostMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PostMessage equ <PostMessageW>
ENDIF

PostQuitMessage PROTO STDCALL :DWORD
RegCloseKey PROTO STDCALL :DWORD

RegOpenKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyW>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RegisterClassW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RegisterClass equ <RegisterClassW>
ENDIF

RegisterWindowMessageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RegisterWindowMessage equ <RegisterWindowMessageW>
ENDIF

ReleaseDC PROTO STDCALL :DWORD,:DWORD

SendMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SendMessage equ <SendMessageW>
ENDIF

SetCursor PROTO STDCALL :DWORD
SetForegroundWindow PROTO STDCALL :DWORD
Sleep PROTO STDCALL :DWORD

SystemParametersInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SystemParametersInfo equ <SystemParametersInfoW>
ENDIF

TranslateMessage PROTO STDCALL :DWORD
UnhandledExceptionFilter PROTO STDCALL :DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file scrnsavw.inc
  echo -------------------------------------------
ENDIF
