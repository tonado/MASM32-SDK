; #########################################################################

    ; -------------------------------------------------------
    ; This procedure was written by Ernie Murphy    10/1/00
    ; -------------------------------------------------------

      .386
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive
      PUBLIC Alloc_pIMalloc 

      include     \masm32\include\ole32.inc
      
      includelib  \masm32\lib\ole32.lib

    .data

Alloc_pIMalloc  DWORD   0

    .code

; #########################################################################

Alloc proc public cb:DWORD
	
    ; -------------------------------------------------------------
    ; Alloc will allocate cb bytes
    ; 
    ; The Alloc method allocates a memory block in essentially the same 
    ; way that the C Library malloc function does.
    ; 
    ; The initial contents of the returned memory block are undefined 
    ; there is no guarantee that the block has been initialized, so you should 
    ; initialize it in your code. The allocated block may be larger than cb bytes 
    ; because of the space required for alignment and for maintenance information.
    ; 
    ; If cb is zero, Alloc allocates a zero-length item and returns a valid 
    ; pointer to that item. If there is insufficient memory available, Alloc 
    ; returns NULL.
    ; 
    ; Note Applications should always check the return value from this method, 
    ; even when requesting small amounts of memory, because there is no guarantee 
    ; the memory will be allocated
    ; 
    ; 
    ; EXAMPLE:
    ; invoke Alloc, 128         ; allocates 128 bytes
    ;                           ; pointer to memory in eax
    ;
    ; Uses: eax, ecx, edx.
    ;
    ; -------------------------------------------------------------
    
    .IF !Alloc_pIMalloc     ; check if we hold a valid pointer
        invoke CoGetMalloc,1 , ADDR Alloc_pIMalloc
        .IF eax
            ; failed getting pIMalloc
            xor eax, eax    ;  NULL return pointer
            ret
        .ENDIF
    .ENDIF
    ; now request the memory
    push cb
    mov ecx, Alloc_pIMalloc
    mov ecx, [ecx]
    call DWORD PTR [ecx] + 12
    ret

Alloc endp
; #########################################################################

end
