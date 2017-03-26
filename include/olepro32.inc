; --------------------------------------------------------------------------------------------------
;                          olepro32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF OLEPRO32_INC
OLEPRO32_INC equ <1>

OleCreateFontIndirect PROTO STDCALL :DWORD,:DWORD,:DWORD
OleCreatePictureIndirect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OleCreatePropertyFrame PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleCreatePropertyFrameIndirect PROTO STDCALL :DWORD
OleIconToCursor PROTO STDCALL :DWORD,:DWORD
OleLoadPicture PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleTranslateColor PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file olepro32.inc
  echo -------------------------------------------
ENDIF
