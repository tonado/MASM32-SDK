; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

    .486                      ; maximum processor model
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code       ; code section

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

arr2file proc arr:DWORD,lpfile:DWORD

  ; -------------------------------------------------------
  ; this procedure write each array member directly to disk
  ; so that an intermediate buffer does not need to be
  ; allocated. This is designed to allow very large arrays
  ; to be written to disk without memory space being a
  ; limitation to the array size.
  ; -------------------------------------------------------

    LOCAL acnt  :DWORD
    LOCAL hFile :DWORD
    LOCAL flen  :DWORD

    push ebx
    push esi
    push edi

    mov acnt, arrcnt$(arr)                 ; get the member count back from the array

    mov hFile, fcreate(lpfile)

    mov ebx, 1
  @@:
    fprint hFile,arrget$(arr,ebx)          ; write each array line to disk
    add ebx, 1
    cmp ebx, acnt
    jle @B

    mov flen, fsize(hFile)

    fclose hFile

    mov eax, flen

    pop edi
    pop esi
    pop ebx

    ret

arr2file endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end
