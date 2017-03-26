; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\masm32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл


; load list of drives into a list box
; to use a different set of filters, copy this algo
; and change the line, "cmp eax, DRIVE_FIXED" to a different
; style as defined for GetDriveType().
; with the "cat$" line, you can change the formatting of the
; text output by modifying the strings in the macro.


load_drives proc list:DWORD

    LOCAL pString:DWORD
    LOCAL pvi    :DWORD
    LOCAL buffer[1024]:BYTE
    LOCAL string[128]:BYTE
    LOCAL vi[128]:BYTE

    push esi

    mov pvi, ptr$(vi)
    invoke GetLogicalDriveStrings,1024,ADDR buffer
    lea esi, buffer
    sub esi, 1
  lpst:
    add esi, 1
    invoke GetDriveType,esi
    cmp eax, DRIVE_FIXED
    jne @F
    invoke GetVolumeInformation,esi,pvi,128,0,0,0,0,0
    mov pString, ptr$(string)
    mov pString, cat$(pString,esi," ",chr$(40),pvi,chr$(41))
    invoke SendMessage,list,LB_ADDSTRING,0,pString
  @@:
    add esi, 1
    cmp BYTE PTR [esi], 0
    jne @B
    cmp BYTE PTR [esi+1], 0
    jne lpst

    pop esi

    ret

load_drives endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
