; #########################################################################

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

align 16

SBMBinSearch proc startpos:DWORD,
                  lpSource:DWORD,srcLngth:DWORD,
                  lpSubStr:DWORD,subLngth:DWORD

  ; --------------------------------------------------------
  ; This variation of a Boyer Moore exact pattern matching
  ; algorithm uses the GOOD SUFFIX shift with the extra
  ; heuristic to handle repeated sequences of characters.
  ; --------------------------------------------------------

    LOCAL shift_table[256]:DWORD

    push ebx
    push esi
    push edi

    mov edx, subLngth

    cmp edx, 1
    jg @F
    mov eax, -2                 ; string too short, must be > 1
    jmp Cleanup
  @@:

    mov esi, lpSource
    add esi, srcLngth
    sub esi, edx
    mov ebx, esi                ; set Exit Length

  ; ----------------------------------------
  ; load shift table with value in subLngth
  ; ----------------------------------------
    mov ecx, 256
    mov eax, edx
    lea edi, shift_table
    rep stosd

  ; ----------------------------------------------
  ; load decending count values into shift table
  ; ----------------------------------------------
    mov ecx, edx                ; SubString length in ECX
    dec ecx                     ; correct for zero based index
    mov esi, lpSubStr           ; address of SubString in ESI
    lea edi, shift_table

    xor eax, eax

  Write_Shift_Chars:
    mov al, [esi]               ; get the character
    inc esi
    mov [edi+eax*4], ecx        ; write shift for each character
    dec ecx                     ; to ascii location in table
    jnz Write_Shift_Chars

  ; -----------------------------
  ; set up for main compare loop
  ; -----------------------------

    mov esi, lpSource
    mov edi, lpSubStr
    dec edx
    xor eax, eax                ; zero EAX
    add esi, startpos           ; add starting position

    jmp Cmp_Loop

; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  Calc_Suffix_Shift:
    add ecx, shift_table[eax*4] ; add shift value to loop counter
    sub ecx, edx                ; sub pattern length
    jns Pre_Compare
    mov ecx, 1                  ; minimum shift is 1

  Pre_Compare:
    add esi, ecx                ; add suffix shift
    mov ecx, edx                ; reset counter for compare loop

  Exit_Text:
    cmp ebx, esi                ; test exit condition
    jl No_Match

    xor eax, eax                ; clear EAX for following partial writes
    mov al, [esi+ecx]
    cmp al, [edi+ecx]           ; cmp characters in ESI / EDI
    je @F
    add esi, shift_table[eax*4]
    jmp Exit_Text
  @@:
    dec ecx

    xor eax, eax                ; clear EAX for following partial writes
  Cmp_Loop:
    mov al, [esi+ecx]
    cmp al, [edi+ecx]           ; cmp characters in ESI / EDI
    jne Calc_Suffix_Shift       ; if not equal, get next shift
    dec ecx
    jns Cmp_Loop
    jmp Match                   ; match on fall through

; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  Match:
    sub esi, lpSource           ; sub source from ESI
    mov eax, esi                ; put length in eax
    jmp Cleanup

  No_Match:
    mov eax, -1

  Cleanup:
    pop edi
    pop esi
    pop ebx

    ret

SBMBinSearch endp

; #########################################################################

    end