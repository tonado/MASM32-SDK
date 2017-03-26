; ########################################################################

    .486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    .code

; ########################################################################

filesize proc lpszFileName:DWORD

    LOCAL wfd :WIN32_FIND_DATA

    invoke FindFirstFile,lpszFileName,ADDR wfd
    .if eax == INVALID_HANDLE_VALUE
      mov eax, -1
      jmp fsEnd
    .endif

    invoke FindClose, eax

    mov eax, wfd.nFileSizeLow

    fsEnd:

    ret

filesize endp

; ########################################################################

end