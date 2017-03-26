; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                  ; set processor model
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \masm32\include\kernel32.inc

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

GetAppPath proc lpPathBuffer:DWORD

    invoke GetModuleFileName,0,lpPathBuffer,128  ; return length in eax
    add eax, lpPathBuffer

  ; ---------------------------------------
  ; scan backwards for first "\" character
  ; ---------------------------------------
  @@:
    dec eax                             ; dec ECX
    cmp BYTE PTR [eax],'\'              ; compare if "\"
    jne @B                              ; jump back to @@: if not "\"

    mov BYTE PTR [eax+1],0              ; write zero terminator after "\"

    mov eax, lpPathBuffer

    ret

GetAppPath endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
