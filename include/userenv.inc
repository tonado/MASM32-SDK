; --------------------------------------------------------------------------------------------------
;                           userenv.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF USERENV_INC
USERENV_INC equ <1>

AddDesktopItemA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddDesktopItem equ <AddDesktopItemA>
ENDIF

AddDesktopItemW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddDesktopItem equ <AddDesktopItemW>
ENDIF

AddItemA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddItem equ <AddItemA>
ENDIF

AddItemW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddItem equ <AddItemW>
ENDIF

ApplyGroupPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ApplySystemPolicyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ApplySystemPolicy equ <ApplySystemPolicyA>
ENDIF

ApplySystemPolicyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ApplySystemPolicy equ <ApplySystemPolicyW>
ENDIF

CheckAccessForPolicyGeneration PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CheckXForestLogon PROTO STDCALL :DWORD

CopyProfileDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CopyProfileDirectory equ <CopyProfileDirectoryA>
ENDIF

CopyProfileDirectoryExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CopyProfileDirectoryEx equ <CopyProfileDirectoryExA>
ENDIF

CopyProfileDirectoryExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CopyProfileDirectoryEx equ <CopyProfileDirectoryExW>
ENDIF

CopyProfileDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CopyProfileDirectory equ <CopyProfileDirectoryW>
ENDIF

CopySystemProfile PROTO STDCALL :DWORD
CreateEnvironmentBlock PROTO STDCALL :DWORD,:DWORD,:DWORD

CreateGroupA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  CreateGroup equ <CreateGroupA>
ENDIF

CreateGroupExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateGroupEx equ <CreateGroupExA>
ENDIF

CreateGroupExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateGroupEx equ <CreateGroupExW>
ENDIF

CreateGroupW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateGroup equ <CreateGroupW>
ENDIF

CreateLinkFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateLinkFile equ <CreateLinkFileA>
ENDIF

CreateLinkFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateLinkFileEx equ <CreateLinkFileExA>
ENDIF

CreateLinkFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateLinkFileEx equ <CreateLinkFileExW>
ENDIF

CreateLinkFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateLinkFile equ <CreateLinkFileW>
ENDIF

CreateURLFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

CreateUserProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateUserProfile equ <CreateUserProfileA>
ENDIF

CreateUserProfileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateUserProfileEx equ <CreateUserProfileExA>
ENDIF

CreateUserProfileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateUserProfileEx equ <CreateUserProfileExW>
ENDIF

CreateUserProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateUserProfile equ <CreateUserProfileW>
ENDIF

DeleteDesktopItemA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteDesktopItem equ <DeleteDesktopItemA>
ENDIF

DeleteDesktopItemW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeleteDesktopItem equ <DeleteDesktopItemW>
ENDIF

DeleteGroupA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteGroup equ <DeleteGroupA>
ENDIF

DeleteGroupW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeleteGroup equ <DeleteGroupW>
ENDIF

DeleteItemA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteItem equ <DeleteItemA>
ENDIF

DeleteItemW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeleteItem equ <DeleteItemW>
ENDIF

DeleteLinkFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteLinkFile equ <DeleteLinkFileA>
ENDIF

DeleteLinkFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeleteLinkFile equ <DeleteLinkFileW>
ENDIF

DeleteProfileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteProfile equ <DeleteProfileA>
ENDIF

DeleteProfileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeleteProfile equ <DeleteProfileW>
ENDIF

DeleteURLFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DestroyEnvironmentBlock PROTO STDCALL :DWORD
DetermineProfilesLocation PROTO STDCALL :DWORD
EnterCriticalPolicySection PROTO STDCALL :DWORD
EnterUserProfileLock PROTO STDCALL :DWORD

ExpandEnvironmentStringsForUserA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ExpandEnvironmentStringsForUser equ <ExpandEnvironmentStringsForUserA>
ENDIF

ExpandEnvironmentStringsForUserW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ExpandEnvironmentStringsForUser equ <ExpandEnvironmentStringsForUserW>
ENDIF

ForceSyncFgPolicy PROTO STDCALL :DWORD

FreeGPOListA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  FreeGPOList equ <FreeGPOListA>
ENDIF

FreeGPOListW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  FreeGPOList equ <FreeGPOListW>
ENDIF

GenerateRsopPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetAllUsersProfileDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetAllUsersProfileDirectory equ <GetAllUsersProfileDirectoryA>
ENDIF

GetAllUsersProfileDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetAllUsersProfileDirectory equ <GetAllUsersProfileDirectoryW>
ENDIF

GetAppliedGPOListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetAppliedGPOList equ <GetAppliedGPOListA>
ENDIF

GetAppliedGPOListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetAppliedGPOList equ <GetAppliedGPOListW>
ENDIF

GetDefaultUserProfileDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetDefaultUserProfileDirectory equ <GetDefaultUserProfileDirectoryA>
ENDIF

GetDefaultUserProfileDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetDefaultUserProfileDirectory equ <GetDefaultUserProfileDirectoryW>
ENDIF

GetGPOListA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetGPOList equ <GetGPOListA>
ENDIF

GetGPOListW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetGPOList equ <GetGPOListW>
ENDIF

GetGroupPolicyNetworkName PROTO STDCALL :DWORD,:DWORD
GetNextFgPolicyRefreshInfo PROTO STDCALL :DWORD,:DWORD
GetPreviousFgPolicyRefreshInfo PROTO STDCALL :DWORD,:DWORD
GetProfileType PROTO STDCALL :DWORD

GetProfilesDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfilesDirectory equ <GetProfilesDirectoryA>
ENDIF

GetProfilesDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetProfilesDirectory equ <GetProfilesDirectoryW>
ENDIF

GetSystemTempDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetSystemTempDirectory equ <GetSystemTempDirectoryA>
ENDIF

GetSystemTempDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetSystemTempDirectory equ <GetSystemTempDirectoryW>
ENDIF

GetUserAppDataPathA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserAppDataPath equ <GetUserAppDataPathA>
ENDIF

GetUserAppDataPathW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetUserAppDataPath equ <GetUserAppDataPathW>
ENDIF

GetUserProfileDirFromSidA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserProfileDirFromSid equ <GetUserProfileDirFromSidA>
ENDIF

GetUserProfileDirFromSidW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUserProfileDirFromSid equ <GetUserProfileDirFromSidW>
ENDIF

GetUserProfileDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUserProfileDirectory equ <GetUserProfileDirectoryA>
ENDIF

GetUserProfileDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUserProfileDirectory equ <GetUserProfileDirectoryW>
ENDIF

GetUserSid PROTO STDCALL :DWORD
InitializeProfiles PROTO STDCALL :DWORD
InitializeUserProfile PROTO STDCALL
IsSyncForegroundPolicyRefresh PROTO STDCALL :DWORD,:DWORD
LeaveCriticalPolicySection PROTO STDCALL :DWORD
LeaveUserProfileLock PROTO STDCALL :DWORD

LoadUserProfileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadUserProfile equ <LoadUserProfileA>
ENDIF

LoadUserProfileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LoadUserProfile equ <LoadUserProfileW>
ENDIF

MigrateNT4ToNT5 PROTO STDCALL
PingComputer PROTO STDCALL :DWORD,:DWORD
ProcessGroupPolicyCompleted PROTO STDCALL :DWORD,:DWORD,:DWORD
ProcessGroupPolicyCompletedEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RefreshPolicy PROTO STDCALL :DWORD
RefreshPolicyEx PROTO STDCALL :DWORD,:DWORD
RegisterGPNotification PROTO STDCALL :DWORD,:DWORD
ResetUserSpecialFolderPaths PROTO STDCALL
RsopAccessCheckByType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RsopFileAccessCheck PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RsopLoggingEnabled PROTO STDCALL
RsopResetPolicySettingStatus PROTO STDCALL :DWORD,:DWORD,:DWORD
RsopSetPolicySettingStatus PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SecureUserProfiles PROTO STDCALL
SetNextFgPolicyRefreshInfo PROTO STDCALL :DWORD,:DWORD,:DWORD
ShutdownGPOProcessing PROTO STDCALL :DWORD
SignalMachinePolicyForegroundProcessingDone PROTO STDCALL
SignalUserPolicyForegroundProcessingDone PROTO STDCALL
UnloadUserProfile PROTO STDCALL :DWORD,:DWORD
UnregisterGPNotification PROTO STDCALL :DWORD
WaitForMachinePolicyForegroundProcessing PROTO STDCALL
WaitForUserPolicyForegroundProcessing PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file userenv.inc
  echo ------------------------------------------
ENDIF
