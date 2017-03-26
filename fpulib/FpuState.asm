; #########################################################################
;
;                             FpuState
;
;##########################################################################

  ; -----------------------------------------------------------------------
  ; This procedure was written by Raymond Filiatreault, March 2004
  ; Modified April, 2005, to include an ID of the call in the report
  ;
  ; This FpuState function converts the content of all the FPU registers
  ; to a null-terminated alphanumeric string at the specified destination
  ; address.
  ;
  ; All the CPU and FPU registers are preserved.
  ;
  ; -----------------------------------------------------------------------

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include Fpu.inc
    includelib Fpu.lib

    .code

; #########################################################################

FpuState proc public lpDest:DWORD, uID:DWORD
        
LOCAL content[108] :BYTE
LOCAL buffer[4]    :BYTE

      pushfd
      pushad
      fsave content
      fwait
      lea   esi,content
      mov   edi,lpDest

;caller ID

      mov   eax,"  DI"
      stosd                   ;write "ID  " to destination
      mov   eax,uID           ;get ID parameter
      xor   ecx,ecx
      push  ecx               ;to be used as a terminator
      mov   cl,10

;convert ID from binary to ASCII

   @@:
      xor   edx,edx
      div   ecx
      add   dl,30h            ;convert remainder to ASCII
      push  edx               ;store it on the stack
      or    eax,eax           ;is conversion completed
      jnz   @B                ;continue if not

;recover ASCII characters one by one and store in buffer

   @@:
      pop   eax
      or    eax,eax           ;is it the end
      jz    @F                ;jump out if it is
      stosb
      jmp   @B

   @@:
      mov   ax,0A0Dh
      stosw                   ;crlf

;Control Word

      mov   eax,"  WC"
      stosd                   ;write "CW  " to destination
      lodsd                   ;get Control Word in AX
      shl   eax,16            ;shift it to the H.O. word
      mov   ecx,4
   @@:
      mov   al,0
      rol   eax,1
      mov   ah," "
      add   al,"0"
      stosw
      dec   ecx
      jnz   @B                ;last one is the IC field
      
      xor   ax,ax
      rol   eax,2
      ror   ax,1
      rol   ah,1
      add   ax,3030h
      stosw                   ;write the RC field
      mov   al," "
      stosb
      
      xor   ax,ax
      rol   eax,2
      ror   ax,1
      rol   ah,1
      add   ax,3030h
      stosw                   ;write the PC field
      mov   ax,"  "
      stosw

      mov   ecx,8
   @@:
      mov   al,0
      rol   eax,1
      mov   ah," "
      add   al,"0"
      stosw
      dec   ecx
      jnz   @B                ;write the interrupt masks
      dec   edi
      mov   ax,0A0Dh
      stosw                   ;crlf

;Status Word

      mov   eax,"  WS"
      stosd                   ;write "SW  " to destination
      lodsd                   ;get Status Word in AX
      shl   eax,16            ;shift it to the H.O. word
      mov   ecx,2
   @@:
      mov   al,0
      rol   eax,1
      mov   ah," "
      add   al,"0"
      stosw
      dec   ecx
      jnz   @B                ;last one is the C3 field

      xor   ax,ax
      rol   eax,3
      mov   buffer,al         ;TOP field
      push  eax
      and   eax,7
      ror   ax,1
      rol   eax,1
      ror   ax,2
      rol   ah,1
      add   eax,20303030h
      stosd                   ;write the TOP field
      pop   eax

      mov   ecx,3
   @@:
      mov   al,0
      rol   eax,1
      mov   ah," "
      add   al,"0"
      stosw
      dec   ecx
      jnz   @B                ;write the C2, C1, C0 field
      mov   al," "
      stosb

      mov   al,0
      rol   eax,1
      add   al,30h
      mov   ah," "
      stosw
      mov   ecx,7
      jmp   @F
      szflags     db    " IDZOUPS"
   @@:
      mov   al,0
      rol   eax,1
      mov   ah," "
      .if   al == 1
            mov   al,szflags[ecx]
      .else
            mov   al,szflags[ecx]
            or    al,20h
      .endif
      stosw
      dec   ecx
      jnz   @B                ;write the interrupt flags
      dec   edi
      mov   ax,0A0Dh
      stosw                   ;crlf

