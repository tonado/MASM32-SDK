; #########################################################################

    .386
    .model flat, stdcall  ; 32 bit memory model
    option casemap :none  ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\shell32.inc
    include \masm32\include\user32.inc
    include \masm32\include\ole32.inc

    cbBrowse  PROTO :DWORD,:DWORD,:DWORD,:DWORD

    .code

; #########################################################################

BrowseForFolder proc hParent:DWORD, lpBuffer:DWORD, lpTitle:DWORD, lpString:DWORD

  ; ------------------------------------------------------
  ; hParent  = parent window handle
  ; lpBuffer = 260 byte buffer to receive path
  ; lpTitle  = zero terminated string with dialog title
  ; lpString = zero terminated string for secondary text
  ; ------------------------------------------------------

    LOCAL lpIDList :DWORD
    LOCAL bi  :BROWSEINFO

    mov eax,                hParent         ; parent handle
    mov bi.hwndOwner,       eax
    mov bi.pidlRoot,        0
    mov bi.pszDisplayName,  0
    mov eax,                lpString        ; secondary text
    mov bi.lpszTitle,       eax
    mov bi.ulFlags,         BIF_RETURNONLYFSDIRS or BIF_DONTGOBELOWDOMAIN
    mov bi.lpfn,            offset cbBrowse
    mov eax,                lpTitle         ; main title
    mov bi.lParam,          eax
    mov bi.iImage,          0

    invoke SHBrowseForFolder,ADDR bi
    mov lpIDList, eax

    .if lpIDList == 0
      mov eax, 0      ; if CANCEL return FALSE
      push eax
      jmp @F
    .else
      invoke SHGetPathFromIDList,lpIDList,lpBuffer
      mov eax, 1        ; if OK, return TRUE
      push eax
      jmp @F
    .endif

    @@:

    invoke CoTaskMemFree,lpIDList

    pop eax
    ret

BrowseForFolder endp

; #########################################################################

cbBrowse proc hWin   :DWORD,
              uMsg   :DWORD,
              lParam :DWORD,
              lpData :DWORD

    invoke SetWindowText,hWin,lpData

    ret

cbBrowse endp

; #########################################################################

end