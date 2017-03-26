; #########################################################################
;
;                             FpuCos
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified January 2004 to prevent stack faults and to adjust
  ; angles outside the acceptable range if necessary.
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ;
  ;                           cos(Src) -> Dest
  ;
  ; This FpuCos function computes the cosine of an angle in degrees or radians
  ; (Src) with the FPU and returns the result as an 80-bit REAL number at
  ; the specified destination (the FPU itself or a memory location), unless
  ; an invalid operation is reported by the FPU or the definition of the
  ; parameters (with uID) is invalid.
  ;
  ; The source can be an 80-bit REAL number from the FPU itself or from
  ; memory, an immediate DWORD value or one in memory.
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

FpuCos proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD
        
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
      fild  dword ptr [eax]               ;lpSrc2
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC1_DIMM     ;is Src an immediate 32-bit integer?
      jnz   @F                ;otherwise no correct flag for Src

srcerr:
      frstor content
srcerr1:
      xor   eax,eax
      ret

   @@:
      fild  lpSrc

dest0:
      test  uID,ANG_RAD
      jnz   @F                ;jump if angle already in radians
      fldpi                   ;load pi (3.14159...) on FPU
      fmul
      pushd 180
      fidiv word ptr[esp]     ;value now in radians
      fwait
      pop   eax               ;clean the stack
   @@:
      fldpi
      fadd  st,st             ;->2pi
      fxch
   @@:
      fprem                   ;reduce the angle
      fcos
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;test for invalid operation
      jc    srcerr            ;clean-up and return error
      sahf                    ;transfer to the CPU flags
      jpe   @B                ;reduce angle again if necessary
      fstp  st(1)             ;get rid of the 2pi

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
    
FpuCos endp

; #########################################################################

end
