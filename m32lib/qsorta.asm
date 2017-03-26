; #########################################################################

    .486                      ; create 32 bit code
    .model flat, stdcall      ; 32 bit memory model
    option casemap :none      ; case sensitive

    include \masm32\include\oleaut32.inc

    .code

; #########################################################################

nrQsortA proc Arr:DWORD,count:DWORD

    LOCAL First :DWORD
    LOCAL Last  :DWORD
    LOCAL cntr  :DWORD
    LOCAL bLen  :DWORD
    LOCAL hMem  :DWORD
    LOCAL temp  :DWORD

    push ebx
    push esi
    push edi

    mov esi, Arr              ; source address in ESI

    mov cntr, 0

  ; --------------------------
  ; allocate temporary buffer
  ; --------------------------
    mov eax, count
    add eax, 40
    mov bLen, eax
    invoke SysAllocStringByteLen,0,bLen
    mov hMem, eax

    mov edi, hMem             ; buffer address in EDI

  ; ------------------------------------
  ; set First and Last reference values
  ; ------------------------------------
    mov First, 0
    mov eax, count
    dec eax
    mov Last, eax             ; Last = count - 1

  outer_loop:
  ; -------------------
  ; calculate midpoint
  ; -------------------
    mov eax, Last
    add eax, First
    shr eax, 1
  ; =========================
    mov ebx, [esi+eax*4]      ; midpoint in EBX
    mov temp, ebx
  ; =========================
    mov ecx, First
    mov edx, Last
  ; ---------------------------------------------------------
  inner_loop:
    cmp [esi+ecx*4], ebx
    jge wl2
    inc ecx
    jmp inner_loop
  wl2:
    cmp [esi+edx*4], ebx
    jle wl2Out
    dec edx
    jmp wl2
  wl2Out:
    cmp ecx, edx              ; If ecx > edx, exit inner loop
    jg exit_innerx
  ; =========================
    mov eax, [esi+ecx*4]
    mov ebx, [esi+edx*4]      ; swap elements
    mov [esi+ecx*4], ebx
    mov [esi+edx*4], eax
  ; =========================
    mov ebx, temp             ; restore EBX
    inc ecx
    dec edx
    cmp ecx, edx
    jle inner_loop
  exit_innerx:
  ; ---------------------------------------------------------
    cmp ecx, Last             ; If ecx < Last jump over
    jg iNxt
  ; =========================
    mov eax, cntr
    mov [edi+eax*4], ecx
    mov ebx, Last
    mov [edi+eax*4+4], ebx
  ; =========================
    add cntr, 2
  iNxt:
    mov ebx, temp             ; restore EBX
    mov Last, edx             ; Last  = EDX
    cmp edx, First            ; compare Last & First
    jg outer_loop

    cmp cntr, 0
    jz qsOut
    sub cntr, 2
  ; =========================
    mov eax, cntr
    mov ebx, [edi+eax*4]
    mov First, ebx
    mov ebx, [edi+eax*4+4]
    mov Last, ebx
  ; =========================
    mov ebx, temp             ; restore EBX
    jmp outer_loop

    qsOut:

    invoke SysFreeString,hMem

    pop edi
    pop esi
    pop ebx

    ret

nrQsortA endp

; #########################################################################

    end