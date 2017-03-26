; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .686p                       ; create 32 bit code
    .mmx                        ; enable MMX instructions
    .xmm                        ; enable SSE instructions
    .model flat, stdcall        ; 32 bit memory model
    option casemap :none        ; case sensitive

  ; -------------------------------------------------------------
  ; equates for controlling the toolbar button size and placement
  ; -------------------------------------------------------------
    rbht     equ <44>           ; rebar height in pixels
    tbbW     equ <32>           ; toolbar button width in pixels
    tbbH     equ <32>           ; toolbar button height in pixels
    vpad     equ <12>           ; vertical button padding in pixels
    hpad     equ <12>           ; horizontal button padding in pixels
    lind     equ  <5>           ; left side initial indent in pixels

    bColor   equ  <00999999h>   ; client area brush colour

    include fda32.inc           ; local includes for this file

    include \masm32\include\ole32.inc
    includelib \masm32\lib\ole32.lib

    ComboBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    Static   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    Staticr  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    Editml   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    BrowseForFolder_ex     PROTO :DWORD,:DWORD,:DWORD,:DWORD
    cbBrowse_ex            PROTO :DWORD,:DWORD,:DWORD,:DWORD
    write_obj PROTO

    .data?
      hCombo dd ?
      hLbl1  dd ?
      hLbl2  dd ?
      hLbl3  dd ?
      hLbl4  dd ?
      hLbl5  dd ?
      hEdit1 dd ?
      hEdit2 dd ?
      hBrush dd ?

      hRslt1 dd ?
      hRslt2 dd ?
      hRslt3 dd ?
      hRslt4 dd ?

      srcbuf db 260 dup (?)

    .data
      psrcbuf dd srcbuf

.code

start:

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

  ; ------------------
  ; set global values
  ; ------------------
    mov hInstance,   rv(GetModuleHandle, NULL)
    mov CommandLine, rv(GetCommandLine)
    mov hIcon,       rv(LoadIcon,hInstance,500)
    mov hCursor,     rv(LoadCursor,NULL,IDC_ARROW)
    mov sWid,        rv(GetSystemMetrics,SM_CXSCREEN)
    mov sHgt,        rv(GetSystemMetrics,SM_CYSCREEN)

  ; -------------------------------------------------
  ; load the toolbar button strip at its default size
  ; -------------------------------------------------
    invoke LoadImage,hInstance,700,IMAGE_BITMAP,0,0, \
           LR_DEFAULTSIZE or LR_LOADTRANSPARENT or LR_LOADMAP3DCOLORS
    mov hBitmap, eax

  ; ----------------------------------------------------------------
  ; load the rebar background tile stretching it to the rebar height
  ; ----------------------------------------------------------------
    mov tbTile, rv(LoadImage,hInstance,800,IMAGE_BITMAP,sWid,rbht,LR_DEFAULTCOLOR)

    call Main

    invoke ExitProcess,eax

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

