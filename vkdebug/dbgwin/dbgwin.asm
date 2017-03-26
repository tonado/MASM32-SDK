;The program is written by vkim
;vkim@aport2000.ru
;-----------------------------------------------------------------------------
;WinMain procedure based on Iczelion's code
;-----------------------------------------------------------------------------
;Some bugs are fixed by bitRAKE
;-----------------------------------------------------------------------------

.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\masm32.inc
include \masm32\include\comctl32.inc
include \masm32\include\comdlg32.inc
include Registry.inc
include File.inc
include dbgwin.inc
include \masm32\vkdebug\dbproc\debug.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\comctl32.lib
includelib \masm32\lib\comdlg32.lib
includelib \masm32\vkdebug\dbproc\debug.lib

public hwnd

.data
hEdit           dword 0
hwnd            dword 0
hInstance       dword 0
hTbr            dword 0
dwStyle         dword 0
hAccel          dword 0
align 4
ofn OPENFILENAME <>
tbb TBBUTTON 2 dup (<>)
tbab TBADDBITMAP <>
rtDsk RECT <>
szClassName     byte "DbgWinClass", 0
szWinName       byte "DbgWinName", 0
szTipTop        byte "Topmost", 0
szTipClear      byte "Clear", 0
szTipHelp       byte "Help", 0
szTipSave       byte "Save", 0
szTipOpen       byte "Open", 0
szFilter        byte "DbgWin log files (*.dbw)", 0, "*.dbw", 0, 0
szTitleSave     byte "Save log file as", 0
szTitleOpen     byte "Open log file", 0
szHelpPath      byte "\masm32\help\dbgwin.hlp", 0
szLogExt        byte ".dbw", 0
szPoint         byte ".", 0

.data?
dwCommandLine   dword ?
szInitDir       byte 256 dup(?)
szFileName      byte 256 dup(?)

.code
start:
    invoke GetModuleHandle, NULL
    mov hInstance, eax
    invoke GetCommandLine
    mov dwCommandLine, eax
    invoke InitCommonControls
    invoke WinMain, hInstance, NULL, dwCommandLine, SW_SHOWDEFAULT
    invoke ExitProcess, eax

WndProc proc hWnd: HWND, uMsg: UINT, wParam: WPARAM, lParam: LPARAM
    .if uMsg == WM_DESTROY
        invoke HANDLE_WM_DESTROY, hWnd, wParam, lParam
    .elseif uMsg == WM_SIZE
        invoke  HANDLE_WM_SIZE, hWnd, wParam, lParam
    .elseif uMsg == WM_CREATE
        invoke HANDLE_WM_CREATE, hWnd, wParam, lParam
    .elseif uMsg == WM_INITDIALOG
        invoke HANDLE_WM_INITDIALOG, hWnd, wParam, lParam
    .elseif uMsg == WM_COMMAND
        invoke HANDLE_WM_COMMAND, hWnd, wParam, lParam
    .elseif uMsg == WM_NOTIFY ;trap message for tooltips
        invoke HANDLE_WM_NOTIFY, hWnd, wParam, lParam
    .else
        invoke DefWindowProc, hWnd, uMsg, wParam, lParam
        jmp ext
    .endif
    xor eax, eax
ext:
    ret
WndProc endp

WinMain proc hInst: dword, hPrevInst: dword, CommandLine: dword, CmdShow: dword
    local wc: WNDCLASSEX
    local msg: MSG
    mov wc.cbSize, sizeof WNDCLASSEX
    mov wc.style, CS_HREDRAW or CS_VREDRAW
    mov wc.lpfnWndProc, offset WndProc
    mov wc.cbClsExtra, NULL
    mov wc.cbWndExtra, DLGWINDOWEXTRA
    push hInst
    pop wc.hInstance
    mov wc.hbrBackground, COLOR_BTNFACE + 1
    mov wc.lpszMenuName, NULL
    mov wc.lpszClassName, offset szClassName
    invoke LoadIcon, hInstance, 1
    mov wc.hIcon, eax
    invoke LoadCursor, NULL, IDC_ARROW
    mov wc.hCursor, eax
    mov wc.hIconSm, NULL
    invoke RegisterClassEx, addr wc
    invoke CreateDialogParam, hInstance, addr szWinName, NULL, addr WndProc, NULL
    mov hwnd, eax
    invoke LoadAccelerators, hInst, CTEXT("HOTKEYS")
    mov hAccel, eax
    .while TRUE
        invoke GetMessage, addr msg, NULL, 0, 0
        .break .if (!eax)
        invoke TranslateAccelerator, hwnd, hAccel, addr msg
        .if eax == FALSE
            invoke IsDialogMessage, hwnd, addr msg
            .if eax == FALSE
                invoke TranslateMessage, addr msg
                invoke DispatchMessage, addr msg
            .endif
        .endif
    .endw
    mov eax, msg.wParam
    ret