;Tag Word

      mov   eax,"  WT"
      stosd                   ;write "TW  " to destination
      lodsd                   ;get Tag Word in AX
      mov   cl,buffer
      shl   cl,1
      ror   ax,cl
      shl   eax,16            ;shift it to the H.O. word
      mov   ecx,8
   @@:
      mov   al,0
      ror   eax,2
      rol   ax,2
      push  eax
      .if   al == 0
            mov   eax," LAV"
      .elseif al == 1
            mov   eax," LUN"
      .elseif al == 2
            mov   eax," NaN"
      .else
            mov   eax," ERF"
      .endif
      stosd
      pop   eax
      dec   ecx
      jnz   @B
      dec   edi
      mov   ax,0A0Dh
      stosw                   ;crlf

;Instruction pointer

      mov   eax,"  PI"
      stosd                   ;write "IP  " to destination
      lodsd                   ;get Instruction pointer in EAX
      mov   ecx,8
   @@:
      rol   eax,4
      push  eax
      and   al,0fh
      add   al,30h
      .if   al > "9"
            add   al,7
      .endif
      stosb                   ;write each nibble as a hex number
      pop   eax
      dec   ecx
      jnz   @B
      mov   ax,0A0Dh
      stosw                   ;crlf

;Code segment

      mov   eax,"  SC"
      stosd                   ;write "CS  " to destination
      lodsd                   ;get Code segment in AX
      shl   eax,16            ;shift it to the H.O. word
      mov   ecx,4
   @@:
      rol   eax,4
      push  eax
      and   al,0fh
      add   al,30h
      .if   al > "9"
            add   al,7
      .endif
      stosb                   ;write each nibble as a hex number
      pop   eax
      dec   ecx
      jnz   @B
      mov   ax,0A0Dh
      stosw                   ;crlf

;Operand address

      mov   eax,"  AO"
      stosd                   ;write "OA  " to destination
      lodsd                   ;get Operand address in EAX
      mov   ecx,8
   @@:
      rol   eax,4
      push  eax
      and   al,0fh
      add   al,30h
      .if   al > "9"
            add   al,7
      .endif
      stosb                   ;write each nibble as a hex number
      pop   eax
      dec   ecx
      jnz   @B
      mov   ax,0A0Dh
      stosw                   ;crlf

;Data segment

      mov   eax,"  SD"
      stosd                   ;write "DS  " to destination
      lodsd                   ;get Data segment in AX
      shl   eax,16            ;shift it to the H.O. word
      mov   ecx,4
   @@:
      rol   eax,4
      push  eax
      and   al,0fh
      add   al,30h
      .if   al > "9"
            add   al,7
      .endif
      stosb                   ;write each nibble as a hex number
      pop   eax
      dec   ecx
      jnz   @B
      
      mov   ax,0A0Dh
      stosw                   ;crlf

;Data registers

      xor   ecx,ecx           ;count for registers
datareg:
      mov   ax,0A0Dh
      stosw                   ;crlf

      push  ecx
      mov   eax," 0TS"
      shl   ecx,16
      add   eax,ecx
      stosd                   ;write "STx " to destination
      
      shr   ecx,16
      add   cl,buffer
      and   cl,7
      shl   cl,1
      lea   eax,content+8
      mov   ax,[eax]          ;get Tag Word in AX
      shr   eax,cl
      and   al,3              ;get Tag of register in AL
      .if   al == 3           ;register is FREE
            mov   eax,"PME "
            stosd
            mov   ax,"YT"
            stosw
      .elseif al == 1         ;register == 0
            invoke FpuExam,esi,SRC1_REAL
            mov   dl,"+"
            test  eax,XAM_NEG
            jz    @F
            mov   dl,"-"
         @@:
            mov   eax," 0  "
            mov   ah,dl
            stosd
      .elseif al == 0         ;valid non-zero number
            invoke FpuFLtoA,esi,15,edi,SRC1_REAL or SRC2_DIMM or STR_SCI
            add   edi,24
      .else
            invoke FpuExam,esi,SRC1_REAL
            test  eax,XAM_VALID
            jnz   @F          ;valid = INFINITY, if not = INDEFINITE
            mov   eax,"DNI "
            stosd
            mov   eax,"NIFE"
            stosd
            mov   eax," ETI"
            stosd
            jmp   nextST
         @@:
            mov   dx,"+ "
            test  eax,XAM_NEG
            jz    @F
            mov   dh,"-"
         @@:
            mov   ax,dx
            stosw
            mov   eax,"IFNI"
            stosd
            mov   eax,"YTIN"
            stosd
      .endif

nextST:
      add   esi,10
      pop   ecx
      inc   ecx
      cmp   cl,8
      jb    datareg

      mov   byte ptr[edi],0

      frstor content
      fwait
      popad
      popfd
      ret
    
FpuState endp

; #########################################################################

end
