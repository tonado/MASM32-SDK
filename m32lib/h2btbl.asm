; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    PUBLIC h2btbl

  ; ---------------------------------------------
  ; code that uses this table must have the line,
  ; EXTERNDEF h2btbl:DWORD
  ; ---------------------------------------------

    .data

    ; 1st offset table

    align 4
    h2btbl \
      db 00h,10h,20h,30h,40h,50h,60h,70h,80h,90h,0,0,0,0,0,0      ; 63
      db 00h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h,0,0,0,0,0,0,0,0,0      ; 79
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0                          ; 95
      db 00h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h

    ; 2nd offset table
      db 00h,01h,02h,03h,04h,05h,06h,07h,08h,09h,0,0,0,0,0,0      ; 63
      db 00h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh,0,0,0,0,0,0,0,0,0            ; 79
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0                          ; 95
      db 00h,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh

      ; sub 48 from 1st offset table
      ; add 7 for the second BYTE

 ;     mov cl, [reg1+h2btbl-48]        ; load 1st character into CL from 2nd table
 ;     add cl, [reg2+h2btbl+7]         ; add value of second character from 3rd table


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
