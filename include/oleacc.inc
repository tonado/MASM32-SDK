; --------------------------------------------------------------------------------------------------
;                           oleacc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF OLEACC_INC
OLEACC_INC equ <1>

AccessibleChildren PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromPoint PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromWindow PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreateStdAccessibleObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateStdAccessibleProxyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateStdAccessibleProxy equ <CreateStdAccessibleProxyA>
ENDIF

CreateStdAccessibleProxyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateStdAccessibleProxy equ <CreateStdAccessibleProxyW>
ENDIF

GetOleaccVersionInfo PROTO STDCALL :DWORD,:DWORD

GetRoleTextA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetRoleText equ <GetRoleTextA>
ENDIF

GetRoleTextW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetRoleText equ <GetRoleTextW>
ENDIF

GetStateTextA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetStateText equ <GetStateTextA>
ENDIF

GetStateTextW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetStateText equ <GetStateTextW>
ENDIF

LresultFromObject PROTO STDCALL :DWORD,:DWORD,:DWORD
ObjectFromLresult PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
WindowFromAccessibleObject PROTO STDCALL :DWORD,:DWORD

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file oleacc.inc
  echo -----------------------------------------
ENDIF
