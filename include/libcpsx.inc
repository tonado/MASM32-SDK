; --------------------------------------------------------------------------------------------------
;                           libcpsx.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LIBCPSX_INC
LIBCPSX_INC equ <1>

GetDateFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDateFormat equ <GetDateFormatA>
ENDIF

GetModuleFileNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetModuleFileName equ <GetModuleFileNameA>
ENDIF

GetProcessHeap PROTO STDCALL

GetTimeFormatA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetTimeFormat equ <GetTimeFormatA>
ENDIF

HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAnsiCharToUnicodeChar PROTO STDCALL :DWORD
RtlMultiByteToUnicodeN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUpcaseUnicodeChar PROTO STDCALL :DWORD
RtlUpcaseUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file libcpsx.inc
  echo ------------------------------------------
ENDIF
