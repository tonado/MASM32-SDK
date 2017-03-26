; #########################################################################
;
;                             FpuExam
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ;
  ; This FpuExam function examines an 80-bit REAL number (Src) for its
  ; validity, its sign, a value of zero, an absolute value less than 1, and
  ; a value of infinity.
  ; The result is returned in EAX as coded bits:
  ;         EAX = 0     invalid number
  ;         bit 0       1 = valid number
  ;         bit 1       1 = number is equal to zero
  ;         bit 2       1 = number is negative
  ;         bit 3       1 = number less than 1 but not zero
  ;         bit 4       1 = number is infinity
  ; If the source was on the FPU, it will be preserved if no error is
  ; reported.
  ;
  ; The source can only be an 80-bit REAL number from the FPU itself or
  ; from memory.
  ;
  ; Only EAX is used to return the result. All other CPU registers are
  ; preserved. All FPU registers are also preserved.
  ;
  ; -----------------------------------------------------------------------

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include Fpu.inc

    .code

; #########################################################################

FpuExam proc public lpSrc:DWORD, uID:DWORD
        
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; Because a library is assembled before its functions are called, all
; references to external memory data must be qualified for the expected
; size of that data so that the proper code is generated.
;
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE

      push  edx
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
      xor   eax,eax
      ret

dest0:
      xor   edx,edx
      ftst                    ;test number
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;invalid operation?
      jc    srcerr

      sahf                    ;transfer flags to CPU flag register
      jnz   @F                ;if not 0 value or NAN
      jc    examine           ;go check for infinity or NAN value
      or    edx,XAM_ZERO or XAM_SMALL
      jmp   finish            ;no need for checking for sign or size if 0
      
   @@:
      jnc   @F                ;number is not negative
      or    edx,XAM_NEG

;check for size smaller than 1 by comparing the absolute value to 1

   @@:
      fabs                    ;make sure it is positive
      fld1                    ;for comparing to 1
      fcompp                  ;compare 1 to absolute value and pop both
      fstsw ax                ;retrieve result flags from FPU
      fwait
      sahf                    ;transfer flags to CPU flag register
      jc    finish            ;src>1
      jz    finish            ;src=1
      or    edx,XAM_SMALL     ;value less than 1 

finish:
      frstor content
      mov   eax,edx
      pop   edx               ;retrieve its original value
      or    al,1              ;to indicate source was a valid number
      ret

examine:                      ;strictly for infinity value
      fxam
      fstsw ax                ;retrieve result of fxam
      fwait
      sahf                    ;transfer flags to CPU flag register
      jpo   srcerr            ;must be NAN
      or    edx,XAM_INFINIT
      jmp   finish
      

FpuExam endp

; #########################################################################

end
