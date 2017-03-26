; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szMid proc src:DWORD,dst:DWORD,stp:DWORD,ln:DWORD

    mov ecx, [esp+16]       ; ln        length in ECX
    mov edx, [esp+4]        ; src       source address
    add edx, ecx            ; add required length
    add edx, [esp+12]       ; stp       add starting position
    mov eax, [esp+8]        ; dst       destination address
    add eax, ecx            ; add length and set terminator position
    neg ecx                 ; invert sign

    push ebx

  @@:
    movzx ebx, BYTE PTR [edx+ecx]
    mov [eax+ecx], bl
    add ecx, 1
    jnz @B

    pop ebx

    mov BYTE PTR [eax], 0   ; write terminator

    ret 16

szMid endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end