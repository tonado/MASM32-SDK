; --------------------------------------------------------------------------------------------------
;                             pdh.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PDH_INC
PDH_INC equ <1>

PdhAddCounterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhAddCounter equ <PdhAddCounterA>
ENDIF

PdhAddCounterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhAddCounter equ <PdhAddCounterW>
ENDIF

PdhBindInputDataSourceA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  PdhBindInputDataSource equ <PdhBindInputDataSourceA>
ENDIF

PdhBindInputDataSourceW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  PdhBindInputDataSource equ <PdhBindInputDataSourceW>
ENDIF

PdhBrowseCountersA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhBrowseCounters equ <PdhBrowseCountersA>
ENDIF

PdhBrowseCountersHA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhBrowseCountersH equ <PdhBrowseCountersHA>
ENDIF

PdhBrowseCountersHW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhBrowseCountersH equ <PdhBrowseCountersHW>
ENDIF

PdhBrowseCountersW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhBrowseCounters equ <PdhBrowseCountersW>
ENDIF

PdhCalculateCounterFromRawValue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhCloseLog PROTO STDCALL :DWORD,:DWORD
PdhCloseQuery PROTO STDCALL :DWORD
PdhCollectQueryData PROTO STDCALL :DWORD
PdhCollectQueryDataEx PROTO STDCALL :DWORD,:DWORD,:DWORD
PdhComputeCounterStatistics PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

PdhConnectMachineA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhConnectMachine equ <PdhConnectMachineA>
ENDIF

PdhConnectMachineW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhConnectMachine equ <PdhConnectMachineW>
ENDIF

PdhCreateSQLTablesA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhCreateSQLTables equ <PdhCreateSQLTablesA>
ENDIF

PdhCreateSQLTablesW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhCreateSQLTables equ <PdhCreateSQLTablesW>
ENDIF

PdhEnumLogSetNamesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumLogSetNames equ <PdhEnumLogSetNamesA>
ENDIF

PdhEnumLogSetNamesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumLogSetNames equ <PdhEnumLogSetNamesW>
ENDIF

PdhEnumMachinesA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumMachines equ <PdhEnumMachinesA>
ENDIF

PdhEnumMachinesHA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumMachinesH equ <PdhEnumMachinesHA>
ENDIF

PdhEnumMachinesHW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumMachinesH equ <PdhEnumMachinesHW>
ENDIF

PdhEnumMachinesW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumMachines equ <PdhEnumMachinesW>
ENDIF

PdhEnumObjectItemsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumObjectItems equ <PdhEnumObjectItemsA>
ENDIF

PdhEnumObjectItemsHA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumObjectItemsH equ <PdhEnumObjectItemsHA>
ENDIF

PdhEnumObjectItemsHW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumObjectItemsH equ <PdhEnumObjectItemsHW>
ENDIF

PdhEnumObjectItemsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumObjectItems equ <PdhEnumObjectItemsW>
ENDIF

PdhEnumObjectsA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumObjects equ <PdhEnumObjectsA>
ENDIF

PdhEnumObjectsHA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhEnumObjectsH equ <PdhEnumObjectsHA>
ENDIF

PdhEnumObjectsHW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumObjectsH equ <PdhEnumObjectsHW>
ENDIF

PdhEnumObjectsW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhEnumObjects equ <PdhEnumObjectsW>
ENDIF

PdhExpandCounterPathA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhExpandCounterPath equ <PdhExpandCounterPathA>
ENDIF

PdhExpandCounterPathW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhExpandCounterPath equ <PdhExpandCounterPathW>
ENDIF

PdhExpandWildCardPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhExpandWildCardPath equ <PdhExpandWildCardPathA>
ENDIF

PdhExpandWildCardPathHA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhExpandWildCardPathH equ <PdhExpandWildCardPathHA>
ENDIF

PdhExpandWildCardPathHW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhExpandWildCardPathH equ <PdhExpandWildCardPathHW>
ENDIF

PdhExpandWildCardPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhExpandWildCardPath equ <PdhExpandWildCardPathW>
ENDIF

PdhFormatFromRawValue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

PdhGetCounterInfoA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetCounterInfo equ <PdhGetCounterInfoA>
ENDIF

PdhGetCounterInfoW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetCounterInfo equ <PdhGetCounterInfoW>
ENDIF

PdhGetCounterTimeBase PROTO STDCALL :DWORD,:DWORD

PdhGetDataSourceTimeRangeA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetDataSourceTimeRange equ <PdhGetDataSourceTimeRangeA>
ENDIF

PdhGetDataSourceTimeRangeH PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD

PdhGetDataSourceTimeRangeW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetDataSourceTimeRange equ <PdhGetDataSourceTimeRangeW>
ENDIF

PdhGetDefaultPerfCounterA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetDefaultPerfCounter equ <PdhGetDefaultPerfCounterA>
ENDIF

PdhGetDefaultPerfCounterHA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetDefaultPerfCounterH equ <PdhGetDefaultPerfCounterHA>
ENDIF

PdhGetDefaultPerfCounterHW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetDefaultPerfCounterH equ <PdhGetDefaultPerfCounterHW>
ENDIF

PdhGetDefaultPerfCounterW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetDefaultPerfCounter equ <PdhGetDefaultPerfCounterW>
ENDIF

PdhGetDefaultPerfObjectA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetDefaultPerfObject equ <PdhGetDefaultPerfObjectA>
ENDIF

PdhGetDefaultPerfObjectHA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetDefaultPerfObjectH equ <PdhGetDefaultPerfObjectHA>
ENDIF

PdhGetDefaultPerfObjectHW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetDefaultPerfObjectH equ <PdhGetDefaultPerfObjectHW>
ENDIF

