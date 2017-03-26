; #########################################################################

    .386
    .model flat, stdcall        ; 32 bit memory model
    option casemap :none        ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc

    RichEd1 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

RichEd1 proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,
             hParent:DWORD,instance:DWORD,ID:DWORD,WRAP:DWORD

    LOCAL wStyle :DWORD
    LOCAL hndl   :DWORD

    jmp @F
    RE1 db "RICHEDIT",0
    @@:

    mov wStyle, WS_VISIBLE or ES_SUNKEN or \
                WS_CHILDWINDOW or WS_CLIPSIBLINGS or \
                ES_MULTILINE or WS_VSCROLL or \
                ES_AUTOVSCROLL or ES_NOHIDESEL

    .if WRAP == 0
      or wStyle, WS_HSCROLL or ES_AUTOHSCROLL
    .endif

    invoke CreateWindowEx,0,ADDR RE1,0,wStyle,
                          a,b,wd,ht,hParent,ID,instance,NULL

    ret

RichEd1 endp

; #########################################################################

end