; --------------------------------------------------------------------------------------------------
;                           ntmsapi.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF NTMSAPI_INC
NTMSAPI_INC equ <1>

AccessNtmsLibraryDoor PROTO STDCALL :DWORD,:DWORD,:DWORD
AddNtmsMediaType PROTO STDCALL :DWORD,:DWORD,:DWORD
AllocateNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BeginNtmsDeviceChangeDetection PROTO STDCALL :DWORD,:DWORD
CancelNtmsLibraryRequest PROTO STDCALL :DWORD,:DWORD
CancelNtmsOperatorRequest PROTO STDCALL :DWORD,:DWORD
ChangeNtmsMediaType PROTO STDCALL :DWORD,:DWORD,:DWORD
CleanNtmsDrive PROTO STDCALL :DWORD,:DWORD
CloseNtmsNotification PROTO STDCALL :DWORD
CloseNtmsSession PROTO STDCALL :DWORD

CreateNtmsMediaA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateNtmsMedia equ <CreateNtmsMediaA>
ENDIF

CreateNtmsMediaPoolA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateNtmsMediaPool equ <CreateNtmsMediaPoolA>
ENDIF

CreateNtmsMediaPoolW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateNtmsMediaPool equ <CreateNtmsMediaPoolW>
ENDIF

CreateNtmsMediaW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateNtmsMedia equ <CreateNtmsMediaW>
ENDIF

DeallocateNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD
DecommissionNtmsMedia PROTO STDCALL :DWORD,:DWORD
DeleteNtmsDrive PROTO STDCALL :DWORD,:DWORD
DeleteNtmsLibrary PROTO STDCALL :DWORD,:DWORD
DeleteNtmsMedia PROTO STDCALL :DWORD,:DWORD
DeleteNtmsMediaPool PROTO STDCALL :DWORD,:DWORD
DeleteNtmsMediaType PROTO STDCALL :DWORD,:DWORD,:DWORD
DeleteNtmsRequests PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DisableNtmsObject PROTO STDCALL :DWORD,:DWORD,:DWORD
DismountNtmsDrive PROTO STDCALL :DWORD,:DWORD
DismountNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

DoEjectFromSADriveW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DoEjectFromSADrive equ <DoEjectFromSADriveW>
ENDIF

EjectDiskFromSADriveA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EjectDiskFromSADrive equ <EjectDiskFromSADriveA>
ENDIF

EjectDiskFromSADriveW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EjectDiskFromSADrive equ <EjectDiskFromSADriveW>
ENDIF

EjectNtmsCleaner PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
EjectNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
EnableNtmsObject PROTO STDCALL :DWORD,:DWORD,:DWORD
EndNtmsDeviceChangeDetection PROTO STDCALL :DWORD,:DWORD
EnumerateNtmsObject PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExportNtmsDatabase PROTO STDCALL :DWORD

GetNtmsMediaPoolNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNtmsMediaPoolName equ <GetNtmsMediaPoolNameA>
ENDIF

GetNtmsMediaPoolNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNtmsMediaPoolName equ <GetNtmsMediaPoolNameW>
ENDIF

GetNtmsObjectAttributeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNtmsObjectAttribute equ <GetNtmsObjectAttributeA>
ENDIF

GetNtmsObjectAttributeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNtmsObjectAttribute equ <GetNtmsObjectAttributeW>
ENDIF

GetNtmsObjectInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNtmsObjectInformation equ <GetNtmsObjectInformationA>
ENDIF

GetNtmsObjectInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNtmsObjectInformation equ <GetNtmsObjectInformationW>
ENDIF

GetNtmsObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNtmsRequestOrder PROTO STDCALL :DWORD,:DWORD,:DWORD

GetNtmsUIOptionsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetNtmsUIOptions equ <GetNtmsUIOptionsA>
ENDIF

GetNtmsUIOptionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetNtmsUIOptions equ <GetNtmsUIOptionsW>
ENDIF

GetVolumesFromDriveA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetVolumesFromDrive equ <GetVolumesFromDriveA>
ENDIF

GetVolumesFromDriveW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetVolumesFromDrive equ <GetVolumesFromDriveW>
ENDIF

IdentifyNtmsSlot PROTO STDCALL :DWORD,:DWORD,:DWORD
ImportNtmsDatabase PROTO STDCALL :DWORD
InjectNtmsCleaner PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InjectNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
InventoryNtmsLibrary PROTO STDCALL :DWORD,:DWORD,:DWORD
MountNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MoveToNtmsMediaPool PROTO STDCALL :DWORD,:DWORD,:DWORD
OpenNtmsNotification PROTO STDCALL :DWORD,:DWORD

OpenNtmsSessionA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenNtmsSession equ <OpenNtmsSessionA>
ENDIF

OpenNtmsSessionW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenNtmsSession equ <OpenNtmsSessionW>
ENDIF

ReleaseNtmsCleanerSlot PROTO STDCALL :DWORD,:DWORD
ReserveNtmsCleanerSlot PROTO STDCALL :DWORD,:DWORD,:DWORD
SatisfyNtmsOperatorRequest PROTO STDCALL :DWORD,:DWORD
SetNtmsDeviceChangeDetection PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsMediaComplete PROTO STDCALL :DWORD,:DWORD

SetNtmsObjectAttributeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetNtmsObjectAttribute equ <SetNtmsObjectAttributeA>
ENDIF

SetNtmsObjectAttributeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetNtmsObjectAttribute equ <SetNtmsObjectAttributeW>
ENDIF

SetNtmsObjectInformationA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetNtmsObjectInformation equ <SetNtmsObjectInformationA>
ENDIF

SetNtmsObjectInformationW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetNtmsObjectInformation equ <SetNtmsObjectInformationW>
ENDIF

SetNtmsObjectSecurity PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsRequestOrder PROTO STDCALL :DWORD,:DWORD,:DWORD

SetNtmsUIOptionsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetNtmsUIOptions equ <SetNtmsUIOptionsA>
ENDIF

SetNtmsUIOptionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetNtmsUIOptions equ <SetNtmsUIOptionsW>
ENDIF

SubmitNtmsOperatorRequestA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SubmitNtmsOperatorRequest equ <SubmitNtmsOperatorRequestA>
ENDIF

SubmitNtmsOperatorRequestW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SubmitNtmsOperatorRequest equ <SubmitNtmsOperatorRequestW>
ENDIF

SwapNtmsMedia PROTO STDCALL :DWORD,:DWORD,:DWORD
UpdateNtmsOmidInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WaitForNtmsNotification PROTO STDCALL :DWORD,:DWORD,:DWORD
WaitForNtmsOperatorRequest PROTO STDCALL :DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file ntmsapi.inc
  echo ------------------------------------------
ENDIF
