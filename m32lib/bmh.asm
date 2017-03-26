; #########################################################################

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    .code

; #########################################################################

align 16

BMHBinsearch proc startpos:DWORD,
                  lpSource:DWORD,srcLngth:DWORD,
                  lpSubStr:DWORD,subLngth:DWORD

  ; ------------------------------------------------------------------
  ; This algorithm is related to a Horspool variation of a Boyer
  ; Moore exact pattern matching algorithm. It only uses the bad char
  ; shift and increments the source if the character is in the table
  ; ------------------------------------------------------------------

    LOCAL cval:DWORD
    LOCAL shift_table[256]:DWORD

    push ebx
    push esi
    push edi

    mov ebx, subLngth

    cmp ebx, 1
    jg @F
    mov eax, -2                 ; string too short, must be > 1
    jmp BMHout
  @@:

    mov esi, lpSource
    add esi, srcLngth
    sub esi, ebx
    mov edx, esi                ; set Exit Length

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

  Write_Chars:
    mov al, [esi]               ; get the character
    inc esi
    mov [edi+eax*4], ecx        ; write shift for each character
    dec ecx                     ; to ascii location in table
    jnz Write_Chars

  ; -----------------------------
  ; set up for main compare loop
  ; -----------------------------
    mov ecx, ebx
    dec ecx
    mov cval, ecx

    mov esi, lpSource
    mov edi, lpSubStr
    add esi, startpos           ; add starting position

; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  Main_Loop:
    sub eax, eax                ; zero EAX before partial write
    mov al, [esi+ecx]
    cmp al, [edi+ecx]           ; cmp characters in ESI / EDI
    jne Get_Shift               ; if not equal, get next shift
    dec ecx
    jns Main_Loop

    jmp Matchx

  Get_Shift:
    inc esi                     ; inc esi for minimum shift
    cmp ebx, shift_table[eax*4] ; cmp subLngth to char shift
    jne Exit_Test
    add esi, ecx                ; add bad char shift
  Exit_Test:
    mov ecx, cval               ; reset counter in compare loop
    cmp esi, edx                ; test for exit condition
    jl Main_Loop

    jmp MisMatch

; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  Matchx:
    sub esi, lpSource           ; sub source from ESI
    mov eax, esi                ; put length in eax
    jmp BMHout

  MisMatch:
    mov eax, -1

  BMHout:
    pop edi
    pop esi
    pop ebx

    ret

BMHBinsearch endp

; #########################################################################

    end