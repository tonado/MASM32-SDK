; #########################################################################

    ; --------------------------------------
    ; This procedure was written by Iczelion
    ; --------------------------------------

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

      include \MASM32\INCLUDE\kernel32.inc

    .code

; #########################################################################

a2dw proc uses ecx edi edx esi String:DWORD

      ;----------------------------------------
      ; Convert decimal string into dword value
      ; return value in eax
      ;----------------------------------------

      xor ecx, ecx
      mov edi, String
      invoke lstrlen, String

      .while eax != 0
        xor edx, edx
        mov dl, byte ptr [edi]
        sub dl, "0" ; subtrack each digit with "0" to convert it to hex value
        mov esi, eax
        dec esi
        push eax
        mov eax, edx
        push ebx
        mov ebx, 10
          .while esi > 0
            mul ebx
            dec esi
          .endw
        pop ebx
        add ecx, eax
        pop eax
        inc edi
        dec eax
      .endw

        mov eax, ecx
        ret

a2dw endp

; #########################################################################

end