comment * ¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤

    This application simplifies the handling of the 256 check boxes
    by synchronising the ANSI character number with the control ID
    of the check box. To obtain the ANSI character number for each
    control in the common subclass involves no more than subtracting
    the starting control ID (500) from the current control ID to get
    the correct ANSI character number.

    A similar technique is used with the button control "CharButton"
    where the control IDs are set to 1000 + the ANSI character number
    so that the calculation of the ANSI character number is a simple
    task when toggling specific characters.

¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤÷¤ *

      .486                      ; create 32 bit code
      .model flat, stdcall      ; 32 bit memory model
      option casemap :none      ; case sensitive

      include maketbl.inc       ; local includes for this file

.code

start:

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    ; ------------------
    ; set global values
    ; ------------------
      mov hInstance,   FUNC(GetModuleHandle, NULL)
      mov CommandLine, FUNC(GetCommandLine)
      mov hIcon,       FUNC(LoadIcon,NULL,IDI_ASTERISK)
      mov hCursor,     FUNC(LoadCursor,NULL,IDC_ARROW)
      mov sWid,        FUNC(GetSystemMetrics,SM_CXSCREEN)
      mov sHgt,        FUNC(GetSystemMetrics,SM_CYSCREEN)

      call Main

      invoke ExitProcess,eax

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

Main proc

    LOCAL Wwd:DWORD,Wht:DWORD,Wtx:DWORD,Wty:DWORD

    STRING szClassName,"qe_tbl_class"

    invoke RegisterWinClass,ADDR WndProc,ADDR szClassName,
                       hIcon,hCursor,COLOR_BTNFACE+1

    mov Wwd, 560
    mov Wht, 410
    mov Wtx, rv(TopXY,Wwd,sWid)
    mov Wty, rv(TopXY,Wht,sHgt)

    fn CreateWindowEx,WS_EX_LEFT, \
                      ADDR szClassName, \
                      "MASM32 Character Table Tool", \
                      WS_OVERLAPPED or WS_SYSMENU, \
                      Wtx,Wty,Wwd,Wht, \
                      NULL,NULL, \
                      hInstance,NULL
    mov hWnd,eax

    DisplayWindow hWnd,SW_SHOWNORMAL

    call MsgLoop
    ret

Main endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

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

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

MsgLoop proc

    LOCAL msg:MSG

    push esi
    push edi
    xor edi, edi                        ; clear EDI
    lea esi, msg                        ; Structure address in ESI
    jmp jumpin

    StartLoop:
      invoke TranslateMessage, esi
      invoke DispatchMessage,  esi
    jumpin:
      invoke GetMessage,esi,edi,edi,edi
      test eax, eax
      jnz StartLoop

    mov eax, msg.wParam
    pop edi
    pop esi

    ret

MsgLoop endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

