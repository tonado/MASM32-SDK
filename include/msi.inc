; --------------------------------------------------------------------------------------------------
;                             msi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF MSI_INC
MSI_INC equ <1>

DllGetVersion PROTO STDCALL :DWORD

Migrate10CachedPackagesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  Migrate10CachedPackages equ <Migrate10CachedPackagesA>
ENDIF

Migrate10CachedPackagesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  Migrate10CachedPackages equ <Migrate10CachedPackagesW>
ENDIF

MsiAdvertiseProductA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiAdvertiseProduct equ <MsiAdvertiseProductA>
ENDIF

MsiAdvertiseProductExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiAdvertiseProductEx equ <MsiAdvertiseProductExA>
ENDIF

MsiAdvertiseProductExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiAdvertiseProductEx equ <MsiAdvertiseProductExW>
ENDIF

MsiAdvertiseProductW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiAdvertiseProduct equ <MsiAdvertiseProductW>
ENDIF

MsiAdvertiseScriptA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiAdvertiseScript equ <MsiAdvertiseScriptA>
ENDIF

MsiAdvertiseScriptW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiAdvertiseScript equ <MsiAdvertiseScriptW>
ENDIF

MsiApplyMultiplePatchesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiApplyMultiplePatches equ <MsiApplyMultiplePatchesA>
ENDIF

MsiApplyMultiplePatchesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiApplyMultiplePatches equ <MsiApplyMultiplePatchesW>
ENDIF

MsiApplyPatchA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiApplyPatch equ <MsiApplyPatchA>
ENDIF

MsiApplyPatchW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiApplyPatch equ <MsiApplyPatchW>
ENDIF

MsiCloseAllHandles PROTO STDCALL
MsiCloseHandle PROTO STDCALL :DWORD

MsiCollectUserInfoA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  MsiCollectUserInfo equ <MsiCollectUserInfoA>
ENDIF

MsiCollectUserInfoW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  MsiCollectUserInfo equ <MsiCollectUserInfoW>
ENDIF

MsiConfigureFeatureA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiConfigureFeature equ <MsiConfigureFeatureA>
ENDIF

MsiConfigureFeatureFromDescriptorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiConfigureFeatureFromDescriptor equ <MsiConfigureFeatureFromDescriptorA>
ENDIF

MsiConfigureFeatureFromDescriptorW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiConfigureFeatureFromDescriptor equ <MsiConfigureFeatureFromDescriptorW>
ENDIF

MsiConfigureFeatureW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiConfigureFeature equ <MsiConfigureFeatureW>
ENDIF

MsiConfigureProductA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiConfigureProduct equ <MsiConfigureProductA>
ENDIF

MsiConfigureProductExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiConfigureProductEx equ <MsiConfigureProductExA>
ENDIF

MsiConfigureProductExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiConfigureProductEx equ <MsiConfigureProductExW>
ENDIF

MsiConfigureProductW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiConfigureProduct equ <MsiConfigureProductW>
ENDIF

MsiCreateAndVerifyInstallerDirectory PROTO STDCALL :DWORD
MsiCreateRecord PROTO STDCALL :DWORD

MsiCreateTransformSummaryInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiCreateTransformSummaryInfo equ <MsiCreateTransformSummaryInfoA>
ENDIF

MsiCreateTransformSummaryInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiCreateTransformSummaryInfo equ <MsiCreateTransformSummaryInfoW>
ENDIF

MsiDatabaseApplyTransformA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseApplyTransform equ <MsiDatabaseApplyTransformA>
ENDIF

MsiDatabaseApplyTransformW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseApplyTransform equ <MsiDatabaseApplyTransformW>
ENDIF

MsiDatabaseCommit PROTO STDCALL :DWORD

MsiDatabaseExportA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseExport equ <MsiDatabaseExportA>
ENDIF

MsiDatabaseExportW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseExport equ <MsiDatabaseExportW>
ENDIF

MsiDatabaseGenerateTransformA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseGenerateTransform equ <MsiDatabaseGenerateTransformA>
ENDIF

MsiDatabaseGenerateTransformW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseGenerateTransform equ <MsiDatabaseGenerateTransformW>
ENDIF

MsiDatabaseGetPrimaryKeysA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseGetPrimaryKeys equ <MsiDatabaseGetPrimaryKeysA>
ENDIF

