; --------------------------------------------------------------------------------------------------
;                           wininet.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WININET_INC
WININET_INC equ <1>

CommitUrlCacheEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CommitUrlCacheEntry equ <CommitUrlCacheEntryA>
ENDIF

CommitUrlCacheEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CommitUrlCacheEntry equ <CommitUrlCacheEntryW>
ENDIF

CreateMD5SSOHash PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

CreateUrlCacheContainerA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateUrlCacheContainer equ <CreateUrlCacheContainerA>
ENDIF

CreateUrlCacheContainerW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateUrlCacheContainer equ <CreateUrlCacheContainerW>
ENDIF

CreateUrlCacheEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateUrlCacheEntry equ <CreateUrlCacheEntryA>
ENDIF

CreateUrlCacheEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateUrlCacheEntry equ <CreateUrlCacheEntryW>
ENDIF

CreateUrlCacheGroup PROTO STDCALL :DWORD,:DWORD
DeleteIE3Cache PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

DeleteUrlCacheContainerA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteUrlCacheContainer equ <DeleteUrlCacheContainerA>
ENDIF

DeleteUrlCacheContainerW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeleteUrlCacheContainer equ <DeleteUrlCacheContainerW>
ENDIF


DeleteUrlCacheEntryA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeleteUrlCacheEntry equ <DeleteUrlCacheEntryA>
ENDIF

DeleteUrlCacheEntryW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeleteUrlCacheEntry equ <DeleteUrlCacheEntryW>
ENDIF

DeleteUrlCacheGroup PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DetectAutoProxyUrl PROTO STDCALL :DWORD,:DWORD,:DWORD
DoConnectoidsExist PROTO STDCALL

ExportCookieFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ExportCookieFile equ <ExportCookieFileA>
ENDIF

ExportCookieFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ExportCookieFile equ <ExportCookieFileW>
ENDIF

FindCloseUrlCache PROTO STDCALL :DWORD

FindFirstUrlCacheContainerA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstUrlCacheContainer equ <FindFirstUrlCacheContainerA>
ENDIF

FindFirstUrlCacheContainerW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstUrlCacheContainer equ <FindFirstUrlCacheContainerW>
ENDIF

FindFirstUrlCacheEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstUrlCacheEntry equ <FindFirstUrlCacheEntryA>
ENDIF

FindFirstUrlCacheEntryExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindFirstUrlCacheEntryEx equ <FindFirstUrlCacheEntryExA>
ENDIF

FindFirstUrlCacheEntryExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstUrlCacheEntryEx equ <FindFirstUrlCacheEntryExW>
ENDIF

FindFirstUrlCacheEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindFirstUrlCacheEntry equ <FindFirstUrlCacheEntryW>
ENDIF

FindFirstUrlCacheGroup PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

FindNextUrlCacheContainerA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextUrlCacheContainer equ <FindNextUrlCacheContainerA>
ENDIF

FindNextUrlCacheContainerW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindNextUrlCacheContainer equ <FindNextUrlCacheContainerW>
ENDIF

FindNextUrlCacheEntryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextUrlCacheEntry equ <FindNextUrlCacheEntryA>
ENDIF

FindNextUrlCacheEntryExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FindNextUrlCacheEntryEx equ <FindNextUrlCacheEntryExA>
ENDIF

FindNextUrlCacheEntryExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindNextUrlCacheEntryEx equ <FindNextUrlCacheEntryExW>
ENDIF

FindNextUrlCacheEntryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FindNextUrlCacheEntry equ <FindNextUrlCacheEntryW>
ENDIF

FindNextUrlCacheGroup PROTO STDCALL :DWORD,:DWORD,:DWORD
FindP3PPolicySymbol PROTO STDCALL :DWORD
ForceNexusLookup PROTO STDCALL

ForceNexusLookupExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ForceNexusLookupEx equ <ForceNexusLookupExW>
ENDIF

FreeP3PObject PROTO STDCALL :DWORD

FreeUrlCacheSpaceA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FreeUrlCacheSpace equ <FreeUrlCacheSpaceA>
ENDIF

FreeUrlCacheSpaceW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FreeUrlCacheSpace equ <FreeUrlCacheSpaceW>
ENDIF

FtpCommandA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpCommand equ <FtpCommandA>
ENDIF

FtpCommandW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpCommand equ <FtpCommandW>
ENDIF

FtpCreateDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FtpCreateDirectory equ <FtpCreateDirectoryA>
ENDIF

FtpCreateDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FtpCreateDirectory equ <FtpCreateDirectoryW>
ENDIF

FtpDeleteFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FtpDeleteFile equ <FtpDeleteFileA>
ENDIF

FtpDeleteFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FtpDeleteFile equ <FtpDeleteFileW>
ENDIF

FtpFindFirstFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpFindFirstFile equ <FtpFindFirstFileA>
ENDIF

FtpFindFirstFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpFindFirstFile equ <FtpFindFirstFileW>
ENDIF

FtpGetCurrentDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpGetCurrentDirectory equ <FtpGetCurrentDirectoryA>
ENDIF

FtpGetCurrentDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpGetCurrentDirectory equ <FtpGetCurrentDirectoryW>
ENDIF

FtpGetFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpGetFile equ <FtpGetFileA>
ENDIF

FtpGetFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FtpGetFileSize PROTO STDCALL :DWORD,:DWORD

FtpGetFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpGetFile equ <FtpGetFileW>
ENDIF

FtpOpenFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpOpenFile equ <FtpOpenFileA>
ENDIF

FtpOpenFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpOpenFile equ <FtpOpenFileW>
ENDIF

FtpPutFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpPutFile equ <FtpPutFileA>
ENDIF

FtpPutFileEx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

FtpPutFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpPutFile equ <FtpPutFileW>
ENDIF

FtpRemoveDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FtpRemoveDirectory equ <FtpRemoveDirectoryA>
ENDIF

FtpRemoveDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FtpRemoveDirectory equ <FtpRemoveDirectoryW>
ENDIF

FtpRenameFileA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  FtpRenameFile equ <FtpRenameFileA>
ENDIF

FtpRenameFileW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  FtpRenameFile equ <FtpRenameFileW>
ENDIF

FtpSetCurrentDirectoryA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  FtpSetCurrentDirectory equ <FtpSetCurrentDirectoryA>
ENDIF

FtpSetCurrentDirectoryW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  FtpSetCurrentDirectory equ <FtpSetCurrentDirectoryW>
ENDIF

GetDiskInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDiskInfo equ <GetDiskInfoA>
ENDIF

GetP3PPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
GetP3PRequestStatus PROTO STDCALL :DWORD

GetUrlCacheConfigInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUrlCacheConfigInfo equ <GetUrlCacheConfigInfoA>
ENDIF

GetUrlCacheConfigInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUrlCacheConfigInfo equ <GetUrlCacheConfigInfoW>
ENDIF

GetUrlCacheEntryInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUrlCacheEntryInfo equ <GetUrlCacheEntryInfoA>
ENDIF

GetUrlCacheEntryInfoExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUrlCacheEntryInfoEx equ <GetUrlCacheEntryInfoExA>
ENDIF

GetUrlCacheEntryInfoExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUrlCacheEntryInfoEx equ <GetUrlCacheEntryInfoExW>
ENDIF

GetUrlCacheEntryInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUrlCacheEntryInfo equ <GetUrlCacheEntryInfoW>
ENDIF

GetUrlCacheGroupAttributeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetUrlCacheGroupAttribute equ <GetUrlCacheGroupAttributeA>
ENDIF

GetUrlCacheGroupAttributeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetUrlCacheGroupAttribute equ <GetUrlCacheGroupAttributeW>
ENDIF

GetUrlCacheHeaderData PROTO STDCALL :DWORD,:DWORD

GopherCreateLocatorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GopherCreateLocator equ <GopherCreateLocatorA>
ENDIF

GopherCreateLocatorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GopherCreateLocator equ <GopherCreateLocatorW>
ENDIF

GopherFindFirstFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GopherFindFirstFile equ <GopherFindFirstFileA>
ENDIF

GopherFindFirstFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GopherFindFirstFile equ <GopherFindFirstFileW>
ENDIF

GopherGetAttributeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GopherGetAttribute equ <GopherGetAttributeA>
ENDIF

GopherGetAttributeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GopherGetAttribute equ <GopherGetAttributeW>
ENDIF

GopherGetLocatorTypeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GopherGetLocatorType equ <GopherGetLocatorTypeA>
ENDIF

GopherGetLocatorTypeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GopherGetLocatorType equ <GopherGetLocatorTypeW>
ENDIF

GopherOpenFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GopherOpenFile equ <GopherOpenFileA>
ENDIF

GopherOpenFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GopherOpenFile equ <GopherOpenFileW>
ENDIF

HttpAddRequestHeadersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpAddRequestHeaders equ <HttpAddRequestHeadersA>
ENDIF

HttpAddRequestHeadersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpAddRequestHeaders equ <HttpAddRequestHeadersW>
ENDIF


HttpCheckDavComplianceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpCheckDavCompliance equ <HttpCheckDavComplianceA>
ENDIF

HttpCheckDavComplianceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpCheckDavCompliance equ <HttpCheckDavComplianceW>
ENDIF

HttpEndRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpEndRequest equ <HttpEndRequestA>
ENDIF

HttpEndRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpEndRequest equ <HttpEndRequestW>
ENDIF

HttpOpenRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpOpenRequest equ <HttpOpenRequestA>
ENDIF

HttpOpenRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpOpenRequest equ <HttpOpenRequestW>
ENDIF

HttpQueryInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpQueryInfo equ <HttpQueryInfoA>
ENDIF

HttpQueryInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpQueryInfo equ <HttpQueryInfoW>
ENDIF

HttpSendRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpSendRequest equ <HttpSendRequestA>
ENDIF

HttpSendRequestExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  HttpSendRequestEx equ <HttpSendRequestExA>
ENDIF

HttpSendRequestExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpSendRequestEx equ <HttpSendRequestExW>
ENDIF

HttpSendRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  HttpSendRequest equ <HttpSendRequestW>
ENDIF

ImportCookieFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  ImportCookieFile equ <ImportCookieFileA>
ENDIF

ImportCookieFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  ImportCookieFile equ <ImportCookieFileW>
ENDIF

IncrementUrlCacheHeaderData PROTO STDCALL :DWORD,:DWORD

InternetAlgIdToStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetAlgIdToString equ <InternetAlgIdToStringA>
ENDIF

InternetAlgIdToStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetAlgIdToString equ <InternetAlgIdToStringW>
ENDIF

InternetAttemptConnect PROTO STDCALL :DWORD
InternetAutodial PROTO STDCALL :DWORD,:DWORD
InternetAutodialCallback PROTO STDCALL :DWORD,:DWORD
InternetAutodialHangup PROTO STDCALL :DWORD

InternetCanonicalizeUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetCanonicalizeUrl equ <InternetCanonicalizeUrlA>
ENDIF

InternetCanonicalizeUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetCanonicalizeUrl equ <InternetCanonicalizeUrlW>
ENDIF

InternetCheckConnectionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetCheckConnection equ <InternetCheckConnectionA>
ENDIF

InternetCheckConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetCheckConnection equ <InternetCheckConnectionW>
ENDIF

InternetClearAllPerSiteCookieDecisions PROTO STDCALL
InternetCloseHandle PROTO STDCALL :DWORD

InternetCombineUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetCombineUrl equ <InternetCombineUrlA>
ENDIF

InternetCombineUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetCombineUrl equ <InternetCombineUrlW>
ENDIF


InternetConfirmZoneCrossingA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetConfirmZoneCrossing equ <InternetConfirmZoneCrossingA>
ENDIF

InternetConfirmZoneCrossingW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetConfirmZoneCrossing equ <InternetConfirmZoneCrossingW>
ENDIF

InternetConnectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetConnect equ <InternetConnectA>
ENDIF

InternetConnectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetConnect equ <InternetConnectW>
ENDIF

InternetCrackUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetCrackUrl equ <InternetCrackUrlA>
ENDIF

InternetCrackUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetCrackUrl equ <InternetCrackUrlW>
ENDIF

InternetCreateUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetCreateUrl equ <InternetCreateUrlA>
ENDIF

InternetCreateUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetCreateUrl equ <InternetCreateUrlW>
ENDIF


InternetDialA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetDial equ <InternetDialA>
ENDIF

InternetDialW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetDial equ <InternetDialW>
ENDIF

InternetEnumPerSiteCookieDecisionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetEnumPerSiteCookieDecision equ <InternetEnumPerSiteCookieDecisionA>
ENDIF

InternetEnumPerSiteCookieDecisionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetEnumPerSiteCookieDecision equ <InternetEnumPerSiteCookieDecisionW>
ENDIF

InternetErrorDlg PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

InternetFindNextFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InternetFindNextFile equ <InternetFindNextFileA>
ENDIF

InternetFindNextFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InternetFindNextFile equ <InternetFindNextFileW>
ENDIF

InternetFortezzaCommand PROTO STDCALL :DWORD,:DWORD,:DWORD

InternetGetCertByURLA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetCertByURL equ <InternetGetCertByURLA>
ENDIF

InternetGetConnectedState PROTO STDCALL :DWORD,:DWORD

InternetGetConnectedStateExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetConnectedStateEx equ <InternetGetConnectedStateExA>
ENDIF

InternetGetConnectedStateExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetGetConnectedStateEx equ <InternetGetConnectedStateExW>
ENDIF

