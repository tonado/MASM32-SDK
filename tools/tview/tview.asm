; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
    ReEntryPoint PROTO STDCALL
    include \masm32\include\masm32rt.inc
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      WndProc          PROTO :DWORD,:DWORD,:DWORD,:DWORD
      TopXY            PROTO :DWORD,:DWORD
      RegisterWinClass PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
      MsgLoop          PROTO
      Main             PROTO
      Select_All       PROTO :DWORD
      ReEntryPoint     PROTO

      AutoScale MACRO swidth, sheight
        invoke GetPercent,sWid,swidth
        mov Wwd, eax
        invoke GetPercent,sHgt,sheight
        mov Wht, eax

        invoke TopXY,Wwd,sWid
        mov Wtx, eax

        invoke TopXY,Wht,sHgt
        mov Wty, eax
      ENDM

      DisplayWindow MACRO handl, ShowStyle
        invoke ShowWindow,handl, ShowStyle
        invoke UpdateWindow,handl
      ENDM

    .data?
      hInstance dd ?
      CommandLine dd ?
      hIcon dd ?
      hCursor dd ?
      sWid dd ?
      sHgt dd ?
      hWnd dd ?
      hEdit dd ?

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ReEntryPoint proc    ;; <<<< This is the entry point

    ; ------------------
    ; set global values
    ; ------------------
      mov hInstance,   FUNC(GetModuleHandle, NULL)
      mov hIcon,       FUNC(LoadIcon,NULL,IDI_APPLICATION)
      mov hCursor,     FUNC(LoadCursor,NULL,IDC_ARROW)
      mov sWid,        FUNC(GetSystemMetrics,SM_CXSCREEN)
      mov sHgt,        FUNC(GetSystemMetrics,SM_CYSCREEN)

      call Main

      invoke ExitProcess,eax

ReEntryPoint endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

Main proc

    LOCAL Wwd:DWORD,Wht:DWORD,Wtx:DWORD,Wty:DWORD
    LOCAL ptxt:DWORD
    LOCAL tbuff[260]:BYTE

    STRING szClassName,"vu_text_class"
    invoke RegisterWinClass,ADDR WndProc,ADDR szClassName,
                       hIcon,hCursor,NULL


    invoke GetPercent,sWid,80
    mov Wwd, eax
    invoke GetPercent,sHgt,70
    mov Wht, eax

    mov eax, Wht
    invoke IntDiv,Wht,3

    add eax, Wht

    .if Wwd > eax
      mov Wwd, eax      ; limit the aspect ratio on wide screens to 1.3
    .endif

    invoke TopXY,Wwd,sWid
    mov Wtx, eax

    invoke TopXY,Wht,sHgt
    mov Wty, eax

    invoke CreateWindowEx,WS_EX_LEFT or WS_EX_ACCEPTFILES,
                          ADDR szClassName,
                          chr$("Text View...  F1 to copy, ESC to exit"),
                          WS_OVERLAPPEDWINDOW,
                          Wtx,Wty,Wwd,Wht,
                          NULL,NULL,
                          hInstance,NULL
    mov hWnd,eax

    mov ptxt, ptr$(tbuff)
    invoke GetCL,1,ptxt
    cmp eax, 1
    jne nxt
    invoke Read_File_In,hEdit,ptxt
    ;;;; invoke SetWindowText,hWnd,ptxt
  nxt:

    DisplayWindow hWnd,SW_SHOWNORMAL

    call MsgLoop
    ret

Main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

RegisterWinClass proc lpWndProc:DWORD, lpClassName:DWORD,
                      Icon:DWORD, Cursor:DWORD, bColor:DWORD

    LOCAL wc:WNDCLASSEX

    mov wc.cbSize,         sizeof WNDCLASSEX
    mov wc.style,          CS_BYTEALIGNCLIENT or \
                           CS_BYTEALIGNWINDOW
    m2m wc.lpfnWndProc,    lpWndProc
    mov wc.cbClsExtra,     NULL
    mov wc.cbWndExtra,     NULL
    m2m wc.hInstance,      hInstance
    m2m wc.hbrBackground,  bColor
    mov wc.lpszMenuName,   NULL
    m2m wc.lpszClassName,  lpClassName
    m2m wc.hIcon,          Icon
    m2m wc.hCursor,        Cursor
    m2m wc.hIconSm,        Icon

    invoke RegisterClassEx, ADDR wc

    ret

RegisterWinClass endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

MsgLoop proc

    LOCAL rval  :DWORD
    LOCAL msg   :MSG

    StartLoop:
      invoke GetMessage,ADDR msg,NULL,0,0
      test eax, eax
      je ExitLoop

      Switch msg.message
        Case WM_KEYDOWN
          Switch msg.wParam
            Case VK_ESCAPE
              invoke SendMessage,hWnd,WM_SYSCOMMAND,SC_CLOSE,NULL
            Case VK_F1
              invoke Select_All,hEdit
              invoke SendMessage,hEdit,WM_COPY,0,0
          Endsw
          @@:
      Endsw
      invoke TranslateMessage, ADDR msg
      invoke DispatchMessage,  ADDR msg
      jmp StartLoop
    ExitLoop:

    mov eax, msg.wParam
    ret

MsgLoop endp

; ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд

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

; ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд



WndProc proc hWin   :DWORD,
             uMsg   :DWORD,
             wParam :DWORD,
             lParam :DWORD

    LOCAL fname  :DWORD
    LOCAL patn   :DWORD
    LOCAL Rct    :RECT
    LOCAL buffer[MAX_PATH]:BYTE

    Switch uMsg
      Case WM_COMMAND

      Case WM_SETFOCUS
        invoke SetFocus,hEdit

      Case WM_CREATE
        fn LoadLibrary,"RICHED32.DLL"
        mov hEdit, FUNC(RichEd1,0,0,100,100,hWin,hInstance,555,0)
        invoke SendMessage,hEdit,WM_SETFONT,FUNC(GetStockObject,ANSI_FIXED_FONT),0
        invoke SendMessage,hEdit,EM_EXLIMITTEXT,0,500000000
        invoke SendMessage,hEdit,EM_SETOPTIONS,ECOOP_XOR,ECO_SELECTIONBAR
        invoke SendMessage,hEdit,WM_SETFONT,rv(GetStockObject,SYSTEM_FIXED_FONT),TRUE

      Case WM_SIZE
        invoke GetClientRect,hWin,ADDR Rct
        invoke MoveWindow,hEdit,0,0,Rct.right,Rct.bottom,TRUE

      Case WM_DESTROY
        invoke PostQuitMessage,NULL
        return 0

    Endsw

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

WndProc endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

TopXY proc wDim:DWORD, sDim:DWORD

    shr sDim, 1      ; divide screen dimension by 2
    shr wDim, 1      ; divide window dimension by 2
    mov eax, wDim    ; copy window dimension into eax
    sub sDim, eax    ; sub half win dimension from half screen dimension

    return sDim

TopXY endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end ReEntryPoint
