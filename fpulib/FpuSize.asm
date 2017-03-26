; #########################################################################
;
;                             FpuSize
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002.
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ;
  ; This FpuSize function computes the exponent of a number (Src) as if it
  ; were expressed in scientific notation and returns the result as a LONG
  ; integer at the specified destination, unless an invalid operation
  ; is reported by the FPU or the definition of the parameters (with uID)
  ; is invalid.
  ;
  ; The source can be an 80-bit REAL number from the FPU itself or from
  ; memory, or an immediate DWORD value or one in memory. The FPU
  ; constants are not allowed as input. If the source is taken from the
  ; FPU, its value will be preserved. The destination must be a pointer
  ; to a 32-bit integer memory variable.
  ;
  ; The source is not checked for validity. This is the programmer's
  ; responsibility.
  ;
  ; This function simply computes the common logarithm (base 10) of the
  ; absolute value of the number and returns the characteristic
  ; (i.e. power of 10), adjusted if necessary for a negative log value.
  ; For example,
  ; 5432    would return +3  (log =  3.735)
  ; 5.432   would return  0  (log =  0.735)
  ; 0.05432 would return -2  (log = -1.265)
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

FpuSize proc public lpSrc:DWORD, lpDest:DWORD, uID:DWORD
        
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
      jz    continue          ;go check for potential overflow

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
      jz    srcerr            ;no correct flag for Src
      fild  lpSrc
      jmp   dest0             ;go complete process
      
srcerr:
      frstor content
srcerr1:
      xor   eax,eax
      ret

dest0:
      fabs                    ;insures a positive value
      ftst                    ;check the value on the FPU
      fstsw ax                ;store the result flags in AX
      fwait
      sahf                    ;transfer flags to CPU flag register
      jnz   @F                ;not NAN or zero
      jc    srcerr            ;invalid number or infinity
      mov   eax,lpDest
      mov   dword ptr[eax],80000000h     ;code it for 0 value
      jmp   finish            ;this avoids an invalid operation if computing
                              ;the logarithm of zero was attempted

   @@:
      fldlg2                  ;load log10(2)
      fxch                    ;set up registers for next operation
      fyl2x                   ;->[log2(x)]*[log10(2)] = log(x) base 10
      push  eax               ;reserve space on CPU stack
      fstcw [esp]             ;get current control word
      fwait
      mov   ax,[esp]
      and   ax,0f3ffh         ;clear RC field
      or    ax,0400h          ;code it for rounding down
      push  eax
      fldcw [esp]             ;change rounding code of FPU to rounding down
                              ;towards -INFINITY
      mov   eax,lpDest
      fistp dword ptr[eax]    ;store integer result at specified address
      fldcw [esp+4]           ;load back the former control word
      add   esp,8             ;restore stack pointer

finish:
      frstor content
      or    al,1              ;to insure EAX!=0
      ret
    
FpuSize endp

; #########################################################################

end
