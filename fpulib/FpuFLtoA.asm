; #########################################################################
;
;                             FpuFLtoA
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; and modified April 2003. A minor flaw was corrected in July 2003.
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ;
  ; This FpuFLtoA function converts an 80-bit REAL number (Src) to its
  ; decimal representation as a zero terminated alphanumeric string which
  ; is returned at the specified memory destination unless an invalid
  ; operation is reported by the FPU or the definition of the parameters
  ; (with uID) is invalid.
  ;
  ; The format of the string can be specified as regular (default) or
  ; scientific notation. The number of decimal places returned must also be
  ; specified but the total number of significant digits must not exceed 16.
  ; When the regular format is specified, the integer portion can also be
  ; padded with preceding spaces to position the decimal point at a
  ; specified location from the start of the string.
  ;
  ; The source can be an 80-bit REAL number from the FPU itself or from
  ; memory.
  ;
  ; The source is not checked for validity. This is the programmer's
  ; responsibility.
  ;
  ; This procedure is based on using an FPU instruction to convert the
  ; REAL number into a specific packed decimal format. After unpacking,
  ; the decimal point is positioned as required.
  ;
  ; Only EAX is used to return error or success. All other CPU registers
  ; are preserved. All FPU registers are preserved.
  ;
  ; -----------------------------------------------------------------------

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include Fpu.inc

      .code

; #########################################################################

FpuFLtoA proc public lpSrc:DWORD, lpDecimal:DWORD, lpDest:DWORD, uID:DWORD

LOCAL tempdw       :DWORD    
LOCAL esize        :DWORD
LOCAL Padding      :DWORD
LOCAL Decimal      :DWORD
LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE
LOCAL bcdstr       :TBYTE
LOCAL oldcw        :WORD
LOCAL truncw       :WORD
LOCAL unpacked[20] :BYTE    

;get the specified number of decimals for result
;and make corrections if necessary

      mov   eax,lpDecimal
      test  uID,SRC2_DMEM
      jz    @F
      mov   eax,[eax]         ;get the decimals from memory
   @@:
      push  eax
      movzx eax,al            ;low byte - number of decimal digits
      cmp   eax,15
      jbe   @F
      mov   eax,15            ;a maximum of 15 decimals is allowed
   @@:
      mov   Decimal,eax
      pop   eax
      movzx eax,ah            ;2nd byte - number of char before decimal point
      cmp   eax,17
      jbe   @F
      mov   eax,17            ;a maximum of 17 characters is allowed
   @@:
      mov   Padding,eax

      test  uID,SRC1_FPU      ;is data taken from FPU?
      jz    @F                ;continue if not

;-------------------------------
;check if top register is empty
;-------------------------------

      fxam                    ;examine its content
      fstsw ax                ;store results in AX
      fwait                   ;for precaution
      sahf                    ;transfer result bits to CPU flag
      jnc   @F                ;not empty if Carry flag not set
      jpe   @F                ;not empty if Parity flag set
      jz    srcerr1           ;empty if Zero flag set

   @@:
      fsave content

;----------------------------------------
;check source for Src and load it to FPU
;----------------------------------------

      test  uID,SRC1_FPU
      jz    @F
      lea   eax,content
      fld   tbyte ptr[eax+28]
      jmp   dest0

   @@:
      test  uID,SRC1_REAL     ;is Src an 80-bit REAL in memory?
      jz    srcerr            ;no proper source identificaiton
      mov   eax,lpSrc
      fld   tbyte ptr [eax]
      jmp   dest0             ;go complete process
      
srcerr:
      frstor content
srcerr1:
      push  edi
      mov   edi,lpDest
      mov   eax,"ORRE"
      stosd
      mov   ax,"R"
      stosw
      pop   edi
      xor   eax,eax
      ret

dest0:

;-------------------------------------------
;first examine the value on FPU for validity
;-------------------------------------------

      fxam                    ;examine value on FPU
      fstsw ax                ;get result
      fwait
      sahf                    ;transfer to CPU flags
      jz    maybezero
      jpo   srcerr            ;C3=0 and C2=0 would be NAN or unsupported
      jnc   getnumsize        ;continue if normal finite number

