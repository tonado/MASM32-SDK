; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

; LoadFile loads a disk file into a memory buffer of the same length,
; allocates another buffer of the same size as the target buffer.

; lpName is the disk file to open

; lpSaved is for a target file name to save after processing original data.

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

LoadFile proc lpName:DWORD,lpSaved:DWORD

    LOCAL hFile     :DWORD
    LOCAL fl        :DWORD
    LOCAL bRead     :DWORD
    LOCAL hMem$     :DWORD      ; source memory handle
    LOCAL hBuffer$  :DWORD      ; result memory handle

    invoke CreateFile,lpName,GENERIC_READ,0,NULL,OPEN_EXISTING,NULL,NULL
    mov hFile, eax

    invoke GetFileSize,hFile,NULL
    mov fl, eax

    stralloc fl
    mov hMem$, eax      ; source file memory
    stralloc fl
    mov hBuffer$, eax   ; write buffer memory

    invoke ReadFile,hFile,hMem$,fl,ADDR bRead,NULL
    invoke CloseHandle,hFile

  ; лллллллллллллллллллллллллллллллллллллллллллллллллл

  ; write code here to process disk file data in memory.

  ; hMem$    : buffer that holds the data
  ; fl       : buffer and data length
  ; hBuffer$ : target buffer after processing

  ; лллллллллллллллллллллллллллллллллллллллллллллллллл

    strfree hBuffer$
    strfree hMem$

    ret

LoadFile endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
