; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    asqsort PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    acisort PROTO :DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

assort proc arr:DWORD,cnt:DWORD,rdi:DWORD

    .if rdi == 0
      mov rdi, 100                      ; set default maximum recursion depth
    .endif

    mov eax, cnt
    sub eax, 1

    invoke asqsort,arr,0,eax,0,rdi
    xor eax, eax                        ; exit with EAX = 0 is quick sorted
    test edx, edx                       ; if EDX = 0 quick sort failed by
    jnz @F                              ; exceeding maximum recursion depth
    invoke acisort,arr,cnt
    mov eax, 1                          ; exit with EAX = 1 is CISORTed
  @@:

    ret

assort endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
