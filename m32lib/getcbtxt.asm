; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    GetClipboardText PROTO

    .code       ; code section

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

GetClipboardText proc

    push ebx
    push esi
    push edi

    ; --------------------------------------------------------
    ; if the return value is not zero, deallocate the returned
    ; memory handle with GlobalFree() or the macro "free" when
    ; the data is no longer required.
    ; --------------------------------------------------------
    invoke OpenClipboard,NULL                   ; open clipboard
    .if rv(IsClipboardFormatAvailable,CF_TEXT) != 0 ; if text available
      invoke GetClipboardData,CF_TEXT           ; get pointer to text
      mov ebx, eax
      invoke StrLen,eax                         ; get text length
      mov esi, eax
      mov edi, alloc(esi)                       ; allocate that much memory
      cst edi, ebx
      invoke CloseClipboard                     ; close the clipboard
      mov eax, edi                              ; return memory handle
      jmp bye
    .else                                       ; else
      xor eax, eax                              ; set return to zero
      invoke CloseClipboard                     ; close the clipboard
      jmp bye
    .endif

  bye:
    pop edi
    pop esi
    pop ebx

    ret

GetClipboardText endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
