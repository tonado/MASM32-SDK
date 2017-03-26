; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    include \masm32\include\windows.inc
    include \masm32\include\gdi32.inc

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

RetFontHandle proc lpfname:DWORD,fhgt:DWORD,fwgt:DWORD

    invoke CreateFont,fhgt,0,0,0,fwgt,0,0,0,
           DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
           CLIP_DEFAULT_PRECIS,PROOF_QUALITY,
           DEFAULT_PITCH,lpfname
    ret

RetFontHandle endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
