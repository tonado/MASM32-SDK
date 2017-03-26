; #########################################################################
;
;            This procedure was developed with the technical 
;                   assistance of Iczelion and Lucifer
;
; #########################################################################

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

      include \MASM32\INCLUDE\kernel32.inc

  ; ------------------------------------
  ; Read text at end of module for usage
  ; ------------------------------------

    ArgCl PROTO :DWORD,:DWORD

    .code

; #########################################################################

ArgCl proc ArgNum:DWORD, ItemBuffer:DWORD

    LOCAL cmdLine        :DWORD
    LOCAL cmdBuffer[192] :BYTE
    LOCAL tmpBuffer[192] :BYTE

  ; --------------
  ; save esi & edi
  ; --------------
    push esi
    push edi

    invoke GetCommandLine
    mov cmdLine, eax        ; address command line

    cmp ArgNum, 0
    jne @F
    xor eax, eax
      jmp jmp_In
    @@:

    mov esi, cmdLine
    lodsb                   ; read first byte
    cmp al, 34
    je @F                   ; if its not ( " ) exit proc.
      pop edi
      pop esi
      xor eax, eax          ; return zero in eax = no command tail
      ret
    @@:
    
  ; -------------------------------------------------
  ; count quotation marks to see if pairs are matched
  ; -------------------------------------------------
    xor ecx, ecx            ; zero ecx & use as counter
    mov esi, cmdLine
    
    @@:
      lodsb
      cmp al, 0
      je @F
      cmp al, 34            ; [ " ] character
      jne @B
      inc ecx               ; increment counter
      jmp @B
    @@:

    push ecx                ; save count

    shr ecx, 1              ; integer divide ecx by 2
    shl ecx, 1              ; multiply ecx by 2 to get dividend

    pop eax                 ; put count in eax
    cmp eax, ecx            ; check if they are the same
    je @F
      pop edi
      pop esi
      mov eax, 3            ; return 3 in eax = non matching quotation marks
      ret
    @@:

  ; -------------------------------------------
  ; following loop code removes path & filename
  ; from the command line leaving only the tail
  ; -------------------------------------------
    mov esi, cmdLine
    lea edi, tmpBuffer
    
    lodsb           ; read first [ " ]

    @@:
      lodsb
      cmp al, 34
      jne @B        ; loops till next [ " ]
      
    wtIn:
      lodsb
      cmp al, 0
      je wtOut
      stosb         ; write the rest
      jmp wtIn
    wtOut:
      stosb         ; write last byte

  ; -----------------------------------
  ; handle empty quotation marks [ "" ]
  ; -----------------------------------

    lea esi, tmpBuffer
    lea edi, cmdBuffer

    xor edx, edx    ; use as flag, set to 0

    rnsSt:
      lodsb
      cmp al, 0
      je rnsEnd

      .if al != 34
        .if edx == 1
          xor edx, edx
          jmp rnsWrt
        .endif
      .elseif al == 34
        .if edx == 1
          mov al, 255
          stosb
          mov al, 34
          stosb
          dec edx
          jmp rnsSt
        .elseif edx == 0
          inc edx
        .endif
      .endif

    rnsWrt:
      stosb
      jmp rnsSt

    rnsEnd:
      stosb

  ; ----------------------------------
  ; substitute spaces within quotation
  ; marks and remove quotation marks
  ; ----------------------------------
    lea esi, cmdBuffer
    lea edi, cmdBuffer

    subSt:
      lodsb
      cmp al, 0
      jne @F
      jmp subOut
    @@:
      cmp al, 34
      jne subNxt
      jmp subSl     ; goto subloop
    subNxt:
      stosb
      jmp subSt
    ; --------------------------
    subSl:
      lodsb
      cmp al, 32    ; space
      jne @F
        mov al, 254 ; substitute character
      @@:
      cmp al, 34
      jne @F
        jmp subSt
      @@:
      stosb
      jmp subSl
    ; --------------------------
    subOut:
      stosb         ; write last byte

    ; ------------------------
    ; replace tabs with spaces
    ; ------------------------

    lea esi, cmdBuffer
    lea edi, cmdBuffer

    @@:
      lodsb
      cmp al, 0
      je rtOut
      cmp al, 9     ; tab
      jne rtIn
      mov al, 32
    rtIn:
      stosb
      jmp @B
    rtOut:
      stosb         ; write last byte

  ; ----------------------------------------------------
  ; the following code determines the correct arg number
  ; and writes the arg into the destination buffer
  ; ----------------------------------------------------
    lea eax, cmdBuffer
    mov esi, eax
    mov edi, ItemBuffer ; the destination buffer for cmdline arg

    mov ecx, 1          ; use ecx as counter

  ; ---------------------------
  ; strip leading spaces if any
  ; ---------------------------
    @@:
      lodsb
      cmp al, 32
      je @B

    l2St:
      cmp ecx, ArgNum     ; the number of required cmdline arg
      je clSubLp2
      lodsb
      cmp al, 0
      je cl2Out
      cmp al, 32
      jne cl2Ovr           ; if not space

    @@:
      lodsb
      cmp al, 32          ; catch consecutive spaces
      je @B

      inc ecx             ; increment arg count
      cmp al, 0
      je cl2Out

    cl2Ovr:
      jmp l2St

    clSubLp2:
      stosb
    @@:
      lodsb
      cmp al, 32
      je cl2Out
      cmp al, 0
      je cl2Out
      stosb
      jmp @B

    cl2Out:
      mov al, 0
      stosb

  ; ---------------------------------
  ; replace substitutions with spaces
  ; ---------------------------------
    mov esi, ItemBuffer
    mov edi, ItemBuffer

    @@:
      lodsb
      cmp al, 0
      je @F
      cmp al, 254   ; this is the substitute character
      jne nxt1
      mov al, 32
    nxt1:
      stosb
      jmp @B
    @@:

  ; -------------------------------------------------
  ; replace substituted character in [ "" ] with zero
  ; -------------------------------------------------
    mov esi, ItemBuffer
    mov edi, ItemBuffer
    lodsb
    cmp al, 255 ; if substitute char
    jne @F
    mov al, 0   ; replace it with zero
    stosb
    mov eax, 4  ; return value, empty quotation marks as argument
    pop edi
    pop esi
    ret
  @@:

  ; ----------------------------------
  ; put zero as 1st byte in ItemBuffer
  ; if number is not reached by counter
  ; ----------------------------------

    .if ecx < ArgNum
    jmp_In:
      mov edi, ItemBuffer
      mov al, 0
      stosb
      mov eax, 2  ; return value of 2 means arg did not exist
      jmp @F
    .endif

    mov eax, 1  ; return value of 1 means tail has been processed

    @@:

      pop edi
      pop esi

    ret

ArgCl endp

; #########################################################################
;
;       This proc recieves two (2) parameters
;
;       1.  The command line argument number
;       2.  The address of the buffer to put the arg into.
;       
;       Example: If 4 arguments are placed on the command line,
;       progname arg1 arg2 arg3 arg4 , calling this proc with,
;
;       invoke ArgCl,3,ADDR buffer
;
;       will place arg3 into the buffer.
;
;       Note, quoted args are supported I.E. "long file name"
;
;       Ensure buffer size is large enough to recieve the argument.
;       Comand line can only be 128 bytes long so this is the maximum
;       size that can be used as a buffer for the argument.
;       Within a proc,
;
;       LOCAL Buffer[128]:BYTE  ; allocates the required buffer size.
;
;       Return values in eax
;
;       0 = no command tail
;       1 = command tail processed normally
;       2 = processed but arg does not exist
;       3 = unmatched quotation marks
;       4 = empty quotation marks as arg [ "" ]
;
;       Delimiting characters are both tabs and spaces
;
; #########################################################################

end