Main proc

    LOCAL Wwd:DWORD,Wht:DWORD,Wtx:DWORD,Wty:DWORD
    LOCAL wc:WNDCLASSEX,icce:INITCOMMONCONTROLSEX

  ; --------------------------------------
  ; comment out the styles you don't need.
  ; --------------------------------------
    mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX            ; set the structure size
    xor eax, eax                                            ; set EAX to zero
    or eax, ICC_ANIMATE_CLASS                               ; OR as many styles as you need to it
    or eax, ICC_BAR_CLASSES                                 ; comment out the rest
    or eax, ICC_COOL_CLASSES
    or eax, ICC_DATE_CLASSES
    or eax, ICC_HOTKEY_CLASS
    or eax, ICC_INTERNET_CLASSES
    or eax, ICC_LISTVIEW_CLASSES
    or eax, ICC_PAGESCROLLER_CLASS
    or eax, ICC_PROGRESS_CLASS
    or eax, ICC_TAB_CLASSES
    or eax, ICC_TREEVIEW_CLASSES
    or eax, ICC_UPDOWN_CLASS
    or eax, ICC_USEREX_CLASSES
    or eax, ICC_WIN95_CLASSES
    mov icce.dwICC, eax
    invoke InitCommonControlsEx,ADDR icce                   ; initialise the common control library
  ; --------------------------------------

    STRING szClassName,   "fda3_Class"
    STRING szDisplayName, "Assemble File As Object Module"

    ;;;; mov hBrush, rv(CreateSolidBrush,bColor)

  ; ---------------------------------------------------
  ; set window class attributes in WNDCLASSEX structure
  ; ---------------------------------------------------
    mov wc.cbSize,         sizeof WNDCLASSEX
    mov wc.style,          CS_BYTEALIGNCLIENT or CS_BYTEALIGNWINDOW
    m2m wc.lpfnWndProc,    OFFSET WndProc
    mov wc.cbClsExtra,     NULL
    mov wc.cbWndExtra,     NULL
    m2m wc.hInstance,      hInstance
    m2m wc.hbrBackground,  COLOR_BTNFACE+1
    mov wc.lpszMenuName,   NULL
    mov wc.lpszClassName,  OFFSET szClassName
    m2m wc.hIcon,          hIcon
    m2m wc.hCursor,        hCursor
    m2m wc.hIconSm,        hIcon

  ; ------------------------------------
  ; register class with these attributes
  ; ------------------------------------
    invoke RegisterClassEx, ADDR wc

    mov Wwd, 400
    mov Wht, 330

  ; ------------------------------------------------
  ; Top X and Y co-ordinates for the centered window
  ; ------------------------------------------------
    mov eax, sWid
    sub eax, Wwd                ; sub window width from screen width
    shr eax, 1                  ; divide it by 2
    mov Wtx, eax                ; copy it to variable

    mov eax, sHgt
    sub eax, Wht                ; sub window height from screen height
    shr eax, 1                  ; divide it by 2
    mov Wty, eax                ; copy it to variable

  ; -----------------------------------------------------------------
  ; create the main window with the size and attributes defined above
  ; -----------------------------------------------------------------
    invoke CreateWindowEx,WS_EX_LEFT or WS_EX_ACCEPTFILES,
                          ADDR szClassName,
                          ADDR szDisplayName,
                          WS_OVERLAPPED or WS_SYSMENU,
                          Wtx,Wty,Wwd,Wht,
                          NULL,NULL,
                          hInstance,NULL
    mov hWnd,eax

    invoke SendMessage,hToolBar,TB_ENABLEBUTTON,51,FALSE
    invoke SendMessage,hToolBar,TB_ENABLEBUTTON,52,FALSE

    invoke ShowWindow,hWnd, SW_SHOWNORMAL
    invoke UpdateWindow,hWnd

    call MsgLoop
    ret

Main endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

MsgLoop proc

    LOCAL msg:MSG

    push ebx
    lea ebx, msg
    invoke GetMessage,ebx,0,0,0

  msgloop:
    invoke TranslateMessage, ebx
    invoke DispatchMessage,  ebx
    invoke GetMessage,ebx,0,0,0
    test eax, eax
    jnz msgloop

    pop ebx
    ret

MsgLoop endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

