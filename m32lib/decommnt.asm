; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

decomment proc src:DWORD

comment * -------------------------------------------------------
        Remove assembler comment ";" from line of code and right
        trim any trailing tabs and spaces.

        Source is overwritten with result.

        Algorithm suports both double and single quotes.

        Algorithm does not evaluate the contents of quoted text.

        RETURN VALUE in EAX
        1  = line has text in next line to append to it
        0  = line is complete
        -1 = quotation error, no closing quotation
        ------------------------------------------------------- *

    mov eax, [esp+4]
    mov ecx, -1
    xor edx, edx

  ; *********
  ; main loop
  ; *********
  lpst:
    add ecx, 1
    cmp BYTE PTR [eax+ecx], 32      ; is it a space ?
    je lpst
    cmp BYTE PTR [eax+ecx], 9       ; is it a tab ?
    je lpst
    cmp BYTE PTR [eax+ecx], 0       ; terminator
    je quit
    cmp BYTE PTR [eax+ecx], 34      ; double quote character
    je doubleqt
    cmp BYTE PTR [eax+ecx], 39      ; single quote character
    je singleqt
    cmp BYTE PTR [eax+ecx], ";"     ; comment character
    je commnt
  storeit:
    mov edx, ecx                    ; store the last non space position
    jmp lpst

  ; *******************
  ; quotation sub loops
  ; *******************
  doubleqt:                         ; loop through text enclosed in double quotations
    add ecx, 1
    cmp BYTE PTR [eax+ecx], 0
    je qerror
    cmp BYTE PTR [eax+ecx], 34
    je storeit
    jmp doubleqt

  singleqt:                         ; loop through text enclosed in single quotations
    add ecx, 1
    cmp BYTE PTR [eax+ecx], 0
    je qerror
    cmp BYTE PTR [eax+ecx], 39
    je storeit
    jmp singleqt

  ; ************************
  ; quotation error handling
  ; ************************
  qerror:
    mov eax, -1                     ; quote error, no closing quote
    ret 4

  ; ********************************
  ; remove comment and trim trailing
  ; white space characters.
  ; ********************************
  commnt:
    mov BYTE PTR [eax+edx+1], 0     ; truncate string with terminator after last non space
    movzx eax, BYTE PTR [eax+edx]   ; zero extend trailing character

  ; ********************************
  ; set the return value to indicate
  ; if it is a split line or not.
  ; 0 = complete line
  ; 1 = split line
  ; ********************************

    cmp eax, 44                     ; comma character is split line
    jnz lbl0
    mov eax, 1
    jmp lbl2

  lbl0:
    cmp eax, 92                     ; backslash character is split line
    jnz lbl1
    mov eax, 1
    jmp lbl2

  lbl1:
    xor eax, eax                    ; any other is complete line

  lbl2:
    ret 4

  quit:
    xor eax, eax
    ret 4

decomment endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
