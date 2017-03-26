; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

LoadListFromData proc hLst:DWORD,lpdata:DWORD

  ; ----------------------------------------------------------------------
  ; This procedure is designed to read a list of seperate items of string
  ; data from the data section that is zero seperated and double zero
  ; terminated. It passes the start address to the LB_ADDSTRING message
  ; then scans the string data for the next zero seperator. When it finds
  ; the next zero seperator, it tests if the next byte is also a zero,
  ; returns to the LB_ADDSTRING call if it is not or exits if it is.
  ; ----------------------------------------------------------------------

    invoke SendMessage,hLst,WM_SETREDRAW,FALSE,0

    push esi
    mov esi, lpdata

  llfd:
    invoke SendMessage,hLst,LB_ADDSTRING,0,esi
  @@:
    inc esi
    cmp BYTE PTR [esi], 0   ; check for zero seperator
    jne @B
    inc esi
    cmp BYTE PTR [esi], 0   ; check for 2nd terminator
    jne llfd

    pop esi

    invoke SendMessage,hLst,WM_SETREDRAW,TRUE,0

    ret

LoadListFromData endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
