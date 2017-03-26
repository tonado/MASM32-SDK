; --------------------------------------------------------------------------------------------------
;                           spoolss.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF SPOOLSS_INC
SPOOLSS_INC equ <1>

AbortPrinter PROTO STDCALL :DWORD
AddDriverCatalog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

AddFormW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddForm equ <AddFormW>
ENDIF

AddJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddJob equ <AddJobW>
ENDIF

AddMonitorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddMonitor equ <AddMonitorW>
ENDIF

AddPerMachineConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPerMachineConnection equ <AddPerMachineConnectionW>
ENDIF

AddPortExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPortEx equ <AddPortExW>
ENDIF

AddPortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPort equ <AddPortW>
ENDIF

AddPrintProcessorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrintProcessor equ <AddPrintProcessorW>
ENDIF

AddPrintProvidorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrintProvidor equ <AddPrintProvidorW>
ENDIF

AddPrinterConnectionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  AddPrinterConnection equ <AddPrinterConnectionW>
ENDIF

AddPrinterDriverExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinterDriverEx equ <AddPrinterDriverExW>
ENDIF

AddPrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinterDriver equ <AddPrinterDriverW>
ENDIF

AddPrinterExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinterEx equ <AddPrinterExW>
ENDIF

AddPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinter equ <AddPrinterW>
ENDIF

AdjustPointers PROTO STDCALL :DWORD,:DWORD,:DWORD
AdjustPointersInStructuresArray PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AlignKMPtr PROTO STDCALL :DWORD,:DWORD
AlignRpcPtr PROTO STDCALL :DWORD,:DWORD
AllocSplStr PROTO STDCALL :DWORD
AppendPrinterNotifyInfoData PROTO STDCALL :DWORD,:DWORD,:DWORD
BuildOtherNamesFromMachineName PROTO STDCALL :DWORD,:DWORD
CallDrvDevModeConversion PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CallRouterFindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClosePrinter PROTO STDCALL :DWORD
ClusterSplClose PROTO STDCALL :DWORD
ClusterSplIsAlive PROTO STDCALL :DWORD
ClusterSplOpen PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ConfigurePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConfigurePort equ <ConfigurePortW>
ENDIF

CreatePrinterIC PROTO STDCALL :DWORD,:DWORD
DbgGetPointers PROTO STDCALL

DeleteFormW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeleteForm equ <DeleteFormW>
ENDIF

DeleteMonitorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeleteMonitor equ <DeleteMonitorW>
ENDIF

DeletePerMachineConnectionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePerMachineConnection equ <DeletePerMachineConnectionW>
ENDIF

DeletePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePort equ <DeletePortW>
ENDIF

DeletePrintProcessorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrintProcessor equ <DeletePrintProcessorW>
ENDIF

DeletePrintProvidorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrintProvidor equ <DeletePrintProvidorW>
ENDIF

DeletePrinter PROTO STDCALL :DWORD

DeletePrinterConnectionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeletePrinterConnection equ <DeletePrinterConnectionW>
ENDIF

DeletePrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterDataEx equ <DeletePrinterDataExW>
ENDIF

DeletePrinterDataW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterData equ <DeletePrinterDataW>
ENDIF

DeletePrinterDriverExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterDriverEx equ <DeletePrinterDriverExW>
ENDIF

DeletePrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterDriver equ <DeletePrinterDriverW>
ENDIF

DeletePrinterIC PROTO STDCALL :DWORD

DeletePrinterKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterKey equ <DeletePrinterKeyW>
ENDIF

DllAllocSplMem PROTO STDCALL :DWORD
DllFreeSplMem PROTO STDCALL :DWORD
DllFreeSplStr PROTO STDCALL :DWORD
EndDocPrinter PROTO STDCALL :DWORD
EndPagePrinter PROTO STDCALL :DWORD

EnumFormsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumForms equ <EnumFormsW>
ENDIF

EnumJobsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumJobs equ <EnumJobsW>
ENDIF

EnumMonitorsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumMonitors equ <EnumMonitorsW>
ENDIF

EnumPerMachineConnectionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPerMachineConnections equ <EnumPerMachineConnectionsW>
ENDIF

EnumPortsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPorts equ <EnumPortsW>
ENDIF

EnumPrintProcessorDatatypesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesW>
ENDIF

EnumPrintProcessorsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrintProcessors equ <EnumPrintProcessorsW>
ENDIF

EnumPrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterDataEx equ <EnumPrinterDataExW>
ENDIF

EnumPrinterDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterData equ <EnumPrinterDataW>
ENDIF

EnumPrinterDriversW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterDrivers equ <EnumPrinterDriversW>
ENDIF

EnumPrinterKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterKey equ <EnumPrinterKeyW>
ENDIF

EnumPrintersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinters equ <EnumPrintersW>
ENDIF

FindClosePrinterChangeNotification PROTO STDCALL :DWORD
FlushPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FormatPrinterForRegistryKey PROTO STDCALL :DWORD,:DWORD,:DWORD
FormatRegistryKeyForPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD
FreeOtherNames PROTO STDCALL :DWORD,:DWORD
GetClientUserHandle PROTO STDCALL :DWORD

GetFormW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetForm equ <GetFormW>
ENDIF

GetJobAttributes PROTO STDCALL :DWORD,:DWORD,:DWORD

GetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetJob equ <GetJobW>
ENDIF

GetNetworkId PROTO STDCALL :DWORD,:DWORD

GetPrintProcessorDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryW>
ENDIF

GetPrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDataEx equ <GetPrinterDataExW>
ENDIF

GetPrinterDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterData equ <GetPrinterDataW>
ENDIF

GetPrinterDriverDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryW>
ENDIF

GetPrinterDriverExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDriverEx equ <GetPrinterDriverExW>
ENDIF

GetPrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDriver equ <GetPrinterDriverW>
ENDIF

GetPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinter equ <GetPrinterW>
ENDIF

GetShrinkedSize PROTO STDCALL :DWORD,:DWORD
ImpersonatePrinterClient PROTO STDCALL :DWORD
InitializeRouter PROTO STDCALL :DWORD
IsLocalCall PROTO STDCALL
IsNamedPipeRpcCall PROTO STDCALL
LoadDriver PROTO STDCALL :DWORD
LoadDriverFiletoConvertDevmode PROTO STDCALL :DWORD
LoadDriverWithVersion PROTO STDCALL :DWORD,:DWORD
LogWmiTraceEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
MIDL_user_allocate1 PROTO STDCALL :DWORD
MIDL_user_free1 PROTO STDCALL :DWORD
MarshallDownStructure PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MarshallDownStructuresArray PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MarshallUpStructure PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
MarshallUpStructuresArray PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

OldGetPrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OldGetPrinterDriver equ <OldGetPrinterDriverW>
ENDIF

OpenPrinterExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenPrinterEx equ <OpenPrinterExW>
ENDIF

OpenPrinterPortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenPrinterPort equ <OpenPrinterPortW>
ENDIF

OpenPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenPrinter equ <OpenPrinterW>
ENDIF

PackStrings PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PartialReplyPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD
PlayGdiScriptOnPrinterIC PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterHandleRundown PROTO STDCALL :DWORD

PrinterMessageBoxW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PrinterMessageBox equ <PrinterMessageBoxW>
ENDIF

ProvidorFindClosePrinterChangeNotification PROTO STDCALL :DWORD
ProvidorFindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ReallocSplMem PROTO STDCALL :DWORD,:DWORD,:DWORD
ReallocSplStr PROTO STDCALL :DWORD,:DWORD
RemoteFindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReplyClosePrinter PROTO STDCALL :DWORD
ReplyOpenPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReplyPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

ResetPrinterW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ResetPrinter equ <ResetPrinterW>
ENDIF

RevertToPrinterSelf PROTO STDCALL
RouterAllocBidiMem PROTO STDCALL :DWORD
RouterAllocBidiResponseContainer PROTO STDCALL :DWORD
RouterAllocPrinterNotifyInfo PROTO STDCALL :DWORD
RouterFindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterFindNextPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterFreeBidiMem PROTO STDCALL :DWORD
RouterFreePrinterNotifyInfo PROTO STDCALL :DWORD
RouterRefreshPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RouterReplyPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ScheduleJob PROTO STDCALL :DWORD,:DWORD
SeekPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SendRecvBidiData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetAllocFailCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetFormW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetForm equ <SetFormW>
ENDIF

SetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetJob equ <SetJobW>
ENDIF

SetPortW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetPort equ <SetPortW>
ENDIF

SetPrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetPrinterDataEx equ <SetPrinterDataExW>
ENDIF

SetPrinterDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetPrinterData equ <SetPrinterDataW>
ENDIF

SetPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetPrinter equ <SetPrinterW>
ENDIF

SplCloseSpoolFileHandle PROTO STDCALL :DWORD
SplCommitSpoolData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SplDriverUnloadComplete PROTO STDCALL :DWORD
SplGetSpoolFileInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SplInitializeWinSpoolDrv PROTO STDCALL :DWORD
SplIsSessionZero PROTO STDCALL :DWORD,:DWORD,:DWORD
SplIsUpgrade PROTO STDCALL
SplPowerEvent PROTO STDCALL :DWORD
SplProcessPnPEvent PROTO STDCALL :DWORD,:DWORD,:DWORD
SplPromptUIInUsersSession PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SplReadPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD
SplRegisterForDeviceEvents PROTO STDCALL :DWORD,:DWORD,:DWORD
SplShutDownRouter PROTO STDCALL
SplStartPhase2Init PROTO STDCALL
SplUnregisterForDeviceEvents PROTO STDCALL :DWORD
SpoolerFindClosePrinterChangeNotification PROTO STDCALL :DWORD
SpoolerFindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SpoolerFindNextPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SpoolerFreePrinterNotifyInfo PROTO STDCALL :DWORD
SpoolerHasInitialized PROTO STDCALL
SpoolerInit PROTO STDCALL

StartDocPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartDocPrinter equ <StartDocPrinterW>
ENDIF

StartPagePrinter PROTO STDCALL :DWORD
UndoAlignKMPtr PROTO STDCALL :DWORD,:DWORD
UndoAlignRpcPtr PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
UnloadDriver PROTO STDCALL :DWORD
UnloadDriverFile PROTO STDCALL :DWORD
UpdateBufferSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UpdatePrinterRegAll PROTO STDCALL :DWORD,:DWORD,:DWORD
UpdatePrinterRegUser PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WaitForPrinterChange PROTO STDCALL :DWORD,:DWORD
WaitForSpoolerInitialization PROTO STDCALL
WritePrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

XcvDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  XcvData equ <XcvDataW>
ENDIF

bGetDevModePerUser PROTO STDCALL :DWORD,:DWORD,:DWORD
bSetDevModePerUser PROTO STDCALL :DWORD,:DWORD,:DWORD

pszDbgAllocMsgA PROTO C :VARARG
IFNDEF __UNICODE__
  pszDbgAllocMsg equ <pszDbgAllocMsgA>
ENDIF

vDbgLogError PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file spoolss.inc
  echo ------------------------------------------
ENDIF
