; #########################################################################
;
;                             FpuTexpX
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ;
  ;            10^(Src) = antilog2[ log2(10) * Src ] -> Dest
  ;
  ; This FpuTexpX function computes the base 10 antilogarithm of a number.
  ; It raises 10 to the power of the Src number with the FPU and returns
  ; the result as an 80-bit REAL number at the specified destination
  ; (the FPU itself or a memory location), unless an invalid operation is
  ; reported by the FPU or the definition of the parameters (with uID) is
  ; invalid.
  ;
  ; The exponent can be an 80-bit REAL number from the FPU itself or from
  ; memory, an immediate DWORD value or one in memory, or one of the FPU
  ; constants.
  ;
  ; The source is not checked for validity. This is the programmer's
  ; responsibility.
  ;
  ; Only EAX is used to return error or success. All other CPU registers
  ; are preserved.
  ;
  ; IF a source is specified to be the FPU top data register, it would be
  ; removed from the FPU. It would be replaced by the result only if the
  ; FPU is specified as the destination.
  ;
  ; IF source data is only from memory
  ; AND the FPU is specified as the destination for the result,
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

FpuTexpX proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD
        
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; Because a library is assembled before its functions are called, all
; references to external memory data must be qualified for the expected
; size of that data so that the proper code is generated.
;
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE

      test  uID,SRC1_FPU      ;is Src taken from FPU?
      jz    continue

;-------------------------------
;check if top register is empty
;-------------------------------

      fxam                    ;examine its content
      fstsw ax                ;store results in AX
      fwait                   ;for precaution
      sahf                    ;transfer result bits to CPU flag
      jnc   continue          ;not empty if Carry flag not set
      jpe   continue          ;not empty if Parity flag set
      jz    srcerr1           ;empty if Zero flag set

continue:
      fsave content

;----------------------------------------
;check source for Src and load it to FPU
;----------------------------------------

      test  uID,SRC1_FPU      ;is Src taken from FPU?
      jz    @F
      lea   eax,content
      fld   tbyte ptr[eax+28]
      jmp   dest0             ;go complete process
      
   @@:
      mov   eax,lpSrc
      test  uID,SRC1_REAL     ;is Src an 80-bit REAL in memory?
      jz    @F
      fld   tbyte ptr [eax]
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC1_DMEM     ;is Src a 32-bit integer in memory?
      jz    @F
      fild  dword ptr [eax]
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC1_DIMM     ;is Src an immediate 32-bit integer?
      jz    @F
      fild  lpSrc
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC1_CONST    ;is Src one of the FPU constants?
      jnz   @F                ;otherwise no correct flag for Src

srcerr:
      frstor content
srcerr1:
      xor   eax,eax
      ret

   @@:
      test  eax,FPU_PI
      jz    @F
      fldpi                   ;load pi (3.14159...) on FPU
      jmp   dest0             ;go complete process
   @@:
      test  eax,FPU_NAPIER
      jz    srcerr            ;no correct CONST flag for Src
      fld1
      fldl2e
      fsub  st,st(1)
      f2xm1
      fadd  st,st(1)
      fscale
      fstp  st(1)

dest0:
      fldl2t                  ;->log2(10)
      fmul                    ;->log2(10)*Src
      
;the FPU can compute the antilog only with the mantissa
;the characteristic of the logarithm must thus be removed
      
      fld   st                ;copy the logarithm
      frndint                 ;keep only the characteristic
      fsub  st(1),st          ;keeps only the mantissa
      fxch                    ;get the mantissa on top

      f2xm1                   ;->2^(mantissa)-1
      fld1
      fadd                    ;add 1 back

;the number must now be readjusted for the characteristic of the logarithm

      fscale                  ;scale it with the characteristic
      
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;test for invalid operation
      jc    srcerr            ;clean-up and return error
      
;the characteristic is still on the FPU and must be removed

      fstp  st(1)             ;overwrite the characteristic

      test  uID,DEST_FPU      ;check where result should be stored
      jnz   @F                ;leave result on FPU if so indicated
      mov   eax,lpDest
      fstp  tbyte ptr[eax]    ;store result at specified address
      jmp   restore
   @@:
      fstp  tempst            ;store it temporarily

restore:
      frstor  content         ;restore all previous FPU registers

      test  uID,SRC1_FPU      ;was Src taken from FPU
      jz    @F
      fstp  st                ;remove source

   @@:
      test  uID,DEST_FPU
      jz    @F                ;the new value has been stored in memory
                              ;none of the FPU data was modified

      ffree st(7)             ;free it if not already empty
      fld   tempst            ;load the new value on the FPU
   @@:
      or    al,1              ;to insure EAX!=0
      ret
    
FpuTexpX endp

; #########################################################################

end
