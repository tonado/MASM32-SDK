; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\macros\macros.asm

    arrcnt    PROTO :DWORD
    arrset    PROTO :DWORD,:DWORD,:DWORD
    arrget    PROTO :DWORD,:DWORD
    szappend  PROTO :DWORD,:DWORD,:DWORD

    .code       ; code section

 ; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arr2text proc arr:DWORD,pmem:DWORD

    LOCAL acnt  :DWORD          ; array count
    LOCAL cloc  :DWORD          ; current location pointer for szappend

    push ebx
    push esi
    push edi

    mov acnt, arrcnt$(arr)      ; get the array count
    mov cloc, 0                 ; set current location pointer to start of buffer
    mov ebx, 1                  ; use EBX as a 1 based index
  @@:
    mov ecx, arrget$(arr,ebx)
    mov cloc, rv(szappend,pmem,ecx,cloc)
    mov esi, pmem
    add esi, cloc
    mov WORD PTR [esi], 0A0Dh   ; append CRLF
    add cloc, 2                 ; correct cloc by 2 bytes
    add ebx, 1
    cmp ebx, acnt
    jle @B

    mov eax, acnt               ; return array line count

    pop edi
    pop esi
    pop ebx

    ret

arr2text endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