;--------------------------------
;value to be converted = INFINITY
;--------------------------------

      push  ecx
      push  esi
      push  edi
      mov   edi,lpDest
      mov   al,"+"
      test  ah,2              ;C1 field = sign
      jz    @F
      mov   al,"-"
   @@:
      stosb
      mov   eax,"IFNI"
      stosd
      mov   eax,"YTIN"
      stosd
      jmp   finish      

;-------------------------
;value to be converted = 0
;-------------------------

maybezero:
      jpe   getnumsize        ;would be denormalized number
      fstp  st(0)             ;flush that 0 value off the FPU
      push  ecx
      push  esi
      push  edi
      mov   edi,lpDest
      test  uID,STR_SCI       ;scientific notation?
      jnz   @F                ;no padding
      mov   ecx,Padding
      sub   ecx,2
      jle   @F                ;no padding specified or necessary
      mov   al," "
      rep   stosb
   @@:
      mov   ax,3020h          ;" 0" szstring
      stosw                   ;write it
      jmp   finish
      
;---------------------------
; get the size of the number
;---------------------------

getnumsize:
      fldlg2                  ;log10(2)
      fld   st(1)             ;copy Src
      fabs                    ;insures a positive value
      fyl2x                   ;->[log2(Src)]*[log10(2)] = log10(Src)
      
      fstcw oldcw             ;get current control word
      fwait
      mov   ax,oldcw
      or    ax,0c00h          ;code it for truncating
      mov   truncw,ax
      fldcw truncw            ;insure rounding code of FPU to truncating
      
      fist  esize             ;store characteristic of logarithm
      fldcw oldcw             ;load back the former control word

      ftst                    ;test logarithm for its sign
      fstsw ax                ;get result
      fwait
      sahf                    ;transfer to CPU flags
      sbb   esize,0           ;decrement esize if log is negative
      fstp  st(0)             ;get rid of the logarithm

;-----------------------------------------------------------------------
; get the power of 10 required to generate an integer with the specified
; number of significant digits
;-----------------------------------------------------------------------

      mov   eax,uID
      and   eax,STR_SCI
      .if   eax == 0          ;regular decimal notation
            mov   eax,esize
            or    eax,eax     ;check if number is < 1
            js    @F
            .if   eax > 15    ;if number is >= 10^16
                  or    uID,STR_SCI ;switch to scientific notation
                  mov   Decimal,15  ;insures 15 decimal places in result
                  jmp   scific
            .endif
            add   eax,Decimal
            .if   eax > 15    ;if integer + decimal digits > 16
                  sub   eax,15
                  sub   Decimal,eax ;reduce decimal digits as required
            .endif
         @@:
            push  Decimal
            pop   tempdw
      .else                   ;scientific notation
      scific:
            mov   eax,Decimal
            sub   eax,esize
            mov   tempdw,eax
      .endif

;----------------------------------------------------------------------------------------
; multiply the number by the power of 10 to generate required integer and store it as BCD
;----------------------------------------------------------------------------------------

.if   tempdw != 0
      fild  tempdw
      fldl2t
      fmul                    ;->log2(10)*exponent
      fld   st(0)
      frndint                 ;get the characteristic of the log
      fxch
      fsub st,st(1)           ;get only the fractional part but keep the characteristic
      f2xm1                   ;->2^(fractional part)-1
      fld1
      fadd                    ;add 1 back
      fscale                  ;re-adjust the exponent part of the REAL number
      fstp  st(1)             ;get rid of the characteristic of the log
      fmul                    ;->16-digit integer
.endif

      fbstp bcdstr            ;->TBYTE containing the packed digits
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   eax,1             ;test for invalid operation
      jc    srcerr            ;clean-up and return error

