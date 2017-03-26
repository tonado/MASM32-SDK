; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    EXTERNDEF hex_table :DWORD

  .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 16

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

dw2hex_ex proc src:DWORD,buf:DWORD

    movzx ecx, BYTE PTR [esp+4]
    mov edx, DWORD PTR [ecx+ecx+hex_table]
    mov eax, [esp+8]                        ; load buffer address
    shl edx, 16
    movzx ecx, BYTE PTR [esp+5]
    mov dx, WORD PTR [ecx+ecx+hex_table]

    movzx ecx, BYTE PTR [esp+6]
    mov [eax+4], edx                        ; write 2nd DWORD
    mov ecx, DWORD PTR [ecx+ecx+hex_table]
    movzx edx, BYTE PTR [esp+7]
    shl ecx, 16
    mov cx, WORD PTR [edx+edx+hex_table]
    xor edx, edx
    mov [eax], ecx                          ; write 1st DWORD

    mov BYTE PTR [eax+8], dl

    ret 8

dw2hex_ex endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
