; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .data

    align 4
    abntbl \
      db 2,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 1,0,3,0,0,0,0,0,0,0,0,0,1,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

    ; 0 = OK char
    ; 1 = delimiting characters   tab LF CR space ","
    ;
    ; 2 = ASCII zero    This should not be changed in the table
    ; 3 = quotation     This should not be changed in the table

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

ArgByNumber proc src:DWORD,dst:DWORD,num:DWORD,npos:DWORD

comment * -----------------------------------------------

        Return values in EAX
        --------------------
        >0 = there is a higher number argument available
        0  = end of command line has been found
        -1 = a non matching quotation error occurred

        conditions of 0 or greater can have argument
        content which can be tested as follows.

        Test Argument for content
        -------------------------
        If the argument is empty, the first BYTE in the
        destination buffer is set to zero

        mov eax, destbuffer     ; load destination buffer
        cmp BYTE PTR [eax], 0   ; test its first BYTE
        je no_arg               ; branch to no arg handler
        print destbuffer,13,10  ; display the argument

        NOTE : A pair of empty quotes "" returns ascii 0
               in the destination buffer

        ----------------------------------------------- *

    push ebx
    push esi
    push edi

    mov esi, src
    add esi, npos
    mov edi, dst

    mov BYTE PTR [edi], 0           ; set destination buffer to zero length

    xor ebx, ebx

  ; *********
  ; scan args
  ; *********
  bcscan:
    movzx eax, BYTE PTR [esi]
    add esi, 1
    cmp BYTE PTR [abntbl+eax], 1    ; delimiting character
    je bcscan
    cmp BYTE PTR [abntbl+eax], 2    ; ASCII zero
    je quit

    sub esi, 1
    add ebx, 1
    cmp ebx, num                    ; copy next argument if number matches
    je cparg

  gcscan:
    movzx eax, BYTE PTR [esi]
    add esi, 1
    cmp BYTE PTR [abntbl+eax], 0    ; OK character
    je gcscan
    cmp BYTE PTR [abntbl+eax], 2    ; ASCII zero
    je quit
    cmp BYTE PTR [abntbl+eax], 3    ; quotation
    je dblquote
    jmp bcscan                      ; return to delimiters

  dblquote:
    add esi, 1
    cmp BYTE PTR [esi], 0
    je qterror
    cmp BYTE PTR [esi], 34
    jne dblquote
    add esi, 1
    jmp bcscan                      ; return to delimiters

  ; ********
  ; copy arg
  ; ********
  cparg:
    xor eax, eax
    xor edx, edx
    cmp BYTE PTR [esi+edx], 34      ; if 1st char is a quote
    je cpquote                      ; jump to quote copy
  @@:
    mov al, [esi+edx]               ; copy normal argument to buffer
    mov [edi+edx], al
    test eax, eax
    jz quit
    add edx, 1
    cmp BYTE PTR [abntbl+eax], 1
    jl @B
    mov BYTE PTR [edi+edx-1], 0     ; append terminator
    jmp next_read

  ; ********************
  ; copy quoted argument
  ; ********************
  cpquote:
    add esi, 1
  @@:
    mov al, [esi+edx]               ; strip quotes and copy contents to buffer
    test al, al
    jz qterror
    cmp al, 34
    je write_zero
    mov [edi+edx], al
    add edx, 1
    jmp @B

  write_zero:
    add edx, 1                      ; correct EDX for final exit position
    mov BYTE PTR [edi+edx-1], 0     ; append terminator

    jmp next_read                    ; jump to next read setup
  ; *****************
  ; set return values
  ; *****************
  qterror:
    mov eax, -1                     ; quotation error
    jmp rstack

  quit:
    xor eax, eax                    ; set EAX to zero for end of source buffer
    jmp rstack

  next_read:
    mov eax, esi
    add eax, edx
    sub eax, src

  rstack:
    pop edi
    pop esi
    pop ebx

    ret

ArgByNumber endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
