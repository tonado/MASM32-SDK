; --------------------------------------------------------------------------------------------------
;                          winspool.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF WINSPOOL_INC
WINSPOOL_INC equ <1>

ADVANCEDSETUPDIALOG PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
AbortPrinter PROTO STDCALL :DWORD
AddDriverCatalog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

AddFormA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddForm equ <AddFormA>
ENDIF

AddFormW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddForm equ <AddFormW>
ENDIF

AddJobA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddJob equ <AddJobA>
ENDIF

AddJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddJob equ <AddJobW>
ENDIF

AddMonitorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddMonitor equ <AddMonitorA>
ENDIF

AddMonitorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddMonitor equ <AddMonitorW>
ENDIF

AddPerMachineConnectionA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPerMachineConnection equ <AddPerMachineConnectionA>
ENDIF

AddPerMachineConnectionW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPerMachineConnection equ <AddPerMachineConnectionW>
ENDIF

AddPortA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPort equ <AddPortA>
ENDIF

AddPortExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPortEx equ <AddPortExA>
ENDIF

AddPortExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPortEx equ <AddPortExW>
ENDIF

AddPortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPort equ <AddPortW>
ENDIF

AddPrintProcessorA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPrintProcessor equ <AddPrintProcessorA>
ENDIF

AddPrintProcessorW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrintProcessor equ <AddPrintProcessorW>
ENDIF

AddPrintProvidorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPrintProvidor equ <AddPrintProvidorA>
ENDIF

AddPrintProvidorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrintProvidor equ <AddPrintProvidorW>
ENDIF

AddPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPrinter equ <AddPrinterA>
ENDIF

AddPrinterConnectionA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  AddPrinterConnection equ <AddPrinterConnectionA>
ENDIF

AddPrinterConnectionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  AddPrinterConnection equ <AddPrinterConnectionW>
ENDIF

AddPrinterDriverA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPrinterDriver equ <AddPrinterDriverA>
ENDIF

AddPrinterDriverExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AddPrinterDriverEx equ <AddPrinterDriverExA>
ENDIF

AddPrinterDriverExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinterDriverEx equ <AddPrinterDriverExW>
ENDIF

AddPrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinterDriver equ <AddPrinterDriverW>
ENDIF

AddPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AddPrinter equ <AddPrinterW>
ENDIF

AdvancedDocumentPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  AdvancedDocumentProperties equ <AdvancedDocumentPropertiesA>
ENDIF

AdvancedDocumentPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  AdvancedDocumentProperties equ <AdvancedDocumentPropertiesW>
ENDIF

AdvancedSetupDialog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CallCommonPropertySheetUI PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ClosePrinter PROTO STDCALL :DWORD
CloseSpoolFileHandle PROTO STDCALL :DWORD,:DWORD
ClusterSplClose PROTO STDCALL :DWORD
ClusterSplIsAlive PROTO STDCALL :DWORD
ClusterSplOpen PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CommitSpoolData PROTO STDCALL :DWORD,:DWORD,:DWORD

ConfigurePortA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  ConfigurePort equ <ConfigurePortA>
ENDIF

ConfigurePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  ConfigurePort equ <ConfigurePortW>
ENDIF

ConnectToLd64In32Server PROTO STDCALL :DWORD
ConnectToPrinterDlg PROTO STDCALL :DWORD,:DWORD
ConvertAnsiDevModeToUnicodeDevmode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ConvertUnicodeDevModeToAnsiDevmode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
CreatePrinterIC PROTO STDCALL :DWORD,:DWORD
DEVICECAPABILITIES PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DEVICEMODE PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

DeleteFormA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteForm equ <DeleteFormA>
ENDIF

DeleteFormW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeleteForm equ <DeleteFormW>
ENDIF

DeleteMonitorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeleteMonitor equ <DeleteMonitorA>
ENDIF

DeleteMonitorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeleteMonitor equ <DeleteMonitorW>
ENDIF

DeletePerMachineConnectionA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePerMachineConnection equ <DeletePerMachineConnectionA>
ENDIF

DeletePerMachineConnectionW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePerMachineConnection equ <DeletePerMachineConnectionW>
ENDIF

DeletePortA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePort equ <DeletePortA>
ENDIF

DeletePortW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePort equ <DeletePortW>
ENDIF

DeletePrintProcessorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrintProcessor equ <DeletePrintProcessorA>
ENDIF

DeletePrintProcessorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrintProcessor equ <DeletePrintProcessorW>
ENDIF

DeletePrintProvidorA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrintProvidor equ <DeletePrintProvidorA>
ENDIF

DeletePrintProvidorW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrintProvidor equ <DeletePrintProvidorW>
ENDIF

DeletePrinter PROTO STDCALL :DWORD

DeletePrinterConnectionA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DeletePrinterConnection equ <DeletePrinterConnectionA>
ENDIF

