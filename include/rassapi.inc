; --------------------------------------------------------------------------------------------------
;                           rassapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RASSAPI_INC
RASSAPI_INC equ <1>

RasAdminCompressPhoneNumber PROTO STDCALL :DWORD,:DWORD
RasAdminFreeBuffer PROTO STDCALL :DWORD
RasAdminGetErrorString PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAdminGetUserAccountServer PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAdminGetUserParms PROTO STDCALL :DWORD,:DWORD
RasAdminPortClearStatistics PROTO STDCALL :DWORD,:DWORD
RasAdminPortDisconnect PROTO STDCALL :DWORD,:DWORD
RasAdminPortEnum PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAdminPortGetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasAdminServerGetInfo PROTO STDCALL :DWORD,:DWORD
RasAdminSetUserParms PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAdminUserGetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
RasAdminUserSetInfo PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file rassapi.inc
  echo ------------------------------------------
ENDIF
