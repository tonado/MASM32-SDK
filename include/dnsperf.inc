; --------------------------------------------------------------------------------------------------
;                           dnsperf.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF DNSPERF_INC
DNSPERF_INC equ <1>

CloseDnsPerformanceData PROTO STDCALL
CollectDnsPerformanceData PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
OpenDnsPerformanceData PROTO STDCALL :DWORD

ELSE
  echo ------------------------------------------
  echo WARNING duplicate include file dnsperf.inc
  echo ------------------------------------------
ENDIF
