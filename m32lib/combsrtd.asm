; #########################################################################

      .486                      ; create 32 bit code
      .model flat, stdcall      ; 32 bit memory model
      option casemap :none      ; case sensitive

    .code

;##########################################################################

CombSortD proc Arr:DWORD,aSize:DWORD

    LOCAL Gap   :DWORD
    LOCAL eFlag :DWORD

    .data
      const REAL4 1.3
    .code

    push ebx
    push esi
    push edi

    mov eax, aSize
    mov Gap, eax
    mov esi, Arr    ; address of 1st element
    dec aSize

  stLbl:
    fild Gap        ; load integer memory operand to divide
    fdiv const      ; divide number by 1.3
    fistp Gap       ; store result back in integer memory operand
    dec Gap
    jnz ovr
    mov Gap, 1
  ovr:
    mov eFlag, 0

    mov edi, aSize
    sub edi, Gap
    xor ecx, ecx              ; low value index
  iLoop:
    mov edx, ecx
    add edx, Gap              ; high value index
    mov eax, [esi+ecx*4]      ; lower value
    mov ebx, [esi+edx*4]      ; swap values
    cmp eax, ebx
    jge iLnxt                 ; sort decending
    mov [esi+edx*4], eax
    mov [esi+ecx*4], ebx
    inc eFlag
  iLnxt:

    inc ecx
    cmp ecx, edi
    jle iLoop

    cmp eFlag, 0
    jg stLbl
    cmp Gap, 1
    jg stLbl

    pop edi
    pop esi
    pop ebx

    ret

CombSortD endp

;##########################################################################

    end