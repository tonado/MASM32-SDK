; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

addstr proc string:DWORD,buffer:DWORD,location:DWORD

  ; This procedure appends a zero terminated "string" to the
  ; location in a memory "buffer" pointed to by the variable
  ; "location". Within the scope of the caller, a DWORD variable
  ; should be allocated that is used as the position indicator
  ; in the memory buffer. It can be called in this manner.

  ; LOCAL locpointer    :DWORD

  ; mov locpointer, 0
  ; invoke addstr,MyString,TheBuffer,locpointer
  ; mov locpointer, eax

  ; or you can use the macro FUNC like the following.
  ; mov locpointer, FUNC(addstr,MyString,TheBuffer,locpointer)





    push esi

    mov esi, string
    mov edx, buffer
    add edx, location   ; add starting location to output buffer
    xor eax, eax

  @@:
    mov cl, [esi+eax]
    mov [edx+eax], cl
    add eax, 1
    test cl, cl
    jne @B

    add eax, location
    sub eax, 1

    pop esi

    ret

addstr endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
