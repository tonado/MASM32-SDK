; --------------------------------------------------------------------------------------------------
;                           rpcns4.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF RPCNS4_INC
RPCNS4_INC equ <1>

I_GetDefaultEntrySyntax PROTO STDCALL
I_RpcNsGetBuffer PROTO STDCALL :DWORD
I_RpcNsNegotiateTransferSyntax PROTO STDCALL :DWORD
I_RpcNsRaiseException PROTO STDCALL :DWORD,:DWORD
I_RpcNsSendReceive PROTO STDCALL :DWORD,:DWORD
I_RpcReBindBuffer PROTO STDCALL :DWORD
RpcIfIdVectorFree PROTO STDCALL :DWORD

RpcNsBindingExportA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingExport equ <RpcNsBindingExportA>
ENDIF

RpcNsBindingExportPnPA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingExportPnP equ <RpcNsBindingExportPnPA>
ENDIF

RpcNsBindingExportPnPW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingExportPnP equ <RpcNsBindingExportPnPW>
ENDIF

RpcNsBindingExportW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingExport equ <RpcNsBindingExportW>
ENDIF

RpcNsBindingImportBeginA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingImportBegin equ <RpcNsBindingImportBeginA>
ENDIF

RpcNsBindingImportBeginW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingImportBegin equ <RpcNsBindingImportBeginW>
ENDIF

RpcNsBindingImportDone PROTO STDCALL :DWORD
RpcNsBindingImportNext PROTO STDCALL :DWORD,:DWORD

RpcNsBindingLookupBeginA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginA>
ENDIF

RpcNsBindingLookupBeginW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginW>
ENDIF

RpcNsBindingLookupDone PROTO STDCALL :DWORD
RpcNsBindingLookupNext PROTO STDCALL :DWORD,:DWORD
RpcNsBindingSelect PROTO STDCALL :DWORD,:DWORD

RpcNsBindingUnexportA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingUnexport equ <RpcNsBindingUnexportA>
ENDIF

RpcNsBindingUnexportPnPA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsBindingUnexportPnP equ <RpcNsBindingUnexportPnPA>
ENDIF

RpcNsBindingUnexportPnPW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingUnexportPnP equ <RpcNsBindingUnexportPnPW>
ENDIF

RpcNsBindingUnexportW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsBindingUnexport equ <RpcNsBindingUnexportW>
ENDIF

RpcNsEntryExpandNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsEntryExpandName equ <RpcNsEntryExpandNameA>
ENDIF

RpcNsEntryExpandNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsEntryExpandName equ <RpcNsEntryExpandNameW>
ENDIF

RpcNsEntryObjectInqBeginA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginA>
ENDIF

RpcNsEntryObjectInqBeginW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginW>
ENDIF

RpcNsEntryObjectInqDone PROTO STDCALL :DWORD
RpcNsEntryObjectInqNext PROTO STDCALL :DWORD,:DWORD

RpcNsGroupDeleteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsGroupDelete equ <RpcNsGroupDeleteA>
ENDIF

RpcNsGroupDeleteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsGroupDelete equ <RpcNsGroupDeleteW>
ENDIF

RpcNsGroupMbrAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddA>
ENDIF

RpcNsGroupMbrAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddW>
ENDIF

RpcNsGroupMbrInqBeginA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginA>
ENDIF

RpcNsGroupMbrInqBeginW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginW>
ENDIF

RpcNsGroupMbrInqDone PROTO STDCALL :DWORD

RpcNsGroupMbrInqNextA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextA>
ENDIF

RpcNsGroupMbrInqNextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextW>
ENDIF

RpcNsGroupMbrRemoveA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveA>
ENDIF

RpcNsGroupMbrRemoveW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveW>
ENDIF

RpcNsMgmtBindingUnexportA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportA>
ENDIF

RpcNsMgmtBindingUnexportW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportW>
ENDIF

RpcNsMgmtEntryCreateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateA>
ENDIF

RpcNsMgmtEntryCreateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateW>
ENDIF

RpcNsMgmtEntryDeleteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteA>
ENDIF

RpcNsMgmtEntryDeleteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteW>
ENDIF

RpcNsMgmtEntryInqIfIdsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsA>
ENDIF

RpcNsMgmtEntryInqIfIdsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsW>
ENDIF

RpcNsMgmtHandleSetExpAge PROTO STDCALL :DWORD,:DWORD
RpcNsMgmtInqExpAge PROTO STDCALL :DWORD
RpcNsMgmtSetExpAge PROTO STDCALL :DWORD

RpcNsProfileDeleteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsProfileDelete equ <RpcNsProfileDeleteA>
ENDIF

RpcNsProfileDeleteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsProfileDelete equ <RpcNsProfileDeleteW>
ENDIF

RpcNsProfileEltAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsProfileEltAdd equ <RpcNsProfileEltAddA>
ENDIF

RpcNsProfileEltAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsProfileEltAdd equ <RpcNsProfileEltAddW>
ENDIF

RpcNsProfileEltInqBeginA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginA>
ENDIF

RpcNsProfileEltInqBeginW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginW>
ENDIF

RpcNsProfileEltInqDone PROTO STDCALL :DWORD

RpcNsProfileEltInqNextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextA>
ENDIF

RpcNsProfileEltInqNextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextW>
ENDIF

RpcNsProfileEltRemoveA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveA>
ENDIF

RpcNsProfileEltRemoveW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file rpcns4.inc
  echo -----------------------------------------
ENDIF
