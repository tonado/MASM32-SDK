; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    EXTERNDEF d_e_f_a_u_l_t__n_u_l_l_$ :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    align 16

arralloc proc mcnt:DWORD

  ; ----------------------------------------------------------------
  ; return values = handle of pointer array or 0 on allocation error
  ; ----------------------------------------------------------------
    push esi

    mov eax, mcnt                               ; load the member count into EAX
    add eax, 1                                  ; correct for 1 based array
    lea eax, [0+eax*4]                          ; multiply it by 4 for memory size

    invoke GlobalAlloc,GMEM_FIXED,eax
    mov esi, eax

    test eax, eax                               ; if allocation failure return zero
    jz quit

    mov eax, esi
    mov ecx, mcnt
    mov DWORD PTR [eax], ecx                    ; write count to 1st member

    xor edx, edx
  @@:
    add edx, 1                                  ; write adress of null string to all members
    mov [eax+edx*4], OFFSET d_e_f_a_u_l_t__n_u_l_l_$
    cmp edx, ecx
    jle @B

    mov eax, esi                                ; return pointer array handle

  quit:
    pop esi

    ret

arralloc endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