InternetGetCookieA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetCookie equ <InternetGetCookieA>
ENDIF

InternetGetCookieExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetCookieEx equ <InternetGetCookieExA>
ENDIF

InternetGetCookieExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetGetCookieEx equ <InternetGetCookieExW>
ENDIF

InternetGetCookieW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetGetCookie equ <InternetGetCookieW>
ENDIF

InternetGetLastResponseInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetLastResponseInfo equ <InternetGetLastResponseInfoA>
ENDIF

InternetGetLastResponseInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetGetLastResponseInfo equ <InternetGetLastResponseInfoW>
ENDIF

InternetGetPerSiteCookieDecisionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGetPerSiteCookieDecision equ <InternetGetPerSiteCookieDecisionA>
ENDIF

InternetGetPerSiteCookieDecisionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InternetGetPerSiteCookieDecision equ <InternetGetPerSiteCookieDecisionW>
ENDIF


InternetGoOnlineA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetGoOnline equ <InternetGoOnlineA>
ENDIF

InternetGoOnlineW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetGoOnline equ <InternetGoOnlineW>
ENDIF

InternetHangUp PROTO STDCALL :DWORD,:DWORD
InternetInitializeAutoProxyDll PROTO STDCALL :DWORD
InternetLockRequestFile PROTO STDCALL :DWORD,:DWORD

InternetOpenA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetOpen equ <InternetOpenA>
ENDIF

InternetOpenUrlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetOpenUrl equ <InternetOpenUrlA>
ENDIF

InternetOpenUrlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetOpenUrl equ <InternetOpenUrlW>
ENDIF

InternetOpenW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetOpen equ <InternetOpenW>
ENDIF

InternetQueryDataAvailable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
InternetQueryFortezzaStatus PROTO STDCALL :DWORD,:DWORD

InternetQueryOptionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetQueryOption equ <InternetQueryOptionA>
ENDIF

InternetQueryOptionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetQueryOption equ <InternetQueryOptionW>
ENDIF

InternetReadFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

InternetReadFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetReadFileEx equ <InternetReadFileExA>
ENDIF

InternetReadFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetReadFileEx equ <InternetReadFileExW>
ENDIF

InternetSecurityProtocolToStringA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSecurityProtocolToString equ <InternetSecurityProtocolToStringA>
ENDIF

InternetSecurityProtocolToStringW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSecurityProtocolToString equ <InternetSecurityProtocolToStringW>
ENDIF

InternetSetCookieA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetCookie equ <InternetSetCookieA>
ENDIF

InternetSetCookieExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetCookieEx equ <InternetSetCookieExA>
ENDIF

InternetSetCookieExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetCookieEx equ <InternetSetCookieExW>
ENDIF

InternetSetCookieW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetCookie equ <InternetSetCookieW>
ENDIF


InternetSetDialStateA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetDialState equ <InternetSetDialStateA>
ENDIF

InternetSetDialStateW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetDialState equ <InternetSetDialStateW>
ENDIF

InternetSetFilePointer PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

InternetSetOptionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetOption equ <InternetSetOptionA>
ENDIF

InternetSetOptionExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetOptionEx equ <InternetSetOptionExA>
ENDIF

InternetSetOptionExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetOptionEx equ <InternetSetOptionExW>
ENDIF

InternetSetOptionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetOption equ <InternetSetOptionW>
ENDIF

InternetSetPerSiteCookieDecisionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetPerSiteCookieDecision equ <InternetSetPerSiteCookieDecisionA>
ENDIF

InternetSetPerSiteCookieDecisionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetPerSiteCookieDecision equ <InternetSetPerSiteCookieDecisionW>
ENDIF


InternetSetStatusCallbackA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InternetSetStatusCallback equ <InternetSetStatusCallbackA>
ENDIF

InternetSetStatusCallbackW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InternetSetStatusCallback equ <InternetSetStatusCallbackW>
ENDIF


InternetShowSecurityInfoByURLA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  InternetShowSecurityInfoByURL equ <InternetShowSecurityInfoByURLA>
ENDIF

InternetShowSecurityInfoByURLW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  InternetShowSecurityInfoByURL equ <InternetShowSecurityInfoByURLW>
ENDIF


InternetTimeFromSystemTimeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetTimeFromSystemTime equ <InternetTimeFromSystemTimeA>
ENDIF

InternetTimeFromSystemTimeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetTimeFromSystemTime equ <InternetTimeFromSystemTimeW>
ENDIF


InternetTimeToSystemTimeA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetTimeToSystemTime equ <InternetTimeToSystemTimeA>
ENDIF

