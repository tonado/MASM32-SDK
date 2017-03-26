; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

szLeft proc src:DWORD,dst:DWORD,ln:DWORD

    mov edx, [esp+12]   ; ln
    mov eax, [esp+4]    ; src
    mov ecx, [esp+8]    ; dst

    add eax, edx
    add ecx, edx
    neg edx

    push ebx

  align 4
  @@:
    movzx ebx, BYTE PTR [eax+edx]
    mov [ecx+edx], bl
    add edx, 1
    jnz @B

    mov BYTE PTR [ecx+edx], 0

    pop ebx

    mov eax, [esp+8]    ; return the destination address in EAX

    ret 12

szLeft endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end

