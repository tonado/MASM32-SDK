; #########################################################################

ComboBox proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

; ComboBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
; invoke ComboBox,200,10,150,250,hWnd,700

    szText cmbBox,"COMBOBOX"

    invoke CreateWindowEx,WS_EX_CLIENTEDGE,ADDR cmbBox,0,
              WS_CHILD or WS_BORDER or WS_VISIBLE or \ 
              CBS_HASSTRINGS or CBS_DROPDOWNLIST or WS_VSCROLL,
              a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

ComboBox endp

; #########################################################################
