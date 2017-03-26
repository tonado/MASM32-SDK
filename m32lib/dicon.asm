; #########################################################################

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\gdi32.inc
    include \MASM32\INCLUDE\user32.inc
    include \MASM32\INCLUDE\kernel32.inc

    .data
      stWin db "STATIC",0
    .code

; ########################################################################

DisplayIcon proc hParent:DWORD,bmpID:DWORD,x:DWORD,y:DWORD,ID:DWORD

    LOCAL hModule:DWORD
    LOCAL hIcon  :DWORD
    LOCAL hImage :DWORD

    invoke GetModuleHandle,NULL
    mov hModule, eax

    invoke CreateWindowEx,WS_EX_LEFT,
            ADDR stWin,NULL,
            WS_CHILD or WS_VISIBLE or SS_ICON,
            x,y,10,10,hParent,ID,
            hModule,NULL

    mov hImage, eax

    invoke LoadIcon,hModule,bmpID
    mov hIcon, eax

    invoke SendMessage,hImage,STM_SETIMAGE,IMAGE_ICON,hIcon

    mov eax, hImage
    ret

DisplayIcon endp

; ########################################################################

end