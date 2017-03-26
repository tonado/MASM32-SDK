; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

    align 16

arrget proc arr:DWORD,indx:DWORD

    mov eax, [esp+4]                        ; write array adress to EAX
    mov ecx, [esp+8]                        ; write required index to ECX
    mov edx, [eax]                          ; write member count to EDX

    cmp ecx, 1
    jl error1                               ; lower bound error
    cmp ecx, edx
    jg error2                               ; upper bound error

    mov eax, [eax+ecx*4]                    ; write array member address to EAX
    ret 8

  error1:
    mov eax, -1                             ; return -1 on lower bound error
    ret 8

  error2:
    mov eax, -2                             ; return -2 on upper bound error
    ret 8

arrget endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
