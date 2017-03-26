; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

get_ml proc src:DWORD,dst:DWORD,rpos:DWORD

comment * --------------------------------------------------------------

        src     SOURCE address of code to get multiline statement from
        dst     DESTINATION buffer for result
        rpos    OFFSET pointer in source code to read from.

        RETURN VALUES
        0  = end of source data
        >0 = next read position
        -1 = quotation ERROR, non matching quotes

        EXAMPLE : 
      
          mov rpos, 0
        stlp:
          mov rpos, rv(get_ml,hMem,hBuf,rpos)
          print hBuf,13,10
          cmp rpos, 0
          jnz stlp

        -------------------------------------------------------------- *

    LOCAL bsflag    :DWORD

    push ebx
    push esi
    push edi

    mov bsflag, 0                       ; set backslash flag to zero

    mov esi, src
    add esi, rpos                       ; add next read position to source address
    mov edi, dst
    xor ecx, ecx                        ; set source index to ZERO
    xor ebx, ebx                        ; set destination index to ZERO
    xor edx, edx

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  ; ************************************************************
  ; lead_trim loop scans through commented lines and empty lines
  ; until it finds the beginning of the next statement.
  ; ************************************************************
  align 4
  lead_trim:
    mov al, [esi+ecx]
    add ecx, 1
    test al, al                         ; test for zero
    je setend
    cmp al, 32
    jbe lead_trim                       ; ignore anything else from 32 down
    cmp al, ";"
    je lcommnt                          ; branch on comment
    sub ecx, 1
    jmp main_text

  align 4
  lcommnt:                              ; comment in lead trim area
    mov al, [esi+ecx]
    add ecx, 1
    test al, al
    jz setend
    cmp al, 10                          ; use line feed as end of line indicator
    jne lcommnt
    jmp lead_trim

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  ; **************************************
  ; trim loop is faster than the main_loop
  ; **************************************
  align 4
  ftrim:
    mov al, [esi+ecx]
    add ecx, 1
    test al, al
    jz setend
    cmp al, 32                          ; trash anything from ascii 32 down
    jle ftrim
    sub ecx, 1                          ; correct for last trailing ADD

  ; ************************************************
  ; the main loop handles character type evaluation,
  ; destination writes and stores the two flags used
  ; to determine the line continuation condition
  ; ************************************************
  align 4
  main_text:
    mov al, [esi+ecx]
    add ecx, 1
    test al, al                         ; test for zero
    je setend
    cmp al, 13
    je main_text                        ; throw CR away
    cmp al, 10
    je test_tail                        ; if end of line test last stored char
    cmp al, ";"
    je mtcommnt
    cmp al, 34                          ; branch on double quote
    je dblquote
    cmp al, 39                          ; branch on single quote
    je snglquote
    cmp al, 32
    jle @F
    mov edx, ecx                        ; write last normal character position in EDX
    mov bsflag, ebx                     ; write last backslash position in bsflag
  @@:
    mov [edi+ebx], al                   ; write BYTE to destination
    add ebx, 1
    jmp main_text

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  ; ******************
  ; single quoted text
  ; ******************
  align 4
  snglquote:
    mov [edi+ebx], al                   ; write the first quote
    add ebx, 1
  sqtret:
    mov al, [esi+ecx]
    add ecx, 1
    mov [edi+ebx], al                   ; copy each byte
    add ebx, 1
    test al, al
    jz qterror                          ; branch to ERROR on terminator
    cmp al, 10
    je qterror                          ; branch to ERROR on line feed
    cmp al, 39
    jne sqtret
    jmp ftrim                           ; return to main loop on closing quote

  ; ******************
  ; double quoted text
  ; ******************
  align 4
  dblquote:
    mov [edi+ebx], al                   ; write the first quote
    add ebx, 1
  qtret:
    mov al, [esi+ecx]
    add ecx, 1
    mov [edi+ebx], al                   ; copy each byte
    add ebx, 1
    test al, al
    jz qterror                          ; branch to ERROR on terminator
    cmp al, 10
    je qterror                          ; branch to ERROR on line feed
    cmp al, 34
    jne qtret
    jmp ftrim                           ; return to main loop on closing quote

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  ; ********************************************************
  ; remove comments and test for line continuation character
  ; ********************************************************
  align 4
  mtcommnt:
    sub ecx, 1
  @@:
    add ecx, 1
    cmp BYTE PTR [esi+ecx], 0           ; quit on terminator
    je setend
    cmp BYTE PTR [esi+ecx], 10          ; exit loop on LF
    jne @B

  test_tail:
    cmp BYTE PTR [esi+edx-1], ","       ; trailing comma is unfinished line
    je ftrim
    cmp BYTE PTR [esi+edx-1], "\"       ; trailing backslash is unfinished line
    jne next_rpos

    mov eax, bsflag
    mov BYTE PTR [edi+eax], 32          ; overwrite backslash with space
    mov bsflag, 0

    jmp ftrim

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  ; ***************************************
  ; set return values and append terminator
  ; ***************************************
  qterror:
    mov eax, -1                         ; set quotation error
    jmp lastbyte                        ; NON MATCHING QUOTATION

  setend:
    xor eax, eax                        ; return ZERO in EAX on terminator
    jmp lastbyte

  next_rpos:
    mov eax, ecx                        ; ELSE return the next read position
    add eax, rpos

  lastbyte:
    mov BYTE PTR [edi+ebx], 0           ; append the terminator

; д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д=ў=д

  quit:
    pop edi
    pop esi
    pop ebx

    ret

get_ml endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
