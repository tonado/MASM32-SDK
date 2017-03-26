; #########################################################################

    .386
    .model flat, stdcall        ; 32 bit memory model
    option casemap :none        ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    Write_To_Disk PROTO :DWORD,:DWORD
    sfCallBack PROTO :DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

Write_To_Disk proc hEdit:DWORD,lpszFileName:DWORD

    LOCAL hFile :DWORD
    LOCAL ofs   :OFSTRUCT
    LOCAL est   :EDITSTREAM

    invoke OpenFile,lpszFileName,ADDR ofs,OF_CREATE
    mov hFile, eax

    mov est.dwCookie, eax
    mov est.dwError, 0
    mov eax, offset sfCallBack
    mov est.pfnCallback, eax

    invoke SendMessage,hEdit,EM_STREAMOUT,SF_TEXT,ADDR est
    invoke CloseHandle,hFile

    invoke SendMessage,hEdit,EM_SETMODIFY,0,0

    mov eax, 0
    ret

Write_To_Disk endp

; #########################################################################

sfCallBack proc dwCookie:DWORD,pbBuff:DWORD,cb:DWORD,pcb:DWORD

    invoke WriteFile,dwCookie,pbBuff,cb,pcb,NULL

    mov eax, 0
    ret

sfCallBack endp

; #########################################################################

end
