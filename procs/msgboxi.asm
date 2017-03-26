; ¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤

MessageBoxI proc hParent:DWORD,lpMsg:DWORD,
             lpTitle:DWORD,dlgStyle:DWORD,iconID:DWORD

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

MessageBoxI endp

; ¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤
