; #########################################################################
;
;                             FpuComp
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, December 2002
  ; Modified March 2004 to avoid any potential data loss from the FPU
  ;
  ; This FpuComp function compares one number (Src1) to another (Src2)
  ; with the FPU and returns the result in EAX as coded bits:
  ;         EAX = 0     comparison impossible
  ;         bit 0       1 = Src1 = Src2
  ;         bit 1       1 = Src1 > Src2
  ;         bit 2       1 = Src1 < Src2
  ;
  ; Either of the two sources can be an 80-bit REAL number from the FPU
  ; itself or from memory, an immediate DWORD value or one in memory,
  ; or one of the FPU constants. If one of the sources is from the FPU,
  ; its value will be preserved if no error is reported.
  ;
  ; None of the sources are checked for validity. This is the programmer's
  ; responsibility.
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

FpuComp proc public lpSrc1:DWORD, lpSrc2:DWORD, uID:DWORD
        
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
;
; Because a library is assembled before its functions are called, all
; references to external memory data must be qualified for the expected
; size of that data so that the proper code is generated.
;
;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

LOCAL content[108] :BYTE
LOCAL tempst       :TBYTE

      test  uID,SRC1_FPU or SRC2_FPU      ;is data taken from FPU?
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
;check source for Src1 and load it to FPU
;----------------------------------------

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
      fxch
      fcom
      fstsw ax                ;retrieve exception flags from FPU
      fwait
      shr   al,1              ;test for invalid operation
      jc    srcerr            ;clean-up and return result
      sahf                    ;transfer to the CPU flags
      jpe   srcerr            ;error if non comparable
      ja    greater
      jc    @F
      mov   eax,CMP_EQU       ;Src2 = Src1
      jmp   finish

   @@:
      mov   eax,CMP_LOWER     ;Src1 < Src2
      jmp   finish

greater:
      mov   eax,CMP_GREATER   ;Src1 > Src2

finish:
      frstor content

      ret
    
FpuComp endp

; #########################################################################

end
