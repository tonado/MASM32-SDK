; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    get_line_count PROTO :DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arrfile proc file_name:DWORD

    LOCAL arr   :DWORD
    LOCAL hMem  :DWORD
    LOCAL flen  :DWORD
    LOCAL lcnt  :DWORD
    LOCAL pbuf  :DWORD
    LOCAL spos  :DWORD
    LOCAL void  :DWORD

    push ebx
    mov hMem, InputFile(file_name)
    mov flen, ecx
    mov lcnt, rv(get_line_count,hMem,flen)
    mov arr, arralloc$(lcnt)
    mov pbuf, alloc(flen)

    mov spos, 0
    mov ebx, 1
  @@:
    mov spos, rv(readline,hMem,pbuf,spos)
    mov void, arrset$(arr,ebx,pbuf)
    add ebx, 1
    cmp ebx, lcnt
    jle @B

    free pbuf
    free hMem

    mov eax, arr
    pop ebx

    ret

arrfile endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