WndProc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    LOCAL cnt    :DWORD
    LOCAL lcn    :DWORD
    LOCAL ID     :DWORD
    LOCAL anum   :DWORD
    LOCAL chnum  :DWORD

    Switch uMsg
      Case WM_COMMAND
        switch wParam
          case 400  ; -------------------------------------- toggle numbers
            .if nflag == 0
              mov chnum, BST_CHECKED
            .else
              mov chnum, BST_UNCHECKED
            .endif
            push esi
            mov esi, 548
          @@:
            invoke SendMessage,rv(GetDlgItem,hWin,esi),BM_SETCHECK,chnum,0
            add esi, 1
            cmp esi, 558
            jb @B
            pop esi
            .if nflag == 0
              mov nflag, 1
            .else
              mov nflag, 0
            .endif

          case 401  ; -------------------------------------- toggle upper case
            .if uflag == 0
              mov chnum, BST_CHECKED
            .else
              mov chnum, BST_UNCHECKED
            .endif
            push esi
            mov esi, 565
          @@:
            invoke SendMessage,rv(GetDlgItem,hWin,esi),BM_SETCHECK,chnum,0
            add esi, 1
            cmp esi, 591
            jb @B
            pop esi
            .if uflag == 0
              mov uflag, 1
            .else
              mov uflag, 0
            .endif

          case 402  ; -------------------------------------- toggle lower case
            .if lflag == 0
              mov chnum, BST_CHECKED
            .else
              mov chnum, BST_UNCHECKED
            .endif
            push esi
            mov esi, 597
          @@:
            invoke SendMessage,rv(GetDlgItem,hWin,esi),BM_SETCHECK,chnum,0
            add esi, 1
            cmp esi, 623
            jb @B
            pop esi
            .if lflag == 0
              mov lflag, 1
            .else
              mov lflag, 0
            .endif

          case 403  ; -------------------------------------- toggle high ANSI
            .if hflag == 0
              mov chnum, BST_CHECKED
            .else
              mov chnum, BST_UNCHECKED
            .endif
            push esi
            mov esi, 628
          @@:
            invoke SendMessage,rv(GetDlgItem,hWin,esi),BM_SETCHECK,chnum,0
            add esi, 1
            cmp esi, 756
            jb @B
            pop esi
            .if hflag == 0
              mov hflag, 1
            .else
              mov hflag, 0
            .endif

          case 410  ; -------------------------------------- clear all

            push esi
            mov esi, 755
          @@:
            invoke SendMessage,rv(GetDlgItem,hWin,esi),BM_SETCHECK,BST_UNCHECKED,0
            sub esi, 1
            cmp esi, 500
            jge @B

          ; ---------------------------
          ; reset toggle flags to clear
          ; ---------------------------
            mov nflag, 0
            mov uflag, 0
            mov lflag, 0
            mov hflag, 0

            pop esi

          case 411  ; -------------------------------------- view table

            invoke EnableWindow,hWnd,FALSE      ; disable parent window
            invoke view_win,hWin                ; call the view window

        endsw

      ; ---------------------------------------------
      ; toggle specific characters. range is 0 to 255
      ; ---------------------------------------------
        .if wParam > 999
        .if wParam < 1256

          push esi
          mov esi, 500
          add esi, wParam
          sub esi, 1000
          mov esi, rv(GetDlgItem,hWin,esi)
          .if rv(SendMessage,esi,BM_GETCHECK,0,0) == BST_CHECKED
            invoke SendMessage,esi,BM_SETCHECK,BST_UNCHECKED,0
          .else
            invoke SendMessage,esi,BM_SETCHECK,BST_CHECKED,0
          .endif
          pop esi

        .endif
        .endif
      ; ---------------------------------------------

      Case WM_SYSCOLORCHANGE

      Case WM_SIZE

      Case WM_MOUSEMOVE
        fn SetWindowText,hlbl,"No Character Selected"

      Case WM_CREATE
        mov hlbl, rv(Static,"No Character Selected",hWin,180,20,400,22,65534)
        invoke SendMessage,hlbl,WM_SETFONT,rv(GetStockObject,SYSTEM_FIXED_FONT),0

        fn PushButton,"Toggle Numbers",hWin,15,53,150,27,400
        fn PushButton,"Toggle Upper Case",hWin,15,80,150,27,401
        fn PushButton,"Toggle Lower Case",hWin,15,107,150,27,402
        fn PushButton,"Toggle High ANSI",hWin,15,134,150,27,403

        mov ecx, rv(Static,"Toggle Specifics",hWin,50,168,100,22,65530)
        invoke SendMessage,ecx,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),0

        fn CharButton,"$",hWin,15,190,30,27,1036        ; $ = 36
        fn CharButton,chr$(40),hWin,55,190,30,27,1040   ; ( = 40
        fn CharButton,chr$(41),hWin,95,190,30,27,1041   ; ) = 41
        fn CharButton,".",hWin,135,190,30,27,1046       ; . = 46

        fn CharButton,":",hWin,15,225,30,27,1058        ; : = 58
        fn CharButton,chr$(60),hWin,55,225,30,27,1060   ; < = 60
        fn CharButton,chr$(62),hWin,95,225,30,27,1062   ; > = 62
        fn CharButton,"@",hWin,135,225,30,27,1064       ; @ = 64

        fn CharButton,"[",hWin,15,260,30,27,1091        ; [ = 91
        fn CharButton,"]",hWin,55,260,30,27,1093        ; ] = 93
        fn CharButton,"_",hWin,95,260,30,27,1095        ; _ = 95
        fn CharButton,"~",hWin,135,260,30,27,1126       ; ~ = 126

        fn PushButton,"Clear All",hWin,15,313,150,27,410
        fn PushButton,"View Table",hWin,15,340,150,27,411

      ; -------------------------------
      ; create the table of check boxes
      ; -------------------------------
        mov anum, 15
        mov lcn, 16     ; outer loop counter
        push ebx
        push esi
        push edi
        mov esi, 50     ; starting Y co-ordinate
        mov ebx, 500    ; the first control ID
      outer:
        mov cnt, 16     ; inner loop counter
        mov edi, 180    ; starting X co-ordinate
      inner:
        invoke CheckBox,0,hWin,edi,esi,20,20,ebx
        add ebx, 1      ; increment control ID
        add edi, 20     ; step across 20 pixels
        sub cnt, 1
        jnz inner

        add esi, 3      ; drop static TY by 3 pixels
        fn Static,str$(anum),hWin,510,esi,60,22,65530   ; write the trailing ANSI character number
        sub esi, 3      ; restore ESI                   ; for each line of check boxes
        mov edx, eax
        invoke SendMessage,edx,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),0

        add anum, 16
        add esi, 20     ; step down 20 pixels

        sub lcn, 1
        jnz outer

        pop edi
        pop esi
        pop ebx
      ; -------------------------------

      Case WM_CLOSE

      Case WM_DESTROY
        invoke PostQuitMessage,NULL
        return 0

    Endsw

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

