; #########################################################################

;       -------------------------------------------------------------
;       This original algorithm was designed by Alexander Yackubtchik
;                     It was re-written in August 2006
;       -------------------------------------------------------------

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szMultiCat proc C pcount:DWORD,lpBuffer:DWORD,args:VARARG

    push ebx
    push esi
    push edi
    push ebp

    mov ebx, 1

    mov ebp, [esp+20]

    mov edi, [esp+24]           ; lpBuffer
    xor ecx, ecx
    lea edx, [esp+28]           ; args
    sub edi, ebx
  align 4
  @@:
    add edi, ebx
    movzx eax, BYTE PTR [edi]   ; unroll by 2
    test eax, eax
    je nxtstr

    add edi, ebx
    movzx eax, BYTE PTR [edi]
    test eax, eax
    jne @B
  nxtstr:
    sub edi, ebx
    mov esi, [edx+ecx*4]
  @@:
    add edi, ebx
    movzx eax, BYTE PTR [esi]   ; unroll by 2
    mov [edi], al
    add esi, ebx
    test eax, eax
    jz @F

    add edi, ebx
    movzx eax, BYTE PTR [esi]
    mov [edi], al
    add esi, ebx
    test eax, eax
    jne @B

  @@:
    add ecx, ebx
    cmp ecx, ebp                ; pcount
    jne nxtstr

    mov eax, [esp+24]           ; lpBuffer

    pop ebp
    pop edi
    pop esi
    pop ebx

    ret

szMultiCat endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end