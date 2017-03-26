; #########################################################################
;
;                             FpuArcsin
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ;
  ;                                  Src
  ;            asin(Src) = atan -------------  -> Dest
  ;                             sqrt(1-Src^2)
  ;
  ; This FpuArcsin function computes the angle in degrees or radians
  ; with the FPU corresponding to the sine value provided in the source
  ; parameter (Src) and returns the result as an 80-bit REAL number at
  ; the specified destination (the FPU itself or a memory location), unless
  ; an invalid operation is reported by the FPU or the definition of the
  ; parameters (with uID) is invalid.
  ;
  ; The source can be an 80-bit REAL number from the FPU itself or from
  ; memory. Its absolute value must be equal to or less than 1.
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

FpuArcsin proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD
        
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
      jmp   dest0                   ;go complete process
      
   @@:
      test  uID,SRC1_REAL     ;is Src an 80-bit REAL in memory?
      jnz   @F                ;valid ID of source

srcerr:
      frstor content
srcerr1:
      xor   eax,eax
      ret

   @@:
      mov   eax,lpSrc
      fld   tbyte ptr[eax]

dest0:
      fld   st(0)             ;copy sine value
      fmul  st,st(0)          ;sin^2
      fld1
      fsubr                   ;1-sin^2 = cos^2
      fsqrt                   ;->cos
      fpatan                  ;i.e. arctan(sin/cos) = arcsin

      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   eax,1             ;test for invalid operation
      jc    srcerr            ;clean-up and return error

      test  uID,ANG_RAD
      jnz   @F                ;jump if angle is required in radians
      pushd 180
      fimul dword ptr[esp]    ;*180 degrees
      fldpi                   ;load pi (3.14159...) on FPU
      fdiv                    ;*180/pi, angle now in degrees
      pop   eax               ;clean CPU stack

      ftst                    ;check for negative value
      fstsw ax                ;retrieve status word from FPU
      fwait
      sahf
      jnc   @F                ;jump if positive number
      pushd 360
      fiadd dword ptr[esp]    ;angle now 0-360
      fwait
      pop   eax               ;clean CPU stack
      
@@:
      test  uID,DEST_FPU      ;check where result should be stored
      jnz   @F                ;destination is the FPU
      mov   eax,lpDest
      fstp  tbyte ptr[eax]    ;store result at specified address
      jmp   restore
   @@:
      fstp  tempst            ;store it temporarily

restore:
      frstor  content         ;restore all previous FPU registers

      test  uID,SRC1_FPU      ;was any data taken from FPU?
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
    
FpuArcsin endp

; #########################################################################

end
