; --------------------------------------------------------------------------------------------------
;                           ftsrch.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF FTSRCH_INC
FTSRCH_INC equ <1>

ClearDisplayText PROTO STDCALL :DWORD
CompressText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CountHilites PROTO STDCALL :DWORD,:DWORD,:DWORD
DecompressText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DeleteCompressor PROTO STDCALL :DWORD
DeleteHiliter PROTO STDCALL :DWORD
DeleteIndex PROTO STDCALL :DWORD
DeleteSearcher PROTO STDCALL :DWORD
DiscardIndex PROTO STDCALL :DWORD,:DWORD
DllMain PROTO STDCALL :DWORD,:DWORD,:DWORD
GetPhraseTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsValidIndex PROTO STDCALL :DWORD,:DWORD
LoadGroup PROTO STDCALL :DWORD,:DWORD
NewCompressor PROTO STDCALL :DWORD
NewHiliter PROTO STDCALL :DWORD
NewIndex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NewSearcher PROTO STDCALL
OpenBiDiTabDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OpenDialog PROTO STDCALL :DWORD,:DWORD
OpenIndex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenTabDialog PROTO STDCALL :DWORD,:DWORD,:DWORD
QueryHilites PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryOptions PROTO STDCALL :DWORD,:DWORD,:DWORD
RegisterAnimator PROTO STDCALL :DWORD,:DWORD
SaveGroup PROTO STDCALL :DWORD,:DWORD
SaveIndex PROTO STDCALL :DWORD,:DWORD
ScanDisplayText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScanText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ScanTopicText PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScanTopicTitle PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetDirectoryLocator PROTO STDCALL :DWORD
SetPhraseTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file ftsrch.inc
  echo -----------------------------------------
ENDIF
