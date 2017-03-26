    .586
    .model flat,stdcall
    option casemap:none

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\user32.inc

;The Proc will produce MsgBox with Last error number and description

; ==================================
; GetErrDescription, ErrNum if ErrNum = 0 the procedure call GetLastError to
; obtain LastErrorNumber If you already know the error number (for Example
; WNetAddConnection2 return 0 on seccess and Error number when failes) pass
; it as ErrNum.
; Example:
; invoke WNetAddConnection2,offset nr,offset Pass,0,CONNECT_UPDATE_PROFILE
; or eax,eax
; jne GetErr
; ..... ;code if OK
; GetErr:
; invoke GetErrDescription,eax 
; ===================================
; When you don't get the error code pass 0 as parameter
; Example:
; invoke LocalFree,1234
; jne OK ;0 if error
; invoke GetErrDescription,eax ;eax=0
; OK:
;==================================

    .data
      ErrMsgTmpl db 'Error Code %i',13,10
      db 'Description: %s',0
      Unknown db 'UnKnownError',0
    .code

GetErrDescription proc uses ebx edi ErrNum:DWORD

    LOCAL hLocal:DWORD
    LOCAL Buffer[256]:BYTE

    mov eax,ErrNum
    or eax,eax
    jne WeAlreadyKnowIt
    invoke GetLastError

    WeAlreadyKnowIt:
    mov edi,eax

    invoke FormatMessage,FORMAT_MESSAGE_ALLOCATE_BUFFER or \
                         FORMAT_MESSAGE_FROM_SYSTEM,
                         0,             ; GetItFromSystem
                         edi,0,         ; ErrNum,Default language
                         addr hLocal,   ; where to send the address of string from system
                         0,0            ; any size, no arguments

    or eax,eax
    mov ebx,offset UnKnown
    je UnKnown

    invoke LocalLock,hLocal

    mov ebx,eax

    UnKnown:

    invoke wsprintf,addr Buffer,offset ErrMsgTmpl,edi,ebx
    invoke MessageBox,0,addr Buffer,0,0
    cmp ebx,offset UnKnown
    je @F
    invoke LocalFree,hLocal
  @@:

    ret

GetErrDescription endp

;=======================================

end