WndProc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    LOCAL var    :DWORD
    LOCAL caW    :DWORD
    LOCAL caH    :DWORD
    LOCAL fname  :DWORD
    LOCAL opatn  :DWORD
    LOCAL spatn  :DWORD
    LOCAL rct    :RECT
    LOCAL buffer1[260]:BYTE  ; these are two spare buffers
    LOCAL buffer2[260]:BYTE  ; for text manipulation etc..
    LOCAL pbuf   :DWORD

    Switch uMsg
      Case WM_COMMAND
      ; -------------------------------------------------------------------
        Switch wParam
          case 50
            invoke SetWindowText,hRslt1,0
            invoke SetWindowText,hRslt2,0
            invoke SetWindowText,hRslt3,0
            invoke SetWindowText,hRslt4,0

            sas opatn, "All files",0,"*.*",0
            mov fname, rv(open_file_dialog,hWin,hInstance,"Open Source File",opatn)
            cmp BYTE PTR [eax], 0
            jne @F
            return 0
            @@:

            mov pbuf, ptr$(buffer1)             ; get pointer to buffer
            invoke NameFromPath,fname,pbuf      ; extract bare file name from full path
            fn szRep,pbuf,pbuf,".","_"          ; replace periods with underscores
            fn szRep,pbuf,pbuf," ","_"          ; replace spaces with underscores
            fn SetWindowText,hEdit2,pbuf        ; write the bare name to the LABEL text box
            mov pbuf, cat$(pbuf,".obj")         ; append the OBJ extension to the name
            fn SetWindowText,hEdit1,pbuf        ; write it to the MODULE name text box
            cst psrcbuf, fname                  ; copy file name into GLOBAL buffer

            invoke SendMessage,hToolBar,TB_ENABLEBUTTON,51,TRUE

          case 51
            invoke SetWindowText,hRslt1,0
            invoke SetWindowText,hRslt2,0
            invoke SetWindowText,hRslt3,0
            invoke SetWindowText,hRslt4,0

            mov pbuf, ptr$(buffer1)
            fn BrowseForFolder_ex,hWin,pbuf,"Select Target Folder","This is where the OBJ module will be written."
            test eax, eax
            jnz @F
            ret
          @@:

            invoke SetWindowText,hLbl3,pbuf
            invoke SendMessage,hToolBar,TB_ENABLEBUTTON,52,TRUE
            chdir pbuf

          case 52
            invoke write_obj

          case 53
            jmp app_about

          case 54
            jmp app_close

          case 1090
          app_close:
            invoke SendMessage,hWin,WM_SYSCOMMAND,SC_CLOSE,NULL

          case 10000
          app_about:
            invoke DialogBoxParam,hInstance,5000,hWin,ADDR AboutProc,0

        Endsw
      ; -------------------------------------------------------------------

      case WM_DROPFILES
      ; --------------------------
      ; process dropped files here
      ; --------------------------
        mov fname, DropFileName(wParam)
        fn MsgboxI,hWin,fname,"WM_DROPFILES",MB_OK,500
        return 0

      case WM_CREATE
        mov hRebar,   rv(rebar,hInstance,hWin,rbht)     ; create the rebar control
        mov hToolBar, rv(addband,hInstance,hRebar)      ; add the toolbar band to it
        mov hStatus,  rv(StatusBar,hWin)                ; create the status bar


        mov hLbl1, rv(Staticr,"Data Alignment",hWin,15,60,80,20,500)
        fn SendMessage,hLbl1,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hCombo, rv(ComboBox,110,55,60,250,hWin,699)
        fn SendMessage,hCombo,WM_SETFONT,rv(GetStockObject,ANSI_FIXED_FONT),TRUE

        mov hLbl2, rv(Staticr,"Target Folder",hWin,15,90,80,20,501)
        fn SendMessage,hLbl2,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hLbl3, rv(Static,"No Target Set",hWin,110,90,400,20,501)
        fn SendMessage,hLbl3,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hLbl4, rv(Staticr,"Module Name",hWin,15,120,80,20,502)
        fn SendMessage,hLbl4,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hEdit1, rv(Editml,0,110,118,200,18,hWin,700)
        fn SendMessage,hEdit1,WM_SETFONT,rv(GetStockObject,ANSI_FIXED_FONT),TRUE

        mov hLbl5, rv(Staticr,"Label Name",hWin,15,145,80,20,503)
        fn SendMessage,hLbl5,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hEdit2, rv(Editml,0,110,143,200,18,hWin,701)
        fn SendMessage,hEdit2,WM_SETFONT,rv(GetStockObject,ANSI_FIXED_FONT),TRUE

        mov hRslt1, rv(Static,"-",hWin,30,180,400,20,504)
        fn SendMessage,hRslt1,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hRslt2, rv(Static,"-",hWin,30,200,400,20,505)
        fn SendMessage,hRslt2,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hRslt3, rv(Static,"-",hWin,30,220,400,20,506)
        fn SendMessage,hRslt3,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        mov hRslt4, rv(Static,"-",hWin,30,240,400,20,507)
        fn SendMessage,hRslt4,WM_SETFONT,rv(GetStockObject,ANSI_VAR_FONT),TRUE

        fn SendMessage,hCombo,CB_ADDSTRING,0,"1"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"2"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"4"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"8"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"16"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"32"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"64"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"128"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"256"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"512"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"1024"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"2048"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"4096"
        fn SendMessage,hCombo,CB_ADDSTRING,0,"8192"

        invoke SendMessage,hCombo,CB_SETCURSEL,2,0

      case WM_SIZE
        invoke MoveWindow,hStatus,0,0,0,0,TRUE

      case WM_CLOSE
      ; -----------------------------
      ; perform any required cleanups
      ; here before closing.
      ; -----------------------------

      case WM_DESTROY
        invoke PostQuitMessage,NULL
        return 0

    Endsw

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

