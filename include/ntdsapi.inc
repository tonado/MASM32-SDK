; --------------------------------------------------------------------------------------------------
;                           ntdsapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTDSAPI_INC
NTDSAPI_INC equ <1>

DsAddSidHistoryA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsAddSidHistory equ <DsAddSidHistoryA>
ENDIF

DsAddSidHistoryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsAddSidHistory equ <DsAddSidHistoryW>
ENDIF

DsBindA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBind equ <DsBindA>
ENDIF

DsBindW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBind equ <DsBindW>
ENDIF

DsBindWithCredA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBindWithCred equ <DsBindWithCredA>
ENDIF

DsBindWithCredW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBindWithCred equ <DsBindWithCredW>
ENDIF

DsBindWithSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsBindWithSpn equ <DsBindWithSpnA>
ENDIF

DsBindWithSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBindWithSpn equ <DsBindWithSpnW>
ENDIF

DsClientMakeSpnForTargetServerA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsClientMakeSpnForTargetServer equ <DsClientMakeSpnForTargetServerA>
ENDIF

DsClientMakeSpnForTargetServerW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsClientMakeSpnForTargetServer equ <DsClientMakeSpnForTargetServerW>
ENDIF

DsCrackNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsCrackNames equ <DsCrackNamesA>
ENDIF

DsCrackNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackNames equ <DsCrackNamesW>
ENDIF

DsCrackSpn2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsCrackSpn2 equ <DsCrackSpn2A>
ENDIF

DsCrackSpn2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackSpn2 equ <DsCrackSpn2W>
ENDIF

DsCrackSpn3W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackSpn3 equ <DsCrackSpn3W>
ENDIF

DsCrackSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsCrackSpn equ <DsCrackSpnA>
ENDIF

DsCrackSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackSpn equ <DsCrackSpnW>
ENDIF

DsCrackUnquotedMangledRdnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsCrackUnquotedMangledRdn equ <DsCrackUnquotedMangledRdnA>
ENDIF

DsCrackUnquotedMangledRdnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackUnquotedMangledRdn equ <DsCrackUnquotedMangledRdnW>
ENDIF

DsFreeDomainControllerInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsFreeDomainControllerInfo equ <DsFreeDomainControllerInfoA>
ENDIF

DsFreeDomainControllerInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsFreeDomainControllerInfo equ <DsFreeDomainControllerInfoW>
ENDIF

DsFreeNameResultA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DsFreeNameResult equ <DsFreeNameResultA>
ENDIF

DsFreeNameResultW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsFreeNameResult equ <DsFreeNameResultW>
ENDIF

DsFreePasswordCredentials PROTO STDCALL :DWORD

DsFreeSchemaGuidMapA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DsFreeSchemaGuidMap equ <DsFreeSchemaGuidMapA>
ENDIF

DsFreeSchemaGuidMapW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsFreeSchemaGuidMap equ <DsFreeSchemaGuidMapW>
ENDIF

DsFreeSpnArrayA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsFreeSpnArray equ <DsFreeSpnArrayA>
ENDIF

DsFreeSpnArrayW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsFreeSpnArray equ <DsFreeSpnArrayW>
ENDIF

DsGetDomainControllerInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetDomainControllerInfo equ <DsGetDomainControllerInfoA>
ENDIF

DsGetDomainControllerInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetDomainControllerInfo equ <DsGetDomainControllerInfoW>
ENDIF

DsGetRdnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetRdn equ <DsGetRdnW>
ENDIF

DsGetSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsGetSpn equ <DsGetSpnA>
ENDIF

DsGetSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsGetSpn equ <DsGetSpnW>
ENDIF

DsInheritSecurityIdentityA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsInheritSecurityIdentity equ <DsInheritSecurityIdentityA>
ENDIF

DsInheritSecurityIdentityW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsInheritSecurityIdentity equ <DsInheritSecurityIdentityW>
ENDIF

DsIsMangledDnA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsIsMangledDn equ <DsIsMangledDnA>
ENDIF

DsIsMangledDnW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsIsMangledDn equ <DsIsMangledDnW>
ENDIF

DsIsMangledRdnValueA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsIsMangledRdnValue equ <DsIsMangledRdnValueA>
ENDIF

DsIsMangledRdnValueW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsIsMangledRdnValue equ <DsIsMangledRdnValueW>
ENDIF

DsListDomainsInSiteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsListDomainsInSite equ <DsListDomainsInSiteA>
ENDIF

DsListDomainsInSiteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsListDomainsInSite equ <DsListDomainsInSiteW>
ENDIF

DsListInfoForServerA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsListInfoForServer equ <DsListInfoForServerA>
ENDIF

DsListInfoForServerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsListInfoForServer equ <DsListInfoForServerW>
ENDIF

DsListRolesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsListRoles equ <DsListRolesA>
ENDIF

DsListRolesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsListRoles equ <DsListRolesW>
ENDIF

DsListServersForDomainInSiteA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsListServersForDomainInSite equ <DsListServersForDomainInSiteA>
ENDIF

DsListServersForDomainInSiteW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsListServersForDomainInSite equ <DsListServersForDomainInSiteW>
ENDIF

DsListServersInSiteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsListServersInSite equ <DsListServersInSiteA>
ENDIF

DsListServersInSiteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsListServersInSite equ <DsListServersInSiteW>
ENDIF

DsListSitesA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsListSites equ <DsListSitesA>
ENDIF

DsListSitesW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsListSites equ <DsListSitesW>
ENDIF

DsLogEntry PROTO C :VARARG

DsMakePasswordCredentialsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsMakePasswordCredentials equ <DsMakePasswordCredentialsA>
ENDIF

DsMakePasswordCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsMakePasswordCredentials equ <DsMakePasswordCredentialsW>
ENDIF

DsMakeSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsMakeSpn equ <DsMakeSpnA>
ENDIF

DsMakeSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsMakeSpn equ <DsMakeSpnW>
ENDIF

DsMapSchemaGuidsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsMapSchemaGuids equ <DsMapSchemaGuidsA>
ENDIF

DsMapSchemaGuidsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsMapSchemaGuids equ <DsMapSchemaGuidsW>
ENDIF

DsQuoteRdnValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsQuoteRdnValue equ <DsQuoteRdnValueA>
ENDIF

DsQuoteRdnValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsQuoteRdnValue equ <DsQuoteRdnValueW>
ENDIF

DsRemoveDsDomainA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DsRemoveDsDomain equ <DsRemoveDsDomainA>
ENDIF

DsRemoveDsDomainW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DsRemoveDsDomain equ <DsRemoveDsDomainW>
ENDIF

DsRemoveDsServerA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsRemoveDsServer equ <DsRemoveDsServerA>
ENDIF

DsRemoveDsServerW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsRemoveDsServer equ <DsRemoveDsServerW>
ENDIF

DsReplicaAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaAdd equ <DsReplicaAddA>
ENDIF

DsReplicaAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaAdd equ <DsReplicaAddW>
ENDIF

DsReplicaConsistencyCheck PROTO STDCALL :DWORD,:DWORD,:DWORD

DsReplicaDelA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaDel equ <DsReplicaDelA>
ENDIF

DsReplicaDelW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaDel equ <DsReplicaDelW>
ENDIF

DsReplicaFreeInfo PROTO STDCALL :DWORD,:DWORD

DsReplicaGetInfo2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaGetInfo2 equ <DsReplicaGetInfo2W>
ENDIF

DsReplicaGetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaGetInfo equ <DsReplicaGetInfoW>
ENDIF

DsReplicaModifyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaModify equ <DsReplicaModifyA>
ENDIF

DsReplicaModifyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaModify equ <DsReplicaModifyW>
ENDIF

DsReplicaSyncA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaSync equ <DsReplicaSyncA>
ENDIF

DsReplicaSyncAllA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaSyncAll equ <DsReplicaSyncAllA>
ENDIF

DsReplicaSyncAllW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaSyncAll equ <DsReplicaSyncAllW>
ENDIF

DsReplicaSyncW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaSync equ <DsReplicaSyncW>
ENDIF

DsReplicaUpdateRefsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaUpdateRefs equ <DsReplicaUpdateRefsA>
ENDIF

DsReplicaUpdateRefsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaUpdateRefs equ <DsReplicaUpdateRefsW>
ENDIF

DsReplicaVerifyObjectsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsReplicaVerifyObjects equ <DsReplicaVerifyObjectsA>
ENDIF

DsReplicaVerifyObjectsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsReplicaVerifyObjects equ <DsReplicaVerifyObjectsW>
ENDIF

DsServerRegisterSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsServerRegisterSpn equ <DsServerRegisterSpnA>
ENDIF

DsServerRegisterSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsServerRegisterSpn equ <DsServerRegisterSpnW>
ENDIF

DsUnBindA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DsUnBind equ <DsUnBindA>
ENDIF

DsUnBindW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsUnBind equ <DsUnBindW>
ENDIF

DsUnquoteRdnValueA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsUnquoteRdnValue equ <DsUnquoteRdnValueA>
ENDIF

DsUnquoteRdnValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsUnquoteRdnValue equ <DsUnquoteRdnValueW>
ENDIF

DsWriteAccountSpnA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DsWriteAccountSpn equ <DsWriteAccountSpnA>
ENDIF

DsWriteAccountSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsWriteAccountSpn equ <DsWriteAccountSpnW>
ENDIF

DsaopBind PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsaopBindWithCred PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsaopBindWithSpn PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsaopExecuteScript PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsaopPrepareScript PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DsaopUnBind PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntdsapi.inc
  echo ------------------------------------------
ENDIF
