; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい
;                       Local include data and prototypes for this application
; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    IFNDEF cgv                     ;; include this macro if not defined elsewhere
      cgv MACRO args:VARARG
        LOCAL hndl
        .data?
          hndl dd ?
        .code
          invoke args
          mov hndl, eax
        EXITM < EQU <hndl>>
      ENDM
    ENDIF

    WndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

    Edit1Proc PROTO :DWORD,:DWORD,:DWORD,:DWORD
    Edit2Proc PROTO :DWORD,:DWORD,:DWORD,:DWORD
    Edit3Proc PROTO :DWORD,:DWORD,:DWORD,:DWORD
