; #########################################################################

    .386
    .model flat, stdcall        ; 32 bit memory model
    option casemap :none        ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    Read_File_In PROTO :DWORD,:DWORD
    ofCallBack PROTO :DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

Read_File_In proc hEdit:DWORD,lpszFileName:DWORD

    LOCAL hFile :DWORD
    LOCAL ofs   :OFSTRUCT
    LOCAL est   :EDITSTREAM

    invoke OpenFile,lpszFileName,ADDR ofs,OF_READ
    mov hFile, eax

    mov est.dwCookie, eax
    mov est.dwError, 0
    mov eax, offset ofCallBack
    mov est.pfnCallback, eax

    invoke SendMessage,hEdit,EM_STREAMIN,SF_TEXT,ADDR est
    invoke CloseHandle,hFile

    invoke SendMessage,hEdit,EM_SETMODIFY,0,0

    mov eax, 0
    ret

Read_File_In endp

; #########################################################################

ofCallBack proc dwCookie:DWORD,pbBuff:DWORD,cb:DWORD,pcb:DWORD

    invoke ReadFile,dwCookie,pbBuff,cb,pcb,NULL

    mov eax, 0
    ret

ofCallBack endp

; #########################################################################

end