DeletePrinterConnectionW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DeletePrinterConnection equ <DeletePrinterConnectionW>
ENDIF

DeletePrinterDataA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrinterData equ <DeletePrinterDataA>
ENDIF

DeletePrinterDataExA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrinterDataEx equ <DeletePrinterDataExA>
ENDIF

DeletePrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterDataEx equ <DeletePrinterDataExW>
ENDIF

DeletePrinterDataW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterData equ <DeletePrinterDataW>
ENDIF

DeletePrinterDriverA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrinterDriver equ <DeletePrinterDriverA>
ENDIF

DeletePrinterDriverExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrinterDriverEx equ <DeletePrinterDriverExA>
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

DeletePrinterKeyA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  DeletePrinterKey equ <DeletePrinterKeyA>
ENDIF

DeletePrinterKeyW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  DeletePrinterKey equ <DeletePrinterKeyW>
ENDIF

DevQueryPrint PROTO STDCALL :DWORD,:DWORD,:DWORD
DevQueryPrintEx PROTO STDCALL :DWORD

DeviceCapabilitiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DeviceCapabilities equ <DeviceCapabilitiesA>
ENDIF

DeviceCapabilitiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DeviceCapabilities equ <DeviceCapabilitiesW>
ENDIF

DeviceMode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
DevicePropertySheets PROTO STDCALL :DWORD,:DWORD
DocumentEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DocumentPropertiesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DocumentProperties equ <DocumentPropertiesA>
ENDIF

DocumentPropertiesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DocumentProperties equ <DocumentPropertiesW>
ENDIF

DocumentPropertySheets PROTO STDCALL :DWORD,:DWORD
EXTDEVICEMODE PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EndDocPrinter PROTO STDCALL :DWORD
EndPagePrinter PROTO STDCALL :DWORD

EnumFormsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumForms equ <EnumFormsA>
ENDIF

EnumFormsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumForms equ <EnumFormsW>
ENDIF

EnumJobsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumJobs equ <EnumJobsA>
ENDIF

EnumJobsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumJobs equ <EnumJobsW>
ENDIF

EnumMonitorsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumMonitors equ <EnumMonitorsA>
ENDIF

EnumMonitorsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumMonitors equ <EnumMonitorsW>
ENDIF

EnumPerMachineConnectionsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPerMachineConnections equ <EnumPerMachineConnectionsA>
ENDIF

EnumPerMachineConnectionsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPerMachineConnections equ <EnumPerMachineConnectionsW>
ENDIF

EnumPortsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPorts equ <EnumPortsA>
ENDIF

EnumPortsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPorts equ <EnumPortsW>
ENDIF

EnumPrintProcessorDatatypesA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesA>
ENDIF

EnumPrintProcessorDatatypesW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesW>
ENDIF

EnumPrintProcessorsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrintProcessors equ <EnumPrintProcessorsA>
ENDIF

EnumPrintProcessorsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrintProcessors equ <EnumPrintProcessorsW>
ENDIF

EnumPrinterDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrinterData equ <EnumPrinterDataA>
ENDIF

EnumPrinterDataExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrinterDataEx equ <EnumPrinterDataExA>
ENDIF

EnumPrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterDataEx equ <EnumPrinterDataExW>
ENDIF

EnumPrinterDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterData equ <EnumPrinterDataW>
ENDIF

EnumPrinterDriversA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrinterDrivers equ <EnumPrinterDriversA>
ENDIF

EnumPrinterDriversW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterDrivers equ <EnumPrinterDriversW>
ENDIF

EnumPrinterKeyA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrinterKey equ <EnumPrinterKeyA>
ENDIF

EnumPrinterKeyW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinterKey equ <EnumPrinterKeyW>
ENDIF

EnumPrinterPropertySheets PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

EnumPrintersA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  EnumPrinters equ <EnumPrintersA>
ENDIF

EnumPrintersW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  EnumPrinters equ <EnumPrintersW>
ENDIF

ExtDeviceMode PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindClosePrinterChangeNotification PROTO STDCALL :DWORD
FindFirstPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FindNextPrinterChangeNotification PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FlushPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ForceUnloadDriver PROTO STDCALL :DWORD
FreePrinterNotifyInfo PROTO STDCALL :DWORD

GetDefaultPrinterA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  GetDefaultPrinter equ <GetDefaultPrinterA>
ENDIF

GetDefaultPrinterW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  GetDefaultPrinter equ <GetDefaultPrinterW>
ENDIF

GetFormA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetForm equ <GetFormA>
ENDIF

GetFormW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetForm equ <GetFormW>
ENDIF

GetJobA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetJob equ <GetJobA>
ENDIF

GetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetJob equ <GetJobW>
ENDIF

GetPrintProcessorDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryA>
ENDIF

GetPrintProcessorDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryW>
ENDIF

GetPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrinter equ <GetPrinterA>
ENDIF

GetPrinterDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrinterData equ <GetPrinterDataA>
ENDIF

GetPrinterDataExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrinterDataEx equ <GetPrinterDataExA>
ENDIF

GetPrinterDataExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDataEx equ <GetPrinterDataExW>
ENDIF

GetPrinterDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterData equ <GetPrinterDataW>
ENDIF

GetPrinterDriverA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrinterDriver equ <GetPrinterDriverA>
ENDIF

GetPrinterDriverDirectoryA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryA>
ENDIF

GetPrinterDriverDirectoryW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryW>
ENDIF

GetPrinterDriverW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinterDriver equ <GetPrinterDriverW>
ENDIF

GetPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetPrinter equ <GetPrinterW>
ENDIF

GetSpoolFileHandle PROTO STDCALL :DWORD

IsValidDevmodeA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  IsValidDevmode equ <IsValidDevmodeA>
ENDIF

IsValidDevmodeW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  IsValidDevmode equ <IsValidDevmodeW>
ENDIF

LoadPrinterDriver PROTO STDCALL :DWORD

OpenPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  OpenPrinter equ <OpenPrinterA>
ENDIF

OpenPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  OpenPrinter equ <OpenPrinterW>
ENDIF

PlayGdiScriptOnPrinterIC PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrintUICreateInstance PROTO STDCALL :DWORD,:DWORD
PrintUIDocumentDefaults PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PrintUIDocumentPropertiesWrap PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrintUIPrinterPropPages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PrintUIPrinterSetup PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrintUIQueueCreate PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PrintUIServerPropPages PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PrintUIWebPnpEntry PROTO STDCALL :DWORD
PrintUIWebPnpPostEntry PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

PrinterMessageBoxA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PrinterMessageBox equ <PrinterMessageBoxA>
ENDIF

PrinterMessageBoxW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PrinterMessageBox equ <PrinterMessageBoxW>
ENDIF

PrinterProperties PROTO STDCALL :DWORD,:DWORD

PublishPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PublishPrinter equ <PublishPrinterA>
ENDIF

PublishPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PublishPrinter equ <PublishPrinterW>
ENDIF

QueryColorProfile PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryRemoteFonts PROTO STDCALL :DWORD,:DWORD,:DWORD
QuerySpoolMode PROTO STDCALL :DWORD,:DWORD,:DWORD
ReadPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RefCntLoadDriver PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RefCntUnloadDriver PROTO STDCALL :DWORD,:DWORD

ResetPrinterA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  ResetPrinter equ <ResetPrinterA>
ENDIF

ResetPrinterW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  ResetPrinter equ <ResetPrinterW>
ENDIF

RouterFreeBidiResponseContainer PROTO STDCALL :DWORD
ScheduleJob PROTO STDCALL :DWORD,:DWORD
SeekPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SendRecvBidiData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
SetAllocFailCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

SetDefaultPrinterA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  SetDefaultPrinter equ <SetDefaultPrinterA>
ENDIF

SetDefaultPrinterW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  SetDefaultPrinter equ <SetDefaultPrinterW>
ENDIF

SetFormA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetForm equ <SetFormA>
ENDIF

SetFormW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetForm equ <SetFormW>
ENDIF

SetJobA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetJob equ <SetJobA>
ENDIF

SetJobW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetJob equ <SetJobW>
ENDIF

SetPortA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetPort equ <SetPortA>
ENDIF

SetPortW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SetPort equ <SetPortW>
ENDIF

SetPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetPrinter equ <SetPrinterA>
ENDIF

SetPrinterDataA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetPrinterData equ <SetPrinterDataA>
ENDIF

SetPrinterDataExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SetPrinterDataEx equ <SetPrinterDataExA>
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

SplDriverUnloadComplete PROTO STDCALL :DWORD
SplReadPrinter PROTO STDCALL :DWORD,:DWORD,:DWORD

SpoolerDevQueryPrintW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  SpoolerDevQueryPrint equ <SpoolerDevQueryPrintW>
ENDIF

SpoolerInit PROTO STDCALL
SpoolerPrinterEvent PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

StartDocDlgA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  StartDocDlg equ <StartDocDlgA>
ENDIF

StartDocDlgW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  StartDocDlg equ <StartDocDlgW>
ENDIF

StartDocPrinterA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  StartDocPrinter equ <StartDocPrinterA>
ENDIF

StartDocPrinterW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  StartDocPrinter equ <StartDocPrinterW>
ENDIF

StartPagePrinter PROTO STDCALL :DWORD
WaitForPrinterChange PROTO STDCALL :DWORD,:DWORD
WritePrinter PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

XcvDataW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  XcvData equ <XcvDataW>
ENDIF

ELSE
  echo -------------------------------------------
  echo WARNING duplicate include file winspool.inc
  echo -------------------------------------------
ENDIF
