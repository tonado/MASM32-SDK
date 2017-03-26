; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\kernel32.inc

    ucCmdTail PROTO

    .code       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

ucCmdTail proc

  ; --------------------------------------------
  ; returns the command tail of the command line.
  ;
  ; c:\> drv:\path\yourapp.exe This is your command tail
  ;
  ; The returned command line can be either
  ; drv:\path\yourapp.exe This is your command tail
  ;   or
  ; "drv:\path\yourapp.exe" This is your command tail
  ;
  ; Return string = This is your command tail
  ;
  ; To further parse the command tail you should
  ; copy it to its own buffer and modify it from
  ; there.
  ;
  ; cst yourbuffer, cmdtail_return string_address
  ;  or
  ; invoke ucCopy,cmdtail_return string_address,yourbuffer
  ; --------------------------------------------

    invoke GetCommandLineW
    sub eax, 2

  @@:
    add eax, 2
    cmp WORD PTR [eax], 0
    je zero
    cmp WORD PTR [eax], 34      ; branch on leading double quote
    je quoted
    cmp WORD PTR [eax], 32
    je @B

  unquoted:
    add eax, 2
    cmp WORD PTR [eax], 0
    je zero
    cmp WORD PTR [eax], 32      ; scan to 1st space
    jne unquoted
    jmp trimit

  quoted:
    add eax, 2
    cmp WORD PTR [eax], 0
    je zero
    cmp WORD PTR [eax], 34      ; scan to closing double quote
    jne quoted

  trimit:
    add eax, 2
    cmp WORD PTR [eax], 32      ; trim any leading spaces off cmd tail
    je trimit

  zero:
    ret

ucCmdTail endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
