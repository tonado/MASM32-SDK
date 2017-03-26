; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
;
; GetFileData reads data from a disk file into a buffer allocated by the
; API function SysAllocStringByteLen. It returns the length of the data
; that is read which is also the length of the disk file in EAX.
;
; Parameters are,
;               1. lpName : zero terminated file name
;               2. lpMem  : address of allocated DWORD handle
;
; EXAMPLE : invoke GetFileData,SADD("filename.ext"),ADDR hMem$
;
; The allocated memory must be deallocated after use with the API function
; "SysFreeString".
;
; EXAMPLE : invoke SysFreeString,hMem$
;
; NOTE
; ~~~~
; The "oleaut32" include and library must be used with this procedure.
;
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

GetFileData proc lpName:DWORD,lpMem:DWORD

; ------------------------------------------
; GetFileData proc lpName:DWORD,lpMem:DWORD
; ------------------------------------------

    LOCAL hFile     :DWORD
    LOCAL fl        :DWORD
    LOCAL bRead     :DWORD
    LOCAL Mem       :DWORD

    invoke CreateFile,lpName,GENERIC_READ,0,NULL,OPEN_EXISTING,NULL,NULL
    mov hFile, eax

    invoke GetFileSize,hFile,NULL
    mov fl, eax

  ; -----------------------
  ; allocate string memory
  ; -----------------------
    invoke SysAllocStringByteLen,0,fl
    mov Mem, eax

  ; ---------------------------------------------------
  ; write handle to DWORD variable passed as parameter
  ; ---------------------------------------------------
    mov ecx, lpMem
    mov [ecx], eax

    invoke ReadFile,hFile,Mem,fl,ADDR bRead,NULL
    invoke CloseHandle,hFile

  ; -------------------------
  ; return bytes read in EAX
  ; -------------------------
    mov eax, bRead

    ret

GetFileData endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
