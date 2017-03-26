; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

        RichEdit2        PROTO :DWORD,:DWORD,:DWORD,:DWORD
        file_write       PROTO :DWORD,:DWORD
        cbSaveFile       PROTO :DWORD,:DWORD,:DWORD,:DWORD
        Select_All       PROTO :DWORD

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

RichEdit2 proc iinstance:DWORD,hParent:DWORD,ID:DWORD,WRAP:DWORD

    LOCAL wStyle :DWORD

    mov wStyle, WS_VISIBLE or WS_CHILDWINDOW or WS_CLIPSIBLINGS or ES_MULTILINE or \
                WS_VSCROLL or ES_AUTOVSCROLL or ES_NOHIDESEL or ES_DISABLENOSCROLL

    .if WRAP == 0
      or wStyle, WS_HSCROLL or ES_AUTOHSCROLL
    .endif

    fn CreateWindowEx,WS_EX_STATICEDGE,"RichEdit20a",0,wStyle, \
                      0,0,100,100,hParent,ID,iinstance,NULL

    ret

RichEdit2 endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

file_write proc edit:DWORD,lpszFileName:DWORD

    LOCAL hFile :DWORD
    LOCAL ofs   :OFSTRUCT
    LOCAL est   :EDITSTREAM

    invoke OpenFile,lpszFileName,ADDR ofs,OF_CREATE
    mov hFile, eax

    mov est.dwCookie, eax
    mov est.dwError, 0
    mov eax, offset cbSaveFile
    mov est.pfnCallback, eax

    invoke SendMessage,edit,EM_STREAMOUT,SF_TEXT,ADDR est
    invoke CloseHandle,hFile

    invoke SendMessage,edit,EM_SETMODIFY,0,0

    xor eax, eax
    ret

file_write endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

cbSaveFile proc dwCookie:DWORD,pbBuff:DWORD,cb:DWORD,pcb:DWORD

  ; ---------------------------------------------------------------
  ; this callback procedure is called by the "file_write" procedure
  ; ---------------------------------------------------------------

    invoke WriteFile,dwCookie,pbBuff,cb,pcb,NULL
    xor eax, eax
    ret

cbSaveFile endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

Select_All Proc Edit:DWORD

    LOCAL tl :DWORD
    LOCAL Cr :CHARRANGE

    mov Cr.cpMin,0
    invoke GetWindowTextLength,Edit
    inc eax
    mov Cr.cpMax, eax
    invoke SendMessage,Edit,EM_EXSETSEL,0,ADDR Cr

    ret

Select_All endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい
