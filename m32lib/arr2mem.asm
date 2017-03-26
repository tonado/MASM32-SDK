; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    ; EXTERNDEF d_e_f_a_u_l_t__n_u_l_l_$ :DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arr2mem proc arr:DWORD,pmem:DWORD

  ; ---------------------------------------------------
  ; this procedure is primarily for writing binary data
  ; to a memory buffer that has been allocated by the
  ; caller to the correct buffer size.
  ; ---------------------------------------------------

    LOCAL acnt  :DWORD                      ; array count
    LOCAL llen  :DWORD                      ; line length

    push ebx
    push esi
    push edi

    mov acnt, arrcnt$(arr)                  ; get the member count back from the array

    mov esi, pmem                           ; use ESI as memory pointer
    mov ebx, 1                              ; set EBX as 1 based index
  @@:
    mov llen, arrlen$(arr,ebx)              ; get each line length
    invoke MemCopy,arrget$(arr,ebx),esi,llen    ; write line to memory buffer
    add ebx, 1                              ; increment index
    add esi, llen                           ; update memory pointer
    cmp ebx, acnt                           ; test if index has reached array count
    jle @B

    mov eax, esi                            ; return the total length

    pop edi
    pop esi
    pop ebx

    ret

arr2mem endp

 ; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
