; --------------------------------------------------------------------------------------------------
;                           parser.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PARSER_INC
PARSER_INC equ <1>

AddressToString PROTO STDCALL :DWORD,:DWORD
BERGetHeader PROTO C :VARARG
BERGetInteger PROTO C :VARARG
BERGetString PROTO C :VARARG
BuildINIPath PROTO C :VARARG
ByteToBinary PROTO STDCALL :DWORD,:DWORD
CanonHex PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CanonicalizeHexString PROTO STDCALL :DWORD,:DWORD,:DWORD
DwordToBinary PROTO STDCALL :DWORD,:DWORD
FormatByteFlags PROTO C :VARARG
FormatDwordFlags PROTO C :VARARG
FormatLabeledByteSet PROTO C :VARARG
FormatLabeledByteSetAsFlags PROTO C :VARARG
FormatLabeledDwordSet PROTO C :VARARG
FormatLabeledDwordSetAsFlags PROTO C :VARARG
FormatLabeledWordSet PROTO C :VARARG
FormatLabeledWordSetAsFlags PROTO C :VARARG
FormatPropertyDataAsHexString PROTO C :VARARG
FormatPropertyDataAsInt64 PROTO C :VARARG
FormatPropertyDataAsString PROTO C :VARARG
FormatPropertyDataAsTime PROTO C :VARARG
FormatPropertyDataAsWord PROTO C :VARARG
FormatTimeAsString PROTO C :VARARG
FormatWordFlags PROTO C :VARARG
GetEtype PROTO STDCALL :DWORD,:DWORD
GetLLCHeaderLength PROTO STDCALL :DWORD
GetMacHeaderLength PROTO STDCALL :DWORD,:DWORD
GetProtocolDescription PROTO STDCALL :DWORD
GetProtocolDescriptionTable PROTO STDCALL :DWORD
GetSaps PROTO STDCALL :DWORD,:DWORD
IsLLCPresent PROTO STDCALL :DWORD,:DWORD
LookupByteSetString PROTO STDCALL :DWORD,:DWORD
LookupDwordSetString PROTO STDCALL :DWORD,:DWORD
LookupWordSetString PROTO STDCALL :DWORD,:DWORD
StringToAddress PROTO STDCALL :DWORD,:DWORD
VarLenSmallIntToDword PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WordToBinary PROTO STDCALL :DWORD,:DWORD
byte_flag_to_string PROTO C :VARARG
dword_flag_to_string PROTO C :VARARG
fm_byte10 PROTO C :VARARG
fm_byte16 PROTO C :VARARG
fm_byte_flags PROTO C :VARARG
fm_byte_set PROTO C :VARARG
fm_dword10 PROTO C :VARARG
fm_dword16 PROTO C :VARARG
fm_dword_flags PROTO C :VARARG
fm_dword_set PROTO C :VARARG
fm_hex_string PROTO C :VARARG
fm_largeint16 PROTO C :VARARG
fm_property_name PROTO C :VARARG
fm_string PROTO C :VARARG
fm_swap_dword10 PROTO C :VARARG
fm_swap_dword16 PROTO C :VARARG
fm_swap_word10 PROTO C :VARARG
fm_swap_word16 PROTO C :VARARG
fm_time PROTO C :VARARG
fm_time_ex PROTO C :VARARG
fm_word10 PROTO C :VARARG
fm_word16 PROTO C :VARARG
fm_word_flags PROTO C :VARARG
fm_word_set PROTO C :VARARG
hex_canon PROTO C :VARARG
hex_canon2 PROTO C :VARARG
itoa1 PROTO C :VARARG
prop_name_equals PROTO C :VARARG
property_name PROTO C :VARARG
strcpy1 PROTO C :VARARG
time_string PROTO C :VARARG
  ; word_flag_to_string arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file parser.inc
  echo -----------------------------------------
ENDIF