WndProc endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

TBcreate proc parent:DWORD

  ; ------------------------------
  ; run the toolbar creation macro
  ; ------------------------------
    ToolbarInit tbbW, tbbH, parent

  ; -----------------------------------
  ; Add toolbar buttons and spaces here
  ; arg1 bmpID (zero based)
  ; arg2 cmdID (1st is 50)
  ; -----------------------------------
    TBbutton  0,  50
    TBbutton  1,  51
    TBbutton  2,  52
    TBbutton  3,  53
    TBbutton  4,  54
  ; -----------------------------------

    mov eax, tbhandl

    ret

TBcreate endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

StatusBar proc hParent:DWORD

    LOCAL handl :DWORD
    LOCAL sbParts[1] :DWORD

    mov handl, rv(CreateStatusWindow,WS_CHILD or WS_VISIBLE or SBS_SIZEGRIP,NULL,hParent,200)

  ; --------------------------------------------
  ; set the width of each part, -1 for last part
  ; --------------------------------------------
    mov [sbParts+0], -1

    invoke SendMessage,handl,SB_SETPARTS,1,ADDR sbParts

    mov eax, handl

    ret

StatusBar endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

ComboBox proc a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_CLIENTEDGE or WS_EX_RIGHT,"COMBOBOX",0, \
              WS_CHILD or WS_BORDER or WS_VISIBLE or \ 
              CBS_HASSTRINGS or CBS_DROPDOWNLIST or WS_VSCROLL, \
              a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

ComboBox endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

Static proc lpText:DWORD,hParent:DWORD,
                 a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
            "STATIC",lpText, \
            WS_CHILD or WS_VISIBLE or SS_LEFT, \
            a,b,wd,ht,hParent,ID, \
            hInstance,NULL

    ret

Static endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

Staticr proc lpText:DWORD,hParent:DWORD,
                 a:DWORD,b:DWORD,wd:DWORD,ht:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_LEFT, \
            "STATIC",lpText, \
            WS_CHILD or WS_VISIBLE or SS_RIGHT, \
            a,b,wd,ht,hParent,ID, \
            hInstance,NULL

    ret

Staticr endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

Editml proc szMsg:DWORD,a:DWORD,b:DWORD,
               wd:DWORD,ht:DWORD,hParent:DWORD,ID:DWORD

    fn CreateWindowEx,WS_EX_STATICEDGE,"EDIT",szMsg, \
                WS_VISIBLE or WS_CHILDWINDOW or \
                ES_AUTOHSCROLL or ES_NOHIDESEL or ES_MULTILINE, \
                a,b,wd,ht,hParent,ID,hInstance,NULL

    ret

Editml endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

BrowseForFolder_ex proc hParent:DWORD,lpBuffer:DWORD,lpTitle:DWORD,lpString:DWORD

  ; ------------------------------------------------------
  ; hParent  = parent window handle
  ; lpBuffer = 260 byte buffer to receive path
  ; lpTitle  = zero terminated string with dialog title
  ; lpString = zero terminated string for secondary text
  ; ------------------------------------------------------

    LOCAL lpIDList :DWORD
    LOCAL bi  :BROWSEINFO

    mov eax,                hParent         ; parent handle
    mov bi.hwndOwner,       eax
    mov bi.pidlRoot,        0
    mov bi.pszDisplayName,  0
    mov eax,                lpString        ; secondary text
    mov bi.lpszTitle,       eax
    mov bi.ulFlags,         BIF_RETURNONLYFSDIRS or BIF_DONTGOBELOWDOMAIN or \
                            BIF_NEWDIALOGSTYLE or BIF_EDITBOX
    mov bi.lpfn,            offset cbBrowse_ex
    mov eax,                lpTitle         ; main title
    mov bi.lParam,          eax
    mov bi.iImage,          0

    invoke SHBrowseForFolder,ADDR bi
    mov lpIDList, eax

    .if lpIDList == 0
      mov eax, 0            ; if CANCEL return FALSE
      push eax
      jmp @F
    .else
      invoke SHGetPathFromIDList,lpIDList,lpBuffer
      mov eax, 1            ; if OK, return TRUE
      push eax
      jmp @F
    .endif

    @@:
    invoke CoTaskMemFree,lpIDList

    pop eax
    ret

