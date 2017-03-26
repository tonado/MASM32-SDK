; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 

align 4

ssorta proc arr:DWORD,left:DWORD,right:DWORD

comment * -------------------------------------------------------
        This is a classic Shell sort that was redesigned by Janet
        Incerpi and Robert Sedgewick using a preset gap table.
        ------------------------------------------------------- *

    .data
      align 4
  ; ---------------------------------------
  ; mangle the table name to keep it unique
  ; ---------------------------------------
      Incerpi_@_Sedgewick_@_Shell_@_Table \
             dd 1391376,463792,198768,86961,33936,13776
             dd 4592,1968,861,336,112,48,21,7,3,1
    .code

    mov [esp-4],  ebx
    mov [esp-8],  esi
    mov [esp-12], edi
    mov [esp-16], ebp

    mov ebx, [esp+4]

    mov DWORD PTR [esp-20], -17

  entry:
    add DWORD PTR [esp-20], 1
    jz quit
    mov ecx, [esp-20]
    mov ecx, [Incerpi_@_Sedgewick_@_Shell_@_Table+ecx*4+64]
    mov esi, [esp+8]        ; left
    add esi, ecx
    sub esi, 1              ; fall through
  inner:
    add esi, 1
    cmp esi, [esp+12]       ; right
    jg entry
    mov ebp, [ebx+esi*4]
    mov edi, esi
    mov [esp-24], esi
    cmp edi, ecx
    jl noswap
  swap:
    mov eax, edi
    sub eax, ecx
    mov eax, [ebx+eax*4]
  ; ==========================
    mov esi, -1
  strcmp:
    add esi, 1
    mov dl, [ebp+esi]
    cmp dl, [eax+esi]
    jg noswap
    jl nxt
    test dl, dl
    jnz strcmp
  ; ==========================
  nxt:
    mov [ebx+edi*4], eax
    sub edi, ecx
    cmp edi, ecx
    jge swap
  noswap:
    mov [ebx+edi*4], ebp
    mov esi, [esp-24]
    jmp inner

  quit:
    mov ebx, [esp-4]
    mov esi, [esp-8]
    mov edi, [esp-12]
    mov ebp, [esp-16]

    ret 12

ssorta endp

OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
