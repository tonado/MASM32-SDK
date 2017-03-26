; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

    __UNICODE__ equ 1

    .686p                     ; maximum processor model
    .XMM                      ; SIMD extensions
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    ;; include \masm32\include\masm32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

    include \masm32\macros\macros.asm

    .code       ; code section

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

GetAppPathW proc

  ; ---------------------------------------------------
  ; return OFFSET of unicode app path with trailing "\"
  ; ---------------------------------------------------
    LOCAL plen :DWORD

    .data?
      uc_path_buffer dw 260 dup (?)
    .code

    mov plen, rv(GetModuleFileName,NULL,OFFSET uc_path_buffer,260)

    mov edx, OFFSET uc_path_buffer  ; store beginning in EDX
    mov eax, edx                    ; copy it to EAX
    mov ecx, plen                   ; load path length into ECX
    add ecx, ecx                    ; double it to convert unicode to byte length
    add eax, ecx                    ; add length to OFFSET to get path end

  ; ------------------------------
  ; loop backwards to get last "\"
  ; ------------------------------
  @@:
    sub eax, 2
    cmp WORD PTR [eax], "\"         ; get last "\"
    je @F
    cmp eax, edx                    ; else exit at beginning if no "\"
    jne @B

  @@:
    mov WORD PTR [eax+2], 0         ; terminate leaving trailing "\"
    mov eax, OFFSET uc_path_buffer  ; return the buffer OFFSET
    ret

GetAppPathW endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
