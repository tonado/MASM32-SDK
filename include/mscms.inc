; --------------------------------------------------------------------------------------------------
;                            mscms.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSCMS_INC
MSCMS_INC equ <1>

AssociateColorProfileWithDeviceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AssociateColorProfileWithDevice equ <AssociateColorProfileWithDeviceA>
ENDIF

AssociateColorProfileWithDeviceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AssociateColorProfileWithDevice equ <AssociateColorProfileWithDeviceW>
ENDIF

CheckBitmapBits PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CheckColors PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CloseColorProfile PROTO STDCALL :DWORD
ConvertColorNameToIndex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ConvertIndexToColorName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateColorTransformA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateColorTransform equ <CreateColorTransformA>
ENDIF

CreateColorTransformW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateColorTransform equ <CreateColorTransformW>
ENDIF

CreateDeviceLinkProfile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateMultiProfileTransform PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateProfileFromLogColorSpaceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateProfileFromLogColorSpace equ <CreateProfileFromLogColorSpaceA>
ENDIF

CreateProfileFromLogColorSpaceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateProfileFromLogColorSpace equ <CreateProfileFromLogColorSpaceW>
ENDIF

DeleteColorTransform PROTO STDCALL :DWORD

DisassociateColorProfileFromDeviceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DisassociateColorProfileFromDevice equ <DisassociateColorProfileFromDeviceA>
ENDIF

DisassociateColorProfileFromDeviceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DisassociateColorProfileFromDevice equ <DisassociateColorProfileFromDeviceW>
ENDIF

EnumColorProfilesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumColorProfiles equ <EnumColorProfilesA>
ENDIF

EnumColorProfilesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumColorProfiles equ <EnumColorProfilesW>
ENDIF

GenerateCopyFilePaths PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetCMMInfo PROTO STDCALL :DWORD,:DWORD

GetColorDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetColorDirectory equ <GetColorDirectoryA>
ENDIF

GetColorDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetColorDirectory equ <GetColorDirectoryW>
ENDIF

GetColorProfileElement PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetColorProfileElementTag PROTO STDCALL :DWORD,:DWORD,:DWORD
GetColorProfileFromHandle PROTO STDCALL :DWORD,:DWORD,:DWORD
GetColorProfileHeader PROTO STDCALL :DWORD,:DWORD
GetCountColorProfileElements PROTO STDCALL :DWORD,:DWORD
GetNamedProfileInfo PROTO STDCALL :DWORD,:DWORD
GetPS2ColorRenderingDictionary PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorRenderingIntent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorSpaceArray PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetStandardColorSpaceProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStandardColorSpaceProfile equ <GetStandardColorSpaceProfileA>
ENDIF

GetStandardColorSpaceProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStandardColorSpaceProfile equ <GetStandardColorSpaceProfileW>
ENDIF

InstallColorProfileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InstallColorProfile equ <InstallColorProfileA>
ENDIF

InstallColorProfileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InstallColorProfile equ <InstallColorProfileW>
ENDIF

InternalGetDeviceConfig PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2CSAFromLCS PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2ColorRenderingDictionary PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2ColorSpaceArray PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2PreviewCRD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalSetDeviceConfig PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsColorProfileTagPresent PROTO STDCALL :DWORD,:DWORD,:DWORD
IsColorProfileValid PROTO STDCALL :DWORD,:DWORD

OpenColorProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenColorProfile equ <OpenColorProfileA>
ENDIF

OpenColorProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenColorProfile equ <OpenColorProfileW>
ENDIF

RegisterCMMA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RegisterCMM equ <RegisterCMMA>
ENDIF

RegisterCMMW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegisterCMM equ <RegisterCMMW>
ENDIF

SelectCMM PROTO STDCALL :DWORD
SetColorProfileElement PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetColorProfileElementReference PROTO STDCALL :DWORD,:DWORD,:DWORD
SetColorProfileElementSize PROTO STDCALL :DWORD,:DWORD,:DWORD
SetColorProfileHeader PROTO STDCALL :DWORD,:DWORD

SetStandardColorSpaceProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetStandardColorSpaceProfile equ <SetStandardColorSpaceProfileA>
ENDIF

SetStandardColorSpaceProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetStandardColorSpaceProfile equ <SetStandardColorSpaceProfileW>
ENDIF

SpoolerCopyFileEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
TranslateBitmapBits PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TranslateColors PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

UninstallColorProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  UninstallColorProfile equ <UninstallColorProfileA>
ENDIF

UninstallColorProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  UninstallColorProfile equ <UninstallColorProfileW>
ENDIF

UnregisterCMMA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UnregisterCMM equ <UnregisterCMMA>
ENDIF

UnregisterCMMW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UnregisterCMM equ <UnregisterCMMW>
ENDIF

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file mscms.inc
  echo ----------------------------------------
ENDIF
