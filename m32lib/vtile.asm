; ########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

;     include files
;     ~~~~~~~~~~~~~
    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\user32.inc

    DisplayBmp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

    .code

; ########################################################################

VerticalTile proc hWin:DWORD,bmpID:DWORD,cnt:DWORD

  ; hWin  = is the window to tile the bitmap on
  ; bmpID = is the RESOURCE ID number
  ; cnt   = is the number of times to tile from top down

    LOCAL hndl:DWORD
    LOCAL tp  :DWORD
    LOCAL step:DWORD
    LOCAL lpz :DWORD
    LOCAL Rct :RECT

    cmp cnt, 1
    jl thOut

    mov tp, 0

    invoke DisplayBmp,hWin,bmpID,0,tp,150
    mov hndl, eax

    cmp cnt, 1
    jle thOut

    invoke GetWindowRect,hndl,ADDR Rct

    mov eax, Rct.top
    mov ecx, Rct.bottom
    sub ecx, eax
    mov step, ecx

    add tp, ecx

    mov lpz, 1      ; use as counter

  @@:
    invoke DisplayBmp,hWin,bmpID,0,tp,150
    mov eax, step
    add tp, eax
    inc lpz
    mov eax, cnt
    cmp lpz, eax
    jne @B

  thOut:

    ret

VerticalTile endp

; ########################################################################

end