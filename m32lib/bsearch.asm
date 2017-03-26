; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .486                      ; create 32 bit code
    .model flat, stdcall      ; 32 bit memory model
    option casemap :none      ; case sensitive

    .code

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align 16

BinSearch proc stpos:DWORD,src:DWORD,slen:DWORD,patn:DWORD,plen:DWORD

  ; ---------------------------------------------------------
  ; ARGUMENTS
  ; ---------
  ; 1. stpos        offset from src start address
  ; 2. src          start address of data to search
  ; 3. slen         1 based length of src
  ; 4. patn         address of pattern to search for
  ; 5. plen         1 based length of pattern

  ; RETURN VALUES
  ; -------------
  ; 0 or greater    OFFSET of matched pattern
  ; -1              pattern not found
  ; -2              pattern > source length
  ; -3              start OFFSET > last valid search position
  ; ---------------------------------------------------------
    push ebx
    push esi
    push edi
    push ebp

    mov ecx, [esp+24][4]            ; load source length
    sub ecx, [esp+32][4]            ; calculate last search position
    js errquit1                     ; if pattern > source length
    cmp [esp+16][4], ecx
    jg errquit2                     ; if startpos > last sch position
    mov esi, [esp+20][4]            ; load the source address in ESI
    mov edi, [esp+28][4]            ; load the pattern address in EDI
    movzx ebx, BYTE PTR [edi]       ; get the 1st byte of the pattern
    add ecx, esi                    ; add ESI to the exit count
    sub DWORD PTR [esp+32][4], 1    ; correct for zero based match loop counter
    sub esi, 1
    add esi, DWORD PTR [esp+16][4]  ; add the starting offset
    mov ebp, [esp+32][4]            ; put pattern length into EBP
  ; ---------------------------------
  scanloop:
    add esi, 1
    cmp esi, ecx                    ; exit on end location
    jg nomatch
    cmp [esi], bl                   ; cmp current byte to 1st byte in pattern
    jne scanloop
  ; ---------------------------------
  matchloop:
    or edx, -1                      ; use edx as the index for matching
  ; =================================
  mloop:
    add edx, 1
    mov al, [esi+edx]
    cmp al, [edi+edx]
    jne scanloop                    ; exit on mismatch within valid range
    cmp edx, ebp                    ; compare counter against pattern length
    jne mloop
  ; =================================
    sub esi, [esp+20][4]            ; on match, calculate length
    mov eax, esi                    ; return it in EAX
    jmp quit
  nomatch:
    mov eax, -1
    jmp quit
  errquit1:
    mov eax, -2
    jmp quit
  errquit2:
    mov eax, -3
    jmp quit

  quit:
    pop ebp
    pop edi
    pop esi
    pop ebx

    ret 20

BinSearch endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    end