InternetTimeToSystemTimeW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetTimeToSystemTime equ <InternetTimeToSystemTimeW>
ENDIF

InternetUnlockRequestFile PROTO STDCALL :DWORD
InternetWriteFile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

InternetWriteFileExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  InternetWriteFileEx equ <InternetWriteFileExA>
ENDIF

InternetWriteFileExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  InternetWriteFileEx equ <InternetWriteFileExW>
ENDIF

IsDomainLegalCookieDomainA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  IsDomainLegalCookieDomain equ <IsDomainLegalCookieDomainA>
ENDIF

IsDomainLegalCookieDomainW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  IsDomainLegalCookieDomain equ <IsDomainLegalCookieDomainW>
ENDIF

IsHostInProxyBypassList PROTO STDCALL :DWORD,:DWORD,:DWORD
IsProfilesEnabled PROTO STDCALL

IsUrlCacheEntryExpiredA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  IsUrlCacheEntryExpired equ <IsUrlCacheEntryExpiredA>
ENDIF

IsUrlCacheEntryExpiredW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  IsUrlCacheEntryExpired equ <IsUrlCacheEntryExpiredW>
ENDIF

LoadUrlCacheContent PROTO STDCALL
MapResourceToPolicy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ParseX509EncodedCertificateForListBoxEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

PerformOperationOverUrlCacheA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PerformOperationOverUrlCache equ <PerformOperationOverUrlCacheA>
ENDIF

PrivacyGetZonePreferenceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PrivacyGetZonePreference equ <PrivacyGetZonePreferenceW>
ENDIF

PrivacySetZonePreferenceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PrivacySetZonePreference equ <PrivacySetZonePreferenceW>
ENDIF

ReadUrlCacheEntryStream PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterUrlCacheNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResumeSuspendedDownload PROTO STDCALL :DWORD,:DWORD

RetrieveUrlCacheEntryFileA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RetrieveUrlCacheEntryFile equ <RetrieveUrlCacheEntryFileA>
ENDIF

RetrieveUrlCacheEntryFileW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RetrieveUrlCacheEntryFile equ <RetrieveUrlCacheEntryFileW>
ENDIF

RetrieveUrlCacheEntryStreamA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  RetrieveUrlCacheEntryStream equ <RetrieveUrlCacheEntryStreamA>
ENDIF

RetrieveUrlCacheEntryStreamW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  RetrieveUrlCacheEntryStream equ <RetrieveUrlCacheEntryStreamW>
ENDIF

RunOnceUrlCache PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

SetUrlCacheConfigInfoA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetUrlCacheConfigInfo equ <SetUrlCacheConfigInfoA>
ENDIF

SetUrlCacheConfigInfoW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetUrlCacheConfigInfo equ <SetUrlCacheConfigInfoW>
ENDIF


SetUrlCacheEntryGroupA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetUrlCacheEntryGroup equ <SetUrlCacheEntryGroupA>
ENDIF

SetUrlCacheEntryGroupW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetUrlCacheEntryGroup equ <SetUrlCacheEntryGroupW>
ENDIF

SetUrlCacheEntryInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetUrlCacheEntryInfo equ <SetUrlCacheEntryInfoA>
ENDIF

SetUrlCacheEntryInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetUrlCacheEntryInfo equ <SetUrlCacheEntryInfoW>
ENDIF

SetUrlCacheGroupAttributeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetUrlCacheGroupAttribute equ <SetUrlCacheGroupAttributeA>
ENDIF

SetUrlCacheGroupAttributeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetUrlCacheGroupAttribute equ <SetUrlCacheGroupAttributeW>
ENDIF

SetUrlCacheHeaderData PROTO STDCALL :DWORD,:DWORD
ShowCertificate PROTO STDCALL :DWORD,:DWORD
ShowClientAuthCerts PROTO STDCALL :DWORD
ShowSecurityInfo PROTO STDCALL :DWORD,:DWORD
ShowX509EncodedCertificate PROTO STDCALL :DWORD,:DWORD,:DWORD

UnlockUrlCacheEntryFileA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  UnlockUrlCacheEntryFile equ <UnlockUrlCacheEntryFileA>
ENDIF

UnlockUrlCacheEntryFileW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  UnlockUrlCacheEntryFile equ <UnlockUrlCacheEntryFileW>
ENDIF

UnlockUrlCacheEntryStream PROTO STDCALL :DWORD,:DWORD
UpdateUrlCacheContentPath PROTO STDCALL :DWORD
UrlZonesDetach PROTO STDCALL

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file wininet.inc
  echo ------------------------------------------
ENDIF
