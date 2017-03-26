; --------------------------------------------------------------------------------------------------
;                           netlib.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NETLIB_INC
NETLIB_INC equ <1>

AccessCheck PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ChangeServiceConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ChangeServiceConfig equ <ChangeServiceConfigW>
ENDIF

CloseHandle PROTO STDCALL :DWORD
CloseServiceHandle PROTO STDCALL :DWORD
ControlService PROTO STDCALL :DWORD,:DWORD,:DWORD

CreateDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  CreateDirectory equ <CreateDirectoryW>
ENDIF

CreateFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateFile equ <CreateFileW>
ENDIF

CreateMailslotA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateMailslot equ <CreateMailslotA>
ENDIF

CryptAcquireContextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CryptAcquireContext equ <CryptAcquireContextW>
ENDIF

CryptGenRandom PROTO STDCALL :DWORD,:DWORD,:DWORD
CryptReleaseContext PROTO STDCALL :DWORD,:DWORD
DeleteCriticalSection PROTO STDCALL :DWORD

DeleteFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteFile equ <DeleteFileW>
ENDIF

DeregisterEventSource PROTO STDCALL :DWORD
DeviceIoControl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DnsHostnameToComputerNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DnsHostnameToComputerName equ <DnsHostnameToComputerNameW>
ENDIF

DsBindWithCredW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsBindWithCred equ <DsBindWithCredW>
ENDIF

DsCrackNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsCrackNames equ <DsCrackNamesW>
ENDIF

DsFreeNameResultW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsFreeNameResult equ <DsFreeNameResultW>
ENDIF

DsFreePasswordCredentials PROTO STDCALL :DWORD

DsMakePasswordCredentialsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsMakePasswordCredentials equ <DsMakePasswordCredentialsW>
ENDIF

DsUnBindW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DsUnBind equ <DsUnBindW>
ENDIF

DsWriteAccountSpnW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DsWriteAccountSpn equ <DsWriteAccountSpnW>
ENDIF

EnterCriticalSection PROTO STDCALL :DWORD

EnumDependentServicesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumDependentServices equ <EnumDependentServicesW>
ENDIF

ExpandEnvironmentStringsW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ExpandEnvironmentStrings equ <ExpandEnvironmentStringsW>
ENDIF

FlushFileBuffers PROTO STDCALL :DWORD

FormatMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FormatMessage equ <FormatMessageW>
ENDIF

FreeLibrary PROTO STDCALL :DWORD

GetComputerNameExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerNameEx equ <GetComputerNameExW>
ENDIF

GetComputerNameW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetComputerName equ <GetComputerNameW>
ENDIF

GetCurrentThread PROTO STDCALL
GetCurrentThreadId PROTO STDCALL

GetFileAttributesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetFileAttributes equ <GetFileAttributesW>
ENDIF

GetLastError PROTO STDCALL
GetLocalTime PROTO STDCALL :DWORD
GetProcAddress PROTO STDCALL :DWORD,:DWORD

GetProfileIntA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfileInt equ <GetProfileIntA>
ENDIF

GetProfileStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetProfileString equ <GetProfileStringA>
ENDIF

GetSidSubAuthority PROTO STDCALL :DWORD,:DWORD
GetSidSubAuthorityCount PROTO STDCALL :DWORD
GetSystemMetrics PROTO STDCALL :DWORD
GetSystemTimeAsFileTime PROTO STDCALL :DWORD

GetSystemWindowsDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetSystemWindowsDirectory equ <GetSystemWindowsDirectoryW>
ENDIF

GetThreadLocale PROTO STDCALL
GetTimeZoneInformation PROTO STDCALL :DWORD

GetVersionExW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetVersionEx equ <GetVersionExW>
ENDIF

GetWindowsDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetWindowsDirectory equ <GetWindowsDirectoryW>
ENDIF

InitializeCriticalSection PROTO STDCALL :DWORD
LdapGetLastError PROTO C :VARARG
LdapMapErrorToWin32 PROTO C :VARARG
LeaveCriticalSection PROTO STDCALL :DWORD

LoadLibraryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadLibrary equ <LoadLibraryA>
ENDIF

LoadLibraryExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LoadLibraryEx equ <LoadLibraryExW>
ENDIF

LoadLibraryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LoadLibrary equ <LoadLibraryW>
ENDIF

LocalAlloc PROTO STDCALL :DWORD,:DWORD
LocalFree PROTO STDCALL :DWORD
LocalHandle PROTO STDCALL :DWORD
LocalReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
LocalSize PROTO STDCALL :DWORD

LookupAccountSidW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  LookupAccountSid equ <LookupAccountSidW>
ENDIF

MoveFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  MoveFile equ <MoveFileW>
ENDIF

MultiByteToWideChar PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtAccessCheckAndAuditAlarm PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtAdjustPrivilegesToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtClose PROTO STDCALL :DWORD
NtCreateFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtDuplicateToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtFsControlFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtImpersonateAnonymousToken PROTO STDCALL :DWORD
NtOpenFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NtOpenProcessToken PROTO STDCALL :DWORD,:DWORD,:DWORD
NtOpenThreadToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
NtQuerySystemTime PROTO STDCALL :DWORD
NtSetInformationThread PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

OpenSCManagerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenSCManager equ <OpenSCManagerW>
ENDIF

OpenServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenService equ <OpenServiceW>
ENDIF

OpenThreadToken PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

QueryServiceConfigW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  QueryServiceConfig equ <QueryServiceConfigW>
ENDIF

QueryServiceStatus PROTO STDCALL :DWORD,:DWORD
RegCloseKey PROTO STDCALL :DWORD

RegConnectRegistryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegConnectRegistry equ <RegConnectRegistryW>
ENDIF

RegCreateKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegCreateKeyEx equ <RegCreateKeyExW>
ENDIF

RegDeleteKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteKey equ <RegDeleteKeyW>
ENDIF

RegDeleteValueW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegDeleteValue equ <RegDeleteValueW>
ENDIF

RegEnumValueW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegEnumValue equ <RegEnumValueW>
ENDIF

RegFlushKey PROTO STDCALL :DWORD

RegOpenKeyExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKeyEx equ <RegOpenKeyExW>
ENDIF

RegOpenKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegOpenKey equ <RegOpenKeyW>
ENDIF

RegQueryInfoKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryInfoKey equ <RegQueryInfoKeyW>
ENDIF

RegQueryValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegQueryValueEx equ <RegQueryValueExW>
ENDIF

RegSetValueExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RegSetValueEx equ <RegSetValueExW>
ENDIF

RegisterEventSourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  RegisterEventSource equ <RegisterEventSourceW>
ENDIF

ReportEventW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ReportEvent equ <ReportEventW>
ENDIF

RevertToSelf PROTO STDCALL
RpcImpersonateClient PROTO STDCALL :DWORD
RpcRevertToSelf PROTO STDCALL
RtlAddAce PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlAdjustPrivilege PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlAllocateHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAnsiStringToUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAssert PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlCompareMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCompareMemoryUlong PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCompareUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlConvertSidToUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCopySid PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCreateAcl PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlCreateEnvironment PROTO STDCALL :DWORD,:DWORD
RtlCreateSecurityDescriptor PROTO STDCALL :DWORD,:DWORD
RtlDeleteSecurityObject PROTO STDCALL :DWORD
RtlDestroyEnvironment PROTO STDCALL :DWORD
RtlDetermineDosPathNameType_U PROTO STDCALL :DWORD
RtlEqualSid PROTO STDCALL :DWORD,:DWORD
RtlEqualUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlExpandEnvironmentStrings_U PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlExtendedIntegerMultiply PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlExtendedMagicDivide PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlFreeHeap PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlFreeOemString PROTO STDCALL :DWORD
RtlFreeUnicodeString PROTO STDCALL :DWORD
RtlGetAce PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlGetNtProductType PROTO STDCALL :DWORD
RtlInitAnsiString PROTO STDCALL :DWORD,:DWORD
RtlInitString PROTO STDCALL :DWORD,:DWORD
RtlInitUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlInitializeSid PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlIsDosDeviceName_U PROTO STDCALL :DWORD
RtlLengthRequiredSid PROTO STDCALL :DWORD
RtlLengthSid PROTO STDCALL :DWORD
RtlNewSecurityObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlNtStatusToDosError PROTO STDCALL :DWORD
RtlOemStringToUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlQueryInformationAcl PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlQueryTimeZoneInformation PROTO STDCALL :DWORD
RtlRunDecodeUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlRunEncodeUnicodeString PROTO STDCALL :DWORD,:DWORD
RtlSetDaclSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlSetEnvironmentVariable PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlSetGroupSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlSetOwnerSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlSetSaclSecurityDescriptor PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlSubAuthorityCountSid PROTO STDCALL :DWORD
RtlSubAuthoritySid PROTO STDCALL :DWORD,:DWORD
RtlTimeFieldsToTime PROTO STDCALL :DWORD,:DWORD
RtlTimeToSecondsSince1970 PROTO STDCALL :DWORD,:DWORD
RtlTimeToSecondsSince1980 PROTO STDCALL :DWORD,:DWORD
RtlUnicodeStringToAnsiString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUnicodeStringToOemString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUnicodeToOemN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUniform PROTO STDCALL :DWORD
RtlUpcaseUnicodeString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUpcaseUnicodeStringToOemString PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUpcaseUnicodeToOemN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlValidSid PROTO STDCALL :DWORD
RtlxAnsiStringToUnicodeSize PROTO STDCALL :DWORD
RtlxOemStringToUnicodeSize PROTO STDCALL :DWORD
RtlxUnicodeStringToAnsiSize PROTO STDCALL :DWORD
RtlxUnicodeStringToOemSize PROTO STDCALL :DWORD

