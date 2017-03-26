; #########################################################################
;
;                             FpuAdd
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified March 2004 to avoid any potential data loss from the FPU.
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ;
  ;                           Src1 + Src2 -> Dest
  ;
  ; This FpuAdd function adds the numbers from two sources (Src1 and Src2)
  ; with the FPU and returns the result as an 80-bit REAL number at the
  ; specified destination (the FPU itself or a memory location), unless an
  ; invalid operation is reported by the FPU or the definition of the
  ; parameters (with uID) is invalid.
  ;
  ; Either of the two sources can be an 80-bit REAL number from the FPU
  ; itself or from memory, an immediate DWORD value or one in memory,
  ; or one of the FPU constants.
  ;
  ; None of the sources are checked for validity. This is the programmer's
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

FpuAdd proc public lpSrc1:DWORD, lpSrc2:DWORD, lpDest:DWORD, uID:DWORD
        
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; Because a library is assembled before its functions are called, all
; references to external memory data must be qualified for the expected
; size of that data so that the proper code is generated.
;
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE

      test  uID,SRC1_FPU or SRC2_FPU      ;is any data taken from FPU?
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

      test  uID,SRC1_FPU
      jz    @F
      lea   eax,content
      fld   tbyte ptr[eax+28]
      jmp   src2

   @@:
      mov   eax,lpSrc1
      test  uID,SRC1_REAL     ;is Src1 an 80-bit REAL in memory?
      jz    @F                ;check next source for Src1
      fld   tbyte ptr [eax]
      jmp   src2              ;check next parameter for Src2

   @@:
      test  uID,SRC1_DMEM     ;is Src1 a 32-bit integer in memory?
      jz    @F                ;check next source for Src1
      fild  dword ptr [eax]
      jmp   src2              ;check next parameter for Src2

   @@:
      test  uID,SRC1_DIMM     ;is Src1 an immediate 32-bit integer?
      jz    @F                ;check next source for Src1
      fild  lpSrc1
      jmp   src2              ;check next parameter for Src2

   @@:
      test  uID,SRC1_CONST    ;is Src1 one of the FPU constants?
      jnz   @F                ;otherwise no valid ID for Src1

srcerr:
      frstor content
srcerr1:
      xor   eax,eax           ;error code
      ret

   @@:
      test  eax,FPU_PI
      jz    @F
      fldpi
      jmp   src2
   @@:
      test  eax,FPU_NAPIER
      jz    srcerr            ;no correct CONST flag for Src1
      fld1
      fldl2e
      fsub  st,st(1)
      f2xm1
      fadd  st,st(1)
      fscale
      fstp  st(1)
      
;----------------------------------------
;check source for Src2 and load it to FPU
;----------------------------------------

src2:
      test  uID,SRC2_FPU      ;is Src2 taken from FPU?
      jz    @F                ;check next source for Src2
      lea   eax,content
      fld   tbyte ptr[eax+28]
      jmp   dest0             ;go complete process
   @@:
      mov   eax,lpSrc2
      test  uID,SRC2_REAL     ;is Src2 an 80-bit REAL in memory?
      jz    @F
      fld   tbyte ptr [eax]
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC2_DMEM     ;is Src2 a 32-bit integer in memory?
      jz    @F
      fild  dword ptr [eax]
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC2_DIMM     ;is Src2 an immediate 32-bit integer?
      jz    @F
      fild  lpSrc2
      jmp   dest0             ;go complete process
   @@:
      test  uID,SRC2_CONST    ;is Src2 one of the FPU constants?
      jz    srcerr            ;no correct flag for Src2
      test  eax,FPU_PI
      jz    @F
      fldpi                   ;load pi (3.14159...) on FPU
      jmp   dest0             ;go complete process
   @@:
      test  eax,FPU_NAPIER
      jz    srcerr            ;no correct CONST flag for Src2
      fld1
      fldl2e
      fsub  st,st(1)
      f2xm1
      fadd  st,st(1)
      fscale
      fstp  st(1)

dest0:
      fadd
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   eax,1             ;test for invalid operation
      jc    srcerr            ;clean-up and return error

      test  uID,DEST_FPU      ;check where result should be stored
      jnz   @F                ;destination is the FPU
      mov   eax,lpDest
      fstp  tbyte ptr[eax]    ;store result at specified address
      jmp   restore
   @@:
      fstp  tempst            ;store it temporarily

restore:
      frstor  content         ;restore all previous FPU registers

      test  uID,SRC1_FPU or SRC2_FPU      ;was any data taken from FPU?
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
    
FpuAdd endp

; #########################################################################

end
