; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
;
;                     Park Miller random number algorithm.
;
;                      Written by Jaymeson Trudgen (NaN)
;                   Optimized by Rickey Bowers Jr. (bitRAKE)
;
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

      .486                      ; create 32 bit code
      .model flat, stdcall      ; 32 bit memory model
      option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

nrandom PROC base:DWORD

    mov eax, nrandom_seed

  ; ****************************************
    test eax, 80000000h
    jz  @F
    add eax, 7fffffffh
  @@:   
  ; **************************************** 

    xor edx, edx
    mov ecx, 127773
    div ecx
    mov ecx, eax
    mov eax, 16807
    mul edx
    mov edx, ecx
    mov ecx, eax
    mov eax, 2836
    mul edx
    sub ecx, eax
    xor edx, edx
    mov eax, ecx
    mov nrandom_seed, ecx
    div base

    mov eax, edx
    ret

nrandom ENDP

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

nseed proc TheSeed:DWORD

    .data
      nrandom_seed dd 12345678
    .code

    mov eax, TheSeed
    mov nrandom_seed, eax

    ret

nseed endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end