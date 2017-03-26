; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
;                  write data in memory to disk file
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

write_to_disk proc lpName:DWORD,lpData:DWORD,fl:DWORD

; ----------------------------------------
; write_to_disk PROTO:DWORD,:DWORD,:DWORD
; ----------------------------------------

    LOCAL hOutput:DWORD
    LOCAL bw     :DWORD

    invoke CreateFile,lpName,GENERIC_WRITE,NULL,NULL,
                      CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL
    mov hOutput, eax
    invoke WriteFile,hOutput,lpData,fl,ADDR bw,NULL
    invoke CloseHandle,hOutput

    mov eax, bw                 ; return written byte count
    ret

write_to_disk endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
