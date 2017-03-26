; #########################################################################

      .386                      ; force 32 bit code
      .model flat, stdcall      ; memory model & calling convention
      option casemap :none      ; case sensitive

      include \masm32\include\kernel32.inc

      GetCL PROTO :DWORD,:DWORD

    .code

; #########################################################################

GetCL proc ArgNum:DWORD, ItemBuffer:DWORD

  ; -------------------------------------------------
  ; arguments returned in "ItemBuffer"
  ;
  ; arg 0 = program name
  ; arg 1 = 1st arg
  ; arg 2 = 2nd arg etc....
  ; -------------------------------------------------
  ; Return values in eax
  ;
  ; 1 = successful operation
  ; 2 = no argument exists at specified arg number
  ; 3 = non matching quotation marks
  ; 4 = empty quotation marks
  ; -------------------------------------------------

    LOCAL lpCmdLine      :DWORD
    LOCAL cmdBuffer[192] :BYTE
    LOCAL tmpBuffer[192] :BYTE

    push esi
    push edi

    invoke GetCommandLine
    mov lpCmdLine, eax        ; address command line

  ; -------------------------------------------------
  ; count quotation marks to see if pairs are matched
  ; -------------------------------------------------
    xor ecx, ecx            ; zero ecx & use as counter
    mov esi, lpCmdLine
    
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

  ; ------------------------
  ; replace tabs with spaces
  ; ------------------------
    mov esi, lpCmdLine
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

  ; -----------------------------------------------------------
  ; substitute spaces in quoted text with replacement character
  ; -----------------------------------------------------------
    lea eax, cmdBuffer
    mov esi, eax
    mov edi, eax

    subSt:
      lodsb
      cmp al, 0
      jne @F
      jmp subOut
    @@:
      cmp al, 34
      jne subNxt
      stosb
      jmp subSl     ; goto subloop
    subNxt:
      stosb
      jmp subSt

    subSl:
      lodsb
      cmp al, 32    ; space
      jne @F
        mov al, 254 ; substitute character
      @@:
      cmp al, 34
      jne @F
        stosb
        jmp subSt
      @@:
      stosb
      jmp subSl

    subOut:
      stosb         ; write last byte

  ; ----------------------------------------------------
  ; the following code determines the correct arg number
  ; and writes the arg into the destination buffer
  ; ----------------------------------------------------
    lea eax, cmdBuffer
    mov esi, eax
    lea edi, tmpBuffer

    mov ecx, 0          ; use ecx as counter

  ; ---------------------------
  ; strip leading spaces if any
  ; ---------------------------
    @@:
      lodsb
      cmp al, 32
      je @B

    l2St:
      cmp ecx, ArgNum     ; the number of the required cmdline arg
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

  ; ------------------------------
  ; exit if arg number not reached
  ; ------------------------------
    .if ecx < ArgNum
      mov edi, ItemBuffer
      mov al, 0
      stosb
      mov eax, 2  ; return value of 2 means arg did not exist
      pop edi
      pop esi
      ret
    .endif

  ; -------------------------------------------------------------
  ; remove quotation marks and replace the substitution character
  ; -------------------------------------------------------------
    lea eax, tmpBuffer
    mov esi, eax
    mov edi, ItemBuffer

    rqStart:
      lodsb
      cmp al, 0
      je rqOut
      cmp al, 34    ; dont write [ " ] mark
      je rqStart
      cmp al, 254
      jne @F
      mov al, 32    ; substitute space
    @@:
      stosb
      jmp rqStart

  rqOut:
      stosb         ; write zero terminator

  ; ------------------
  ; handle empty quote
  ; ------------------
    mov esi, ItemBuffer
    lodsb
    cmp al, 0
    jne @F
    pop edi
    pop esi
    mov eax, 4  ; return value for empty quote
    ret
  @@:

    mov eax, 1  ; return value success

    pop edi
    pop esi

    ret

GetCL endp

; #########################################################################

end