SetComputerNameExW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetComputerNameEx equ <SetComputerNameExW>
ENDIF

SetFilePointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetThreadLocale PROTO STDCALL :DWORD
SetThreadToken PROTO STDCALL :DWORD,:DWORD
Sleep PROTO STDCALL :DWORD

StartServiceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartService equ <StartServiceW>
ENDIF

VerifyVersionInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  VerifyVersionInfo equ <VerifyVersionInfoW>
ENDIF

WideCharToMultiByte PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_itoa PROTO C :VARARG
_stricmp PROTO C :VARARG
_ultoa PROTO C :VARARG
_vsnprintf PROTO C :VARARG
_wcsicmp PROTO C :VARARG
_wcslwr PROTO C :VARARG
_wcsnicmp PROTO C :VARARG
_wcsupr PROTO C :VARARG
ctime PROTO C :VARARG
free PROTO C :VARARG
htons PROTO STDCALL :DWORD
isprint PROTO C :VARARG
iswctype PROTO C :VARARG

ldap_add_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_add_s equ <ldap_add_sW>
ENDIF

ldap_bind_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_bind_s equ <ldap_bind_sW>
ENDIF

ldap_compare_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_compare_s equ <ldap_compare_sW>
ENDIF

ldap_count_entries PROTO C :VARARG

ldap_count_valuesW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_count_values equ <ldap_count_valuesW>
ENDIF

ldap_delete_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_delete_s equ <ldap_delete_sW>
ENDIF

ldap_err2stringA PROTO C :VARARG
IFNDEF __UNICODE__
  ldap_err2string equ <ldap_err2stringA>
ENDIF

ldap_first_entry PROTO C :VARARG

ldap_get_dnW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_dn equ <ldap_get_dnW>
ENDIF

ldap_get_next_page_s PROTO C :VARARG

ldap_get_valuesW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_get_values equ <ldap_get_valuesW>
ENDIF

ldap_initW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_init equ <ldap_initW>
ENDIF

ldap_memfreeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_memfree equ <ldap_memfreeW>
ENDIF

ldap_modify_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_modify_s equ <ldap_modify_sW>
ENDIF

ldap_msgfree PROTO C :VARARG
ldap_next_entry PROTO C :VARARG
ldap_search_abandon_page PROTO C :VARARG

ldap_search_init_pageW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_init_page equ <ldap_search_init_pageW>
ENDIF

ldap_search_sW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_search_s equ <ldap_search_sW>
ENDIF

ldap_set_optionW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_set_option equ <ldap_set_optionW>
ENDIF

ldap_unbind PROTO C :VARARG
ldap_unbind_s PROTO C :VARARG

ldap_value_freeW PROTO C :VARARG
IFDEF __UNICODE__
  ldap_value_free equ <ldap_value_freeW>
ENDIF

lstrcatA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcat equ <lstrcatA>
ENDIF

lstrcpyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  lstrcpy equ <lstrcpyA>
ENDIF

lstrlenA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  lstrlen equ <lstrlenA>
ENDIF

lstrlenW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  lstrlen equ <lstrlenW>
ENDIF

malloc PROTO C :VARARG
memmove PROTO C :VARARG
qsort PROTO C :VARARG
rand PROTO C :VARARG
sprintf PROTO C :VARARG
srand PROTO C :VARARG
sscanf PROTO C :VARARG
strchr PROTO C :VARARG
strcspn PROTO C :VARARG
strncpy PROTO C :VARARG
strpbrk PROTO C :VARARG
strspn PROTO C :VARARG
swprintf PROTO C :VARARG
swscanf PROTO C :VARARG
time PROTO C :VARARG
toupper PROTO C :VARARG
towupper PROTO C :VARARG
wcscat PROTO C :VARARG
wcschr PROTO C :VARARG
wcscmp PROTO C :VARARG
wcscpy PROTO C :VARARG
wcscspn PROTO C :VARARG
wcslen PROTO C :VARARG
wcsncmp PROTO C :VARARG
wcsncpy PROTO C :VARARG
wcsspn PROTO C :VARARG
  ; wcstoul arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file netlib.inc
  echo -----------------------------------------
ENDIF
