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

DisplayBmp proc hParent:DWORD,bmpID:DWORD,x:DWORD,y:DWORD,ID:DWORD

    LOCAL hModule:DWORD
    LOCAL hBmp   :DWORD
    LOCAL hImage :DWORD

    invoke GetModuleHandle,NULL
    mov hModule, eax

    invoke CreateWindowEx,WS_EX_LEFT,
            ADDR stWin,NULL,
            WS_CHILD or WS_VISIBLE or SS_BITMAP,
            x,y,10,10,hParent,ID,
            hModule,NULL

    mov hImage, eax

    invoke LoadBitmap,hModule,bmpID
    mov hBmp, eax

    invoke SendMessage,hImage,STM_SETIMAGE,IMAGE_BITMAP,hBmp

    mov eax, hImage
    ret

DisplayBmp endp

; ########################################################################

end