MsiDatabaseGetPrimaryKeysW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseGetPrimaryKeys equ <MsiDatabaseGetPrimaryKeysW>
ENDIF

MsiDatabaseImportA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseImport equ <MsiDatabaseImportA>
ENDIF

MsiDatabaseImportW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseImport equ <MsiDatabaseImportW>
ENDIF

MsiDatabaseIsTablePersistentA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseIsTablePersistent equ <MsiDatabaseIsTablePersistentA>
ENDIF

MsiDatabaseIsTablePersistentW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseIsTablePersistent equ <MsiDatabaseIsTablePersistentW>
ENDIF

MsiDatabaseMergeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseMerge equ <MsiDatabaseMergeA>
ENDIF

MsiDatabaseMergeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseMerge equ <MsiDatabaseMergeW>
ENDIF

MsiDatabaseOpenViewA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDatabaseOpenView equ <MsiDatabaseOpenViewA>
ENDIF

MsiDatabaseOpenViewW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDatabaseOpenView equ <MsiDatabaseOpenViewW>
ENDIF

MsiDecomposeDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDecomposeDescriptor equ <MsiDecomposeDescriptorA>
ENDIF

MsiDecomposeDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDecomposeDescriptor equ <MsiDecomposeDescriptorW>
ENDIF

MsiDeleteUserDataA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDeleteUserData equ <MsiDeleteUserDataA>
ENDIF

MsiDeleteUserDataW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDeleteUserData equ <MsiDeleteUserDataW>
ENDIF

MsiDetermineApplicablePatchesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDetermineApplicablePatches equ <MsiDetermineApplicablePatchesA>
ENDIF

MsiDetermineApplicablePatchesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDetermineApplicablePatches equ <MsiDetermineApplicablePatchesW>
ENDIF

MsiDeterminePatchSequenceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDeterminePatchSequence equ <MsiDeterminePatchSequenceA>
ENDIF

MsiDeterminePatchSequenceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiDeterminePatchSequence equ <MsiDeterminePatchSequenceW>
ENDIF

MsiDoActionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiDoAction equ <MsiDoActionA>
ENDIF

MsiDoActionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiDoAction equ <MsiDoActionW>
ENDIF

MsiEnableLogA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnableLog equ <MsiEnableLogA>
ENDIF

MsiEnableLogW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnableLog equ <MsiEnableLogW>
ENDIF

MsiEnableUIPreview PROTO STDCALL :DWORD,:DWORD

MsiEnumClientsA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumClients equ <MsiEnumClientsA>
ENDIF

MsiEnumClientsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumClients equ <MsiEnumClientsW>
ENDIF

MsiEnumComponentCostsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumComponentCosts equ <MsiEnumComponentCostsA>
ENDIF

MsiEnumComponentCostsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumComponentCosts equ <MsiEnumComponentCostsW>
ENDIF

MsiEnumComponentQualifiersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumComponentQualifiers equ <MsiEnumComponentQualifiersA>
ENDIF

MsiEnumComponentQualifiersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumComponentQualifiers equ <MsiEnumComponentQualifiersW>
ENDIF

MsiEnumComponentsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumComponents equ <MsiEnumComponentsA>
ENDIF

MsiEnumComponentsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumComponents equ <MsiEnumComponentsW>
ENDIF

MsiEnumFeaturesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumFeatures equ <MsiEnumFeaturesA>
ENDIF

MsiEnumFeaturesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumFeatures equ <MsiEnumFeaturesW>
ENDIF

MsiEnumPatchesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumPatches equ <MsiEnumPatchesA>
ENDIF

MsiEnumPatchesExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumPatchesEx equ <MsiEnumPatchesExA>
ENDIF

MsiEnumPatchesExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumPatchesEx equ <MsiEnumPatchesExW>
ENDIF

MsiEnumPatchesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumPatches equ <MsiEnumPatchesW>
ENDIF

MsiEnumProductsA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumProducts equ <MsiEnumProductsA>
ENDIF

MsiEnumProductsExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumProductsEx equ <MsiEnumProductsExA>
ENDIF

MsiEnumProductsExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumProductsEx equ <MsiEnumProductsExW>
ENDIF

