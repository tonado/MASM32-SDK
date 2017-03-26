; #########################################################################
;
;                             FpuAtoFL
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified January, 2004, to eliminate .data section and remove some
  ; redundant code.
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ; Revised December 2006 to avoid a minuscule error when processing strings
  ; which do not have any decimal digit.
  ;
  ; This FpuAtoFL function converts a decimal number from a zero terminated
  ; alphanumeric string format (Src) to an 80-bit REAL number and returns
  ; the result as an 80-bit REAL number at the specified destination (the
  ; FPU itself or a memory location), unless an invalid operation is
  ; reported by the FPU or the definition of the parameters (with uID) is
  ; invalid.
  ;
  ; The source can be a string in regular numeric format or in scientific
  ; notation. The number of digits (excluding all leading 0's and trailing
  ; decimal 0's) must not exceed 18. If in scientific format, the exponent
  ; must be within +/-4931
  ;
  ; The source is checked for validity. The procedure returns an error if
  ; a character other than those acceptable is detected prior to the
  ; terminating zero or the above limits are exceeded.
  ;
  ; This procedure is based on converting the digits into a specific packed
  ; decimal format which can be used by the FPU and then adjusted for an
  ; exponent of 10.
  ;
  ; Only EAX is used to return error or success. All other CPU registers
  ; are preserved.
  ;
  ; IF the FPU is specified as the destination for the result,
  ;       the st7 data register will become the st0 data register where the
  ;       result will be returned (any valid data in that register would
  ;       have been trashed).
  ;
  ; -----------------------------------------------------------------------

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include Fpu.inc

    .code

; #########################################################################

FpuAtoFL proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD

LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE
LOCAL bcdstrf      :TBYTE
LOCAL bcdstri      :TBYTE

      fsave content

      push  ebx
      push  ecx
      push  edx
      push  esi
      push  edi
      xor   eax,eax
      xor   ebx,ebx
      xor   edx,edx
      lea   edi,bcdstri
      stosd
      stosd
      stosd
      stosd
      stosd
      lea   edi,bcdstri+8
      mov   esi,lpSrc
      mov   ecx,18
   @@:
      lodsb
      cmp   al," "
      jz    @B                ;eliminate leading spaces
      or    al,al             ;is string empty?
      jnz   @F

atoflerr:
      frstor content
atoflerr1:
      xor   eax,eax
      pop   edi
      pop   esi
      pop   edx
      pop   ecx
      pop   ebx
      ret

;----------------------
;check for leading sign
;----------------------

   @@:
      cmp   al,"+"
      jz    @F
      cmp   al,"-"
      jnz   integer
      mov   ah,80h
   @@:
      mov   [edi+1],ah        ;put sign byte in bcd strings
      mov   [edi+11],ah
      xor   eax,eax
      lodsb

;--------------------------------------------
;convert the integer digits to packed decimal
;--------------------------------------------

integer:
      cmp   al,"."
      jnz   @F
      lea   edi,bcdstri
      call  load_integer
      lodsb
      lea   edi,bcdstrf+8
      mov   cl,18
      and   bh,4
      jmp   decimals

   @@:
      cmp   al,"e"
      jnz   @F
      .if   cl == 18
            jmp   atoflerr    ;error if no digit other than 0 before e
      .endif
      lea   edi,bcdstri
      call  load_integer
      jmp   scient

   @@:
      cmp   al,"E"
      jnz   @F
      .if   cl == 18
            jmp   atoflerr    ;error if no digit other than 0 before E
      .endif
      lea   edi,bcdstri
      call  load_integer
      jmp   scient

   @@:
      or    al,al
      jnz   @F
      test  bh,4
      jz    atoflerr          ;error if no numerical digit before terminating 0
      lea   edi,bcdstri
      call  load_integer
      jmp   laststep

   @@:
      sub   al,"0"
      jc    atoflerr          ;unacceptable character
      jnz   @F
      test  bh,2
      jnz   @F
      or    bh,4              ;at least 1 numerical character
      lodsb
      jmp   integer     
   @@:
      cmp   al,9
      ja    atoflerr          ;unacceptable character
      or    bh,6              ;at least 1 non-zero numerical character
      sub   ecx,1
      jc    atoflerr          ;more than 18 integer digits
      mov   ah,al

      lodsb
      cmp   al,"."
      jnz   @F
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstri
      call  load_integer
      lea   edi,bcdstrf+8
      mov   cl,18
      and   bh,4
      lodsb
      jmp   decimals

   @@:
      cmp   al,"e"
      jnz   @F
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstri
      call  load_integer
      jmp   scient

   @@:
      cmp   al,"E"
      jnz   @F
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstri
      call  load_integer
      jmp   scient

   @@:
      or    al,al
      jnz   @F
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstri
      call  load_integer
      jmp   laststep

   @@:
      sub   al,"0"
      jc    atoflerr          ;unacceptable character
      cmp   al,9
      ja    atoflerr          ;unacceptable character
      dec   ecx
      rol   al,4
      ror   ax,4
      mov   [edi],al
      dec   edi
      lodsb
      jmp   integer

;--------------------------------------------
;convert the decimal digits to packed decimal
;--------------------------------------------

decimals:
      cmp   al,"e"
      jnz   @F
      lea   edi,bcdstrf
      call  load_decimal
      jmp   scient

   @@:
      cmp   al,"E"
      jnz   @F
      lea   edi,bcdstrf
      call  load_decimal
      jmp   scient

   @@:
      or    al,al
      jnz   @F
      test  bh,4
      jz    atoflerr          ;error if no numerical digit before terminating 0
      lea   edi,bcdstrf
      call  load_decimal
      jmp   laststep

   @@:
      sub   al,"0"
      jc    atoflerr          ;unacceptable character
      cmp   al,9
      ja    atoflerr          ;unacceptable character
      or    bh,4              ;at least 1 numerical character
      .if   al != 0
            or    bh,2
      .endif
      sub   ecx,1
      jnc   @F
      .if   al == 0           ;if trailing decimal 0
            inc   ecx
            lodsb
            jmp   decimals
      .endif
      jmp   atoflerr
   @@:
      mov   ah,al

decimal1:
      lodsb
      cmp   al,"e"
      jnz   @F
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstrf
      call  load_decimal
      jmp   scient

   @@:
      cmp   al,"E"
      jnz   @F
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstrf
      call  load_decimal
      jmp   scient

   @@:
      or    al,al
      jnz   @F
      test  bh,4
      jz    atoflerr          ;error if no numerical digit before terminating 0
      mov   al,0
      ror   ax,4
      mov   [edi],al
      lea   edi,bcdstrf
      call  load_decimal
      jmp   laststep

   @@:
      sub   al,"0"
      jc    atoflerr          ;unacceptable character
      cmp   al,9
      ja    atoflerr          ;unacceptable character
      .if   al != 0
            or    bh,2        ;at least one non-zero decimal digit
      .endif
      dec   ecx
      rol   al,4
      ror   ax,4
      mov   [edi],al
      dec   edi
      lodsb
      jmp   decimals

laststep:
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;test for invalid operation
      jc    atoflerr          ;clean-up and return error

laststep2:
      test  uID,DEST_FPU      ;check where result should be stored
      jnz   @F                ;destination is the FPU
      mov   eax,lpDest
      fstp  tbyte ptr[eax]    ;store result at specified address
      jmp   restore
   @@:
      fstp  tempst            ;store result temporarily
      
restore:
      frstor  content         ;restore all previous FPU registers
      jz    @F
      ffree st(7)             ;free it if not already empty
      fld   tempst
   @@:
      or    al,1              ;to insure EAX!=0
   @@:
      pop   edi
      pop   esi
      pop   edx
      pop   ecx
      pop   ebx
      ret

scient:
      xor   eax,eax
      xor   edx,edx
      lodsb
      cmp   al,"+"
      jz    @F
      cmp   al,"-"
      jnz   scient1
      stc
      rcr   eax,1     ;keep sign of exponent in most significant bit of EAX
   @@:
      lodsb                   ;get next digit after sign

scient1:
      push  eax
      and   eax,0ffh
      jnz   @F        ;continue if 1st byte of exponent is not terminating 0

scienterr:
      pop   eax
      jmp   atoflerr          ;no exponent

   @@:
      sub   al,30h
      jc    scienterr         ;unacceptable character
      cmp   al,9
      ja    scienterr         ;unacceptable character
      add   edx,edx           ;x2
      lea   edx,[edx+edx*4]   ;x2x5=x10
      add   edx,eax
      cmp   edx,4931
      ja    scienterr         ;exponent too large
      lodsb
      or    al,al
      jnz   @B
      pop   eax               ;retrieve exponent sign flag
      rcl   eax,1             ;is most significant bit set?
      jnc   @F
      neg   edx
   @@:
      call  XexpY
      fmul
      jmp   laststep

FpuAtoFL endp

; #########################################################################

;put 10 to the proper exponent (value in EDX) on the FPU

XexpY:
      push  edx
      fild  dword ptr[esp]    ;load the exponent
      fldl2t                  ;load log2(10)
      fmul                    ;->log2(10)*exponent
      pop   edx

;at this point, only the log base 2 of the 10^exponent is on the FPU
;the FPU can compute the antilog only with the mantissa
;the characteristic of the logarithm must thus be removed
      
      fld   st(0)             ;copy the logarithm
      frndint                 ;keep only the characteristic
      fsub  st(1),st          ;keeps only the mantissa
      fxch                    ;get the mantissa on top

      f2xm1                   ;->2^(mantissa)-1
      fld1
      fadd                    ;add 1 back

;the number must now be readjusted for the characteristic of the logarithm

      fscale                  ;scale it with the characteristic
      
;the characteristic is still on the FPU and must be removed

      fstp  st(1)             ;clean-up the register
      ret

;##########################################################################

;shifts the packed BCD string of the integers to the integer position
;EDI points to the BCD string
;ECX = count of positions for shifting the BCD string
    
load_integer:
      push  esi
      .if   cl == 18
            fldz
      .else
            mov   esi,edi
            sub   ecx,18
            neg   ecx
            shr   ecx,1
            push  edi
            .if   !CARRY?     ;even number of integer digits
                  mov   edx,9
                  sub   edx,ecx
                  add   esi,edx
                  rep   movsb
            .else             ;odd number of integer digits
                  mov   edx,8
                  sub   edx,ecx
                  add   esi,edx
                  xor   eax,eax
                  lodsb
                  rol   ax,4
                  test  ecx,ecx
                  .if   !ZERO?
                     @@:
                        rol   ah,4
                        lodsb
                        rol   ax,4
                        stosb
                        dec   ecx
                        jnz   @B
                  .endif
                  mov   [edi],ah
                  inc   edi
            .endif
            mov   ecx,edx
            xor   eax,eax
            rep   stosb
            pop   edi
            fbld  tbyte ptr[edi]
      .endif
      pop   esi
      ret

;###########################################################################

;converts the decimal portion in the packed BCD string to binary
;EDI points to the BCD string

load_decimal:
      test  bh,2
      jnz   @F
      ret
   @@:
      .if   cl == 18
            fldz
      .else
            fbld  tbyte ptr[edi]
            mov   edx,-18
            call  XexpY
            fmul
      .endif
      fadd
      ret

;###########################################################################

end
