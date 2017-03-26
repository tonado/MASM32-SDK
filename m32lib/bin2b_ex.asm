; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE : NONE
OPTION EPILOGUE : NONE

align 4

bin2byte_ex proc lpword:DWORD

    mov eax, [esp+4]
    
    cmp BYTE PTR [eax+0], '0'
    jne lbl0
    cmp BYTE PTR [eax+1], '0'
    jne lbl1
    cmp BYTE PTR [eax+2], '0'
    jne lbl2
    cmp BYTE PTR [eax+3], '0'
    jne lbl3
    cmp BYTE PTR [eax+4], '0'
    jne lbl4
    cmp BYTE PTR [eax+5], '0'
    jne lbl5
    cmp BYTE PTR [eax+6], '0'
    jne lbl6
    cmp BYTE PTR [eax+7], '0'
    jne lbl7
  lbl7:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 1
    ret 4
  lbl6:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl8
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 2
    ret 4
  lbl8:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 3
    ret 4
  lbl5:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl9
    cmp BYTE PTR [eax+7], '0'
    jne lbl10
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 4
    ret 4
  lbl10:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 5
    ret 4
  lbl9:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl11
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 6
    ret 4
  lbl11:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 7
    ret 4
  lbl4:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl12
    cmp BYTE PTR [eax+6], '0'
    jne lbl13
    cmp BYTE PTR [eax+7], '0'
    jne lbl14
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 8
    ret 4
  lbl14:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 9
    ret 4
  lbl13:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl15
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 10
    ret 4
  lbl15:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 11
    ret 4
  lbl12:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl16
    cmp BYTE PTR [eax+7], '0'
    jne lbl17
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 12
    ret 4
  lbl17:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 13
    ret 4
  lbl16:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl18
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 14
    ret 4
  lbl18:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 15
    ret 4
  lbl3:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl19
    cmp BYTE PTR [eax+5], '0'
    jne lbl20
    cmp BYTE PTR [eax+6], '0'
    jne lbl21
    cmp BYTE PTR [eax+7], '0'
    jne lbl22
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 16
    ret 4
  lbl22:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 17
    ret 4
  lbl21:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl23
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 18
    ret 4
  lbl23:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 19
    ret 4
  lbl20:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl24
    cmp BYTE PTR [eax+7], '0'
    jne lbl25
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 20
    ret 4
  lbl25:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 21
    ret 4
  lbl24:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl26
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 22
    ret 4
  lbl26:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 23
    ret 4
  lbl19:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl27
    cmp BYTE PTR [eax+6], '0'
    jne lbl28
    cmp BYTE PTR [eax+7], '0'
    jne lbl29
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 24
    ret 4
  lbl29:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 25
    ret 4
  lbl28:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl30
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 26
    ret 4
  lbl30:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 27
    ret 4
  lbl27:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl31
    cmp BYTE PTR [eax+7], '0'
    jne lbl32
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 28
    ret 4
  lbl32:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 29
    ret 4
  lbl31:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl33
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 30
    ret 4
  lbl33:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 31
    ret 4
  lbl2:
    cmp BYTE PTR [eax+2], '1'
    jne notfound
    cmp BYTE PTR [eax+3], '0'
    jne lbl34
    cmp BYTE PTR [eax+4], '0'
    jne lbl35
    cmp BYTE PTR [eax+5], '0'
    jne lbl36
    cmp BYTE PTR [eax+6], '0'
    jne lbl37
    cmp BYTE PTR [eax+7], '0'
    jne lbl38
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 32
    ret 4
  lbl38:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 33
    ret 4
  lbl37:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl39
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 34
    ret 4
  lbl39:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 35
    ret 4
  lbl36:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl40
    cmp BYTE PTR [eax+7], '0'
    jne lbl41
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 36
    ret 4
  lbl41:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 37
    ret 4
  lbl40:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl42
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 38
    ret 4
  lbl42:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 39
    ret 4
  lbl35:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl43
    cmp BYTE PTR [eax+6], '0'
    jne lbl44
    cmp BYTE PTR [eax+7], '0'
    jne lbl45
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 40
    ret 4
  lbl45:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 41
    ret 4
  lbl44:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl46
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 42
    ret 4
  lbl46:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 43
    ret 4
  lbl43:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl47
    cmp BYTE PTR [eax+7], '0'
    jne lbl48
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 44
    ret 4
  lbl48:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 45
    ret 4
  lbl47:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl49
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 46
    ret 4
  lbl49:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 47
    ret 4
  lbl34:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl50
    cmp BYTE PTR [eax+5], '0'
    jne lbl51
    cmp BYTE PTR [eax+6], '0'
    jne lbl52
    cmp BYTE PTR [eax+7], '0'
    jne lbl53
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 48
    ret 4
  lbl53:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 49
    ret 4
  lbl52:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl54
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 50
    ret 4
  lbl54:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 51
    ret 4
  lbl51:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl55
    cmp BYTE PTR [eax+7], '0'
    jne lbl56
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 52
    ret 4
  lbl56:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 53
    ret 4
  lbl55:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl57
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 54
    ret 4
  lbl57:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 55
    ret 4
  lbl50:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl58
    cmp BYTE PTR [eax+6], '0'
    jne lbl59
    cmp BYTE PTR [eax+7], '0'
    jne lbl60
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 56
    ret 4
  lbl60:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 57
    ret 4
  lbl59:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl61
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 58
    ret 4
  lbl61:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 59
    ret 4
  lbl58:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl62
    cmp BYTE PTR [eax+7], '0'
    jne lbl63
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 60
    ret 4
  lbl63:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 61
    ret 4
  lbl62:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl64
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 62
    ret 4
  lbl64:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 63
    ret 4
  lbl1:
    cmp BYTE PTR [eax+1], '1'
    jne notfound
    cmp BYTE PTR [eax+2], '0'
    jne lbl65
    cmp BYTE PTR [eax+3], '0'
    jne lbl66
    cmp BYTE PTR [eax+4], '0'
    jne lbl67
    cmp BYTE PTR [eax+5], '0'
    jne lbl68
    cmp BYTE PTR [eax+6], '0'
    jne lbl69
    cmp BYTE PTR [eax+7], '0'
    jne lbl70
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 64
    ret 4
  lbl70:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 65
    ret 4
  lbl69:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl71
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 66
    ret 4
  lbl71:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 67
    ret 4
  lbl68:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl72
    cmp BYTE PTR [eax+7], '0'
    jne lbl73
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 68
    ret 4
  lbl73:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 69
    ret 4
  lbl72:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl74
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 70
    ret 4
  lbl74:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 71
    ret 4
  lbl67:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl75
    cmp BYTE PTR [eax+6], '0'
    jne lbl76
    cmp BYTE PTR [eax+7], '0'
    jne lbl77
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 72
    ret 4
  lbl77:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 73
    ret 4
  lbl76:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl78
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 74
    ret 4
  lbl78:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 75
    ret 4
  lbl75:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl79
    cmp BYTE PTR [eax+7], '0'
    jne lbl80
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 76
    ret 4
  lbl80:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 77
    ret 4
  lbl79:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl81
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 78
    ret 4
  lbl81:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 79
    ret 4
  lbl66:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl82
    cmp BYTE PTR [eax+5], '0'
    jne lbl83
    cmp BYTE PTR [eax+6], '0'
    jne lbl84
    cmp BYTE PTR [eax+7], '0'
    jne lbl85
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 80
    ret 4
  lbl85:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 81
    ret 4
  lbl84:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl86
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 82
    ret 4
  lbl86:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 83
    ret 4
  lbl83:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl87
    cmp BYTE PTR [eax+7], '0'
    jne lbl88
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 84
    ret 4
  lbl88:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 85
    ret 4
  lbl87:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl89
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 86
    ret 4
  lbl89:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 87
    ret 4
  lbl82:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl90
    cmp BYTE PTR [eax+6], '0'
    jne lbl91
    cmp BYTE PTR [eax+7], '0'
    jne lbl92
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 88
    ret 4
  lbl92:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 89
    ret 4
  lbl91:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl93
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 90
    ret 4
  lbl93:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 91
    ret 4
  lbl90:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl94
    cmp BYTE PTR [eax+7], '0'
    jne lbl95
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 92
    ret 4
  lbl95:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 93
    ret 4
  lbl94:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl96
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 94
    ret 4
  lbl96:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 95
    ret 4
  lbl65:
    cmp BYTE PTR [eax+2], '1'
    jne notfound
    cmp BYTE PTR [eax+3], '0'
    jne lbl97
    cmp BYTE PTR [eax+4], '0'
    jne lbl98
    cmp BYTE PTR [eax+5], '0'
    jne lbl99
    cmp BYTE PTR [eax+6], '0'
    jne lbl100
    cmp BYTE PTR [eax+7], '0'
    jne lbl101
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 96
    ret 4
  lbl101:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 97
    ret 4
  lbl100:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl102
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 98
    ret 4
  lbl102:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 99
    ret 4
  lbl99:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl103
    cmp BYTE PTR [eax+7], '0'
    jne lbl104
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 100
    ret 4
  lbl104:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 101
    ret 4
  lbl103:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl105
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 102
    ret 4
  lbl105:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 103
    ret 4
  lbl98:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl106
    cmp BYTE PTR [eax+6], '0'
    jne lbl107
    cmp BYTE PTR [eax+7], '0'
    jne lbl108
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 104
    ret 4
  lbl108:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 105
    ret 4
  lbl107:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl109
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 106
    ret 4
  lbl109:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 107
    ret 4
  lbl106:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl110
    cmp BYTE PTR [eax+7], '0'
    jne lbl111
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 108
    ret 4
  lbl111:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 109
    ret 4
  lbl110:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl112
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 110
    ret 4
  lbl112:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 111
    ret 4
  lbl97:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl113
    cmp BYTE PTR [eax+5], '0'
    jne lbl114
    cmp BYTE PTR [eax+6], '0'
    jne lbl115
    cmp BYTE PTR [eax+7], '0'
    jne lbl116
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 112
    ret 4
  lbl116:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 113
    ret 4
  lbl115:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl117
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 114
    ret 4
  lbl117:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 115
    ret 4
  lbl114:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl118
    cmp BYTE PTR [eax+7], '0'
    jne lbl119
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 116
    ret 4
  lbl119:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 117
    ret 4
  lbl118:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl120
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 118
    ret 4
  lbl120:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 119
    ret 4
  lbl113:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl121
    cmp BYTE PTR [eax+6], '0'
    jne lbl122
    cmp BYTE PTR [eax+7], '0'
    jne lbl123
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 120
    ret 4
  lbl123:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 121
    ret 4
  lbl122:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl124
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 122
    ret 4
  lbl124:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 123
    ret 4
  lbl121:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl125
    cmp BYTE PTR [eax+7], '0'
    jne lbl126
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 124
    ret 4
  lbl126:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 125
    ret 4
  lbl125:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl127
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 126
    ret 4
  lbl127:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 127
    ret 4
  lbl0:
    cmp BYTE PTR [eax+0], '1'
    jne notfound
    cmp BYTE PTR [eax+1], '0'
    jne lbl128
    cmp BYTE PTR [eax+2], '0'
    jne lbl129
    cmp BYTE PTR [eax+3], '0'
    jne lbl130
    cmp BYTE PTR [eax+4], '0'
    jne lbl131
    cmp BYTE PTR [eax+5], '0'
    jne lbl132
    cmp BYTE PTR [eax+6], '0'
    jne lbl133
    cmp BYTE PTR [eax+7], '0'
    jne lbl134
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 128
    ret 4
  lbl134:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 129
    ret 4
  lbl133:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl135
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 130
    ret 4
  lbl135:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 131
    ret 4
  lbl132:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl136
    cmp BYTE PTR [eax+7], '0'
    jne lbl137
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 132
    ret 4
  lbl137:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 133
    ret 4
  lbl136:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl138
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 134
    ret 4
  lbl138:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 135
    ret 4
  lbl131:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl139
    cmp BYTE PTR [eax+6], '0'
    jne lbl140
    cmp BYTE PTR [eax+7], '0'
    jne lbl141
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 136
    ret 4
  lbl141:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 137
    ret 4
  lbl140:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl142
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 138
    ret 4
  lbl142:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 139
    ret 4
  lbl139:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl143
    cmp BYTE PTR [eax+7], '0'
    jne lbl144
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 140
    ret 4
  lbl144:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 141
    ret 4
  lbl143:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl145
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 142
    ret 4
  lbl145:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 143
    ret 4
  lbl130:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl146
    cmp BYTE PTR [eax+5], '0'
    jne lbl147
    cmp BYTE PTR [eax+6], '0'
    jne lbl148
    cmp BYTE PTR [eax+7], '0'
    jne lbl149
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 144
    ret 4
  lbl149:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 145
    ret 4
  lbl148:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl150
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 146
    ret 4
  lbl150:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 147
    ret 4
  lbl147:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl151
    cmp BYTE PTR [eax+7], '0'
    jne lbl152
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 148
    ret 4
  lbl152:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 149
    ret 4
  lbl151:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl153
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 150
    ret 4
  lbl153:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 151
    ret 4
  lbl146:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl154
    cmp BYTE PTR [eax+6], '0'
    jne lbl155
    cmp BYTE PTR [eax+7], '0'
    jne lbl156
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 152
    ret 4
  lbl156:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 153
    ret 4
  lbl155:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl157
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 154
    ret 4
  lbl157:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 155
    ret 4
  lbl154:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl158
    cmp BYTE PTR [eax+7], '0'
    jne lbl159
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 156
    ret 4
  lbl159:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 157
    ret 4
  lbl158:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl160
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 158
    ret 4
  lbl160:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 159
    ret 4
  lbl129:
    cmp BYTE PTR [eax+2], '1'
    jne notfound
    cmp BYTE PTR [eax+3], '0'
    jne lbl161
    cmp BYTE PTR [eax+4], '0'
    jne lbl162
    cmp BYTE PTR [eax+5], '0'
    jne lbl163
    cmp BYTE PTR [eax+6], '0'
    jne lbl164
    cmp BYTE PTR [eax+7], '0'
    jne lbl165
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 160
    ret 4
  lbl165:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 161
    ret 4
  lbl164:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl166
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 162
    ret 4
  lbl166:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 163
    ret 4
  lbl163:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl167
    cmp BYTE PTR [eax+7], '0'
    jne lbl168
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 164
    ret 4
  lbl168:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 165
    ret 4
  lbl167:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl169
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 166
    ret 4
  lbl169:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 167
    ret 4
  lbl162:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl170
    cmp BYTE PTR [eax+6], '0'
    jne lbl171
    cmp BYTE PTR [eax+7], '0'
    jne lbl172
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 168
    ret 4
  lbl172:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 169
    ret 4
  lbl171:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl173
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 170
    ret 4
  lbl173:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 171
    ret 4
  lbl170:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl174
    cmp BYTE PTR [eax+7], '0'
    jne lbl175
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 172
    ret 4
  lbl175:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 173
    ret 4
  lbl174:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl176
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 174
    ret 4
  lbl176:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 175
    ret 4
  lbl161:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl177
    cmp BYTE PTR [eax+5], '0'
    jne lbl178
    cmp BYTE PTR [eax+6], '0'
    jne lbl179
    cmp BYTE PTR [eax+7], '0'
    jne lbl180
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 176
    ret 4
  lbl180:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 177
    ret 4
  lbl179:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl181
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 178
    ret 4
  lbl181:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 179
    ret 4
  lbl178:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl182
    cmp BYTE PTR [eax+7], '0'
    jne lbl183
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 180
    ret 4
  lbl183:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 181
    ret 4
  lbl182:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl184
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 182
    ret 4
  lbl184:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 183
    ret 4
  lbl177:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl185
    cmp BYTE PTR [eax+6], '0'
    jne lbl186
    cmp BYTE PTR [eax+7], '0'
    jne lbl187
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 184
    ret 4
  lbl187:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 185
    ret 4
  lbl186:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl188
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 186
    ret 4
  lbl188:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 187
    ret 4
  lbl185:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl189
    cmp BYTE PTR [eax+7], '0'
    jne lbl190
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 188
    ret 4
  lbl190:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 189
    ret 4
  lbl189:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl191
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 190
    ret 4
  lbl191:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 191
    ret 4
  lbl128:
    cmp BYTE PTR [eax+1], '1'
    jne notfound
    cmp BYTE PTR [eax+2], '0'
    jne lbl192
    cmp BYTE PTR [eax+3], '0'
    jne lbl193
    cmp BYTE PTR [eax+4], '0'
    jne lbl194
    cmp BYTE PTR [eax+5], '0'
    jne lbl195
    cmp BYTE PTR [eax+6], '0'
    jne lbl196
    cmp BYTE PTR [eax+7], '0'
    jne lbl197
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 192
    ret 4
  lbl197:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 193
    ret 4
  lbl196:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl198
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 194
    ret 4
  lbl198:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 195
    ret 4
  lbl195:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl199
    cmp BYTE PTR [eax+7], '0'
    jne lbl200
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 196
    ret 4
  lbl200:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 197
    ret 4
  lbl199:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl201
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 198
    ret 4
  lbl201:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 199
    ret 4
  lbl194:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl202
    cmp BYTE PTR [eax+6], '0'
    jne lbl203
    cmp BYTE PTR [eax+7], '0'
    jne lbl204
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 200
    ret 4
  lbl204:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 201
    ret 4
  lbl203:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl205
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 202
    ret 4
  lbl205:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 203
    ret 4
  lbl202:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl206
    cmp BYTE PTR [eax+7], '0'
    jne lbl207
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 204
    ret 4
  lbl207:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 205
    ret 4
  lbl206:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl208
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 206
    ret 4
  lbl208:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 207
    ret 4
  lbl193:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl209
    cmp BYTE PTR [eax+5], '0'
    jne lbl210
    cmp BYTE PTR [eax+6], '0'
    jne lbl211
    cmp BYTE PTR [eax+7], '0'
    jne lbl212
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 208
    ret 4
  lbl212:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 209
    ret 4
  lbl211:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl213
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 210
    ret 4
  lbl213:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 211
    ret 4
  lbl210:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl214
    cmp BYTE PTR [eax+7], '0'
    jne lbl215
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 212
    ret 4
  lbl215:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 213
    ret 4
  lbl214:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl216
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 214
    ret 4
  lbl216:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 215
    ret 4
  lbl209:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl217
    cmp BYTE PTR [eax+6], '0'
    jne lbl218
    cmp BYTE PTR [eax+7], '0'
    jne lbl219
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 216
    ret 4
  lbl219:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 217
    ret 4
  lbl218:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl220
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 218
    ret 4
  lbl220:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 219
    ret 4
  lbl217:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl221
    cmp BYTE PTR [eax+7], '0'
    jne lbl222
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 220
    ret 4
  lbl222:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 221
    ret 4
  lbl221:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl223
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 222
    ret 4
  lbl223:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 223
    ret 4
  lbl192:
    cmp BYTE PTR [eax+2], '1'
    jne notfound
    cmp BYTE PTR [eax+3], '0'
    jne lbl224
    cmp BYTE PTR [eax+4], '0'
    jne lbl225
    cmp BYTE PTR [eax+5], '0'
    jne lbl226
    cmp BYTE PTR [eax+6], '0'
    jne lbl227
    cmp BYTE PTR [eax+7], '0'
    jne lbl228
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 224
    ret 4
  lbl228:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 225
    ret 4
  lbl227:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl229
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 226
    ret 4
  lbl229:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 227
    ret 4
  lbl226:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl230
    cmp BYTE PTR [eax+7], '0'
    jne lbl231
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 228
    ret 4
  lbl231:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 229
    ret 4
  lbl230:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl232
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 230
    ret 4
  lbl232:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 231
    ret 4
  lbl225:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl233
    cmp BYTE PTR [eax+6], '0'
    jne lbl234
    cmp BYTE PTR [eax+7], '0'
    jne lbl235
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 232
    ret 4
  lbl235:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 233
    ret 4
  lbl234:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl236
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 234
    ret 4
  lbl236:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 235
    ret 4
  lbl233:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl237
    cmp BYTE PTR [eax+7], '0'
    jne lbl238
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 236
    ret 4
  lbl238:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 237
    ret 4
  lbl237:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl239
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 238
    ret 4
  lbl239:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 239
    ret 4
  lbl224:
    cmp BYTE PTR [eax+3], '1'
    jne notfound
    cmp BYTE PTR [eax+4], '0'
    jne lbl240
    cmp BYTE PTR [eax+5], '0'
    jne lbl241
    cmp BYTE PTR [eax+6], '0'
    jne lbl242
    cmp BYTE PTR [eax+7], '0'
    jne lbl243
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 240
    ret 4
  lbl243:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 241
    ret 4
  lbl242:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl244
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 242
    ret 4
  lbl244:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 243
    ret 4
  lbl241:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl245
    cmp BYTE PTR [eax+7], '0'
    jne lbl246
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 244
    ret 4
  lbl246:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 245
    ret 4
  lbl245:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl247
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 246
    ret 4
  lbl247:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 247
    ret 4
  lbl240:
    cmp BYTE PTR [eax+4], '1'
    jne notfound
    cmp BYTE PTR [eax+5], '0'
    jne lbl248
    cmp BYTE PTR [eax+6], '0'
    jne lbl249
    cmp BYTE PTR [eax+7], '0'
    jne lbl250
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 248
    ret 4
  lbl250:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 249
    ret 4
  lbl249:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl251
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 250
    ret 4
  lbl251:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 251
    ret 4
  lbl248:
    cmp BYTE PTR [eax+5], '1'
    jne notfound
    cmp BYTE PTR [eax+6], '0'
    jne lbl252
    cmp BYTE PTR [eax+7], '0'
    jne lbl253
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 252
    ret 4
  lbl253:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 253
    ret 4
  lbl252:
    cmp BYTE PTR [eax+6], '1'
    jne notfound
    cmp BYTE PTR [eax+7], '0'
    jne lbl254
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 254
    ret 4
  lbl254:
    cmp BYTE PTR [eax+7], '1'
    jne notfound
    cmp BYTE PTR [eax+8], 0
    jne notfound
    mov eax, 255
    ret 4
  notfound:
    mov eax, -1
    ret 4

bin2byte_ex endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

OPTION PROLOGUE : PrologueDef
OPTION EPILOGUE : EpilogueDef

end