MsiEnumProductsW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumProducts equ <MsiEnumProductsW>
ENDIF

MsiEnumRelatedProductsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEnumRelatedProducts equ <MsiEnumRelatedProductsA>
ENDIF

MsiEnumRelatedProductsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiEnumRelatedProducts equ <MsiEnumRelatedProductsW>
ENDIF

MsiEvaluateConditionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiEvaluateCondition equ <MsiEvaluateConditionA>
ENDIF

MsiEvaluateConditionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiEvaluateCondition equ <MsiEvaluateConditionW>
ENDIF

MsiExtractPatchXMLDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiExtractPatchXMLData equ <MsiExtractPatchXMLDataA>
ENDIF

MsiExtractPatchXMLDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiExtractPatchXMLData equ <MsiExtractPatchXMLDataW>
ENDIF

MsiFormatRecordA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiFormatRecord equ <MsiFormatRecordA>
ENDIF

MsiFormatRecordW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiFormatRecord equ <MsiFormatRecordW>
ENDIF

MsiGetActiveDatabase PROTO STDCALL :DWORD

MsiGetComponentPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetComponentPath equ <MsiGetComponentPathA>
ENDIF

MsiGetComponentPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetComponentPath equ <MsiGetComponentPathW>
ENDIF

MsiGetComponentStateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetComponentState equ <MsiGetComponentStateA>
ENDIF

MsiGetComponentStateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetComponentState equ <MsiGetComponentStateW>
ENDIF

MsiGetDatabaseState PROTO STDCALL :DWORD

MsiGetFeatureCostA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFeatureCost equ <MsiGetFeatureCostA>
ENDIF

MsiGetFeatureCostW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFeatureCost equ <MsiGetFeatureCostW>
ENDIF

MsiGetFeatureInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFeatureInfo equ <MsiGetFeatureInfoA>
ENDIF

MsiGetFeatureInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFeatureInfo equ <MsiGetFeatureInfoW>
ENDIF

MsiGetFeatureStateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFeatureState equ <MsiGetFeatureStateA>
ENDIF

MsiGetFeatureStateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFeatureState equ <MsiGetFeatureStateW>
ENDIF

MsiGetFeatureUsageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFeatureUsage equ <MsiGetFeatureUsageA>
ENDIF

MsiGetFeatureUsageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFeatureUsage equ <MsiGetFeatureUsageW>
ENDIF

MsiGetFeatureValidStatesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFeatureValidStates equ <MsiGetFeatureValidStatesA>
ENDIF

MsiGetFeatureValidStatesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFeatureValidStates equ <MsiGetFeatureValidStatesW>
ENDIF

MsiGetFileHashA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFileHash equ <MsiGetFileHashA>
ENDIF

MsiGetFileHashW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFileHash equ <MsiGetFileHashW>
ENDIF

MsiGetFileSignatureInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFileSignatureInformation equ <MsiGetFileSignatureInformationA>
ENDIF

MsiGetFileSignatureInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFileSignatureInformation equ <MsiGetFileSignatureInformationW>
ENDIF

MsiGetFileVersionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetFileVersion equ <MsiGetFileVersionA>
ENDIF

MsiGetFileVersionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetFileVersion equ <MsiGetFileVersionW>
ENDIF

MsiGetLanguage PROTO STDCALL :DWORD
MsiGetLastErrorRecord PROTO STDCALL
MsiGetMode PROTO STDCALL :DWORD,:DWORD

MsiGetPatchInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetPatchInfo equ <MsiGetPatchInfoA>
ENDIF

MsiGetPatchInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetPatchInfoEx equ <MsiGetPatchInfoExA>
ENDIF

MsiGetPatchInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetPatchInfoEx equ <MsiGetPatchInfoExW>
ENDIF

MsiGetPatchInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetPatchInfo equ <MsiGetPatchInfoW>
ENDIF

MsiGetProductCodeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductCode equ <MsiGetProductCodeA>
ENDIF

MsiGetProductCodeFromPackageCodeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductCodeFromPackageCode equ <MsiGetProductCodeFromPackageCodeA>
ENDIF

MsiGetProductCodeFromPackageCodeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductCodeFromPackageCode equ <MsiGetProductCodeFromPackageCodeW>
ENDIF

MsiGetProductCodeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductCode equ <MsiGetProductCodeW>
ENDIF

MsiGetProductInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductInfo equ <MsiGetProductInfoA>
ENDIF

MsiGetProductInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductInfoEx equ <MsiGetProductInfoExA>
ENDIF

MsiGetProductInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductInfoEx equ <MsiGetProductInfoExW>
ENDIF

MsiGetProductInfoFromScriptA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductInfoFromScript equ <MsiGetProductInfoFromScriptA>
ENDIF

MsiGetProductInfoFromScriptW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductInfoFromScript equ <MsiGetProductInfoFromScriptW>
ENDIF

MsiGetProductInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductInfo equ <MsiGetProductInfoW>
ENDIF

MsiGetProductPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProductProperty equ <MsiGetProductPropertyA>
ENDIF

MsiGetProductPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProductProperty equ <MsiGetProductPropertyW>
ENDIF

MsiGetPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetProperty equ <MsiGetPropertyA>
ENDIF

MsiGetPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetProperty equ <MsiGetPropertyW>
ENDIF

MsiGetShortcutTargetA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetShortcutTarget equ <MsiGetShortcutTargetA>
ENDIF

MsiGetShortcutTargetW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetShortcutTarget equ <MsiGetShortcutTargetW>
ENDIF

MsiGetSourcePathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetSourcePath equ <MsiGetSourcePathA>
ENDIF

MsiGetSourcePathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetSourcePath equ <MsiGetSourcePathW>
ENDIF

MsiGetSummaryInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetSummaryInformation equ <MsiGetSummaryInformationA>
ENDIF

MsiGetSummaryInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetSummaryInformation equ <MsiGetSummaryInformationW>
ENDIF

MsiGetTargetPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetTargetPath equ <MsiGetTargetPathA>
ENDIF

MsiGetTargetPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetTargetPath equ <MsiGetTargetPathW>
ENDIF

MsiGetUserInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiGetUserInfo equ <MsiGetUserInfoA>
ENDIF

MsiGetUserInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiGetUserInfo equ <MsiGetUserInfoW>
ENDIF

MsiInstallMissingComponentA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiInstallMissingComponent equ <MsiInstallMissingComponentA>
ENDIF

MsiInstallMissingComponentW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiInstallMissingComponent equ <MsiInstallMissingComponentW>
ENDIF

MsiInstallMissingFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiInstallMissingFile equ <MsiInstallMissingFileA>
ENDIF

MsiInstallMissingFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiInstallMissingFile equ <MsiInstallMissingFileW>
ENDIF

MsiInstallProductA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiInstallProduct equ <MsiInstallProductA>
ENDIF

MsiInstallProductW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiInstallProduct equ <MsiInstallProductW>
ENDIF

MsiInvalidateFeatureCache PROTO C :VARARG

MsiIsProductElevatedA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiIsProductElevated equ <MsiIsProductElevatedA>
ENDIF

MsiIsProductElevatedW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiIsProductElevated equ <MsiIsProductElevatedW>
ENDIF

MsiLoadStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiLoadString equ <MsiLoadStringA>
ENDIF

MsiLoadStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiLoadString equ <MsiLoadStringW>
ENDIF

MsiLocateComponentA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiLocateComponent equ <MsiLocateComponentA>
ENDIF

MsiLocateComponentW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiLocateComponent equ <MsiLocateComponentW>
ENDIF

MsiMessageBoxA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiMessageBox equ <MsiMessageBoxA>
ENDIF

MsiMessageBoxExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiMessageBoxEx equ <MsiMessageBoxExA>
ENDIF

MsiMessageBoxExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiMessageBoxEx equ <MsiMessageBoxExW>
ENDIF

MsiMessageBoxW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiMessageBox equ <MsiMessageBoxW>
ENDIF

MsiNotifySidChangeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiNotifySidChange equ <MsiNotifySidChangeA>
ENDIF

MsiNotifySidChangeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiNotifySidChange equ <MsiNotifySidChangeW>
ENDIF

MsiOpenDatabaseA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiOpenDatabase equ <MsiOpenDatabaseA>
ENDIF

MsiOpenDatabaseW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiOpenDatabase equ <MsiOpenDatabaseW>
ENDIF

