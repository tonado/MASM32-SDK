; #########################################################################

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

align 16

BMBinSearch proc startpos:DWORD,
                 lpSource:DWORD,srcLngth:DWORD,
                 lpSubStr:DWORD,subLngth:DWORD

  ; -----------------------------------------------------------------
  ; This version uses four heuristics, it determines the shift type
  ; from the character in the table, if the character is not in the
  ; pattern, it performs a BAD CHARACTER shift, if the character is
  ; in the pattern, it determines if it is the first comparison after
  ; the shift and adds the GOOD SUFFIX shift to the location counter.
  ; If the comparison is not the first after the shift, it calculates
  ; the GOOD SUFFIX shift and adds it to the location counter.
  ; -----------------------------------------------------------------

    LOCAL cval   :DWORD
    LOCAL shift_table[256]:DWORD

    push ebx
    push esi
    push edi

    mov ebx, subLngth

    cmp ebx, 1
    jg @F
    mov eax, -2                 ; string too short, must be > 1
    jmp Cleanup
  @@:

    mov esi, lpSource
    add esi, srcLngth
    sub esi, ebx
    mov edx, esi            ; set Exit Length

  ; ----------------------------------------
  ; load shift table with value in subLngth
  ; ----------------------------------------
    mov ecx, 256
    mov eax, ebx
    lea edi, shift_table
    rep stosd

  ; ----------------------------------------------
  ; load decending count values into shift table
  ; ----------------------------------------------
    mov ecx, ebx                ; SubString length in ECX
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
    mov ecx, ebx
    dec ecx
    mov cval, ecx

    mov esi, lpSource
    mov edi, lpSubStr
    add esi, startpos           ; add starting position

    jmp Pre_Loop

; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  Calc_Suffix_Shift:
    add eax, ecx
    sub eax, cval               ; sub loop count
    jns Add_Suffix_Shift
    mov eax, 1                  ; minimum shift is 1

  Add_Suffix_Shift:
    add esi, eax                ; add SUFFIX shift
    mov ecx, cval               ; reset counter in compare loop

  Test_Length:
    cmp edx, esi                ; test exit condition
    jl No_Match

  Pre_Loop:
    xor eax, eax                ; zero EAX for following partial writes
    mov al, [esi+ecx]
    cmp al, [edi+ecx]           ; cmp characters in ESI / EDI
    je @F
    mov eax, shift_table[eax*4]
    cmp ebx, eax
    jne Add_Suffix_Shift        ; bypass SUFFIX calculations
    lea esi, [esi+ecx+1]        ; add BAD CHAR shift
    jmp Test_Length
  @@:
    dec ecx
    xor eax, eax                ; zero EAX for following partial writes

  Cmp_Loop:
    mov al, [esi+ecx]
    cmp al, [edi+ecx]           ; cmp characters in ESI / EDI
    jne Set_Shift               ; if not equal, get next shift
    dec ecx
    jns Cmp_Loop
    jmp Match                   ; fall through on match

  Set_Shift:
    mov eax, shift_table[eax*4]
    cmp ebx, eax
    jne Calc_Suffix_Shift       ; run SUFFIX calculations
    lea esi, [esi+ecx+1]        ; add BAD CHAR shift
    jmp Test_Length

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

BMBinSearch endp

; #########################################################################

    end