WinMain endp

HANDLE_WM_INITDIALOG proc hWnd: dword, wParam: dword, lParam: dword
    local rt: RECT
    local top: dword
    local left: dword
    local wth: dword
    local hgt: dword
    local state: dword
    ;get settings - position and state (topmost or not topmost)
    invoke GetRegDword, HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("top"),
        addr top
    .if eax != ERROR_SUCCESS ;if err then set default
        mov top, 0
    .endif
    invoke GetRegDword, HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("left"),
        addr left
    .if eax != ERROR_SUCCESS
        mov left, 0
    .endif
    invoke GetRegDword, HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("width"),
        addr wth
    .if eax != ERROR_SUCCESS
        mov wth, DEFAULT_WIDTH
    .endif
    invoke GetRegDword, HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("height"),
        addr hgt
    .if eax != ERROR_SUCCESS
        mov hgt, DEFAULT_HEIGHT
    .endif
    invoke GetRegString, addr szInitDir,
        HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("init_dir")
    invoke GetRegDword, HKEY_LOCAL_MACHINE,
        CTEXT("Software\MASM32\DbgWin\"),
        CTEXT("state"),
        addr state
    .if eax != ERROR_SUCCESS
        mov state, PIN_ON
    .endif
    .if state == PIN_ON ; if a button must be checked
        invoke SetWindowPos, hWnd, HWND_TOPMOST, 0, 0, 0, 0, 3
    .else
        invoke SetWindowPos, hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, 3
    .endif
    invoke PostMessage, hTbr, TB_SETSTATE, TB_PIN, state ;check button

    invoke GetDesktopWindow
    invoke GetWindowRect, eax, addr rtDsk
    invoke PtInRect, addr rtDsk, left, 0
    .if !eax
        mov left, 0
    .endif
    invoke PtInRect, addr rtDsk, 0, top
    .if !eax
        mov top, 0
    .endif
    .if hgt <= TB_HEIGHT
        mov hgt, DEFAULT_HEIGHT
    .endif

    invoke MoveWindow, hWnd, left, top, wth, hgt, TRUE

    ;align edit window
    invoke GetDlgItem, hWnd, DEBUG_EDIT
    mov hEdit, eax

    invoke GetClientRect, hWnd, addr rt
    mov eax, rt.right
    sub eax, rt.left
    mov ebx, eax ;ebx = width
    mov eax, rt.bottom
    sub eax, rt.top
    sub eax, TB_HEIGHT ;eax = height
    invoke MoveWindow, hEdit, 0, TB_HEIGHT, ebx, eax, TRUE
    invoke ShowWindow, hWnd, SW_SHOWNORMAL
    invoke UpdateWindow, hWnd
    ret
HANDLE_WM_INITDIALOG endp

HANDLE_WM_CREATE proc hWnd: dword, wParam: dword, lParam: dword
    ;{open-0}{save-1}{sep}{clear-2}{sep}{help-3}
    ;create toolbar
    mov tbb.iBitmap, 0
    mov tbb.idCommand, TB_OPEN
    mov tbb.fsState, TBSTATE_ENABLED
    mov tbb.fsStyle, TBSTYLE_BUTTON
    mov tbb._wPad1, 0
    mov tbb.dwData, 0
    mov tbb.iString, 0
    invoke CreateToolbarEx, hWnd, WS_CHILD+TBSTYLE_TOOLTIPS+WS_VISIBLE+TBSTYLE_FLAT, 1, 0, hInstance, TB_OPEN, addr tbb, 1, 0, 0, 16, 16, sizeof TBBUTTON
    mov hTbr, eax

    ;add bitmap into the toolbar image list
    m2m tbab.hInst, hInstance
    mov tbab.nID, TB_SAVE
    invoke SendMessage, hTbr, TB_ADDBITMAP, 1, addr tbab
    mov tbb.iBitmap, 1
    mov tbb.idCommand, TB_SAVE
    mov tbb.fsState, 4
    mov tbb.fsStyle, TBSTYLE_BUTTON
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb

    ;add sep button
    mov tbb.iBitmap, 0
    mov tbb.fsStyle, TBSTYLE_SEP
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb

    ;add bitmap into the toolbar image list
    m2m tbab.hInst, hInstance
    mov tbab.nID, TB_CLEAR
    invoke SendMessage, hTbr, TB_ADDBITMAP, 1, addr tbab
    mov tbb.iBitmap, 2
    mov tbb.idCommand, TB_CLEAR
    mov tbb.fsState, 4
    mov tbb.fsStyle, TBSTYLE_BUTTON
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb

    m2m tbab.hInst, hInstance
    mov tbab.nID, TB_PIN
    invoke SendMessage, hTbr, TB_ADDBITMAP, 1, addr tbab
    mov tbb.iBitmap, 3
    mov tbb.idCommand, TB_PIN
    mov tbb.fsState, TBSTATE_ENABLED
    mov tbb.fsStyle, TBSTYLE_CHECK
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb

    ;add sep button
    mov tbb.iBitmap, 0
    mov tbb.fsStyle, TBSTYLE_SEP
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb

    m2m tbab.hInst, hInstance
    mov tbab.nID, TB_HELP
    invoke SendMessage, hTbr, TB_ADDBITMAP, 1, addr tbab
    mov tbb.iBitmap, 4
    mov tbb.idCommand, TB_HELP
    mov tbb.fsState, 4
    mov tbb.fsStyle, TBSTYLE_BUTTON
    invoke SendMessage, hTbr, TB_ADDBUTTONS, 1, addr tbb
    ret
HANDLE_WM_CREATE endp

HANDLE_WM_DESTROY proc hWnd: dword, wParam: dword, lParam: dword
    local rt: RECT
    local wth: dword
    local hgt: dword
    local state: dword
    ;save settings - position and state
    invoke GetWindowRect, hWnd, addr rt
    invoke SetRegDword, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("top"),
            rt.top
    invoke SetRegDword, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("left"),
            rt.left
    mov eax, rt.right
    sub eax, rt.left
    mov wth, eax
    invoke SetRegDword, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("width"),
            wth
    mov eax, rt.bottom
    sub eax, rt.top
    mov hgt, eax
    invoke SetRegDword, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("height"),
            hgt
    invoke SendMessage, hTbr, TB_GETSTATE, TB_PIN, 0
    mov state, eax
    invoke SetRegDword, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("state"),
            state
    invoke SetRegString, HKEY_LOCAL_MACHINE,
            CTEXT("Software\MASM32\DbgWin\"),
            CTEXT("init_dir"),
            offset szInitDir
    ;and terminate window
    invoke PostQuitMessage, NULL
    ret
HANDLE_WM_DESTROY endp

HANDLE_WM_SIZE proc hWnd: dword, wParam: dword, lParam: dword
    ;move the edit and change size of the toolbar
    mov eax, lParam
    push eax
    and eax, 0FFFFh
    mov ebx, eax ;ebx = width
    pop eax
    rol eax, 16
    and eax, 0FFFFh
    sub eax, TB_HEIGHT ; eax = height
    invoke MoveWindow, hEdit, 0, TB_HEIGHT, ebx, eax, TRUE
    invoke SendMessage, hTbr, TB_AUTOSIZE, 0, 0
    ret
HANDLE_WM_SIZE endp

HANDLE_WM_COMMAND proc hWnd: dword, wParam: dword, lParam: dword
    .if lParam
        .if wParam == TB_OPEN
            invoke HANDLE_TB_OPEN, hWnd, wParam, lParam
        .elseif wParam == TB_SAVE
            invoke HANDLE_TB_SAVE, hWnd, wParam, lParam
        .elseif wParam == TB_PIN
            invoke HANDLE_TB_PIN, hWnd, wParam, lParam
        .elseif wParam == TB_CLEAR
            invoke HANDLE_TB_CLEAR, hWnd, wParam, lParam
        .elseif wParam == TB_HELP
            invoke HANDLE_TB_HELP, hWnd, wParam, lParam
        .endif
    .else ;process hot keys
        mov eax, wParam
        .if ax == IDM_SELALL
            invoke SendMessage, hEdit, EM_SETSEL, NULL, -1
        .elseif ax == IDM_HELP
            invoke WinHelp, hEdit, addr szHelpPath, HELP_CONTENTS, 0
        .endif
    .endif
    ret
HANDLE_WM_COMMAND endp

HANDLE_WM_NOTIFY proc hWnd: dword, wParam: dword, lParam: dword
    mov eax,[lParam]
    assume eax: ptr TOOLTIPTEXT
    .if [eax].hdr.code == TTN_NEEDTEXT
        .if [eax].hdr.idFrom == TB_OPEN
            mov [eax].lpszText, offset szTipOpen
        .elseif [eax].hdr.idFrom == TB_SAVE
            mov [eax].lpszText, offset szTipSave
        .elseif [eax].hdr.idFrom == TB_PIN
            mov [eax].lpszText, offset szTipTop
        .elseif [eax].hdr.idFrom == TB_CLEAR
            mov [eax].lpszText, offset szTipClear
        .elseif [eax].hdr.idFrom == TB_HELP
            mov [eax].lpszText, offset szTipHelp
        .endif
    .endif
    assume eax: nothing
    ret
HANDLE_WM_NOTIFY endp

HANDLE_TB_OPEN proc hWnd: dword, wParam: dword, lParam: dword
    local pMem: dword
    mov ofn.lStructSize, sizeof OPENFILENAME
    m2m ofn.hWndOwner, hWnd
    m2m ofn.hInstance, hInstance
    m2m ofn.lpstrFilter,  offset szFilter
    m2m ofn.lpstrFile, offset szFileName
    mov ofn.nMaxFile, sizeof szFileName
    m2m ofn.lpstrTitle, offset szTitleOpen
    m2m ofn.lpstrDefExt, offset szLogExt
    m2m ofn.lpstrInitialDir, offset szInitDir
    mov ofn.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES
    invoke GetOpenFileName, addr ofn
    .if eax
        invoke lstrcpy, addr szInitDir, addr szFileName
        invoke ReadFromFile, addr szFileName
        mov pMem, eax
        .if pMem
            invoke SendMessage, hEdit, WM_SETTEXT, 0, pMem
            invoke GlobalFree, pMem
        .endif
    .endif
    ret
HANDLE_TB_OPEN endp

HANDLE_TB_PIN proc hWnd: dword, wParam: dword, lParam: dword
    invoke SendMessage, hTbr, TB_GETSTATE, TB_PIN, 0
    .if eax == PIN_ON
        invoke SetWindowPos, hWnd, HWND_TOPMOST, 0, 0, 0, 0, 3
    .elseif eax == PIN_OFF
        invoke SetWindowPos, hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, 3
    .endif
    ret
HANDLE_TB_PIN endp

HANDLE_TB_CLEAR proc hWnd: dword, wParam: dword, lParam: dword
    invoke SendMessage, hEdit, WM_SETTEXT, 0, 0
    ret
HANDLE_TB_CLEAR endp

HANDLE_TB_HELP proc hWnd: dword, wParam: dword, lParam: dword
    invoke WinHelp, hWnd, addr szHelpPath, HELP_CONTENTS, 0
    ret
HANDLE_TB_HELP endp

HANDLE_TB_SAVE proc hWnd: dword, wParam: dword, lParam: dword
    local pMem: dword
    mov ofn.lStructSize, sizeof OPENFILENAME
    m2m ofn.lpstrInitialDir, offset szInitDir
    m2m ofn.hWndOwner, hWnd
    m2m ofn.hInstance, hInstance
    m2m ofn.lpstrDefExt, offset szLogExt
    m2m ofn.lpstrFilter, offset szFilter
    m2m ofn.lpstrFile, offset szFileName
    mov ofn.nMaxFile, sizeof szFileName
    m2m ofn.lpstrTitle, offset szTitleSave
    mov ofn.Flags, OFN_EXPLORER or OFN_LONGNAMES
    invoke GetSaveFileName, addr ofn
    .if eax
        invoke SendMessage, hEdit, WM_GETTEXTLENGTH, 0, 0
        inc eax
        push eax
        invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, eax
        mov pMem, eax
        pop eax
        invoke SendMessage, hEdit, WM_GETTEXT, eax, pMem
        invoke InString, 1, addr szFileName, addr szPoint
        .if eax == NULL
            invoke lstrcat, addr szFileName, addr szLogExt
        .endif
        invoke lstrcpy, addr szInitDir, addr szFileName
        invoke SaveAsFile, addr szFileName, pMem
        invoke GlobalFree, pMem
    .endif
    ret
HANDLE_TB_SAVE endp

end start     