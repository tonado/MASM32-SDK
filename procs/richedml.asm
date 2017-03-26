; #########################################################################

RichEdMl proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

; RichEdMl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

    ;szText ReDLL,"RICHED32.DLL"
    ;invoke LoadLibrary,ADDR ReDLL

    ;invoke RichEdMl,200,90,250,200,hWnd,800
    ;mov hRichEd, eax

    ;invoke GetStockObject,OEM_FIXED_FONT
    ;invoke SendMessage,hRichEd,WM_SETFONT,eax,0
    ;invoke SendMessage,hRichEd,EM_EXLIMITTEXT,0,4000000

    szText EditMl,"RICHEDIT"

  invoke CreateWindowEx,0,ADDR EditMl,0,
                WS_VISIBLE or WS_CHILDWINDOW or ES_SUNKEN or \
                ES_MULTILINE or WS_VSCROLL or WS_HSCROLL or \
                ES_AUTOHSCROLL or ES_AUTOVSCROLL or ES_NOHIDESEL,
                a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

RichEdMl endp

; #########################################################################