;------------------------------------------------------------------------------
; unpack BCD, the 10 bytes returned by the FPU being in the little-endian style
;------------------------------------------------------------------------------

      push  ecx
      push  esi
      push  edi
      lea   esi,bcdstr+9      ;go to the most significant byte (sign byte)
      lea   edi,unpacked
      mov   eax,3020h
      mov   cl,byte ptr[esi]  ;sign byte
      .if   cl == 80h
            mov   al,"-"      ;insert sign if negative number
      .endif
      stosw
      mov   ecx,9
   @@:
      dec   esi
      movzx eax,byte ptr[esi]
      ror   ax,4
      ror   ah,4
      add   ax,3030h
      stosw
      dec   ecx
      jnz   @B

      mov   edi,lpDest
      lea   esi,unpacked
      test  uID,STR_SCI       ;scientific notation?
      jnz   scientific

;************************
; REGULAR STRING NOTATION
;************************

;------------------------------
; check if padding is specified
;------------------------------

      mov   ecx,Padding
      or    ecx,ecx           ;check if padding is specified
      jz    nopadding
      
      mov   edx,2             ;at least 1 integer + sign
      mov   eax,esize
      or    eax,eax
      js    @F                ;only 1 integer digit if size is < 1
      add   edx,eax           ;->number of integer digits
   @@:
      sub   ecx,edx
      jle   nopadding
      mov   al," "
      rep   stosb

nopadding:
      pushfd                  ;save padding flags
      movsb                   ;insert sign
      mov   ecx,1             ;at least 1 integer digit
      mov   eax,esize
      or    eax,eax           ;is size negative (i.e. number smaller than 1)
      js    @F
      add   ecx,eax
   @@:
      mov   eax,Decimal
      add   eax,ecx           ;->total number of digits to be displayed
      sub   eax,19
      sub   esi,eax           ;address of 1st digit to be displayed
      pop   eax               ;retrieve padding flags in EAX
      .if   byte ptr[esi-1] == "1"
            dec   esi
            inc   ecx
            push  eax         ;transfer padding flags through stack
            popfd             ;retrieve padding flags
            jle   @F          ;no padding was necessary
            dec   edi         ;adjust for one less padding byte
      .endif
   @@:
      rep   movsb             ;copy required integer digits
      mov   ecx,Decimal
      or    ecx,ecx
      jz    @F
      mov   al,"."
      stosb
      rep   movsb             ;copy required decimal digits
   @@:
      jmp   finish

;********************
; SCIENTIFIC NOTATION
;********************

scientific:
      movsb                   ;insert sign
      mov   ecx,Decimal
      mov   eax,18
      sub   eax,ecx
      add   esi,eax
      cmp   byte ptr[esi-1],"1"
      pushfd                  ;save flags for extra "1"
      jnz   @F
      dec   esi
   @@:
      movsb                   ;copy the integer
      mov   al,"."
      stosb
      rep   movsb             ;copy the decimal digits

      mov   al,"E"
      stosb
      mov   al,"+"
      mov   ecx,esize
      popfd                   ;retrieve flags for extra "1"
      jnz   @F                ;no extra "1"
      inc   ecx               ;adjust exponent
   @@:
      or    ecx,ecx
      jns   @F
      mov   al,"-"
      neg   ecx               ;make number positive
   @@:
      stosb                   ;insert proper sign

;Note: the absolute value of the size could not exceed 4931
      
      mov   eax,ecx
      mov   cl,100
      div   cl                ;->thousands & hundreds in AL, tens & units in AH
      push  eax
      and   eax,0ffh          ;keep only the thousands & hundreds
      mov   cl,10
      div   cl                ;->thousands in AL, hundreds in AH
      add   ax,3030h          ;convert to characters
      stosw                   ;insert them
      pop   eax
      shr   eax,8             ;get the tens & units in AL
      div   cl                ;tens in AL, units in AH
      add   ax,3030h          ;convert to characters
      stosw                   ;insert them

finish:
      xor   eax,eax
      stosb                   ;string terminating 0
      pop   edi
      pop   esi
      pop   ecx

      frstor content

      or    al,1              ;to insure EAX!=0
      ret
      
FpuFLtoA endp

; #########################################################################

end
