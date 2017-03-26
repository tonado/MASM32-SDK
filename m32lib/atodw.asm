; #########################################################################

  ; ---------------------------------------------------------------
  ;      This procedure was originally written by Tim Roberts 
  ;
  ; Part of this code has been optimised by Alexander Yackubtchik
  ; ---------------------------------------------------------------

    .486
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive
    .code

; #########################################################################

atodw proc String:DWORD

  ; ----------------------------------------
  ; Convert decimal string into dword value
  ; return value in eax
  ; ----------------------------------------

    push esi
    push edi

    xor eax, eax
    mov esi, [String]
    xor ecx, ecx
    xor edx, edx
    mov al, [esi]
    inc esi
    cmp al, 2D
    jne proceed
    mov al, byte ptr [esi]
    not edx
    inc esi
    jmp proceed

  @@: 
    sub al, 30h
    lea ecx, dword ptr [ecx+4*ecx]
    lea ecx, dword ptr [eax+2*ecx]
    mov al, byte ptr [esi]
    inc esi

  proceed:
    or al, al
    jne @B
    lea eax, dword ptr [edx+ecx]
    xor eax, edx

    pop edi
    pop esi

    ret

atodw endp

; #########################################################################

end