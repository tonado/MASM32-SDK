; --------------------------------------------------------------------------------------------------
;                            d3dx.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF D3DX_INC
D3DX_INC equ <1>

AdjustWindowRectEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
BitBlt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClientToScreen PROTO STDCALL :DWORD,:DWORD
CloseHandle PROTO STDCALL :DWORD
CreateCompatibleDC PROTO STDCALL :DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingA>
ENDIF

CreateWindowExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExA>
ENDIF

DebugBreak PROTO STDCALL

DefWindowProcA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DefWindowProc equ <DefWindowProcA>
ENDIF

DeleteDC PROTO STDCALL :DWORD

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeleteObject PROTO STDCALL :DWORD
DestroyWindow PROTO STDCALL :DWORD

DrawTextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DrawText equ <DrawTextA>
ENDIF

GetClassInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetClassInfo equ <GetClassInfoA>
ENDIF

GetClientRect PROTO STDCALL :DWORD,:DWORD
GetDC PROTO STDCALL :DWORD
GetFileSize PROTO STDCALL :DWORD,:DWORD
GetLastError PROTO STDCALL
GetMenu PROTO STDCALL :DWORD

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetObject equ <GetObjectA>
ENDIF

GetPaletteEntries PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetParent PROTO STDCALL :DWORD
GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetStockObject PROTO STDCALL :DWORD
GetSystemMetrics PROTO STDCALL :DWORD

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

GetWindowLongA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetWindowLong equ <GetWindowLongA>
ENDIF

GetWindowPlacement PROTO STDCALL :DWORD,:DWORD

GetWindowsDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryA>
ENDIF

IsBadReadPtr PROTO STDCALL :DWORD,:DWORD

LoadCursorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadCursor equ <LoadCursorA>
ENDIF

LoadIconA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadIcon equ <LoadIconA>
ENDIF

LoadImageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LoadImage equ <LoadImageA>
ENDIF

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

MapViewOfFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

RegisterClassA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RegisterClass equ <RegisterClassA>
ENDIF

ReleaseDC PROTO STDCALL :DWORD,:DWORD
SelectObject PROTO STDCALL :DWORD,:DWORD
SetBkMode PROTO STDCALL :DWORD,:DWORD
SetCursor PROTO STDCALL :DWORD
SetFocus PROTO STDCALL :DWORD
SetTextColor PROTO STDCALL :DWORD,:DWORD
SetWindowPlacement PROTO STDCALL :DWORD,:DWORD
StretchBlt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UnmapViewOfFile PROTO STDCALL :DWORD

UnregisterClassA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UnregisterClass equ <UnregisterClassA>
ENDIF

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcmpiA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcmpi equ <lstrcmpiA>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

  ; wsprintfA arg type unknown

ELSE
  echo ---------------------------------------
  echo WARNING duplicate include file d3dx.inc
  echo ---------------------------------------
ENDIF
