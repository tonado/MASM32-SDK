; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .386
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    .code

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

StdIn proc lpszBuffer:DWORD,bLen:DWORD

    LOCAL hInput :DWORD
    LOCAL bRead  :DWORD

    invoke GetStdHandle,STD_INPUT_HANDLE
    mov hInput, eax

    invoke SetConsoleMode,hInput,ENABLE_LINE_INPUT or \
                                 ENABLE_ECHO_INPUT or \
                                 ENABLE_PROCESSED_INPUT

    invoke ReadFile,hInput,lpszBuffer,bLen,ADDR bRead,NULL

  ; -------------------------------
  ; strip the CR LF from the result
  ; -------------------------------
    mov edx, lpszBuffer
    sub edx, 1
  @@:
    add edx, 1
    cmp BYTE PTR [edx], 0
    je @F
    cmp BYTE PTR [edx], 13
    jne @B
    mov BYTE PTR [edx], 0
  @@:

    mov eax, bRead
    sub eax, 2

    ret

StdIn endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
