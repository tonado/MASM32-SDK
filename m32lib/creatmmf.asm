; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\kernel32.inc

    CreateMMF PROTO :DWORD,:DWORD,:DWORD,:DWORD

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

CreateMMF proc lpName:DWORD,bcnt:DWORD,lphndl:DWORD,lpMemFile:DWORD

    invoke CreateFileMapping,0FFFFFFFFh,        ; nominates the system paging
                             NULL,
                             PAGE_READWRITE,    ; read write access to memory
                             0,
                             bcnt,              ; required size in BYTEs
                             lpName             ; set file object name here

    mov edx, eax                                ; MMF handle in EDX
    mov ecx, lphndl                             ; address of variable in ECX
    mov [ecx], eax                              ; write MMF handle to variable

    invoke MapViewOfFile,edx,FILE_MAP_WRITE,0,0,0
    mov ecx, lpMemFile                          ; address of variable in ECX
    mov [ecx], eax                              ; write start address to variable

    ret

CreateMMF endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
