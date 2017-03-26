; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive
 
    ArgByNumber PROTO :DWORD,:DWORD,:DWORD,:DWORD
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

getcl_ex proc num:DWORD,pbuf:DWORD

 ; 1 = successful operation
 ; 2 = no argument exists at specified arg number
 ; 3 = non matching quotation marks

    add num, 1
    invoke ArgByNumber,rv(GetCommandLine),pbuf,num,0

    .if eax >= 0
      mov ecx, pbuf
      .if BYTE PTR [ecx] != 0
        mov eax, 1                      ; successful operation
      .else
        mov eax, 2                      ; no argument at specified number
      .endif
    .elseif eax == -1
      mov eax, 3                        ; non matching quotation marks
    .endif

    ret

getcl_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
