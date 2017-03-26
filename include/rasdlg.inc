; --------------------------------------------------------------------------------------------------
;                           rasdlg.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RASDLG_INC
RASDLG_INC equ <1>

DwTerminalDlg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetRasDialOutProtocols PROTO STDCALL

RasAutodialDisableDlgA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RasAutodialDisableDlg equ <RasAutodialDisableDlgA>
ENDIF

RasAutodialDisableDlgW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RasAutodialDisableDlg equ <RasAutodialDisableDlgW>
ENDIF

RasAutodialQueryDlgA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasAutodialQueryDlg equ <RasAutodialQueryDlgA>
ENDIF

RasAutodialQueryDlgW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasAutodialQueryDlg equ <RasAutodialQueryDlgW>
ENDIF

RasDialDlgA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasDialDlg equ <RasDialDlgA>
ENDIF

RasDialDlgW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasDialDlg equ <RasDialDlgW>
ENDIF

RasEntryDlgA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasEntryDlg equ <RasEntryDlgA>
ENDIF

RasEntryDlgW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasEntryDlg equ <RasEntryDlgW>
ENDIF

RasMonitorDlgA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RasMonitorDlg equ <RasMonitorDlgA>
ENDIF

RasMonitorDlgW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RasMonitorDlg equ <RasMonitorDlgW>
ENDIF

RasPhonebookDlgA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RasPhonebookDlg equ <RasPhonebookDlgA>
ENDIF

RasPhonebookDlgW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RasPhonebookDlg equ <RasPhonebookDlgW>
ENDIF

RasSrvAddPropPages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSrvAddWizPages PROTO STDCALL :DWORD,:DWORD,:DWORD
RasSrvAllowConnectionsConfig PROTO STDCALL :DWORD
RasSrvCleanupService PROTO STDCALL
RasSrvEnumConnections PROTO STDCALL :DWORD,:DWORD,:DWORD
RasSrvHangupConnection PROTO STDCALL :DWORD
RasSrvInitializeService PROTO STDCALL
RasSrvIsConnectionConnected PROTO STDCALL :DWORD,:DWORD
RasSrvIsServiceRunning PROTO STDCALL :DWORD
RasSrvQueryShowIcon PROTO STDCALL :DWORD
RasUserEnableManualDial PROTO STDCALL :DWORD,:DWORD,:DWORD
RasUserGetManualDial PROTO STDCALL :DWORD,:DWORD,:DWORD
RasUserPrefsDlg PROTO STDCALL :DWORD
RasWizCreateNewEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasWizGetNCCFlags PROTO STDCALL :DWORD,:DWORD,:DWORD
RasWizGetSuggestedEntryName PROTO STDCALL :DWORD,:DWORD,:DWORD
RasWizGetUserInputConnectionName PROTO STDCALL :DWORD,:DWORD
RasWizIsEntryRenamable PROTO STDCALL :DWORD,:DWORD,:DWORD
RasWizQueryMaxPageCount PROTO STDCALL :DWORD
RasWizSetEntryName PROTO STDCALL :DWORD,:DWORD,:DWORD

RouterEntryDlgA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RouterEntryDlg equ <RouterEntryDlgA>
ENDIF

RouterEntryDlgW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RouterEntryDlg equ <RouterEntryDlgW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file rasdlg.inc
  echo -----------------------------------------
ENDIF
