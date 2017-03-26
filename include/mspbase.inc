; --------------------------------------------------------------------------------------------------
;                           mspbase.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSPBASE_INC
MSPBASE_INC equ <1>

AtlComPtrAssign PROTO STDCALL :DWORD,:DWORD
AtlInternalQueryInterface PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CLSIDFromString PROTO STDCALL :DWORD,:DWORD
CloseHandle PROTO STDCALL :DWORD
CoCreateFreeThreadedMarshaler PROTO STDCALL :DWORD,:DWORD
CoCreateInstance PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoInitializeEx PROTO STDCALL :DWORD,:DWORD
CoTaskMemFree PROTO STDCALL :DWORD
CoUninitialize PROTO STDCALL
CreateBindCtx PROTO STDCALL :DWORD,:DWORD

CreateEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateEvent equ <CreateEventW>
ENDIF

CreateThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateWindowExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExW>
ENDIF

DefWindowProcW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DefWindowProc equ <DefWindowProcW>
ENDIF

DeleteCriticalSection PROTO STDCALL :DWORD
DestroyWindow PROTO STDCALL :DWORD

DispatchMessageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DispatchMessage equ <DispatchMessageW>
ENDIF

EnterCriticalSection PROTO STDCALL :DWORD
GetCurrentProcessId PROTO STDCALL
GetCurrentThreadId PROTO STDCALL
GetLastError PROTO STDCALL
GetLocalTime PROTO STDCALL :DWORD

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

GetProcessHeap PROTO STDCALL

GetWindowLongW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowLong equ <GetWindowLongW>
ENDIF

HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
IIDFromString PROTO STDCALL :DWORD,:DWORD
InitializeCriticalSection PROTO STDCALL :DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD
IsBadReadPtr PROTO STDCALL :DWORD,:DWORD

IsBadStringPtrW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  IsBadStringPtr equ <IsBadStringPtrW>
ENDIF

IsBadWritePtr PROTO STDCALL :DWORD,:DWORD
LeaveCriticalSection PROTO STDCALL :DWORD
MsgWaitForMultipleObjectsEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

PeekMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PeekMessage equ <PeekMessageW>
ENDIF

QueueUserWorkItem PROTO STDCALL :DWORD,:DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegOpenKeyExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

RegisterClassW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RegisterClass equ <RegisterClassW>
ENDIF

RegisterDeviceNotificationW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegisterDeviceNotification equ <RegisterDeviceNotificationW>
ENDIF

RegisterWaitForSingleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetEvent PROTO STDCALL :DWORD
SetLastError PROTO STDCALL :DWORD

SetWindowLongW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetWindowLong equ <SetWindowLongW>
ENDIF

StringFromCLSID PROTO STDCALL :DWORD,:DWORD
StringFromGUID2 PROTO STDCALL :DWORD,:DWORD,:DWORD
StringFromIID PROTO STDCALL :DWORD,:DWORD
SysAllocString PROTO STDCALL :DWORD
SysFreeString PROTO STDCALL :DWORD
TranslateMessage PROTO STDCALL :DWORD

UnregisterClassW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UnregisterClass equ <UnregisterClassW>
ENDIF

UnregisterDeviceNotification PROTO STDCALL :DWORD
UnregisterWaitEx PROTO STDCALL :DWORD,:DWORD
VariantClear PROTO STDCALL :DWORD
VariantCopy PROTO STDCALL :DWORD,:DWORD
VariantInit PROTO STDCALL :DWORD
WaitForMultipleObjects PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WaitForSingleObject PROTO STDCALL :DWORD,:DWORD
_vsnprintf PROTO C :VARARG
free PROTO C :VARARG

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcpynW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  lstrcpyn equ <lstrcpynW>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

malloc PROTO C :VARARG
memmove PROTO C :VARARG
realloc PROTO C :VARARG
swprintf PROTO C :VARARG
  ; wsprintfA arg type unknown

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file mspbase.inc
  echo ------------------------------------------
ENDIF
