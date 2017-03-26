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

    externdef Alloc_pIMalloc:DWORD

    .code

; #########################################################################

Free proc public pv:DWORD
	
    ; -------------------------------------------------------------
    ; Free frees a block of memory previously allocated through a call to Alloc. 
    ; The number of bytes freed equals the number of bytes that were allocated. 
    ; After the call, the memory block pointed to by pv is invalid and can no 
    ; longer be used.
    ; 
    ; Note The pv parameter can be NULL. If so, this method has no effect.
    ; 
    ; 
    ; EXAMPLE:
    ; invoke Free, pMem         ; frees the memory pointer to by pMem
    ;
    ; Uses: eax, ecx, edx.
    ;
    ; -------------------------------------------------------------
    
    ; free the memory
    push pv
    push Alloc_pIMalloc
    mov ecx, Alloc_pIMalloc
    mov ecx, [ecx]
    ; call IMalloc::Free
    call DWORD PTR [ecx] + 20   ; and you thought COM was hard, huh?   ;-)
    xor eax, eax                ; OK, this is a (void) function, but let's be consistant
    ret

Free endp
; #########################################################################

end
