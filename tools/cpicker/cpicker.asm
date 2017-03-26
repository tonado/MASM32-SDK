; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    include \masm32\include\masm32rt.inc

    WndProc     PROTO :DWORD,:DWORD,:DWORD,:DWORD
    clearbuffer PROTO :DWORD
    ColDialog   PROTO :DWORD,:DWORD,:DWORD,:DWORD

  .data?
    hButn1      dd ?
    hButn2      dd ?
    hButn3      dd ?
    hButn4      dd ?
    hButn5      dd ?
    hButn6      dd ?

    hEdit1      dd ?
    hEdit2      dd ?
    hEdit3      dd ?

    color       dd ?
    hInstance   dd ?
    hIcon       dd ?

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    .code

start:
      mov hInstance, rv(GetModuleHandle, NULL)
      mov color, 00000000h                                  ; start the selected colour at BLACK
      
    ; -------------------------------------------
    ; Call the dialog box stored in resource file
    ; -------------------------------------------
      invoke DialogBoxParam,hInstance,100,0,ADDR WndProc,0

      invoke ExitProcess,eax

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

WndProc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

      LOCAL Ps :PAINTSTRUCT
      LOCAL buffer1[128]:BYTE
      LOCAL buffer2[128]:BYTE

      .if uMsg == WM_INITDIALOG
      
        fn SendMessage,hWin,WM_SETTEXT,0,"COLORREF Color Picker"

        mov hIcon, rv(LoadIcon,hInstance,10)
        invoke SendMessage,hWin,WM_SETICON,1,hIcon

        mov hEdit1, rv(GetDlgItem,hWin,104)
        mov hEdit2, rv(GetDlgItem,hWin,105)
        mov hEdit3, rv(GetDlgItem,hWin,106)

        mov hButn1, rv(GetDlgItem,hWin,101)   ; save asm
        mov hButn2, rv(GetDlgItem,hWin,102)   ; save basic
        mov hButn3, rv(GetDlgItem,hWin,103)   ; save C/C++
        mov hButn4, rv(GetDlgItem,hWin,111)   ; pick colour
        mov hButn5, rv(GetDlgItem,hWin,112)   ; about
        mov hButn6, rv(GetDlgItem,hWin,113)   ; exit

        xor eax, eax
        ret

      .elseif uMsg == WM_COMMAND
        .if wParam == 111
          invoke ColDialog,hWin,hInstance,CC_FULLOPEN or CC_RGBINIT,color
          mov color, eax

          fn clearbuffer, ADDR buffer1
          fn clearbuffer, ADDR buffer2

          fn dw2hex, color, ADDR buffer2
          fn szCatStr,ADDR buffer1,ADDR buffer2
          fn szCatStr,ADDR buffer1,"h"
          fn SetWindowText,hEdit1,ADDR buffer1

          fn clearbuffer, ADDR buffer1
          fn szCatStr,ADDR buffer1,"&H"
          fn szCatStr,ADDR buffer1,ADDR buffer2
          fn SetWindowText,hEdit2,ADDR buffer1

          fn clearbuffer, ADDR buffer1
          fn szCatStr,ADDR buffer1,"0x"
          fn szCatStr,ADDR buffer1,ADDR buffer2
          fn SetWindowText,hEdit3,ADDR buffer1

        .elseif wParam == 112
          .data
            AboutMsg db "COLORREF Color Picker 2.0",13,10,"Copyright © MASM32 2000-2010",0
          .code
          fn ShellAbout,hWin,"COLORREF Color Picker",ADDR AboutMsg,hIcon

        .elseif wParam == 113
          jmp Outa_Here

        .elseif wParam == 101
          invoke SendMessage,hEdit1,EM_SETSEL,0,-1
          invoke SendMessage,hEdit1,WM_COPY,0,0
          invoke SendMessage,hEdit1,EM_SETSEL,-1,0

        .elseif wParam == 102
          invoke SendMessage,hEdit2,EM_SETSEL,0,-1
          invoke SendMessage,hEdit2,WM_COPY,0,0
          invoke SendMessage,hEdit2,EM_SETSEL,-1,0

        .elseif wParam == 103
          invoke SendMessage,hEdit3,EM_SETSEL,0,-1
          invoke SendMessage,hEdit3,WM_COPY,0,0
          invoke SendMessage,hEdit3,EM_SETSEL,-1,0

        .endif

      .elseif uMsg == WM_CLOSE
      Outa_Here:
        invoke EndDialog,hWin,0

      .elseif uMsg == WM_PAINT
        invoke BeginPaint,hWin,ADDR Ps
      ; ----------------------------------------
      ; The following function are in MASM32.LIB
      ; ----------------------------------------
        invoke FrameGrp,hButn4,hButn6,2,1,0
        invoke FrameGrp,hButn4,hButn6,4,1,1
        invoke FrameWindow,hWin,2,1,1
        invoke FrameWindow,hWin,4,1,0

        invoke EndPaint,hWin,ADDR Ps
        xor eax, eax
        ret

      .endif

    xor eax, eax
    ret

WndProc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

clearbuffer proc lpbuffer:DWORD

    push edi

    mov ecx, 32
    xor eax, eax
    mov edi, [esp+8]
    rep stosb

    pop edi

    ret 4

clearbuffer endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

ColDialog proc hWin:DWORD, instance:DWORD, Flags:DWORD, colr:DWORD

    LOCAL ccl:CHOOSECOLOR
    LOCAL crv[16]:DWORD

    push edi

    lea edi, crv[0]
    mov ecx, 16
    mov eax, 0FFFFFFh
    rep stosd

    mov ccl.lStructSize,    sizeof CHOOSECOLOR
    m2m ccl.hwndOwner,      hWin
    m2m ccl.hInstance,      instance
    m2m ccl.rgbResult,      colr
    lea eax,                crv                ; address of 16 item DWORD array
    mov ccl.lpCustColors,   eax
    m2m ccl.Flags,          Flags
    mov ccl.lCustData,      0
    mov ccl.lpfnHook,       0
    mov ccl.lpTemplateName, 0

    invoke ChooseColor,ADDR ccl

    .if eax != 0
      mov eax, ccl.rgbResult
    .endif

    pop edi

    ret

ColDialog endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end start