PdhGetDefaultPerfObjectW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetDefaultPerfObject equ <PdhGetDefaultPerfObjectW>
ENDIF

PdhGetDllVersion PROTO STDCALL :DWORD

PdhGetFormattedCounterArrayA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetFormattedCounterArray equ <PdhGetFormattedCounterArrayA>
ENDIF

PdhGetFormattedCounterArrayW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetFormattedCounterArray equ <PdhGetFormattedCounterArrayW>
ENDIF

PdhGetFormattedCounterValue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PdhGetLogFileSize PROTO STDCALL :DWORD,:DWORD
PdhGetLogSetGUID PROTO STDCALL :DWORD,:DWORD,:DWORD

PdhGetRawCounterArrayA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhGetRawCounterArray equ <PdhGetRawCounterArrayA>
ENDIF

PdhGetRawCounterArrayW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhGetRawCounterArray equ <PdhGetRawCounterArrayW>
ENDIF

PdhGetRawCounterValue PROTO STDCALL :DWORD,:DWORD,:DWORD
PdhIsRealTimeQuery PROTO STDCALL :DWORD

PdhLogServiceCommandA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhLogServiceCommand equ <PdhLogServiceCommandA>
ENDIF

PdhLogServiceCommandW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhLogServiceCommand equ <PdhLogServiceCommandW>
ENDIF

PdhLogServiceControlA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhLogServiceControl equ <PdhLogServiceControlA>
ENDIF

PdhLogServiceControlW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhLogServiceControl equ <PdhLogServiceControlW>
ENDIF

PdhLookupPerfIndexByNameA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhLookupPerfIndexByName equ <PdhLookupPerfIndexByNameA>
ENDIF

PdhLookupPerfIndexByNameW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhLookupPerfIndexByName equ <PdhLookupPerfIndexByNameW>
ENDIF

PdhLookupPerfNameByIndexA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhLookupPerfNameByIndex equ <PdhLookupPerfNameByIndexA>
ENDIF

PdhLookupPerfNameByIndexW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhLookupPerfNameByIndex equ <PdhLookupPerfNameByIndexW>
ENDIF

PdhMakeCounterPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhMakeCounterPath equ <PdhMakeCounterPathA>
ENDIF

PdhMakeCounterPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhMakeCounterPath equ <PdhMakeCounterPathW>
ENDIF

PdhOpenLogA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhOpenLog equ <PdhOpenLogA>
ENDIF

PdhOpenLogW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhOpenLog equ <PdhOpenLogW>
ENDIF


PdhOpenQueryA PROTO STDCALL :DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhOpenQuery equ <PdhOpenQueryA>
ENDIF

PdhOpenQueryH PROTO STDCALL :DWORD,:DWORD,:DWORD

PdhOpenQueryW PROTO STDCALL :DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhOpenQuery equ <PdhOpenQueryW>
ENDIF

PdhParseCounterPathA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhParseCounterPath equ <PdhParseCounterPathA>
ENDIF

PdhParseCounterPathW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhParseCounterPath equ <PdhParseCounterPathW>
ENDIF

PdhParseInstanceNameA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhParseInstanceName equ <PdhParseInstanceNameA>
ENDIF

PdhParseInstanceNameW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhParseInstanceName equ <PdhParseInstanceNameW>
ENDIF

PdhReadRawLogRecord PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhRemoveCounter PROTO STDCALL :DWORD

PdhSelectDataSourceA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  PdhSelectDataSource equ <PdhSelectDataSourceA>
ENDIF

PdhSelectDataSourceW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  PdhSelectDataSource equ <PdhSelectDataSourceW>
ENDIF

PdhSetCounterScaleFactor PROTO STDCALL :DWORD,:DWORD
PdhSetDefaultRealTimeDataSource PROTO STDCALL :DWORD
PdhSetLogSetRunID PROTO STDCALL :DWORD,:DWORD
PdhSetQueryTimeRange PROTO STDCALL :DWORD,:DWORD

PdhUpdateLogA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  PdhUpdateLog equ <PdhUpdateLogA>
ENDIF

PdhUpdateLogFileCatalog PROTO STDCALL :DWORD

PdhUpdateLogW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  PdhUpdateLog equ <PdhUpdateLogW>
ENDIF

PdhValidatePathA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhValidatePath equ <PdhValidatePathA>
ENDIF

PdhValidatePathW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhValidatePath equ <PdhValidatePathW>
ENDIF

PdhVbAddCounter PROTO STDCALL :DWORD,:DWORD,:DWORD
PdhVbCreateCounterPathList PROTO STDCALL :DWORD,:DWORD
PdhVbGetCounterPathElements PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhVbGetCounterPathFromList PROTO STDCALL :DWORD,:DWORD,:DWORD
PdhVbGetDoubleCounterValue PROTO STDCALL :DWORD,:DWORD
PdhVbGetLogFileSize PROTO STDCALL :DWORD,:DWORD
PdhVbGetOneCounterPath PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PdhVbIsGoodStatus PROTO STDCALL :DWORD
PdhVbOpenLog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhVbOpenQuery PROTO STDCALL :DWORD
PdhVbUpdateLog PROTO STDCALL :DWORD,:DWORD

PdhVerifySQLDBA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  PdhVerifySQLDB equ <PdhVerifySQLDBA>
ENDIF

PdhVerifySQLDBW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  PdhVerifySQLDB equ <PdhVerifySQLDBW>
ENDIF

ELSE
  echo --------------------------------------
  echo WARNING duplicate include file pdh.inc
  echo --------------------------------------
ENDIF
