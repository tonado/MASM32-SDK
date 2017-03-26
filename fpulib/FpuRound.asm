; #########################################################################
;
;                             FpuRound
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified January 2004 to remove data section
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ; Revised January 2005 to free the FPU st7 register if necessary.
  ;
  ; This FpuRound function rounds an 80-bit REAL number (Src) to the
  ; nearest integer and returns the integer portion at the specified
  ; destination (the FPU itself, a TBYTE memory variable, or a LONG integer
  ; memory variable), unless an invalid operation is reported by the FPU
  ; or the definition of the parameters (with uID) is invalid.
  ;
  ; The source can only be an 80-bit REAL number from the FPU itself or
  ; from memory.
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

FpuRound proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD
        
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
      test  uID,SRC1_REAL     ;is Src an 80-bit REAL in memory?
      jz    srcerr
      mov   eax,lpSrc
      fld   tbyte ptr [eax]
      jmp   dest0             ;go complete process

srcerr:
      frstor content
srcerr1:
      xor   eax,eax
      ret

dest0:
      push  eax               ;reserve space on CPU stack
      fstcw [esp]             ;get current control word
      fwait
      mov   ax,[esp]
      and   ax,0f3ffh         ;code it for rounding
      push  eax
      fldcw [esp]             ;change rounding code of FPU to round

      frndint                 ;round the number
      pop   eax               ;get rid of last push
      fldcw [esp]             ;load back the former control word
      
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;test for invalid operation
      pop   eax               ;clean CPU stack
      jc    srcerr            ;clean-up and return error

      test  uID,DEST_FPU      ;check where result should be stored
      jz    @F                ;destination is not the FPU
      fstp  tempst            ;store it temporarily
      jmp   restore
   @@:
      mov   eax,lpDest
      test  uID,DEST_IMEM
      jnz   @F
      fstp  tbyte ptr [eax]   ;store result as a REAL10
      jmp   restore
   @@:
      fistp dword ptr [eax]   ;store result as an integer

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
    
FpuRound endp

; #########################################################################

end
