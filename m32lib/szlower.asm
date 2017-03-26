; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

      .486
      .model flat, stdcall  ; 32 bit memory model
      option casemap :none  ; case sensitive

    .code

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

szLower proc text:DWORD

  ; -----------------------------
  ; converts string to lower case
  ; invoke szLower,ADDR szString
  ; -----------------------------

    mov eax, [esp+4]
    dec eax

  @@:
    add eax, 1
    cmp BYTE PTR [eax], 0
    je @F
    cmp BYTE PTR [eax], "A"
    jb @B
    cmp BYTE PTR [eax], "Z"
    ja @B
    add BYTE PTR [eax], 32
    jmp @B
  @@:

    mov eax, [esp+4]

    ret 4

szLower endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end
