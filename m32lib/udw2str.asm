; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

  ; ---------------------------------------------------
  ; The original algorithm was written by comrade
  ; <comrade2k@hotmail.com>; http://www.comrade64.com/
  ;
  ;  It has been optimised by Alexander Yackubtchik
  ; ---------------------------------------------------

  ; udw2str

  ; Parameters
  ;     dwNumber - 32-bit double-word to be converted
  ;     pszString - null-terminated string (output)
  ; Result
  ;     None

    .code

; #########################################################################

udw2str proc dwNumber:DWORD, pszString:DWORD

    push ebx
    push esi
    push edi

    mov     eax, [dwNumber]
    mov     esi, [pszString]
    mov     edi, [pszString]
    mov ecx,429496730

  @@redo:
    mov ebx,eax
    mul ecx
    mov eax,edx
    lea edx,[edx*4+edx]
    add edx,edx
    sub ebx,edx
    add bl,'0'
    mov [esi],bl
    inc esi
    test    eax, eax
    jnz     @@redo
    jmp     @@chks

  @@invs: 
    dec     esi
    mov     al, [edi]
    xchg    [esi], al
    mov     [edi], al
    inc     edi
  @@chks:
    cmp     edi, esi
    jb      @@invs

    pop edi
    pop esi
    pop ebx


    ret

udw2str endp

; #########################################################################

end