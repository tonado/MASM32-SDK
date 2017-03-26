; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    StrLen PROTO :DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

partial proc startat:DWORD,psrc:DWORD,ppatn:DWORD

comment @ ------------------------------------------------------
        Partial string matching algorithm.
        Wildcard character is fixed at "*".
        Leading, mixed and trailing * allowed in search pattern.

        Arguments
        =========
        1.  startat :   zero based offset from start address
        2.  psrc    :   address of zero terminated source to search
        3.  ppatn   :   address of zero terminated pattern to search

        Return values
        =============
        -1 NO match
        0 and greater = zero based offset of match
        ------------------------------------------------------ @

    LOCAL lead  :DWORD          ; number of filler chars at start
    LOCAL lsrc  :DWORD          ; source length in bytes
    LOCAL lptn  :DWORD          ; pattern length in bytes
    LOCAL mptn  :DWORD          ; matching pattern length
    LOCAL quit  :DWORD          ; exit offset for main loop

    push ebx
    push esi
    push edi

    mov eax, startat            ; add starting offset to source address
    add psrc, eax

    invoke StrLen,ppatn
    mov lptn, eax               ; raw patn length
    invoke StrLen,psrc
    mov lsrc, eax               ; source length

    mov esi, psrc
    mov edi, ppatn
    sub edi, 1

  ; ----------------------------------------
  ; scan beginning of string for lead length
  ; ----------------------------------------
    mov lead, 0
    jmp @F
  lbl0:
    add lead, 1                 ; count the lead filler chars
  @@:
    add edi, 1                  ; increment EDI up to 1st non blank char
    cmp BYTE PTR [edi], "*"
    je lbl0
  ; ----------------------------------------

    mov eax, lptn
    sub eax, lead               ; sub lead from patn length
    mov mptn, eax               ; calc the len of the pattern to match
    sub mptn, 1

    mov bl, [edi]               ; 1st non filler char in BL
    add esi, lead               ; start counting the correct number
    sub esi, 1                  ; of characters in from start

  ; -----------------------
  ; calculate "quit" offset
  ; -----------------------
    mov eax, lsrc
    sub eax, lptn
    add eax, lead
    add eax, esi
    mov quit, eax
  ; -----------------------

  ; ****************************************************************

  mainloop:
    add esi, 1
    cmp [esi], bl               ; scan source for 1st non filler char
    je @F
    cmp esi, quit               ; test against exit offset
    jle mainloop
    jmp nomatch

  @@:
    mov edx, -1                 ; set index to -1
  matchloop:
    add edx, 1                  ; increment the index
    cmp edx, mptn               ; check against pattern length
    jg matched
    movzx ecx, BYTE PTR [edi+edx]           ; load current byte in pattern
    cmp cl, 42                  ; test if its a filler "*"
    je matchloop
    cmp cl, [esi+edx]           ; else test if it matches
    je matchloop                ; at next character
    jmp mainloop

  ; ****************************************************************

  matched:
    sub esi, psrc
    sub esi, lead
    mov eax, esi
    add eax, startat
    jmp outa_here

  nomatch:
    mov eax, -1

  outa_here:
    pop edi
    pop esi
    pop ebx

    ret

partial endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
