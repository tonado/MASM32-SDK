; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\include\oleaut32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

a2wc proc asc_txt:DWORD

    LOCAL blen:DWORD
    LOCAL hMem:DWORD

    mov blen, len(asc_txt)
    add eax, eax
    mov hMem, alloc$(eax)
    invoke MultiByteToWideChar,CP_ACP,MB_PRECOMPOSED,
                               asc_txt,blen,hMem,blen
  ; ---------------------------------
  ; release the allocated memory
  ; returned in EAX with either
  ; invoke SysFreeString,strhandle
  ;   or
  ; free$ strhandle
  ; after you have finished using it.
  ; ---------------------------------
    mov eax, hMem

    ret

a2wc endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
