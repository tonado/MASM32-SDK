; ########################################################################

ListBox proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

; ListBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
; invoke ListBox,20,90,150,200,hWnd,600

    szText lstBox,"LISTBOX"

    invoke CreateWindowEx,WS_EX_CLIENTEDGE,ADDR lstBox,0,
              WS_VSCROLL or WS_VISIBLE or \
              WS_BORDER or WS_CHILD or \
              LBS_HASSTRINGS or LBS_NOINTEGRALHEIGHT or \
              LBS_DISABLENOSCROLL,
              a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

ListBox endp

; #########################################################################
