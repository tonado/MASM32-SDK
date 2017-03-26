; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

comment * ---------------------------------------------------
        This algorithm is a classic QUICK sort that has been
        optimised for speed and uses no specialised pivot
        selection methods. It is the fastest sort technique
        for randomly distributed data but is effected by
        presorted data and other unusual data arrangements
        that can make it very slow.
        --------------------------------------------------- *

qssorta proc arr:DWORD,i:DWORD,j:DWORD

    mov eax, i
    cmp eax, j
    jge quit

    mov [esp-8], ebx
    mov [esp-12], esi
    mov [esp-16], edi

    mov edi, arr
    mov esi, i
    mov ebx, j
    mov [esp-20], ebp           ; save EBP
    mov edx, [edi+ebx*4]        ; pivot is from higher index value
    sub ebx, 1
    cmp esi, ebx
    jg lbl5

  lbl0:
    sub esi, 1
  align 4
  lbl1:
    add esi, 1                  ; increment lower index
  ; ***************************
    mov ecx, [edi+esi*4]        ; load lower index string
    mov ebp, -1
  sts0:
    add ebp, 1
    mov al, [ecx+ebp]           ; compare lower and pivot strings
    cmp al, [edx+ebp]
    jg nxt0
    jl lbl1
    test al, al
    jnz sts0
  nxt0:
  ; ***************************
  align 4
  lbl2:
  ; ***************************
    mov ecx, [edi+ebx*4]        ; load upper index string
    mov ebp, -1
  sts1:
    add ebp, 1
    mov al, [ecx+ebp]           ; compare upper and pivot strings
    cmp al, [edx+ebp]
    jg nxt1
    jl lbl3
    test al, al
    jnz sts1
  nxt1:
  ; ***************************
    sub ebx, 1                  ; decrement upper index
    cmp ebx, esi
    jge lbl2

  lbl3:
    cmp esi, ebx
    jg lbl5
    mov eax, [edi+esi*4]        ; swap pointers
    mov ecx, [edi+ebx*4]
    mov [edi+esi*4], ecx
    mov [edi+ebx*4], eax
    add esi, 1
    sub ebx, 1
    cmp esi, ebx
    jle lbl0

  lbl5:
    mov ebp, [esp-20]           ; restore EBP before using LOCAL
    mov eax, j
    mov edx, [edi+esi*4]
    mov ecx, [edi+eax*4]
    mov [edi+esi*4], ecx
    mov [edi+eax*4], edx
    mov eax, esi

    mov ebx, [esp-8]
    mov esi, [esp-12]
    mov edi, [esp-16]

    push eax
    sub eax, 1
    invoke qssorta,arr,i,eax

    pop eax
    add eax, 1
    invoke qssorta,arr,eax,j

  quit:

    ret

qssorta endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
