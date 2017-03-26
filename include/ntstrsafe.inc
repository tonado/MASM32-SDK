  ; ===========================================
  ; ntstrsafe.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NTSTRSAFE_INC
NTSTRSAFE_INC equ <1>

RaiseException PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlAnsiCharToUnicodeChar PROTO :DWORD
RtlMultiByteToUnicodeN PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlRaiseException PROTO :DWORD
RtlStringCatExWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatExWorker equ <RtlStringCatExWorkerA>

RtlStringCatExWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatNExWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatNExWorker equ <RtlStringCatNExWorkerA>

RtlStringCatNExWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatNWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatNWorker equ <RtlStringCatNWorkerA>

RtlStringCatNWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCatWorkerA PROTO :DWORD,:DWORD,:DWORD
RtlStringCatWorker equ <RtlStringCatWorkerA>

RtlStringCatWorkerW PROTO :DWORD,:DWORD,:DWORD
RtlStringCbCatA PROTO :DWORD,:DWORD,:DWORD
RtlStringCbCat equ <RtlStringCbCatA>

RtlStringCbCatExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatEx equ <RtlStringCbCatExA>

RtlStringCbCatExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatNA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatN equ <RtlStringCbCatNA>

RtlStringCbCatNExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatNEx equ <RtlStringCbCatNExA>

RtlStringCbCatNExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatNW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCatW PROTO :DWORD,:DWORD,:DWORD
RtlStringCbCopyA PROTO :DWORD,:DWORD,:DWORD
RtlStringCbCopy equ <RtlStringCbCopyA>

RtlStringCbCopyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyEx equ <RtlStringCbCopyExA>

RtlStringCbCopyExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyNA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyN equ <RtlStringCbCopyNA>

RtlStringCbCopyNExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyNEx equ <RtlStringCbCopyNExA>

RtlStringCbCopyNExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyNW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbCopyW PROTO :DWORD,:DWORD,:DWORD
RtlStringCbLengthA PROTO :DWORD,:DWORD,:DWORD
RtlStringCbLength equ <RtlStringCbLengthA>

RtlStringCbLengthW PROTO :DWORD,:DWORD,:DWORD
RtlStringCbVPrintfA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbVPrintf equ <RtlStringCbVPrintfA>

RtlStringCbVPrintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbVPrintfEx equ <RtlStringCbVPrintfExA>

RtlStringCbVPrintfExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCbVPrintfW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatA PROTO :DWORD,:DWORD,:DWORD
RtlStringCchCat equ <RtlStringCchCatA>

RtlStringCchCatExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatEx equ <RtlStringCchCatExA>

RtlStringCchCatExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatNA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatN equ <RtlStringCchCatNA>

RtlStringCchCatNExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatNEx equ <RtlStringCchCatNExA>

RtlStringCchCatNExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatNW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCatW PROTO :DWORD,:DWORD,:DWORD
RtlStringCchCopyA PROTO :DWORD,:DWORD,:DWORD
RtlStringCchCopy equ <RtlStringCchCopyA>

RtlStringCchCopyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyEx equ <RtlStringCchCopyExA>

RtlStringCchCopyExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyNA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyN equ <RtlStringCchCopyNA>

RtlStringCchCopyNExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyNEx equ <RtlStringCchCopyNExA>

RtlStringCchCopyNExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyNW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchCopyW PROTO :DWORD,:DWORD,:DWORD
RtlStringCchLengthA PROTO :DWORD,:DWORD,:DWORD
RtlStringCchLength equ <RtlStringCchLengthA>

RtlStringCchLengthW PROTO :DWORD,:DWORD,:DWORD
RtlStringCchVPrintfA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchVPrintf equ <RtlStringCchVPrintfA>

RtlStringCchVPrintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchVPrintfEx equ <RtlStringCchVPrintfExA>

RtlStringCchVPrintfExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCchVPrintfW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyExWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyExWorker equ <RtlStringCopyExWorkerA>

RtlStringCopyExWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyNExWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyNExWorker equ <RtlStringCopyNExWorkerA>

RtlStringCopyNExWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyNWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyNWorker equ <RtlStringCopyNWorkerA>

RtlStringCopyNWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringCopyWorkerA PROTO :DWORD,:DWORD,:DWORD
RtlStringCopyWorker equ <RtlStringCopyWorkerA>

RtlStringCopyWorkerW PROTO :DWORD,:DWORD,:DWORD
RtlStringLengthWorkerA PROTO :DWORD,:DWORD,:DWORD
RtlStringLengthWorker equ <RtlStringLengthWorkerA>

RtlStringLengthWorkerW PROTO :DWORD,:DWORD,:DWORD
RtlStringVPrintfExWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringVPrintfExWorker equ <RtlStringVPrintfExWorkerA>

RtlStringVPrintfExWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlStringVPrintfWorkerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlStringVPrintfWorker equ <RtlStringVPrintfWorkerA>

RtlStringVPrintfWorkerW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyExWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyStringExWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyStringNExWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyStringNWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyStringWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringCopyWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringExHandleFailureWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringInitWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringLengthHelper PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringVPrintfExWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringVPrintfWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringValidateDestWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringValidateSrcWorker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeStringValidateWorker PROTO :DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteN PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteSize PROTO :DWORD,:DWORD,:DWORD
RtlUnwind PROTO :DWORD,:DWORD,:DWORD,:DWORD
RtlUpcaseUnicodeChar PROTO :DWORD
RtlUpcaseUnicodeToMultiByteN PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_rt_probe_read4 PROTO :DWORD
_security_check_cookie PROTO :DWORD
_seh_longjmp_unwind PROTO :DWORD
xtoa PROTO :DWORD,:DWORD,:DWORD,:DWORD
xtow PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ntstrsafe.inc
echo -----------------------------------------
ENDIF
