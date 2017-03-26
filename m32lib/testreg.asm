; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                      ; force 32 bit code
    .model flat, stdcall      ; memory model & calling convention
    option casemap :none      ; case sensitive

    .code

comment * -----------------------------------------------------------------

        Very high speed word recognition

        "testreg" tests if a zero terminated string is a register or not.
        It tests if a register is a segment register, 8, 16 or 32
        bit register. It supports both upper and lower case forms.

        Return values
        Not a register      0
        Segment register    1       cs  ds  es  ss  fs  gs
        8  bit register     2       al  ah  bl  bh  cl  ch  dl  dh
        16 bit register     3       ax  bx  cx  dx  si  di  sp  bp
        32 bit register     4       eax ebx ecx edx esi edi esp ebp

        Calling technique
        "testreg" receives the address of the zero terminated string in
        the EAX register and returns the result in the EAX register.

        Example:
        mov eax, lpString
        call testreg

        Code generation powered by JIBZ technology

        ----------------------------------------------------------------- *

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 16

testreg proc

  cmp BYTE PTR [eax+0], 'A'
  jne lbl0
    cmp BYTE PTR [eax+1], 'H'
    jne lbl1
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl1:
    cmp BYTE PTR [eax+1], 'L'
    jne lbl2
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl2:
    cmp BYTE PTR [eax+1], 'X'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl0:
  cmp BYTE PTR [eax+0], 'B'
  jne lbl3
    cmp BYTE PTR [eax+1], 'H'
    jne lbl4
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl4:
    cmp BYTE PTR [eax+1], 'L'
    jne lbl5
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl5:
    cmp BYTE PTR [eax+1], 'P'
    jne lbl6
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl6:
    cmp BYTE PTR [eax+1], 'X'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl3:
  cmp BYTE PTR [eax+0], 'C'
  jne lbl7
    cmp BYTE PTR [eax+1], 'H'
    jne lbl8
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl8:
    cmp BYTE PTR [eax+1], 'L'
    jne lbl9
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl9:
    cmp BYTE PTR [eax+1], 'S'
    jne lbl10
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
    lbl10:
    cmp BYTE PTR [eax+1], 'X'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl7:
  cmp BYTE PTR [eax+0], 'D'
  jne lbl11
    cmp BYTE PTR [eax+1], 'H'
    jne lbl12
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl12:
    cmp BYTE PTR [eax+1], 'I'
    jne lbl13
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl13:
    cmp BYTE PTR [eax+1], 'L'
    jne lbl14
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl14:
    cmp BYTE PTR [eax+1], 'S'
    jne lbl15
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
    lbl15:
    cmp BYTE PTR [eax+1], 'X'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl11:
  cmp BYTE PTR [eax+0], 'E'
  jne lbl16
    cmp BYTE PTR [eax+1], 'A'
    jne lbl17
      cmp BYTE PTR [eax+2], 'X'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl17:
    cmp BYTE PTR [eax+1], 'B'
    jne lbl18
      cmp BYTE PTR [eax+2], 'P'
      jne lbl19
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl19:
      cmp BYTE PTR [eax+2], 'X'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl18:
    cmp BYTE PTR [eax+1], 'C'
    jne lbl20
      cmp BYTE PTR [eax+2], 'X'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl20:
    cmp BYTE PTR [eax+1], 'D'
    jne lbl21
      cmp BYTE PTR [eax+2], 'I'
      jne lbl22
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl22:
      cmp BYTE PTR [eax+2], 'X'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl21:
    cmp BYTE PTR [eax+1], 'S'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne lbl23
        mov eax, 1
        ret
      lbl23:
      cmp BYTE PTR [eax+2], 'I'
      jne lbl24
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl24:
      cmp BYTE PTR [eax+2], 'P'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
  lbl16:
  cmp BYTE PTR [eax+0], 'F'
  jne lbl25
    cmp BYTE PTR [eax+1], 'S'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
  lbl25:
  cmp BYTE PTR [eax+0], 'G'
  jne lbl26
    cmp BYTE PTR [eax+1], 'S'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
  lbl26:
  cmp BYTE PTR [eax+0], 'S'
  jne lbl27
    cmp BYTE PTR [eax+1], 'I'
    jne lbl28
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl28:
    cmp BYTE PTR [eax+1], 'P'
    jne lbl29
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl29:
    cmp BYTE PTR [eax+1], 'S'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
  lbl27:
  cmp BYTE PTR [eax+0], 'a'
  jne lbl30
    cmp BYTE PTR [eax+1], 'h'
    jne lbl31
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl31:
    cmp BYTE PTR [eax+1], 'l'
    jne lbl32
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl32:
    cmp BYTE PTR [eax+1], 'x'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl30:
  cmp BYTE PTR [eax+0], 'b'
  jne lbl33
    cmp BYTE PTR [eax+1], 'h'
    jne lbl34
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl34:
    cmp BYTE PTR [eax+1], 'l'
    jne lbl35
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl35:
    cmp BYTE PTR [eax+1], 'p'
    jne lbl36
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl36:
    cmp BYTE PTR [eax+1], 'x'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl33:
  cmp BYTE PTR [eax+0], 'c'
  jne lbl37
    cmp BYTE PTR [eax+1], 'h'
    jne lbl38
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl38:
    cmp BYTE PTR [eax+1], 'l'
    jne lbl39
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl39:
    cmp BYTE PTR [eax+1], 's'
    jne lbl40
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
    lbl40:
    cmp BYTE PTR [eax+1], 'x'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl37:
  cmp BYTE PTR [eax+0], 'd'
  jne lbl41
    cmp BYTE PTR [eax+1], 'h'
    jne lbl42
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl42:
    cmp BYTE PTR [eax+1], 'i'
    jne lbl43
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl43:
    cmp BYTE PTR [eax+1], 'l'
    jne lbl44
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 2
        ret
    lbl44:
    cmp BYTE PTR [eax+1], 's'
    jne lbl45
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
    lbl45:
    cmp BYTE PTR [eax+1], 'x'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
  lbl41:
  cmp BYTE PTR [eax+0], 'e'
  jne lbl46
    cmp BYTE PTR [eax+1], 'a'
    jne lbl47
      cmp BYTE PTR [eax+2], 'x'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl47:
    cmp BYTE PTR [eax+1], 'b'
    jne lbl48
      cmp BYTE PTR [eax+2], 'p'
      jne lbl49
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl49:
      cmp BYTE PTR [eax+2], 'x'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl48:
    cmp BYTE PTR [eax+1], 'c'
    jne lbl50
      cmp BYTE PTR [eax+2], 'x'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl50:
    cmp BYTE PTR [eax+1], 'd'
    jne lbl51
      cmp BYTE PTR [eax+2], 'i'
      jne lbl52
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl52:
      cmp BYTE PTR [eax+2], 'x'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
    lbl51:
    cmp BYTE PTR [eax+1], 's'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne lbl53
        mov eax, 1
        ret
      lbl53:
      cmp BYTE PTR [eax+2], 'i'
      jne lbl54
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
      lbl54:
      cmp BYTE PTR [eax+2], 'p'
      jne notfound
        cmp BYTE PTR [eax+3], 0
        jne notfound
          mov eax, 4
          ret
  lbl46:
  cmp BYTE PTR [eax+0], 'f'
  jne lbl55
    cmp BYTE PTR [eax+1], 's'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
  lbl55:
  cmp BYTE PTR [eax+0], 'g'
  jne lbl56
    cmp BYTE PTR [eax+1], 's'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret
  lbl56:
  cmp BYTE PTR [eax+0], 's'
  jne notfound
    cmp BYTE PTR [eax+1], 'i'
    jne lbl57
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl57:
    cmp BYTE PTR [eax+1], 'p'
    jne lbl58
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 3
        ret
    lbl58:
    cmp BYTE PTR [eax+1], 's'
    jne notfound
      cmp BYTE PTR [eax+2], 0
      jne notfound
        mov eax, 1
        ret

    notfound:
    xor eax, eax
    ret

testreg endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end