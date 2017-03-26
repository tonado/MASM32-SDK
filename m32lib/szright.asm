; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    StrLen PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szRight proc src:DWORD,dst:DWORD,ln:DWORD

    invoke StrLen,[esp+4]           ; get source length
    sub eax, [esp+12]               ; sub required length from it
    mov edx, [esp+4]                ; source address in EDX
    add edx, eax                    ; add difference to source address
    or ecx, -1                      ; index to minus one
    mov eax, [esp+8]                ; destination address in EBX

    push ebx

  @@:
    add ecx, 1
    movzx ebx, BYTE PTR [edx+ecx]   ; copy bytes
    mov [eax+ecx], bl
    test ebx, ebx                   ; exit after zero written
    jne @B

    pop ebx

    mov eax, [esp+8]

    ret 12

szRight endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end