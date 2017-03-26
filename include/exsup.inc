  ; ===========================================
  ; exsup.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF EXSUP_INC
EXSUP_INC equ <1>

RtlUnwind PROTO :DWORD,:DWORD,:DWORD,:DWORD
_rt_probe_read4 PROTO :DWORD
_seh_longjmp_unwind PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file exsup.inc
echo -----------------------------------------
ENDIF
