; --------------------------------------------------------------------------------------------------
;                           oledlg.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF OLEDLG_INC
OLEDLG_INC equ <1>

OleUIAddVerbMenuA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OleUIAddVerbMenu equ <OleUIAddVerbMenuA>
ENDIF

OleUIAddVerbMenuW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OleUIAddVerbMenu equ <OleUIAddVerbMenuW>
ENDIF

OleUIBusyA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIBusy equ <OleUIBusyA>
ENDIF

OleUIBusyW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIBusy equ <OleUIBusyW>
ENDIF

OleUICanConvertOrActivateAs PROTO STDCALL :DWORD,:DWORD,:DWORD

OleUIChangeIconA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIChangeIcon equ <OleUIChangeIconA>
ENDIF

OleUIChangeIconW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIChangeIcon equ <OleUIChangeIconW>
ENDIF

OleUIChangeSourceA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIChangeSource equ <OleUIChangeSourceA>
ENDIF

OleUIChangeSourceW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIChangeSource equ <OleUIChangeSourceW>
ENDIF

OleUIConvertA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIConvert equ <OleUIConvertA>
ENDIF

OleUIConvertW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIConvert equ <OleUIConvertW>
ENDIF

OleUIEditLinksA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIEditLinks equ <OleUIEditLinksA>
ENDIF

OleUIEditLinksW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIEditLinks equ <OleUIEditLinksW>
ENDIF

OleUIInsertObjectA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIInsertObject equ <OleUIInsertObjectA>
ENDIF

OleUIInsertObjectW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIInsertObject equ <OleUIInsertObjectW>
ENDIF

OleUIObjectPropertiesA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIObjectProperties equ <OleUIObjectPropertiesA>
ENDIF

OleUIObjectPropertiesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIObjectProperties equ <OleUIObjectPropertiesW>
ENDIF

OleUIPasteSpecialA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  OleUIPasteSpecial equ <OleUIPasteSpecialA>
ENDIF

OleUIPasteSpecialW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  OleUIPasteSpecial equ <OleUIPasteSpecialW>
ENDIF

OleUIPromptUserA PROTO C :VARARG
IFNDEF __UNICODE__
  OleUIPromptUser equ <OleUIPromptUserA>
ENDIF

OleUIPromptUserW PROTO C :VARARG
IFDEF __UNICODE__
  OleUIPromptUser equ <OleUIPromptUserW>
ENDIF

OleUIUpdateLinksA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OleUIUpdateLinks equ <OleUIUpdateLinksA>
ENDIF

OleUIUpdateLinksW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OleUIUpdateLinks equ <OleUIUpdateLinksW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file oledlg.inc
  echo -----------------------------------------
ENDIF
