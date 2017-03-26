; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486                      ; create 32 bit code
      .model flat, stdcall      ; 32 bit memory model
      option casemap :none      ; case sensitive

;     include files
;     ~~~~~~~~~~~~~
      include \masm32\include\windows.inc
      include \masm32\include\masm32.inc
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\Comctl32.inc
      include \masm32\include\comdlg32.inc
      include \masm32\include\shell32.inc
      include \masm32\include\oleaut32.inc
      include \masm32\include\dialogs.inc
      include \masm32\macros\macros.asm

;     libraries
;     ~~~~~~~~~
      includelib \masm32\lib\masm32.lib
      includelib \masm32\lib\gdi32.lib
      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\Comctl32.lib
      includelib \masm32\lib\comdlg32.lib
      includelib \masm32\lib\shell32.lib
      includelib \masm32\lib\oleaut32.lib

      FUNC MACRO parameters:VARARG
        invoke parameters
        EXITM <eax>
      ENDM


      dlgproc PROTO :DWORD,:DWORD,:DWORD,:DWORD

      MessageBoxSTD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
      MessageBoxCC PROTO C :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
      MessageBoxFC PROTO STDCALL  :DWORD,:DWORD

      includelib dlltute.lib

    .data?
        hInstance dd ?
        hIcon dd ?

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл


start:

      mov hInstance, FUNC(GetModuleHandle,NULL)
      mov hIcon, FUNC(LoadIcon,hInstance,1)

      call main

      invoke ExitProcess,eax

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    Dialog "Test DLLtute.dll", \            ; caption
           "MS Sans Serif",8, \             ; font,pointsize
            WS_OVERLAPPED or \              ; styles for
            WS_SYSMENU or DS_CENTER, \      ; dialog window
            4, \                            ; number of controls
            50,50,150,90, \                 ; x y co-ordinates
            1024                            ; memory buffer size

    DlgButton "Test STDCALL" ,WS_TABSTOP,25,10,80,13,101
    DlgButton "Test C call"  ,WS_TABSTOP,25,25,80,13,102
    DlgButton "Test FASTCALL",WS_TABSTOP,25,40,80,13,103

    DlgButton "Close",WS_TABSTOP,25,55,80,13,IDCANCEL

    CallModalDialog hInstance,0,dlgproc,NULL

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

dlgproc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    .if uMsg == WM_INITDIALOG
      invoke SendMessage,hWin,WM_SETICON,1,
                         FUNC(LoadIcon,hInstance,1)

    .elseif uMsg == WM_COMMAND
      .if wParam == 101

      ; ----------------------------------------------------------------------
      ; this procedure call from the DLL demonstrates the normal STDCALL call
      ; ----------------------------------------------------------------------
        invoke MessageBoxSTD,hWin,SADD("STDCALL Here"),SADD("DLL Tute procedure"),MB_OK,1

      .elseif wParam == 102
      ; ----------------------------------------------------
      ; this procedure call uses the "C" calling convention
      ; ----------------------------------------------------
        invoke MessageBoxCC,hWin,SADD("C call Here"),SADD("DLL Tute procedure"),MB_OK,1

      .elseif wParam == 103
      ; -------------------------------------------------------------------------
      ; this procedure call demonstrates a simulation of the FASTCALL convention
      ; note that 3 registers are used to pass the 1st 3 parameters
      ; -------------------------------------------------------------------------
        mov eax, hWin
        mov ecx, CTXT("FASTCALL Here")
        mov edx, CTXT("DLL Tute procedure")
        invoke MessageBoxFC,MB_OK,1

      .elseif wParam == IDCANCEL
        jmp quit_dialog
      .endif

    .elseif uMsg == WM_CLOSE
      quit_dialog:
      invoke EndDialog,hWin,0

    .endif

    xor eax, eax
    ret

dlgproc endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start
