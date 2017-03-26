; --------------------------------------------------------------------------------------------------
;                          odbccp32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ODBCCP32_INC
ODBCCP32_INC equ <1>

CloseHandle PROTO STDCALL :DWORD

CreateFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateFile equ <CreateFileA>
ENDIF

FreeLibrary PROTO STDCALL :DWORD
GetFileSize PROTO STDCALL :DWORD,:DWORD

GetModuleFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameA>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetProcAddress PROTO STDCALL :DWORD,:DWORD

GetSystemDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemDirectory equ <GetSystemDirectoryA>
ENDIF

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
LocalLock PROTO STDCALL :DWORD
LocalUnlock PROTO STDCALL :DWORD

MessageBoxA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MessageBox equ <MessageBoxA>
ENDIF

MoveFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MoveFileEx equ <MoveFileExA>
ENDIF

  ; wsprintfA arg type unknown

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file odbccp32.inc
  echo -------------------------------------------
ENDIF
