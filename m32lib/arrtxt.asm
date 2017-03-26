; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    get_line_count PROTO :DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arrtxt proc ptxt:DWORD

    LOCAL flen  :DWORD
    LOCAL lcnt  :DWORD
    LOCAL pbuf  :DWORD
    LOCAL spos  :DWORD
    LOCAL parr  :DWORD
    LOCAL setv  :DWORD

    push ebx
    push esi
    push edi

    mov flen, rv(StrLen,ptxt)               ; save its length

    mov lcnt, rv(get_line_count,ptxt,flen)  ; get the line count
    mov flen, ecx                           ; store corrected byte count

    mov pbuf, alloc(flen)                   ; allocate buffer at length of text

    mov parr, arralloc$(lcnt)              ; allocate empty array

    mov spos, 0                             ; set start pos to 0
    mov ebx, 1                              ; use EBX as 1 based index

  @@:
    mov spos, rv(readline,ptxt,pbuf,spos)   ; read each line in sequence
    mov setv, arrset$(parr,ebx,pbuf)       ; write each line to the string array
    add ebx, 1
    cmp ebx, lcnt
    jle @B

    free pbuf                               ; free the buffer memory

    mov eax, parr                           ; return the array address

    pop edi
    pop esi
    pop ebx

    ret

arrtxt endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
