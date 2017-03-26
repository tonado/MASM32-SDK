; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    __UNICODE__ equ 1

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\comdlg32.inc
    include \masm32\macros\macros.asm

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 4

ucSaveFileDialog proc hParent:DWORD,Instance:DWORD,lpTitle:DWORD,lpFilter:DWORD

    LOCAL ofn:OPENFILENAME

    .data?
      savefilebuffer dw 260 dup (?)
    .code

    mov eax, OFFSET savefilebuffer
    mov WORD PTR [eax], 0

  ; --------------------
  ; zero fill structure
  ; --------------------
    push edi
    mov ecx, sizeof OPENFILENAME
    shr ecx, 2
    xor eax, eax
    lea edi, ofn
    rep stosd
    pop edi

    mov ofn.lStructSize,        sizeof OPENFILENAME
    m2m ofn.hWndOwner,          hParent
    m2m ofn.hInstance,          Instance
    m2m ofn.lpstrFilter,        lpFilter
    m2m ofn.lpstrFile,          offset savefilebuffer
    mov ofn.nMaxFile,           sizeof savefilebuffer
    m2m ofn.lpstrTitle,         lpTitle
    mov ofn.Flags,              OFN_EXPLORER or OFN_LONGNAMES or \
                                OFN_HIDEREADONLY or OFN_OVERWRITEPROMPT
                                
    invoke GetSaveFileName,ADDR ofn
    mov eax, OFFSET savefilebuffer
    ret

ucSaveFileDialog endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
