; --------------------------------------------------------------------------------------------------
;                            icm32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF ICM32_INC
ICM32_INC equ <1>

CMCheckColors PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMCheckColorsInGamut PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMCheckRGBs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMConvertColorNameToIndex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMConvertIndexToColorName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMCreateDeviceLinkProfile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMCreateMultiProfileTransform PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CMCreateProfileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CMCreateProfile equ <CMCreateProfileW>
ENDIF

CMCreateTransform PROTO STDCALL :DWORD,:DWORD,:DWORD

CMCreateTransformExtW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CMCreateTransformExt equ <CMCreateTransformExtW>
ENDIF

CMCreateTransformW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CMCreateTransform equ <CMCreateTransformW>
ENDIF

CMDeleteTransform PROTO STDCALL :DWORD
CMGetInfo PROTO STDCALL :DWORD
CMGetNamedProfileInfo PROTO STDCALL :DWORD,:DWORD
CMIsProfileValid PROTO STDCALL :DWORD,:DWORD
CMTranslateColors PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGB PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGBs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGBsExt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file icm32.inc
  echo ----------------------------------------
ENDIF
