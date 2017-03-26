comment /* лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

                     Build this DLL with MAKEIT.BAT

    This DLL is a test piece to show how to set up a LibMain or a
    DLLmain procedure and how to write and call 3 versions of the
    same procedure using different calling conventions.

           ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл */

    .486                    ; set processor model
    .model flat, stdcall    ; default STDCALL calling convention
    option casemap :none    ; always use the case sensitive option

    include \masm32\include\windows.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
    include \masm32\macros\macros.asm

    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\kernel32.lib

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

  ; -----------------------------------------------
  ; LOCAL prototypes for the three test procedures
  ; -----------------------------------------------
  ; STDCALL calling convention
    MessageBoxSTD PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

  ; C calling convention
    MessageBoxCC PROTO C :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

  ; Simulate FASTCALL calling convention
    MessageBoxFC PROTO STDCALL :DWORD,:DWORD
  ; -----------------------------------------------

    .data?
      hInstance dd ?

    .code
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

LibMain proc hInstDLL:DWORD, reason:DWORD, unused:DWORD

    .if reason == DLL_PROCESS_ATTACH
      invoke GetModuleHandle,NULL   ; use the calling application's instance handle
      mov hInstance, eax            ; so that the icon from the caller can be used.

      mov eax, TRUE                 ; put TRUE in EAX to continue loading the DLL

    comment * ====================================
      These can be used if there is thread specific
      information that needs to be set up as the DLL
      is called.

    .elseif reason == DLL_THREAD_DETACH
    .elseif reason == DLL_THREAD_ATTACH
              ================================== *
    
    .elseif reason == DLL_PROCESS_DETACH
      ; ---------------------------------------
      ; perform any exit code you require here
      ; ---------------------------------------

    .endif

    ret

LibMain Endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

MessageBoxSTD proc STDCALL hParent:DWORD,lpMsg:DWORD,
              lpTitle:DWORD,dlgStyle:DWORD,iconID:DWORD

  comment * ---------------------------------------------
    STDCALL version of the procedure. This is the normal
    calling convention for Window API functions.
    --------------------------------------------------- *

    LOCAL mbp:MSGBOXPARAMS

    mov mbp.cbSize, SIZEOF MSGBOXPARAMS
    mov eax, hParent
    mov mbp.hwndOwner, eax
    mov eax, hInstance
    mov mbp.hInstance, eax
    mov eax, lpMsg
    mov mbp.lpszText, eax
    mov eax, lpTitle
    mov mbp.lpszCaption, eax
    mov eax, dlgStyle
    or eax, MB_USERICON
    mov mbp.dwStyle, eax
    mov eax, iconID
    mov mbp.lpszIcon, eax
    mov mbp.dwContextHelpId, NULL
    mov mbp.lpfnMsgBoxCallback, NULL
    mov mbp.dwLanguageId, NULL

    invoke MessageBoxIndirect,ADDR mbp

    ret

MessageBoxSTD endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

MessageBoxCC proc C hParent:DWORD,lpMsg:DWORD,
             lpTitle:DWORD,dlgStyle:DWORD,iconID:DWORD

  comment * ---------------------------------------------
    This procedure uses the "C" calling convention which
    is used by C / C++ languages for calling procedures.
    --------------------------------------------------- *

    LOCAL mbp:MSGBOXPARAMS

    mov mbp.cbSize, SIZEOF MSGBOXPARAMS
    mov eax, hParent
    mov mbp.hwndOwner, eax
    mov eax, hInstance
    mov mbp.hInstance, eax
    mov eax, lpMsg
    mov mbp.lpszText, eax
    mov eax, lpTitle
    mov mbp.lpszCaption, eax
    mov eax, dlgStyle
    or eax, MB_USERICON
    mov mbp.dwStyle, eax
    mov eax, iconID
    mov mbp.lpszIcon, eax
    mov mbp.dwContextHelpId, NULL
    mov mbp.lpfnMsgBoxCallback, NULL
    mov mbp.dwLanguageId, NULL

    invoke MessageBoxIndirect,ADDR mbp

    ret

MessageBoxCC endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

MessageBoxFC proc STDCALL dlgStyle:DWORD,iconID:DWORD

  comment * ------------------------------------------------------------
    this version of the procedure passes the first 3 parameters in
    registers which reduces the stack overhead and allows the structure
    to load the registers directly into appropriate members. It is a
    simulation of the FASTCALL calling convention.

    parent handle address is in EAX register
    message text address is in  ECX register
    title address is in the     EDX register
    ------------------------------------------------------------------ *

    LOCAL mbp:MSGBOXPARAMS

    mov mbp.cbSize, SIZEOF MSGBOXPARAMS
    mov mbp.hwndOwner, eax              ; parent handle here
    mov eax, hInstance
    mov mbp.hInstance, eax
    mov mbp.lpszText, ecx               ; message text here
    mov mbp.lpszCaption, edx            ; title text here
    mov eax, dlgStyle
    or eax, MB_USERICON
    mov mbp.dwStyle, eax
    mov eax, iconID
    mov mbp.lpszIcon, eax
    mov mbp.dwContextHelpId, NULL
    mov mbp.lpfnMsgBoxCallback, NULL
    mov mbp.dwLanguageId, NULL

    invoke MessageBoxIndirect,ADDR mbp

    ret

MessageBoxFC endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end LibMain
