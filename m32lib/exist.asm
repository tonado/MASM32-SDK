; #########################################################################

    .486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    .code

; #########################################################################

exist proc lpszFileName:DWORD

    LOCAL wfd :WIN32_FIND_DATA

    invoke FindFirstFile,lpszFileName,ADDR wfd
    .if eax == INVALID_HANDLE_VALUE
      mov eax, 0                    ; 0 = NOT exist
    .else
      invoke FindClose, eax
      mov eax, 1                    ; 1 = exist
    .endif

    ret

exist endp

; #########################################################################

end