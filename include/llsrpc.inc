; --------------------------------------------------------------------------------------------------
;                           llsrpc.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF LLSRPC_INC
LLSRPC_INC equ <1>

LlsCapabilityIsSupported PROTO STDCALL :DWORD,:DWORD

LlsCertificateClaimAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsCertificateClaimAdd equ <LlsCertificateClaimAddA>
ENDIF

LlsCertificateClaimAddCheckA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsCertificateClaimAddCheck equ <LlsCertificateClaimAddCheckA>
ENDIF

LlsCertificateClaimAddCheckW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsCertificateClaimAddCheck equ <LlsCertificateClaimAddCheckW>
ENDIF

LlsCertificateClaimAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsCertificateClaimAdd equ <LlsCertificateClaimAddW>
ENDIF

LlsClose PROTO STDCALL :DWORD

LlsConnectA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LlsConnect equ <LlsConnectA>
ENDIF

LlsConnectEnterpriseA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsConnectEnterprise equ <LlsConnectEnterpriseA>
ENDIF

LlsConnectEnterpriseW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsConnectEnterprise equ <LlsConnectEnterpriseW>
ENDIF

LlsConnectW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LlsConnect equ <LlsConnectW>
ENDIF

LlsEnterpriseServerFindA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsEnterpriseServerFind equ <LlsEnterpriseServerFindA>
ENDIF

LlsEnterpriseServerFindW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsEnterpriseServerFind equ <LlsEnterpriseServerFindW>
ENDIF

LlsFreeMemory PROTO STDCALL :DWORD

LlsGroupAddA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupAdd equ <LlsGroupAddA>
ENDIF

LlsGroupAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupAdd equ <LlsGroupAddW>
ENDIF

LlsGroupDeleteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupDelete equ <LlsGroupDeleteA>
ENDIF

LlsGroupDeleteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupDelete equ <LlsGroupDeleteW>
ENDIF

LlsGroupEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupEnum equ <LlsGroupEnumA>
ENDIF

LlsGroupEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupEnum equ <LlsGroupEnumW>
ENDIF

LlsGroupInfoGetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupInfoGet equ <LlsGroupInfoGetA>
ENDIF

LlsGroupInfoGetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupInfoGet equ <LlsGroupInfoGetW>
ENDIF

LlsGroupInfoSetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupInfoSet equ <LlsGroupInfoSetA>
ENDIF

LlsGroupInfoSetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupInfoSet equ <LlsGroupInfoSetW>
ENDIF

LlsGroupUserAddA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupUserAdd equ <LlsGroupUserAddA>
ENDIF

LlsGroupUserAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupUserAdd equ <LlsGroupUserAddW>
ENDIF

LlsGroupUserDeleteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupUserDelete equ <LlsGroupUserDeleteA>
ENDIF

LlsGroupUserDeleteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupUserDelete equ <LlsGroupUserDeleteW>
ENDIF

LlsGroupUserEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsGroupUserEnum equ <LlsGroupUserEnumA>
ENDIF

LlsGroupUserEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsGroupUserEnum equ <LlsGroupUserEnumW>
ENDIF

LlsLicenseAddA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLicenseAdd equ <LlsLicenseAddA>
ENDIF

LlsLicenseAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLicenseAdd equ <LlsLicenseAddW>
ENDIF

LlsLicenseEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLicenseEnum equ <LlsLicenseEnumA>
ENDIF

LlsLicenseEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLicenseEnum equ <LlsLicenseEnumW>
ENDIF

LlsLicenseFree2 PROTO STDCALL :DWORD,:DWORD
LlsLicenseFree PROTO STDCALL :DWORD,:DWORD

LlsLicenseRequest2A PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLicenseRequest2 equ <LlsLicenseRequest2A>
ENDIF

LlsLicenseRequest2W PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLicenseRequest2 equ <LlsLicenseRequest2W>
ENDIF

LlsLicenseRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLicenseRequest equ <LlsLicenseRequestA>
ENDIF

LlsLicenseRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLicenseRequest equ <LlsLicenseRequestW>
ENDIF

LlsLocalServiceEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLocalServiceEnum equ <LlsLocalServiceEnumA>
ENDIF

LlsLocalServiceEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLocalServiceEnum equ <LlsLocalServiceEnumW>
ENDIF

LlsLocalServiceInfoGetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLocalServiceInfoGet equ <LlsLocalServiceInfoGetA>
ENDIF

LlsLocalServiceInfoGetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLocalServiceInfoGet equ <LlsLocalServiceInfoGetW>
ENDIF

LlsLocalServiceInfoSetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsLocalServiceInfoSet equ <LlsLocalServiceInfoSetA>
ENDIF

LlsLocalServiceInfoSetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsLocalServiceInfoSet equ <LlsLocalServiceInfoSetW>
ENDIF

LlsProductAddA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductAdd equ <LlsProductAddA>
ENDIF

LlsProductAddW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductAdd equ <LlsProductAddW>
ENDIF

LlsProductEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductEnum equ <LlsProductEnumA>
ENDIF

LlsProductEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductEnum equ <LlsProductEnumW>
ENDIF

LlsProductLicenseEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductLicenseEnum equ <LlsProductLicenseEnumA>
ENDIF

LlsProductLicenseEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductLicenseEnum equ <LlsProductLicenseEnumW>
ENDIF

LlsProductLicensesGetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductLicensesGet equ <LlsProductLicensesGetA>
ENDIF

LlsProductLicensesGetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductLicensesGet equ <LlsProductLicensesGetW>
ENDIF

LlsProductSecurityGetA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductSecurityGet equ <LlsProductSecurityGetA>
ENDIF

LlsProductSecurityGetW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductSecurityGet equ <LlsProductSecurityGetW>
ENDIF

LlsProductSecuritySetA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductSecuritySet equ <LlsProductSecuritySetA>
ENDIF

LlsProductSecuritySetW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductSecuritySet equ <LlsProductSecuritySetW>
ENDIF

LlsProductServerEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductServerEnum equ <LlsProductServerEnumA>
ENDIF

LlsProductServerEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductServerEnum equ <LlsProductServerEnumW>
ENDIF

LlsProductUserEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsProductUserEnum equ <LlsProductUserEnumA>
ENDIF

LlsProductUserEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsProductUserEnum equ <LlsProductUserEnumW>
ENDIF

LlsReplClose PROTO STDCALL :DWORD

LlsReplConnectW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplConnect equ <LlsReplConnectW>
ENDIF

LlsReplicationCertDbAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationCertDbAdd equ <LlsReplicationCertDbAddW>
ENDIF

LlsReplicationProductSecurityAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationProductSecurityAdd equ <LlsReplicationProductSecurityAddW>
ENDIF

LlsReplicationRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationRequest equ <LlsReplicationRequestW>
ENDIF

LlsReplicationServerAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationServerAdd equ <LlsReplicationServerAddW>
ENDIF

LlsReplicationServerServiceAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationServerServiceAdd equ <LlsReplicationServerServiceAddW>
ENDIF

LlsReplicationServiceAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationServiceAdd equ <LlsReplicationServiceAddW>
ENDIF

LlsReplicationUserAddExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationUserAddEx equ <LlsReplicationUserAddExW>
ENDIF

LlsReplicationUserAddW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsReplicationUserAdd equ <LlsReplicationUserAddW>
ENDIF

LlsServiceInfoGetA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsServiceInfoGet equ <LlsServiceInfoGetA>
ENDIF

LlsServiceInfoGetW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsServiceInfoGet equ <LlsServiceInfoGetW>
ENDIF

LlsServiceInfoSetA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsServiceInfoSet equ <LlsServiceInfoSetA>
ENDIF

LlsServiceInfoSetW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsServiceInfoSet equ <LlsServiceInfoSetW>
ENDIF

LlsUserDeleteA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserDelete equ <LlsUserDeleteA>
ENDIF

LlsUserDeleteW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserDelete equ <LlsUserDeleteW>
ENDIF

LlsUserEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserEnum equ <LlsUserEnumA>
ENDIF

LlsUserEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserEnum equ <LlsUserEnumW>
ENDIF

LlsUserInfoGetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserInfoGet equ <LlsUserInfoGetA>
ENDIF

LlsUserInfoGetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserInfoGet equ <LlsUserInfoGetW>
ENDIF

LlsUserInfoSetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserInfoSet equ <LlsUserInfoSetA>
ENDIF

LlsUserInfoSetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserInfoSet equ <LlsUserInfoSetW>
ENDIF

LlsUserProductDeleteA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserProductDelete equ <LlsUserProductDeleteA>
ENDIF

LlsUserProductDeleteW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserProductDelete equ <LlsUserProductDeleteW>
ENDIF

LlsUserProductEnumA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  LlsUserProductEnum equ <LlsUserProductEnumA>
ENDIF

LlsUserProductEnumW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LlsUserProductEnum equ <LlsUserProductEnumW>
ENDIF

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file llsrpc.inc
  echo -----------------------------------------
ENDIF
