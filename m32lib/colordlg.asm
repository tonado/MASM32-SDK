; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \MASM32\INCLUDE\windows.inc
    include \MASM32\INCLUDE\user32.inc
    include \MASM32\INCLUDE\comdlg32.inc

    .code

; #########################################################################

ColorDialog proc hWin:DWORD, instance:DWORD, Flags:DWORD

    LOCAL ccl:CHOOSECOLOR
    LOCAL crv[16]:DWORD

    lea edi, crv[0]
    mov ecx, 16
    mov eax, 0FFFFFFh
    rep stosd

    mov ccl.lStructSize,    sizeof CHOOSECOLOR
    push hWin
    pop ccl.hwndOwner 
    push instance
    pop ccl.hInstance
    mov ccl.rgbResult,      0
    lea eax, crv                ; address of 16 item DWORD array
    mov ccl.lpCustColors,   eax
    push Flags
    pop ccl.Flags
    mov ccl.lCustData,      0
    mov ccl.lpfnHook,       0
    mov ccl.lpTemplateName, 0

    invoke ChooseColor,ADDR ccl

    .if eax != 0
      mov eax, ccl.rgbResult
    .endif

    ret

ColorDialog endp

; #########################################################################

end