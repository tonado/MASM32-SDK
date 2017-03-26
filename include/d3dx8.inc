; --------------------------------------------------------------------------------------------------
;                            d3dx8.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF D3DX8_INC
D3DX8_INC equ <1>

CloseHandle PROTO STDCALL :DWORD
CreateCompatibleDC PROTO STDCALL :DWORD
CreateDIBSection PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

CreateFileMappingA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFileMapping equ <CreateFileMappingA>
ENDIF

CreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFile equ <CreateFileW>
ENDIF

CreateFontIndirectA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  CreateFontIndirect equ <CreateFontIndirectA>
ENDIF

DeleteDC PROTO STDCALL :DWORD

DeleteFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteFile equ <DeleteFileA>
ENDIF

DeleteObject PROTO STDCALL :DWORD

DrawTextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DrawText equ <DrawTextA>
ENDIF

DrawTextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DrawText equ <DrawTextW>
ENDIF

FindResourceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindResource equ <FindResourceA>
ENDIF

FindResourceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindResource equ <FindResourceW>
ENDIF

GetCurrentObject PROTO STDCALL :DWORD,:DWORD
GetFileSize PROTO STDCALL :DWORD,:DWORD

GetGlyphOutlineA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetGlyphOutline equ <GetGlyphOutlineA>
ENDIF

GetGlyphOutlineW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetGlyphOutline equ <GetGlyphOutlineW>
ENDIF

GetLastError PROTO STDCALL

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetObject equ <GetObjectA>
ENDIF

GetOutlineTextMetricsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetOutlineTextMetrics equ <GetOutlineTextMetricsA>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD
GetProcessHeap PROTO STDCALL

GetTempFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempFileName equ <GetTempFileNameA>
ENDIF

GetTempPathA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetTempPath equ <GetTempPathA>
ENDIF

GetVersionExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetVersionEx equ <GetVersionExA>
ENDIF

HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapValidate PROTO STDCALL :DWORD,:DWORD,:DWORD
InterlockedDecrement PROTO STDCALL :DWORD
InterlockedIncrement PROTO STDCALL :DWORD
IsDBCSLeadByte PROTO STDCALL :DWORD
IsProcessorFeaturePresent PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LoadResource PROTO STDCALL :DWORD,:DWORD
LockResource PROTO STDCALL :DWORD
MapViewOfFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OutputDebugStringA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OutputDebugString equ <OutputDebugStringA>
ENDIF

ReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegOpenKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyA>
ENDIF

RegQueryValueExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExA>
ENDIF

SelectObject PROTO STDCALL :DWORD,:DWORD
SetBkColor PROTO STDCALL :DWORD,:DWORD
SetBkMode PROTO STDCALL :DWORD,:DWORD
SetTextColor PROTO STDCALL :DWORD,:DWORD
SizeofResource PROTO STDCALL :DWORD,:DWORD
UnmapViewOfFile PROTO STDCALL :DWORD
WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file d3dx8.inc
  echo ----------------------------------------
ENDIF
