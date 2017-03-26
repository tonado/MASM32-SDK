; --------------------------------------------------------------------------------------------------
;                           credui.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF CREDUI_INC
CREDUI_INC equ <1>

CredUICmdLinePromptForCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredUICmdLinePromptForCredentials equ <CredUICmdLinePromptForCredentialsA>
ENDIF

CredUICmdLinePromptForCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredUICmdLinePromptForCredentials equ <CredUICmdLinePromptForCredentialsW>
ENDIF

CredUIConfirmCredentialsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CredUIConfirmCredentials equ <CredUIConfirmCredentialsA>
ENDIF

CredUIConfirmCredentialsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CredUIConfirmCredentials equ <CredUIConfirmCredentialsW>
ENDIF

CredUIParseUserNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredUIParseUserName equ <CredUIParseUserNameA>
ENDIF

CredUIParseUserNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredUIParseUserName equ <CredUIParseUserNameW>
ENDIF

CredUIPromptForCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CredUIPromptForCredentials equ <CredUIPromptForCredentialsA>
ENDIF

CredUIPromptForCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredUIPromptForCredentials equ <CredUIPromptForCredentialsW>
ENDIF

CredUIReadSSOCredW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CredUIReadSSOCred equ <CredUIReadSSOCredW>
ENDIF

CredUIStoreSSOCredW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CredUIStoreSSOCred equ <CredUIStoreSSOCredW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file credui.inc
  echo -----------------------------------------
ENDIF