BrowseForFolder_ex endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

cbBrowse_ex proc hWin:DWORD,uMsg:DWORD,lParam:DWORD,lpData:DWORD

    .if uMsg == BFFM_INITIALIZED
      invoke SendMessage,hWin,BFFM_SETSELECTION,1,CurDir$()
      invoke SetWindowText,hWin,lpData
    .endif

    ret

cbBrowse_ex endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

write_obj proc

    LOCAL pinput        :DWORD              ; 1st argument pointer
    LOCAL poutput       :DWORD              ; 2nd argument pointer
    LOCAL pname         :DWORD              ; 3rd argument pointer
    LOCAL pspare        :DWORD              ; spare buffer pointer
    LOCAL pdata         :DWORD              ; pointer to file data
    LOCAL flen          :DWORD              ; variable for file length
    LOCAL hout          :DWORD              ; output file handle
    LOCAL wcnt          :DWORD
    LOCAL hinc          :DWORD              ; file handle for output include file
    LOCAL pftr          :DWORD
    LOCAL paln          :DWORD
    LOCAL aflag         :DWORD              ; alignment flag
    LOCAL alind         :DWORD              ; variable to hold alignment choice
    LOCAL buffer1[260]  :BYTE               ; source file name buffer
    LOCAL buffer2[260]  :BYTE               ; target file name buffer
    LOCAL buffer3[260]  :BYTE               ; external data item name buffer
    LOCAL buffer4[260]  :BYTE               ; spare buffer
    LOCAL alnbuff[32]   :BYTE               ; buffer for alignment size
    LOCAL ifh           :IMAGE_FILE_HEADER
    LOCAL ish           :IMAGE_SECTION_HEADER
    LOCAL ist           :IMAGE_SYMBOL

    mov pinput,  ptr$(buffer1)              ; cast buffers to pointers
    mov poutput, ptr$(buffer2)
    mov pname,   ptr$(buffer3)
    mov pspare,  ptr$(buffer4)
    mov paln,    ptr$(alnbuff)

  ; ********************
  ; load alignment value
  ; ********************

    invoke SendMessage,hCombo,CB_GETCURSEL,0,0
    mov edx, eax
    invoke SendMessage,hCombo,CB_GETLBTEXT,edx,paln  ; get alignment fom combo box

    ;;;; invoke GetWindowText,hStat1,pinput,260

    cst pinput, psrcbuf                             ; get the input file name

    invoke GetWindowText,hEdit1,poutput,260         ; get the output file name
    invoke GetWindowText,hEdit2,pname,260           ; get the label name

    mov pname, cat$(pspare,"_",pname)               ; prepend leading underscore for
                                                    ; object module internal name
    push paln
    call image_align                        ; call procedure to set alignment flag
    mov aflag, eax

    invoke atodw,paln                       ; convert to integer for later display
    mov alind, eax

    mov pdata, InputFile(pinput)
    mov flen, ecx
    mov hout, fcreate(poutput)

  ; ----------------------------------------------
  ; calculate the start offset of the symbol table
  ; ----------------------------------------------
    mov edx, SIZEOF IMAGE_FILE_HEADER
    add edx, SIZEOF IMAGE_SECTION_HEADER
    add edx, flen

  ; -----------------
  ; IMAGE_FILE_HEADER
  ; -----------------
    mov ifh.Machine,                IMAGE_FILE_MACHINE_I386         ; dw
    mov ifh.NumberOfSections,       1                               ; dw
    mov ifh.TimeDateStamp,          0                               ; dd
    mov ifh.PointerToSymbolTable,   edx                             ; dd
    mov ifh.NumberOfSymbols,        1                               ; dd
    mov ifh.SizeOfOptionalHeader,   0                               ; dw
    mov ifh.Characteristics,        IMAGE_FILE_RELOCS_STRIPPED or \
                                    IMAGE_FILE_LINE_NUMS_STRIPPED   ; dw
  ; --------------------
  ; IMAGE_SECTION_HEADER
  ; --------------------
    lea eax, ish.Name1
    mov DWORD PTR [eax], "tad."     ; write ".data" to Name1 member
    mov DWORD PTR [eax+4], "a"

    mov ish.Misc.PhysicalAddress,   0           ; dd
    mov ish.VirtualAddress,         0           ; dd
    m2m ish.SizeOfRawData,          flen        ; dd

    mov edx, SIZEOF IMAGE_FILE_HEADER
    add edx, SIZEOF IMAGE_SECTION_HEADER
    mov ish.PointerToRawData,       edx         ; dd

    mov ish.PointerToRelocations,   0           ; dd
    mov ish.PointerToLinenumbers,   0           ; dd
    mov ish.NumberOfRelocations,    0           ; dw
    mov ish.NumberOfLinenumbers,    0           ; dw

    mov eax, IMAGE_SCN_CNT_INITIALIZED_DATA or IMAGE_SCN_MEM_READ or IMAGE_SCN_MEM_WRITE
    or eax, aflag
    mov ish.Characteristics, eax                ; dd

  ; -----------------
  ; COFF SYMBOL TABLE
  ; -----------------
    lea eax, ist.N.LongName
    mov DWORD PTR [eax], 0                      ; zero fill 1st 4 bytes
    mov DWORD PTR [eax+4], 4                    ; OFFSET is 4th byte into the string table

    mov ist.Value, 0
    mov ist.SectionNumber, 1
    mov ist.Type1, 0
    mov ist.StorageClass, IMAGE_SYM_CLASS_EXTERNAL
    mov ist.NumberOfAuxSymbols, 0

  ; --------------------
  ; write result to file
  ; --------------------
    mov wcnt, fwrite(hout,ADDR ifh,SIZEOF IMAGE_FILE_HEADER)
    mov wcnt, fwrite(hout,ADDR ish,SIZEOF IMAGE_SECTION_HEADER)
    mov wcnt, fwrite(hout,pdata,flen)           ; write the file data
    mov wcnt, fwrite(hout,ADDR ist,SIZEOF IMAGE_SYMBOL)

  ; ------------
  ; string table
  ; ------------
    mov wcnt, 64
    mov wcnt, fwrite(hout,ADDR wcnt,4)          ; write the table length to 1st DWORD

    mov edx, len(pname)
    mov wcnt, fwrite(hout,pname,edx)            ; write the data label name after it.

    mov edx, len(pname)                         ; length of name
    add edx, 4                                  ; add 4 for 1st DWORD
    mov wcnt, 65
    sub wcnt, edx

    .data
      filler db 128 dup (0)
    .code

    mov wcnt, fwrite(hout,ADDR filler,wcnt)

    fclose hout
    free pdata
    free pftr

  ; ---------------------------------
  ; write the EXTERNDEF statement and
  ; length equate to the include file
  ; ---------------------------------
    mov pspare, ptr$(buffer1)                   ; reuse buffer
    mov pspare, cat$(pspare,"Module file '",poutput,"' written to disk")
    invoke SetWindowText,hRslt4,pspare

    mov poutput, lcase$(poutput)                ; ensure lower case
    mov poutput, remove$(poutput,".obj")        ; strip extension
    mov poutput, cat$(poutput,".inc")           ; add new extension

    mov pinput, ptr$(buffer1)                   ; reuse buffer
    mov pinput, cat$(pinput,"Include file '",poutput,"' written to disk")
    invoke SetWindowText,hRslt3,pinput

    mov hinc, fcreate(poutput)

    fprint hinc,"; -----------------------------------------------------"
    fprint hinc,"; Include the contents of this file in your source file"
    fprint hinc,"; to access the data as an OFFSET and use the equate as"
    fprint hinc,"; the byte count for the file data in the object module"
    fprint hinc,"; -----------------------------------------------------"

    mov edx, len(pname)
    sub edx, 1
    mov pname, right$(pname,edx)

    mov poutput, ptr$(buffer2)
    mov poutput, cat$(poutput,"EXTERNDEF ",pname,":DWORD")
    fprint hinc,poutput

    mov poutput, ptr$(buffer2)
    mov poutput, cat$(poutput,"ln_",pname," equ ",chr$(60),str$(flen),chr$(62))
    fprint hinc, poutput

    fclose hinc

    mov pinput, ptr$(buffer1)                   ; reuse buffer
    mov pinput, cat$(pinput,"Raw data size : ",str$(flen)," bytes")
    invoke SetWindowText,hRslt1,pinput

    mov pinput, ptr$(buffer1)                   ; reuse buffer
    mov pinput, cat$(pinput,"Module written with ",str$(alind)," byte alignment")
    invoke SetWindowText,hRslt2,pinput

  ; -----------------------------------------

    ret

