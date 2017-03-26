; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .data
    align 16
      Cmpi_tbl \
      db   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
      db  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
      db  32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
      db  48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
      db  64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
      db 112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95
      db  96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
      db 112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127
      db 128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
      db 144,145,146,147,148,149,150,151,152,153,154,155,156,156,158,159
      db 160,161,162,163,164,165,166,167,168,169,170,171,172,173,173,175
      db 176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191
      db 192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207
      db 208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223
      db 224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239
      db 240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 16

Cmpi proc src:DWORD,dst:DWORD

    push ebx
    push esi
    push edi

    mov esi, [esp+16]               ; src
    mov edi, [esp+20]               ; dst
    sub eax, eax                    ; zero eax as index

  align 4
  @@:
    movzx edx, BYTE PTR [esi+eax]
    movzx ebx, BYTE PTR [edi+eax]
    movzx ecx, BYTE PTR [edx+Cmpi_tbl]
    add eax, 1
    cmp cl, [ebx+Cmpi_tbl]
    jne quit                        ; exit on 1st mismatch with
    test cl, cl                     ; non zero value in EAX
    jnz @B

    sub eax, eax                    ; set EAX to ZERO on match

  quit:
    pop edi
    pop esi
    pop ebx

    ret 8

Cmpi endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
