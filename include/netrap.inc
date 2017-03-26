; --------------------------------------------------------------------------------------------------
;                           netrap.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NETRAP_INC
NETRAP_INC equ <1>

RapArrayLength PROTO STDCALL :DWORD,:DWORD,:DWORD
RapAsciiToDecimal PROTO STDCALL :DWORD
RapAuxDataCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RapAuxDataCountOffset PROTO STDCALL :DWORD,:DWORD,:DWORD
RapConvertSingleEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RapConvertSingleEntryEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RapExamineDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RapGetFieldSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RapIsValidDescriptorSmb PROTO STDCALL :DWORD
RapLastPointerOffset PROTO STDCALL :DWORD,:DWORD,:DWORD
RapParmNumDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RapStructureAlignment PROTO STDCALL :DWORD,:DWORD,:DWORD
RapStructureSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RapTotalSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file netrap.inc
  echo -----------------------------------------
ENDIF
