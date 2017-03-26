; #########################################################################

    ; -----------------------------------------
    ; This procedure was written by Tim Roberts
    ; -----------------------------------------

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; #########################################################################

align 4

MemCopy proc public uses esi edi Source:PTR BYTE,Dest:PTR BYTE,ln:DWORD

    ; ---------------------------------------------------------
    ; Copy ln bytes of memory from Source buffer to Dest buffer
    ;      ~~                      ~~~~~~           ~~~~
    ; USAGE:
    ; invoke MemCopy,ADDR Source,ADDR Dest,4096
    ;
    ; NOTE: Dest buffer must be at least as large as the source
    ;       buffer otherwise a page fault will be generated.
    ; ---------------------------------------------------------

    cld
    mov esi, [Source]
    mov edi, [Dest]
    mov ecx, [ln]

    shr ecx, 2
    rep movsd

    mov ecx, [ln]
    and ecx, 3
    rep movsb

    ret

MemCopy endp

; #########################################################################

end
