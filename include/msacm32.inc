; --------------------------------------------------------------------------------------------------
;                           msacm32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSACM32_INC
MSACM32_INC equ <1>

XRegThunkEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

acmDriverAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmDriverAdd equ <acmDriverAddA>
ENDIF

acmDriverAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmDriverAdd equ <acmDriverAddW>
ENDIF

acmDriverClose PROTO STDCALL :DWORD,:DWORD

acmDriverDetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmDriverDetails equ <acmDriverDetailsA>
ENDIF

acmDriverDetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmDriverDetails equ <acmDriverDetailsW>
ENDIF

acmDriverEnum PROTO STDCALL :DWORD,:DWORD,:DWORD
acmDriverID PROTO STDCALL :DWORD,:DWORD,:DWORD
acmDriverMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
acmDriverOpen PROTO STDCALL :DWORD,:DWORD,:DWORD
acmDriverPriority PROTO STDCALL :DWORD,:DWORD,:DWORD
acmDriverRemove PROTO STDCALL :DWORD,:DWORD

acmFilterChooseA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  acmFilterChoose equ <acmFilterChooseA>
ENDIF

acmFilterChooseW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  acmFilterChoose equ <acmFilterChooseW>
ENDIF

acmFilterDetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFilterDetails equ <acmFilterDetailsA>
ENDIF

acmFilterDetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFilterDetails equ <acmFilterDetailsW>
ENDIF

acmFilterEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFilterEnum equ <acmFilterEnumA>
ENDIF

acmFilterEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFilterEnum equ <acmFilterEnumW>
ENDIF

acmFilterTagDetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFilterTagDetails equ <acmFilterTagDetailsA>
ENDIF

acmFilterTagDetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFilterTagDetails equ <acmFilterTagDetailsW>
ENDIF

acmFilterTagEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFilterTagEnum equ <acmFilterTagEnumA>
ENDIF

acmFilterTagEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFilterTagEnum equ <acmFilterTagEnumW>
ENDIF

acmFormatChooseA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  acmFormatChoose equ <acmFormatChooseA>
ENDIF

acmFormatChooseW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  acmFormatChoose equ <acmFormatChooseW>
ENDIF

acmFormatDetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFormatDetails equ <acmFormatDetailsA>
ENDIF

acmFormatDetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFormatDetails equ <acmFormatDetailsW>
ENDIF

acmFormatEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFormatEnum equ <acmFormatEnumA>
ENDIF

acmFormatEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFormatEnum equ <acmFormatEnumW>
ENDIF

acmFormatSuggest PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

acmFormatTagDetailsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFormatTagDetails equ <acmFormatTagDetailsA>
ENDIF

acmFormatTagDetailsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFormatTagDetails equ <acmFormatTagDetailsW>
ENDIF

acmFormatTagEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  acmFormatTagEnum equ <acmFormatTagEnumA>
ENDIF

acmFormatTagEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  acmFormatTagEnum equ <acmFormatTagEnumW>
ENDIF

acmGetVersion PROTO STDCALL
acmMessage32 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmMetrics PROTO STDCALL :DWORD,:DWORD,:DWORD
acmStreamClose PROTO STDCALL :DWORD,:DWORD
acmStreamConvert PROTO STDCALL :DWORD,:DWORD,:DWORD
acmStreamMessage PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
acmStreamOpen PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmStreamPrepareHeader PROTO STDCALL :DWORD,:DWORD,:DWORD
acmStreamReset PROTO STDCALL :DWORD,:DWORD
acmStreamSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
acmStreamUnprepareHeader PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file msacm32.inc
  echo ------------------------------------------
ENDIF