WndProc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

TopXY proc wDim:DWORD, sDim:DWORD

    mov eax, [esp+8]
    sub eax, [esp+4]
    shr eax, 1

    ret 8

TopXY endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

Static proc lpText:DWORD,hParent:DWORD,
                 a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
                      "STATIC",lpText, \
                      WS_CHILD or WS_VISIBLE or SS_LEFT, \
                      a,b,wd,ht,hParent,ID, \
                      hInstance,NULL
    ret

Static endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

PushButton proc lpText:DWORD,hParent:DWORD,
                a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    LOCAL hCtrl :DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
                      "BUTTON",lpText, \
                      WS_CHILD or WS_VISIBLE, \
                      a,b,wd,ht,hParent,ID, \
                      hInstance,NULL
    mov hCtrl, eax
    invoke SendMessage,hCtrl,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),0
    mov eax, hCtrl

    ret

PushButton endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

CharButton proc lpText:DWORD,hParent:DWORD,
                a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    LOCAL hCtrl :DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
                      "BUTTON",lpText, \
                      WS_CHILD or WS_VISIBLE, \
                      a,b,wd,ht,hParent,ID, \
                      hInstance,NULL
    mov hCtrl, eax
    invoke SendMessage,hCtrl,WM_SETFONT,rv(GetStockObject,SYSTEM_FIXED_FONT),0
    mov eax, hCtrl

    ret

CharButton endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

RichEdMl proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_STATICEDGE,"RICHEDIT",0, \
                      WS_VISIBLE or WS_CHILDWINDOW or \
                      ES_MULTILINE or WS_VSCROLL or WS_HSCROLL or \
                      ES_AUTOHSCROLL or ES_AUTOVSCROLL or ES_NOHIDESEL, \
                      a,b,wd,ht,hParent,ID,hInstance,NULL
    ret

RichEdMl endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

CheckBox proc lpText:DWORD,hParent:DWORD,
                a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    LOCAL hCtrl :DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
                      "BUTTON",lpText, \
                      WS_CHILD or WS_VISIBLE or BS_AUTOCHECKBOX, \
                      a,b,wd,ht,hParent,ID, \
                      hInstance,NULL

    mov hCtrl, eax

  ; ---------------------------------------------
  ; subclass even check box to the same procedure
  ; ---------------------------------------------
    invoke SetWindowLong,hCtrl,GWL_WNDPROC,CtrlProc
    mov lpCtrlProc, eax

    mov eax, hCtrl

    ret

CheckBox endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

