; --------------------------------------------------------------------------------------------------
;                            hlink.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF HLINK_INC
HLINK_INC equ <1>

HlinkClone PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateBrowseContext PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkCreateExtensionServices PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromMoniker PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromString PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcut PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcutFromMoniker PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcutFromString PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkGetSpecialReference PROTO STDCALL :DWORD,:DWORD
HlinkGetValueFromParams PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkIsShortcut PROTO STDCALL :DWORD
HlinkNavigate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkNavigateToStringReference PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkOnNavigate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkOnRenameDocument PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HlinkParseDisplayName PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkPreprocessMoniker PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkQueryCreateFromData PROTO STDCALL :DWORD
HlinkResolveMonikerForData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkResolveShortcut PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkResolveShortcutToMoniker PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkResolveShortcutToString PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkResolveStringForData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkSetSpecialReference PROTO STDCALL :DWORD,:DWORD
HlinkTranslateURL PROTO STDCALL :DWORD,:DWORD,:DWORD
HlinkUpdateStackItem PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleSaveToStreamEx PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ----------------------------------------
  echo WARNING duplicate include file hlink.inc
  echo ----------------------------------------
ENDIF
