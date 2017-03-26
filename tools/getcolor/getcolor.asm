; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい
;                               Build this project with MAKEIT.BAT
; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    include \masm32\include\masm32rt.inc                    ; include the MASM32 runtime library

; --------------------------------------------------------------------------------------------------
;   If you are writing code for legacy hardware, comment out the following processor directives
; --------------------------------------------------------------------------------------------------

    .686p                                                   ; 686 privileged instructions
    .MMX                                                    ; multimedia extensions
    .XMM                                                    ; extended multimedia extensions

    include getcolor.inc

    .data?
      flag dd ?
      crefcolr dd ?
      pt POINT <>

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .code                                                   ; start the code section of the application

start:                                                      ; the application entry point

    hInstance cgv(GetModuleHandle, NULL)                    ; create GLOBAL instance handle
    hCursor cgv(LoadCursor,hInstance,200)
    mov flag, 0
    mov crefcolr, 00000000h                                 ; initial display rectangle is black

    invoke DialogBoxParam,hInstance,1000,0,ADDR WndProc,0   ; Call the dialog box from the resource file

    invoke ExitProcess,eax                                  ; terminate the current running process

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

WndProc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    LOCAL sDC   :DWORD
    LOCAL hDC   :DWORD
    LOCAL pbuf  :DWORD
    LOCAL hBrush:DWORD
    LOCAL hOld  :DWORD
    LOCAL rct   :RECT
    LOCAL buffer[32]:BYTE

    switch uMsg
      case WM_INITDIALOG
        GLOBAL hWnd dd ?                                    ; create a GLOBAL handle for the main window
        m2m hWnd, hWin                                      ; Copy hWin to GLOBAL variable
        fn SendMessage,hWin,WM_SETTEXT,0,"Get RGB Color"    ; overwrite dialog original if necessary
        invoke SendMessage,hWin,WM_SETICON,1,rv(LoadIcon,hInstance,500)

        hButton1 cgv(GetDlgItem,hWin,1001)
        hButton2 cgv(GetDlgItem,hWin,1002)

        hEdit1 cgv(GetDlgItem,hWin,1003)
        hEdit2 cgv(GetDlgItem,hWin,1004)
        hEdit3 cgv(GetDlgItem,hWin,1005)

        hButton3 cgv(GetDlgItem,hWin,1006)
        hButton4 cgv(GetDlgItem,hWin,1007)
        hButton5 cgv(GetDlgItem,hWin,1008)
        hStatic1 cgv(GetDlgItem,hWin,1009)
        hStatic2 cgv(GetDlgItem,hWin,1010)
        hStatic3 cgv(GetDlgItem,hWin,1011)
        hButton6 cgv(GetDlgItem,hWin,1012)

        return 1

      case WM_LBUTTONDOWN
          invoke SetCapture,hWnd
          invoke SetCursor,hCursor
          mov flag, 1

      case WM_LBUTTONUP
        .if flag == 1
          invoke ReleaseCapture
          mov flag, 0

        showit:
          invoke GetDC,NULL ; get screen DC
          mov sDC, eax
          invoke GetPixel,sDC,pt.x,pt.y
          mov crefcolr, eax
          invoke ReleaseDC,NULL,sDC

          mov pbuf, ptr$(buffer)
          fn szCatStr,pbuf,uhex$(crefcolr)
          fn szCatStr,pbuf,"h"
          fn SetWindowText,hEdit1,pbuf

          mov pbuf, ptr$(buffer)
          fn szCatStr,pbuf,"&H"
          fn szCatStr,pbuf,uhex$(crefcolr)
          fn SetWindowText,hEdit2,pbuf

          mov pbuf, ptr$(buffer)
          fn szCatStr,pbuf,"0x"
          fn szCatStr,pbuf,uhex$(crefcolr)
          fn SetWindowText,hEdit3,pbuf

        showrct:
          mov hDC, rv(GetDC,hWin)
          mov hBrush, rv(CreateSolidBrush,crefcolr)
          mov hOld, rv(SelectObject,hDC,hBrush)
          invoke GetClientRect,hWin,ADDR rct
          invoke Rectangle,hDC,0,0,rct.right,30
          fn SelectObject,hDC,hOld
          invoke DeleteObject,hBrush
          invoke ReleaseDC,hWin,hDC

        .endif

      case WM_PAINT
        jmp showrct

      case WM_MOUSEMOVE
        .if flag == 1
          mov eax, lParam
          movsx ecx, ax                                 ; sign extend AX into ECX
          mov pt.x, ecx                                 ; copy ECX to POINT x co-ordinate
          rol eax, 16                                   ; rotate EAX by 16 bits
          movsx ecx, ax                                 ; sign extend AX into ECX
          mov pt.y, ecx                                 ; copy ECX to POINT y co-ordinate
          invoke ClientToScreen,hWnd,ADDR pt            ; convert it to screen co-ordinates
          jmp showit                                    ; jump to rectange display code
        .endif

      case WM_COMMAND
        switch wParam
          case 1006     ; Button3
            invoke SendMessage,hEdit1,EM_SETSEL,0,-1
            invoke SendMessage,hEdit1,WM_COPY,0,0
            invoke SendMessage,hEdit1,EM_SETSEL,-1,0

          case 1007     ; Button4
            invoke SendMessage,hEdit2,EM_SETSEL,0,-1
            invoke SendMessage,hEdit2,WM_COPY,0,0
            invoke SendMessage,hEdit2,EM_SETSEL,-1,0

          case 1008     ; Button5
            invoke SendMessage,hEdit3,EM_SETSEL,0,-1
            invoke SendMessage,hEdit3,WM_COPY,0,0
            invoke SendMessage,hEdit3,EM_SETSEL,-1,0

          case 1012     ; Button6
            jmp exit_dialog

        endsw

      case WM_CLOSE
        exit_dialog:                                        ; jump to this label to close program
        invoke EndDialog,hWin,0

    endsw

    return 0

WndProc endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end start                                                   ; tell MASM where the application end is.

