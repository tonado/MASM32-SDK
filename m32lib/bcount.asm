; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    byte_count PROTO :DWORD,:DWORD,:DWORD

 ;       -------------------------------
 ;       get individual character count 
 ;       value from already loaded array
 ;       -------------------------------
 ;       mov eax, array
 ;       xor edx, edx
 ;       mov dl, ":"
 ;       mov ecx, [eax+edx*4]

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

byte_count proc src:DWORD,cnt:DWORD,array:DWORD

comment * ----------------------------------
    src   = source to count characters in
    cnt   = byte count of source
    array = 1024 bytes of memory that is 
            loaded as 256 DWORD values.
            NOTE: Memory MUST be zero filled
        ---------------------------------- *

    push ebx
    push esi
    push edi
    push ebp

    mov esi, src                    ; source in ESI
    mov edi, cnt                    ; byte count in EDI
  ; -----------------------------------------------------------
    mov ebp, array                  ; overwriting EBP here !!!!
  ; -----------------------------------------------------------
    shr edi, 2
    add edi, edi
    add edi, edi                    ; round EDI down to next 4 byte boundary
    add esi, edi                    ; add count to source
    neg edi                         ; invert sign in EDI

  align 4
  @@:
    movzx eax, BYTE PTR [esi+edi]
    movzx ebx, BYTE PTR [esi+edi+1]
    movzx ecx, BYTE PTR [esi+edi+2]
    movzx edx, BYTE PTR [esi+edi+3]
    add DWORD PTR [ebp+eax*4], 1
    add DWORD PTR [ebp+ebx*4], 1
    add DWORD PTR [ebp+ecx*4], 1
    add DWORD PTR [ebp+edx*4], 1
    add edi, 4
    jnz @B

    mov ecx, ebp                    ; copy EBP to ECX
    pop ebp                         ; restore EBP before accessing stack parameter
    and cnt, 3
    jz bcout

  @@:
    movzx eax, BYTE PTR [esi+edi]
    add edi, 1
    add DWORD PTR [ecx+eax*4], 1
    sub cnt, 1
    jnz @B

  bcout:

    pop edi
    pop esi
    pop ebx

    ret

byte_count endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end
