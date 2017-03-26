; --------------------------------------------------------------------------------------------------
;                          wtsapi32.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WTSAPI32_INC
WTSAPI32_INC equ <1>

WTSCloseServer PROTO STDCALL :DWORD
WTSDisconnectSession PROTO STDCALL :DWORD,:DWORD,:DWORD

WTSEnumerateProcessesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSEnumerateProcesses equ <WTSEnumerateProcessesA>
ENDIF

WTSEnumerateProcessesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSEnumerateProcesses equ <WTSEnumerateProcessesW>
ENDIF

WTSEnumerateServersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSEnumerateServers equ <WTSEnumerateServersA>
ENDIF

WTSEnumerateServersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSEnumerateServers equ <WTSEnumerateServersW>
ENDIF

WTSEnumerateSessionsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSEnumerateSessions equ <WTSEnumerateSessionsA>
ENDIF

WTSEnumerateSessionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSEnumerateSessions equ <WTSEnumerateSessionsW>
ENDIF

WTSFreeMemory PROTO STDCALL :DWORD
WTSLogoffSession PROTO STDCALL :DWORD,:DWORD,:DWORD

WTSOpenServerA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  WTSOpenServer equ <WTSOpenServerA>
ENDIF

WTSOpenServerW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  WTSOpenServer equ <WTSOpenServerW>
ENDIF

WTSQuerySessionInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSQuerySessionInformation equ <WTSQuerySessionInformationA>
ENDIF

WTSQuerySessionInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSQuerySessionInformation equ <WTSQuerySessionInformationW>
ENDIF

WTSQueryUserConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSQueryUserConfig equ <WTSQueryUserConfigA>
ENDIF

WTSQueryUserConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSQueryUserConfig equ <WTSQueryUserConfigW>
ENDIF

WTSQueryUserToken PROTO STDCALL :DWORD,:DWORD
WTSRegisterSessionNotification PROTO STDCALL :DWORD,:DWORD

WTSSendMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSSendMessage equ <WTSSendMessageA>
ENDIF

WTSSendMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSSendMessage equ <WTSSendMessageW>
ENDIF

WTSSetSessionInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSSetSessionInformation equ <WTSSetSessionInformationA>
ENDIF

WTSSetSessionInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSSetSessionInformation equ <WTSSetSessionInformationW>
ENDIF

WTSSetUserConfigA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  WTSSetUserConfig equ <WTSSetUserConfigA>
ENDIF

WTSSetUserConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  WTSSetUserConfig equ <WTSSetUserConfigW>
ENDIF

WTSShutdownSystem PROTO STDCALL :DWORD,:DWORD
WTSTerminateProcess PROTO STDCALL :DWORD,:DWORD,:DWORD
WTSUnRegisterSessionNotification PROTO STDCALL :DWORD
WTSVirtualChannelClose PROTO STDCALL :DWORD
WTSVirtualChannelOpen PROTO STDCALL :DWORD,:DWORD,:DWORD
WTSVirtualChannelPurgeInput PROTO STDCALL :DWORD
WTSVirtualChannelPurgeOutput PROTO STDCALL :DWORD
WTSVirtualChannelQuery PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WTSVirtualChannelRead PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSVirtualChannelWrite PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WTSWaitSystemEvent PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file wtsapi32.inc
  echo -------------------------------------------
ENDIF
