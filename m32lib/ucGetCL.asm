; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    include \masm32\macros\macros.asm

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

ucGetCL proc obuf:DWORD,ccnt:DWORD,argnum:DWORD

  ; --------------------------------------------------------------------------------
  ; algorithm provide double buffer protection, it allocates memory based on the
  ; command tail length so the length cannot be overrun and it allocates the same
  ; length buffer for the user selected argument. When the argument is obtained
  ; from the "ucArgByNum" procedure, its length is checked against the length of
  ; the user supplied buffer and rejected if it is longer. The technique is designed
  ; to prevent deliberate command line exploits.
  ;
  ; ARGUMENTS
  ; obuf   = user supplied output buffer
  ; ccnt   = output buffer character count
  ; argmun = the 1 based arg the user wants 1 = arg1, 2 = arg2 etc ....
  ;
  ; RETURN VALUES
  ; < 0 = buffer not large enough for selected arg
  ;   0 = arg not found
  ; > 0 = arg number read from command tail
  ;
  ; if arg num > 0 result is written to user supplied buffer
  ; --------------------------------------------------------------------------------

    LOCAL pbuf  :DWORD
    LOCAL pcmd  :DWORD
    LOCAL clen  :DWORD
    LOCAL parg  :DWORD
    LOCAL anum  :DWORD
    LOCAL alen  :DWORD

    invoke ucCmdTail                    ; get the command tail
    mov pcmd, eax

    invoke ucLen,pcmd                   ; get the command tail character count
    mov clen, eax

    mov eax, clen                       ; double char count to get BYTE length
    add clen, eax
    mov pbuf, alloc(clen)               ; allocate that much memory
    mov parg, alloc(clen)               ; allocate buffer of same length for arg
    invoke ucCopy,pcmd,pbuf             ; copy it to its own buffer

    invoke ucArgByNum,pbuf,parg,argnum  ; get the specified arg number if it exists
    mov anum, eax

    invoke ucLen,parg                   ; get the selected arg character count
    mov alen, eax

    .if eax > ccnt                      ; if arg is longer than output buffer
      free pbuf                         ; free the temporary buffer
      free parg
      mov eax, -1                       ; set buffer length error return value
      ret
    .endif

    invoke ucCopy,parg,obuf             ; copy arg to output buffer

    free pbuf                           ; free the temporary buffer
    free parg
    mov eax, anum

    ret

ucGetCL endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
