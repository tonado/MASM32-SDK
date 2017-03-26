  ; ===========================================
  ; psxrtl.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF PSXRTL_INC
PSXRTL_INC equ <1>

__PdxInitializeData PROTO :DWORD,:DWORD
__chkstk PROTO 
_chkstk PROTO 
_fptrap PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file psxrtl.inc
echo -----------------------------------------
ENDIF
