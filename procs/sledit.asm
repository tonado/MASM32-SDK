; #########################################################################

EditSl proc szMsg:DWORD,a:DWORD,b:DWORD,
               wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

; EditSl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
; invoke EditSl,ADDR adrTxt,200,10,150,25,hWnd,700

    szText slEdit,"EDIT"

    invoke CreateWindowEx,WS_EX_CLIENTEDGE,ADDR slEdit,szMsg,
                WS_VISIBLE or WS_CHILDWINDOW or \
                ES_AUTOHSCROLL or ES_NOHIDESEL,
              a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

EditSl endp

; ########################################################################