CtrlProc proc hCtl:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

  ; ---------------------------------------------------
  ; This is a common subclass for all of the checkboxes.
  ; ---------------------------------------------------
    LOCAL ascnum    :DWORD
    LOCAL ptxt      :DWORD
    LOCAL pchar     :DWORD
    LOCAL buffer[256]:BYTE
    LOCAL chars[4]:BYTE

    .if uMsg == WM_MOUSEMOVE
        invoke GetDlgCtrlID,hCtl            ; get the checkbox control ID
        mov ascnum, eax
        sub ascnum, 500                     ; sub 500 to get ANSI number

        mov ptxt, ptr$(buffer)
        mov pchar, ptr$(chars)
        mov edx, pchar
        mov ecx, ascnum                     ; write the ANSI number to a string buffer
        mov BYTE PTR [edx], cl              ; single character
        mov BYTE PTR [edx+1], 0             ; terminator

        .if ascnum < 32
          mov ptxt, cat$(ptxt,"Low  ANSI No. = ",str$(ascnum),". Unprintable Character")
        .elseif ascnum == 32
          mov ptxt, cat$(ptxt,"Low  ANSI No. = ",str$(ascnum),". Low  ANSI Char. = space")
        .elseif ascnum == 38
          mov ptxt, cat$(ptxt,"Low  ANSI No. = ",str$(ascnum),". Low  ANSI Char. = ",pchar,pchar) ; double &&
        .elseif ascnum < 128
          mov ptxt, cat$(ptxt,"Low  ANSI No. = ",str$(ascnum),". Low  ANSI Char. = ",pchar)
        .else
          mov ptxt, cat$(ptxt,"High ANSI No. = ",str$(ascnum),". High ANSI Char. = ",pchar)

        .endif

        fn SetWindowText,hlbl,ptxt

    .endif

    invoke CallWindowProc,lpCtrlProc,hCtl,uMsg,wParam,lParam

    ret

CtrlProc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

ReadChecks proc pmem:DWORD,parent:DWORD

    LOCAL lcnt  :DWORD

    push ebx
    push esi
    push edi

    mov esi, pmem           ; load write buffer into ESI
    xor edi, edi            ; loop count
    mov ebx, 500
    mov lcnt, 0

  ; ---------------------------------------------------------------
  ; write the entire table string in one pass to the address "pmem".
  ; ---------------------------------------------------------------
    mov WORD PTR [esi], "  "
    mov WORD PTR [esi+2], "bd"
    mov BYTE PTR [esi+4], " "
    add esi, 5

  @@:
    invoke SendMessage,rv(GetDlgItem,parent,ebx),BM_GETCHECK,0,0
    add ebx, 1
    add lcnt, 1
    .if eax == BST_CHECKED
      mov BYTE PTR [esi], "1"
      .if lcnt != 16
        mov BYTE PTR [esi+1],","
        add esi, 2
      .else
        mov BYTE PTR [esi+1], 13
        mov BYTE PTR [esi+2], 10
        mov lcnt, 0
        add esi, 3
        mov WORD PTR [esi], "  "
        mov WORD PTR [esi+2], "bd"
        mov BYTE PTR [esi+4], " "
        add esi, 5
      .endif
    .else
      mov BYTE PTR [esi], "0"
      .if lcnt != 16
        mov BYTE PTR [esi+1],","
        add esi, 2
      .else
        mov BYTE PTR [esi+1], 13
        mov BYTE PTR [esi+2], 10
        mov lcnt, 0
        add esi, 3
        mov WORD PTR [esi], "  "
        mov WORD PTR [esi+2], "bd"
        mov BYTE PTR [esi+4], " "
        add esi, 5
      .endif
    .endif
    add edi, 1
    cmp edi, 256
    jne @B

    sub esi, 7
    mov BYTE PTR [esi], 0   ; chop off last 7 bytes

    pop edi
    pop esi
    pop ebx

    ret

ReadChecks endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

view_win proc parent:DWORD

    LOCAL Wwd:DWORD,Wht:DWORD,Wtx:DWORD,Wty:DWORD

    STRING vwClassName,"view_win_class"

    invoke RegisterWinClass,ADDR view_win_proc,ADDR vwClassName,
                       hIcon,hCursor,COLOR_BTNFACE+1

    mov Wwd, 377
    mov Wht, 317
    invoke TopXY,Wwd,sWid
    mov Wtx, eax
    invoke TopXY,Wht,sHgt
    mov Wty, eax

    fn CreateWindowEx,WS_EX_LEFT, \
                      ADDR vwClassName, \
                      "View table", \
                      WS_OVERLAPPED or WS_SYSMENU, \
                      Wtx,Wty,Wwd,Wht, \
                      parent,NULL, \
                      hInstance,NULL
    mov vWnd,eax

    DisplayWindow vWnd,SW_SHOWNORMAL

    ret

