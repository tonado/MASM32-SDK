  ; ===========================================
  ; csq.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CSQ_INC
CSQ_INC equ <1>

IoReleaseCancelSpinLock PROTO :DWORD
IopCsqCancelRoutine PROTO :DWORD,:DWORD
WdmlibIoCsqInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WdmlibIoCsqInitializeEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WdmlibIoCsqInsertIrp PROTO :DWORD,:DWORD,:DWORD
WdmlibIoCsqInsertIrpEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
WdmlibIoCsqRemoveIrp PROTO :DWORD,:DWORD
WdmlibIoCsqRemoveNextIrp PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file csq.inc
echo -----------------------------------------
ENDIF