MsiOpenPackageA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiOpenPackage equ <MsiOpenPackageA>
ENDIF

MsiOpenPackageExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiOpenPackageEx equ <MsiOpenPackageExA>
ENDIF

MsiOpenPackageExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiOpenPackageEx equ <MsiOpenPackageExW>
ENDIF

MsiOpenPackageW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiOpenPackage equ <MsiOpenPackageW>
ENDIF

MsiOpenProductA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiOpenProduct equ <MsiOpenProductA>
ENDIF

MsiOpenProductW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiOpenProduct equ <MsiOpenProductW>
ENDIF

MsiPreviewBillboardA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiPreviewBillboard equ <MsiPreviewBillboardA>
ENDIF

MsiPreviewBillboardW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiPreviewBillboard equ <MsiPreviewBillboardW>
ENDIF

MsiPreviewDialogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiPreviewDialog equ <MsiPreviewDialogA>
ENDIF

MsiPreviewDialogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiPreviewDialog equ <MsiPreviewDialogW>
ENDIF

MsiProcessAdvertiseScriptA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProcessAdvertiseScript equ <MsiProcessAdvertiseScriptA>
ENDIF

MsiProcessAdvertiseScriptW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProcessAdvertiseScript equ <MsiProcessAdvertiseScriptW>
ENDIF

MsiProcessMessage PROTO STDCALL :DWORD,:DWORD,:DWORD

MsiProvideAssemblyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProvideAssembly equ <MsiProvideAssemblyA>
ENDIF

MsiProvideAssemblyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProvideAssembly equ <MsiProvideAssemblyW>
ENDIF

MsiProvideComponentA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProvideComponent equ <MsiProvideComponentA>
ENDIF

MsiProvideComponentFromDescriptorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProvideComponentFromDescriptor equ <MsiProvideComponentFromDescriptorA>
ENDIF

MsiProvideComponentFromDescriptorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProvideComponentFromDescriptor equ <MsiProvideComponentFromDescriptorW>
ENDIF

MsiProvideComponentW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProvideComponent equ <MsiProvideComponentW>
ENDIF

MsiProvideQualifiedComponentA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProvideQualifiedComponent equ <MsiProvideQualifiedComponentA>
ENDIF

MsiProvideQualifiedComponentExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiProvideQualifiedComponentEx equ <MsiProvideQualifiedComponentExA>
ENDIF

MsiProvideQualifiedComponentExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProvideQualifiedComponentEx equ <MsiProvideQualifiedComponentExW>
ENDIF

MsiProvideQualifiedComponentW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiProvideQualifiedComponent equ <MsiProvideQualifiedComponentW>
ENDIF

MsiQueryComponentStateA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiQueryComponentState equ <MsiQueryComponentStateA>
ENDIF

MsiQueryComponentStateW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiQueryComponentState equ <MsiQueryComponentStateW>
ENDIF

MsiQueryFeatureStateA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiQueryFeatureState equ <MsiQueryFeatureStateA>
ENDIF

MsiQueryFeatureStateExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiQueryFeatureStateEx equ <MsiQueryFeatureStateExA>
ENDIF

MsiQueryFeatureStateExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiQueryFeatureStateEx equ <MsiQueryFeatureStateExW>
ENDIF

MsiQueryFeatureStateFromDescriptorA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  MsiQueryFeatureStateFromDescriptor equ <MsiQueryFeatureStateFromDescriptorA>
ENDIF

MsiQueryFeatureStateFromDescriptorW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  MsiQueryFeatureStateFromDescriptor equ <MsiQueryFeatureStateFromDescriptorW>
ENDIF

MsiQueryFeatureStateW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiQueryFeatureState equ <MsiQueryFeatureStateW>
ENDIF

MsiQueryProductStateA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  MsiQueryProductState equ <MsiQueryProductStateA>
ENDIF

MsiQueryProductStateW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  MsiQueryProductState equ <MsiQueryProductStateW>
ENDIF

MsiRecordClearData PROTO STDCALL :DWORD
MsiRecordDataSize PROTO STDCALL :DWORD,:DWORD
MsiRecordGetFieldCount PROTO STDCALL :DWORD
MsiRecordGetInteger PROTO STDCALL :DWORD,:DWORD

MsiRecordGetStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiRecordGetString equ <MsiRecordGetStringA>
ENDIF

MsiRecordGetStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiRecordGetString equ <MsiRecordGetStringW>
ENDIF

MsiRecordIsNull PROTO STDCALL :DWORD,:DWORD
MsiRecordReadStream PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MsiRecordSetInteger PROTO STDCALL :DWORD,:DWORD,:DWORD

MsiRecordSetStreamA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiRecordSetStream equ <MsiRecordSetStreamA>
ENDIF

MsiRecordSetStreamW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiRecordSetStream equ <MsiRecordSetStreamW>
ENDIF

MsiRecordSetStringA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiRecordSetString equ <MsiRecordSetStringA>
ENDIF

MsiRecordSetStringW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiRecordSetString equ <MsiRecordSetStringW>
ENDIF

MsiReinstallFeatureA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiReinstallFeature equ <MsiReinstallFeatureA>
ENDIF

MsiReinstallFeatureFromDescriptorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiReinstallFeatureFromDescriptor equ <MsiReinstallFeatureFromDescriptorA>
ENDIF

MsiReinstallFeatureFromDescriptorW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiReinstallFeatureFromDescriptor equ <MsiReinstallFeatureFromDescriptorW>
ENDIF

MsiReinstallFeatureW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiReinstallFeature equ <MsiReinstallFeatureW>
ENDIF

MsiReinstallProductA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiReinstallProduct equ <MsiReinstallProductA>
ENDIF

MsiReinstallProductW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiReinstallProduct equ <MsiReinstallProductW>
ENDIF

MsiRemovePatchesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiRemovePatches equ <MsiRemovePatchesA>
ENDIF

MsiRemovePatchesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiRemovePatches equ <MsiRemovePatchesW>
ENDIF

MsiSequenceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSequence equ <MsiSequenceA>
ENDIF

MsiSequenceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSequence equ <MsiSequenceW>
ENDIF

MsiSetComponentStateA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetComponentState equ <MsiSetComponentStateA>
ENDIF

MsiSetComponentStateW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetComponentState equ <MsiSetComponentStateW>
ENDIF

MsiSetExternalUIA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetExternalUI equ <MsiSetExternalUIA>
ENDIF

MsiSetExternalUIW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetExternalUI equ <MsiSetExternalUIW>
ENDIF

MsiSetFeatureAttributesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetFeatureAttributes equ <MsiSetFeatureAttributesA>
ENDIF

MsiSetFeatureAttributesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetFeatureAttributes equ <MsiSetFeatureAttributesW>
ENDIF

MsiSetFeatureStateA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetFeatureState equ <MsiSetFeatureStateA>
ENDIF

MsiSetFeatureStateW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetFeatureState equ <MsiSetFeatureStateW>
ENDIF

MsiSetInstallLevel PROTO STDCALL :DWORD,:DWORD
MsiSetInternalUI PROTO STDCALL :DWORD,:DWORD
MsiSetMode PROTO STDCALL :DWORD,:DWORD,:DWORD

MsiSetPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetProperty equ <MsiSetPropertyA>
ENDIF

MsiSetPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetProperty equ <MsiSetPropertyW>
ENDIF

MsiSetTargetPathA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSetTargetPath equ <MsiSetTargetPathA>
ENDIF

MsiSetTargetPathW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSetTargetPath equ <MsiSetTargetPathW>
ENDIF

MsiSourceListAddMediaDiskA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListAddMediaDisk equ <MsiSourceListAddMediaDiskA>
ENDIF

MsiSourceListAddMediaDiskW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListAddMediaDisk equ <MsiSourceListAddMediaDiskW>
ENDIF

MsiSourceListAddSourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListAddSource equ <MsiSourceListAddSourceA>
ENDIF

MsiSourceListAddSourceExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListAddSourceEx equ <MsiSourceListAddSourceExA>
ENDIF

MsiSourceListAddSourceExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListAddSourceEx equ <MsiSourceListAddSourceExW>
ENDIF

MsiSourceListAddSourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListAddSource equ <MsiSourceListAddSourceW>
ENDIF

MsiSourceListClearAllA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListClearAll equ <MsiSourceListClearAllA>
ENDIF

MsiSourceListClearAllExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListClearAllEx equ <MsiSourceListClearAllExA>
ENDIF

MsiSourceListClearAllExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListClearAllEx equ <MsiSourceListClearAllExW>
ENDIF

MsiSourceListClearAllW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListClearAll equ <MsiSourceListClearAllW>
ENDIF

MsiSourceListClearMediaDiskA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListClearMediaDisk equ <MsiSourceListClearMediaDiskA>
ENDIF

MsiSourceListClearMediaDiskW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListClearMediaDisk equ <MsiSourceListClearMediaDiskW>
ENDIF

MsiSourceListClearSourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListClearSource equ <MsiSourceListClearSourceA>
ENDIF

MsiSourceListClearSourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListClearSource equ <MsiSourceListClearSourceW>
ENDIF

MsiSourceListEnumMediaDisksA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListEnumMediaDisks equ <MsiSourceListEnumMediaDisksA>
ENDIF

MsiSourceListEnumMediaDisksW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListEnumMediaDisks equ <MsiSourceListEnumMediaDisksW>
ENDIF

MsiSourceListEnumSourcesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListEnumSources equ <MsiSourceListEnumSourcesA>
ENDIF

MsiSourceListEnumSourcesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListEnumSources equ <MsiSourceListEnumSourcesW>
ENDIF

MsiSourceListForceResolutionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListForceResolution equ <MsiSourceListForceResolutionA>
ENDIF

MsiSourceListForceResolutionExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListForceResolutionEx equ <MsiSourceListForceResolutionExA>
ENDIF

MsiSourceListForceResolutionExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListForceResolutionEx equ <MsiSourceListForceResolutionExW>
ENDIF

MsiSourceListForceResolutionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListForceResolution equ <MsiSourceListForceResolutionW>
ENDIF

MsiSourceListGetInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListGetInfo equ <MsiSourceListGetInfoA>
ENDIF

MsiSourceListGetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListGetInfo equ <MsiSourceListGetInfoW>
ENDIF

MsiSourceListSetInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSourceListSetInfo equ <MsiSourceListSetInfoA>
ENDIF

MsiSourceListSetInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSourceListSetInfo equ <MsiSourceListSetInfoW>
ENDIF

MsiSummaryInfoGetPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSummaryInfoGetProperty equ <MsiSummaryInfoGetPropertyA>
ENDIF

MsiSummaryInfoGetPropertyCount PROTO STDCALL :DWORD,:DWORD

MsiSummaryInfoGetPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSummaryInfoGetProperty equ <MsiSummaryInfoGetPropertyW>
ENDIF

MsiSummaryInfoPersist PROTO STDCALL :DWORD

MsiSummaryInfoSetPropertyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiSummaryInfoSetProperty equ <MsiSummaryInfoSetPropertyA>
ENDIF

MsiSummaryInfoSetPropertyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiSummaryInfoSetProperty equ <MsiSummaryInfoSetPropertyW>
ENDIF

MsiUseFeatureA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  MsiUseFeature equ <MsiUseFeatureA>
ENDIF

MsiUseFeatureExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiUseFeatureEx equ <MsiUseFeatureExA>
ENDIF

MsiUseFeatureExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiUseFeatureEx equ <MsiUseFeatureExW>
ENDIF

MsiUseFeatureW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MsiUseFeature equ <MsiUseFeatureW>
ENDIF

MsiVerifyDiskSpace PROTO STDCALL :DWORD

MsiVerifyPackageA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  MsiVerifyPackage equ <MsiVerifyPackageA>
ENDIF

MsiVerifyPackageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  MsiVerifyPackage equ <MsiVerifyPackageW>
ENDIF

MsiViewClose PROTO STDCALL :DWORD
MsiViewExecute PROTO STDCALL :DWORD,:DWORD
MsiViewFetch PROTO STDCALL :DWORD,:DWORD
MsiViewGetColumnInfo PROTO STDCALL :DWORD,:DWORD,:DWORD

MsiViewGetErrorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MsiViewGetError equ <MsiViewGetErrorA>
ENDIF

MsiViewGetErrorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MsiViewGetError equ <MsiViewGetErrorW>
ENDIF

MsiViewModify PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file msi.inc
  echo --------------------------------------
ENDIF