view_win endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

view_win_proc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    LOCAL pmem  :DWORD
    LOCAL pbuf  :DWORD
    LOCAL fname :DWORD
    LOCAL cdir  :DWORD
    LOCAL cr    :CHARRANGE
    LOCAL buffer[4096]:BYTE

    switch uMsg
      case WM_COMMAND
        switch wParam
          case 400 ; ---------------------------------------- copy table to clipboard
            invoke GetWindowTextLength,hRichEd
            mov cr.cpMin, 0
            mov cr.cpMax, eax
            invoke SendMessage,hRichEd,EM_EXSETSEL,0,ADDR cr
            invoke SendMessage,hRichEd,WM_COPY,0,0
            invoke SendMessage,hWin,WM_CLOSE,0,0

          case 401 ; ---------------------------------------- write table to file
            .data
              patn db "All files",0,"*.*",0,0
            .code
            mov fname, rv(GetSaveFile,hWin,hInstance,"Save File As ....",ADDR patn)
            cmp BYTE PTR [eax], 0
            jne @F
            ret
          @@:
            mov pbuf, ptr$(buffer)
            invoke GetWindowText,hRichEd,pbuf,4096
            invoke GetWindowTextLength,hRichEd
            test OutputFile(fname,pbuf,eax), eax
            invoke SendMessage,hWin,WM_CLOSE,0,0

          case 402 ; ---------------------------------------- close view window
            invoke SendMessage,hWin,WM_CLOSE,0,0

        endsw

      case WM_CREATE
        szText ReDLL,"RICHED32.DLL"
        invoke LoadLibrary,ADDR ReDLL
        invoke RichEdMl,5,28,362,260,hWin,800
        mov hRichEd, eax

        invoke SendMessage,hRichEd,WM_SETFONT,
                           rv(GetStockObject,SYSTEM_FIXED_FONT),0
        invoke SendMessage,hRichEd,EM_EXLIMITTEXT,0,4000000

        mov pbuf, ptr$(buffer)
        invoke ReadChecks,pbuf,hWnd         ; checks are children of hWnd
        invoke SetWindowText,hRichEd,pbuf

        fn PushButton,"Copy to Clipboard",hWin,5,0,120,27,400
        fn PushButton,"Save To File",hWin,126,0,120,27,401
        fn PushButton,"Close",hWin,247,0,120,27,402

      case WM_CLOSE
        invoke EnableWindow,hWnd,TRUE       ; re-enable the parent window
        invoke SetForegroundWindow,hWnd     ; set it to the forground

    endsw

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

view_win_proc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

align 4

GetSaveFile proc hParent:DWORD,Instance:DWORD,lpTitle:DWORD,lpFilter:DWORD

    LOCAL ofn:OPENFILENAME

    .data?
      savefilebuffer db 260 dup (?)
    .code

    mov eax, OFFSET savefilebuffer
    mov BYTE PTR [eax], 0

  ; --------------------
  ; zero fill structure
  ; --------------------
    push edi
    mov ecx, sizeof OPENFILENAME
    mov al, 0
    lea edi, ofn
    rep stosb
    pop edi

    mov ofn.lStructSize,        sizeof OPENFILENAME
    m2m ofn.hWndOwner,          hParent
    m2m ofn.hInstance,          Instance
    m2m ofn.lpstrFilter,        lpFilter
    m2m ofn.lpstrFile,          offset savefilebuffer
    mov ofn.nMaxFile,           sizeof savefilebuffer
    mov ofn.lpstrInitialDir,    CurDir$()
    m2m ofn.lpstrTitle,         lpTitle
    mov ofn.Flags,              OFN_EXPLORER or OFN_LONGNAMES or \
                                OFN_HIDEREADONLY or OFN_OVERWRITEPROMPT
                                
    invoke GetSaveFileName,ADDR ofn
    mov eax, OFFSET savefilebuffer
    ret

GetSaveFile endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end start
