; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

    align 16

arrlen proc arr:DWORD,indx:DWORD

    mov ecx, [esp+4]                    ; load array address
    mov eax, [esp+8]                    ; write index to EAX
    mov eax, [ecx+eax*4]                ; get the address of the OLE string
    sub eax, 4                          ; sub 4 from the address
    mov eax, [eax]                      ; write stored string length to EAX

    ret 8

arrlen endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