write_obj endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

align 4

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

image_align proc ptxt:DWORD  

    mov eax, [esp+4]

    cmp BYTE PTR [eax+0], "1"
    jne lbl0
    cmp BYTE PTR [eax+1], 0
    jne lbl1
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_1BYTES ; 1
    ret 4
    ; -------------------
  lbl1:
    cmp BYTE PTR [eax+1], "0"
    jne lbl2
    cmp BYTE PTR [eax+2], "2"
    jne notfound
    cmp BYTE PTR [eax+3], "4"
    jne notfound
    cmp BYTE PTR [eax+4], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_1024BYTES ; 1024
    ret 4
    ; -------------------
  lbl2:
    cmp BYTE PTR [eax+1], "2"
    jne lbl3
    cmp BYTE PTR [eax+2], "8"
    jne notfound
    cmp BYTE PTR [eax+3], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_128BYTES ; 128
    ret 4
    ; -------------------
  lbl3:
    cmp BYTE PTR [eax+1], "6"
    jne notfound
    cmp BYTE PTR [eax+2], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_16BYTES ; 16
    ret 4
    ; -------------------
  lbl0:
    cmp BYTE PTR [eax+0], "2"
    jne lbl4
    cmp BYTE PTR [eax+1], 0
    jne lbl5
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_2BYTES ; 2
    ret 4
    ; -------------------
  lbl5:
    cmp BYTE PTR [eax+1], "0"
    jne lbl6
    cmp BYTE PTR [eax+2], "4"
    jne notfound
    cmp BYTE PTR [eax+3], "8"
    jne notfound
    cmp BYTE PTR [eax+4], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_2048BYTES ; 2048
    ret 4
    ; -------------------
  lbl6:
    cmp BYTE PTR [eax+1], "5"
    jne notfound
    cmp BYTE PTR [eax+2], "6"
    jne notfound
    cmp BYTE PTR [eax+3], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_256BYTES ; 256
    ret 4
    ; -------------------
  lbl4:
    cmp BYTE PTR [eax+0], "3"
    jne lbl7
    cmp BYTE PTR [eax+1], "2"
    jne notfound
    cmp BYTE PTR [eax+2], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_32BYTES ; 32
    ret 4
    ; -------------------
  lbl7:
    cmp BYTE PTR [eax+0], "4"
    jne lbl8
    cmp BYTE PTR [eax+1], 0
    jne lbl9
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_4BYTES ; 4
    ret 4
    ; -------------------
  lbl9:
    cmp BYTE PTR [eax+1], "0"
    jne notfound
    cmp BYTE PTR [eax+2], "9"
    jne notfound
    cmp BYTE PTR [eax+3], "6"
    jne notfound
    cmp BYTE PTR [eax+4], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_4096BYTES ; 4096
    ret 4
    ; -------------------
  lbl8:
    cmp BYTE PTR [eax+0], "5"
    jne lbl10
    cmp BYTE PTR [eax+1], "1"
    jne notfound
    cmp BYTE PTR [eax+2], "2"
    jne notfound
    cmp BYTE PTR [eax+3], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_512BYTES ; 512
    ret 4
    ; -------------------
  lbl10:
    cmp BYTE PTR [eax+0], "6"
    jne lbl11
    cmp BYTE PTR [eax+1], "4"
    jne notfound
    cmp BYTE PTR [eax+2], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_64BYTES ; 64
    ret 4
    ; -------------------
  lbl11:
    cmp BYTE PTR [eax+0], "8"
    jne notfound
    cmp BYTE PTR [eax+1], 0
    jne lbl12
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_8BYTES ; 8
    ret 4
    ; -------------------
  lbl12:
    cmp BYTE PTR [eax+1], "1"
    jne notfound
    cmp BYTE PTR [eax+2], "9"
    jne notfound
    cmp BYTE PTR [eax+3], "2"
    jne notfound
    cmp BYTE PTR [eax+4], 0
    jne notfound
    ; -------------------
    mov eax, IMAGE_SCN_ALIGN_8192BYTES ; 8192
    ret 4
    ; -------------------

  notfound:
    xor eax, eax
    ret 4

image_align endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい


end start
