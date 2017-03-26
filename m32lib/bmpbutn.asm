; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\gdi32.inc
    include \MASM32\INCLUDE\user32.inc
    include \MASM32\INCLUDE\kernel32.inc

    .code

; ########################################################################

BmpButton proc hParent:DWORD,topX:DWORD,topY:DWORD,
                rnum1:DWORD,rnum2:DWORD,ID:DWORD

  ; parameters are,
  ; 1.  Parent handle
  ; 2/3 top X & Y co-ordinates
  ; 4/5 resource ID numbers or identifiers for UP & DOWN bitmaps
  ; 6   ID number for control

    LOCAL hButn1  :DWORD
    LOCAL hImage  :DWORD
    LOCAL hModule :DWORD
    LOCAL wid     :DWORD
    LOCAL hgt     :DWORD
    LOCAL hBmpU   :DWORD
    LOCAL hBmpD   :DWORD
    LOCAL Rct     :RECT
    LOCAL wc      :WNDCLASSEX

    invoke GetModuleHandle,NULL
    mov hModule, eax

    invoke LoadBitmap,hModule,rnum1
    mov hBmpU, eax
    invoke LoadBitmap,hModule,rnum2
    mov hBmpD, eax

    jmp @F
      Bmp_Button_Class db "Bmp_Button_Class",0
    @@:

    mov wc.cbSize,         sizeof WNDCLASSEX
    mov wc.style,          CS_BYTEALIGNWINDOW
    mov wc.lpfnWndProc,    offset BmpButnProc
    mov wc.cbClsExtra,     NULL
    mov wc.cbWndExtra,     16
      push hModule
      pop wc.hInstance
    mov wc.hbrBackground,  COLOR_BTNFACE+1
    mov wc.lpszMenuName,   NULL
    mov wc.lpszClassName,  offset Bmp_Button_Class
    mov wc.hIcon,          NULL
      invoke LoadCursor,NULL,IDC_ARROW
    mov wc.hCursor,        eax
    mov wc.hIconSm,        NULL

    invoke RegisterClassEx, ADDR wc

    invoke CreateWindowEx,WS_EX_TRANSPARENT,
            ADDR Bmp_Button_Class,NULL,
            WS_CHILD or WS_VISIBLE,
            topX,topY,100,100,hParent,ID,
            hModule,NULL

    mov hButn1, eax

    invoke SetWindowLong,hButn1,0,hBmpU
    invoke SetWindowLong,hButn1,4,hBmpD

    jmp @F
    ButnImageClass db "STATIC",0
    @@:

    invoke CreateWindowEx,0,
            ADDR ButnImageClass,NULL,
            WS_CHILD or WS_VISIBLE or SS_BITMAP,
            0,0,0,0,hButn1,ID,
            hModule,NULL

    mov hImage, eax

    invoke SendMessage,hImage,STM_SETIMAGE,IMAGE_BITMAP,hBmpU

    invoke GetWindowRect,hImage,ADDR Rct
    invoke SetWindowLong,hButn1,8,hImage

    mov eax, Rct.bottom
    mov edx, Rct.top
    sub eax, edx
    mov hgt, eax

    mov eax, Rct.right
    mov edx, Rct.left
    sub eax, edx
    mov wid, eax

    invoke SetWindowPos,hButn1,HWND_TOP,0,0,wid,hgt,SWP_NOMOVE

    invoke ShowWindow,hButn1,SW_SHOW

    mov eax, hButn1

    ret

BmpButton endp

; ########################################################################

BmpButnProc proc hWin   :DWORD,
                 uMsg   :DWORD,
                 wParam :DWORD,
                 lParam :DWORD

    LOCAL hBmpU  :DWORD
    LOCAL hBmpD  :DWORD
    LOCAL hImage :DWORD
    LOCAL hParent:DWORD
    LOCAL ID     :DWORD
    LOCAL ptX    :DWORD
    LOCAL ptY    :DWORD
    LOCAL bWid   :DWORD
    LOCAL bHgt   :DWORD
    LOCAL Rct    :RECT

    .data
    cFlag dd 0      ; a GLOBAL variable for the "clicked" setting
    .code

    .if uMsg == WM_LBUTTONDOWN
        invoke GetWindowLong,hWin,4
        mov hBmpD, eax
        invoke GetWindowLong,hWin,8
        mov hImage, eax
        invoke SendMessage,hImage,STM_SETIMAGE,IMAGE_BITMAP,hBmpD
        invoke SetCapture,hWin
        mov cFlag, 1

    .elseif uMsg == WM_LBUTTONUP

        .if cFlag == 0
          ret
        .else
          mov cFlag, 0
        .endif

        invoke GetWindowLong,hWin,0
        mov hBmpU, eax
        invoke GetWindowLong,hWin,8
        mov hImage, eax
        invoke SendMessage,hImage,STM_SETIMAGE,IMAGE_BITMAP,hBmpU

        mov eax, lParam
        cwde
        mov ptX, eax
        mov eax, lParam
        rol eax, 16
        cwde
        mov ptY, eax

        invoke GetWindowRect,hWin,ADDR Rct

        mov eax, Rct.right
        mov edx, Rct.left
        sub eax, edx
        mov bWid, eax

        mov eax, Rct.bottom
        mov edx, Rct.top
        sub eax, edx
        mov bHgt, eax

      ; --------------------------------
      ; exclude button releases outside
      ; of the button rectangle from
      ; sending message back to parent
      ; --------------------------------
        cmp ptX, 0
        jle @F
        cmp ptY, 0
        jle @F
        mov eax, bWid
        cmp ptX, eax
        jge @F
        mov eax, bHgt
        cmp ptY, eax
        jge @F

        invoke GetParent,hWin
        mov hParent, eax
        invoke GetDlgCtrlID,hWin
        mov ID, eax
        invoke SendMessage,hParent,WM_COMMAND,ID,hWin

      @@:

        invoke ReleaseCapture

    .endif

    invoke DefWindowProc,hWin,uMsg,wParam,lParam
    ret

BmpButnProc endp

; ########################################################################

end