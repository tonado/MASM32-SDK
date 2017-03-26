; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

create_hash_table proc acnt:DWORD,asize:DWORD

comment * -------------------------------
    acnt  = number of items in hash table
    asize = byte count for each item ---- *

    LOCAL lparr:DWORD
    LOCAL lpmem:DWORD

    mov ecx, acnt
    shl ecx, 2                  ; multiply by 4
    mov lparr, alloc(ecx)       ; allocate array

    mov ecx, asize
    mov eax, acnt
    imul ecx                    ; multiply count by BYTE size for string memory length
    mov lpmem, alloc(eax)       ; allocate string memory

    mov eax, lpmem              ; string memory start address
    mov edx, lparr              ; array address
    mov ecx, acnt               ; item count
  @@:
    mov [edx], eax              ; load address in EAX into location in array
    add eax, asize              ; add "asize" for next start address
    add edx, 4                  ; set next array location
    sub ecx, 1
    jnz @B

comment * ----------------------------------
    deallocate both of the returned memory
    handles when the hash table is no longer
    required ------------------------------- *

    mov eax, lparr              ; return address of array of pointers in EAX
    mov ecx, lpmem              ; return string memory address in ECX

    ret

create_hash_table endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
