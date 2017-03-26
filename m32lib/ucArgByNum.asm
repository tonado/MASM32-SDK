; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    ucArgByNum PROTO :DWORD,:DWORD,:DWORD

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

ucArgByNum proc src:DWORD,dst:DWORD,num:DWORD

  ; -------------------------------------------------------------
  ; src = string to get argument from
  ; dst = buffer to take selected argument
  ; num = 1 based number for argument, 1 = arg1, 2 = arg2 etc ...
  ;
  ; return value = scanned arg number or 0
  ; if src is a pointer to a null string or empty string
  ; test EAX for zero to determine if no arguments are available
  ;  or
  ; test if dest buffer is zero.
  ; -------------------------------------------------------------
    push esi

    mov esi, src
    mov ecx, 1
    xor eax, eax

    mov edx, dst
    mov WORD PTR [edx], 0

  ; ------------------------------------
  ; handle src as pointer to NULL string
  ; ------------------------------------
    cmp WORD PTR [esi], 0
    jne next1
    jmp bailout
  next1:
    sub esi, 2

  ftrim:
    add esi, 2
    mov ax, WORD PTR [esi]
    cmp ax, 32
    je ftrim
    cmp ax, 9
    je ftrim
    cmp ax, 0
    je bailout                  ; exit on empty string (only white space)

    cmp WORD PTR [esi], 34
    je quoted

    sub esi, 2

  ; ----------------------------

  unquoted:
    add esi, 2
    mov ax, WORD PTR [esi]
    test ax, ax
    jz scanout
    cmp ax, 32
    je wordend
    mov WORD PTR [edx], ax
    add edx, 2
    jmp unquoted

  wordend:
    cmp ecx, num
    je scanout
    add ecx, 1
    mov edx, dst
    mov WORD PTR [edx], 0
    jmp ftrim

  ; ----------------------------

  quoted:
    add esi, 2
    mov ax, WORD PTR [esi]
    test ax, ax
    jz scanout
    cmp ax, 34
    je quoteend
    mov WORD PTR [edx], ax
    add edx, 2
    jmp quoted

  quoteend:
    add edi, 2
    cmp ecx, num
    je scanout
    add ecx, 1
    mov edx, dst
    mov WORD PTR [edx], 0
    jmp ftrim

  ; ----------------------------

  scanout:
    .if num > ecx
    bailout:                        ; error exit
      mov edx, dst                  ; reload dest address
      mov WORD PTR [edx], 0         ; zero dest buffer
      xor eax, eax                  ; zero return value
      jmp quit
    .else                           ; normal exit
      mov WORD PTR [edx], 0         ; terminate output buffer
      mov eax, ecx                  ; set the return value
    .endif

  quit:
    pop esi

    ret

ucArgByNum endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
