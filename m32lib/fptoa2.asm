; #########################################################################

    ; -----------------------------------------
    ; This procedure was written by Tim Roberts
    ; -----------------------------------------

	.486
	.model	flat
      option casemap :none  ; case sensitive


; Convert an 8-byte double-precision value to an ASCII string.  
;
; If the value is an integer of less than 16 digits, we convert it to
; an integral value.
;
; If the value is between 0.1 and 9999999.0, we convert it to a decimal
; value.
;
; Otherwise, we convert it to a scientific notation with 1 digit
; left and up to 6 digits right of the decimal, with a 3 digit exponent:
;    9.999999E+999
;
; Note that these rules differ somewhat from the '%g' specifier in printf.  
; But, since you have the source code, you can make this do whatever you 
; want.
;
; I've tried to include comments on how to convert this to use 10-byte
; doubles.
;
; Tim N. Roberts.


; These are bits in the FP status word.

FP_LESSTHAN	equ	01h
FP_EQUALTO	equ	40h

	.data

; I'd rather this was local to the procedure, but masm doesn't do 
; local arrays correctly.

szTemp	db	18 dup (0)

	.code

PowerOf10	proto

ten	dq	10.0
ten16	dq	1.0e16
rounder	dq	5.0e10


; Convert a floating point register to ASCII.  For internal use.
; The result always has exactly 18 digits, with zero padding on the
; left if required.
;
; Entry:	ST(0) = a number to convert, 0 <= ST(0) < 1E19.
;		szTemp = an 18-character buffer.
;
; Exit:		szTemp = the converted result.

FloatToBCD2	PROC	public uses esi edi

    sub esp, 10

	; The fbstp instruction converts the top of the stack to a
	; packed BCD form in ten bytes, with two digits per byte.  The top 
	; byte has the sign, which we ignore.

    fbstp [esp]

	; Now we need to unpack the BCD to ASCII.

    lea esi, [esp+8]
    lea edi, [szTemp]
    mov ecx, 9

    .REPEAT
	mov al, [esi]		; xxxx xxxx AAAA BBBB
	dec esi
	rol ax, 12		; BBBB xxxx xxxx AAAA
	rol ah, 4		; xxxx BBBB xxxx AAAA
	and ax, 0f0fh		; 0000 BBBB 0000 AAAA
	add ax, 3030h		; 3B3A
	mov [edi], ax
	add edi, 2
	dec ecx
    .UNTIL ZERO?

    add esp, 10
    ret

FloatToBCD2	ENDP

;
; Convert a double precision number to a string.
;
; Entry:	fpin = 8-byte double to convert
;		szDbl = character buffer
;
; Exit:		szDbl = converted value
;
; szDbl should be at least 19 bytes long.
;		

FloatToStr2	PROC	stdcall public USES esi edi, 
		fpin: QWORD, 
		szDbl: PTR CHAR

    LOCAL	iExp: DWORD
    LOCAL	stat: WORD
    LOCAL	mystat: WORD

; Special case zero.  fxtract fails for zero.
	
    mov edi, [szDbl]

    .if	(dword ptr [fpin] == 0) && (dword ptr [fpin][4] == 0)
      mov byte ptr [edi], '0'
      mov byte ptr [edi][1], 0
      ret
    .endif

; Check for a negative number.

    .if	(sdword ptr [fpin][4] < 0)
      and byte ptr [fpin][7], 07fh	; change to positive
      mov byte ptr [edi], '-'		; store a minus sign
      inc edi
    .endif

; Initialize the floating point unit and load our value onto the stack.

    fclex
    fstcw [stat]
    mov [mystat], 027fh
    fldcw [mystat]

    fld [fpin]
    fld st(0)

; Compute the closest power of 10 below the number.  We can't get an
; exact value because of rounding.  We could get close by adding in
; log10(mantissa), but it still wouldn't be exact.  Since we'll have to
; check the result anyway, it's silly to waste cycles worrying about
; the mantissa.
;
; The exponent is basically log2(fpin).  Those of you who remember
; algebra realize that log2(fpin) x log10(2) = log10(fpin), which is
; what we want.

    fxtract			; ST=> mantissa, exponent, fpin
    fstp st(0)			; drop the mantissa
    fldlg2			; push log10(2)
    fmulp st(1), st		; ST = log10(fpin), fpin
    fistp [iExp]		; ST = fpin

; An 8-byte double can carry almost 16 digits of precision.  Actually, it's
; 15.9 digits, so some numbers close to 1E17 will be wrong in the bottom
; digit.  If this is a concern, change the '16' to a '15'.
;
; A 10-byte double can carry almost 19 digits, but fbstp only stores the
; guaranteed 18.  If you're doing 10-byte doubles, change the '16' to '18'.

    .IF	([iExp] < 16)
      fld st(0)			; ST = fpin, fpin
      frndint			; ST = int(fpin), fpin
      fcomp st(1)		; ST = fpin, status set
      fstsw ax
      .IF (ah & FP_EQUALTO)	; if EQUAL

; We have an integer!  Lucky day.  Go convert it into a temp buffer.

	call FloatToBCD2

	mov eax, 17
	mov ecx, [iExp]
	sub eax, ecx
	inc ecx
	lea esi, [szTemp][eax]

; The off-by-one order of magnitude problem below can hit us here.  
; We just trim off the possible leading zero.

	.IF (byte ptr [esi] == '0')
	  inc esi
	  dec ecx
	.ENDIF

; Copy the rest of the converted BCD value to our buffer.

	rep movsb
	jmp ftsExit

      .ENDIF
    .ENDIF

; Have fbstp round to 17 places.

    mov eax, 16; experiment
    sub eax, [iExp]	; adjust exponent to 17
    call PowerOf10

; Either we have exactly 17 digits, or we have exactly 16 digits.  We can
; detect that condition and adjust now.

    fcom [ten16]
    ; x0xxxx00 means top of stack > ten16
    ; x0xxxx01 means top of stack < ten16
    ; x1xxxx00 means top of stack = ten16
    fstsw ax
    .IF (ah & 1)
      fmul [ten]
      dec iExp
    .ENDIF

; Go convert to BCD.

    call FloatToBCD2

    lea esi, [szTemp+1]		; point to converted buffer

; If the exponent is between -15 and 16, we should express this as a number
; without scientific notation.

    mov ecx, iExp
    .IF (SDWORD PTR ecx >= -15) && (SDWORD PTR ecx <= 16)

; If the exponent is less than zero, we insert '0.', then -ecx
; leading zeros, then 16 digits of mantissa.  If the exponent is
; positive, we copy ecx+1 digits, then a decimal point (maybe), then 
; the remaining 16-ecx digits.

      inc ecx
      .IF (SDWORD PTR ecx <= 0)
        mov word ptr [edi], '.0'
	add edi, 2
	neg ecx
	mov al, '0'
	rep stosb
	mov ecx, 16
      .ELSE
        rep movsb
        mov byte ptr [edi], '.'
        inc edi
        mov ecx, 16
        sub ecx, [iExp]
      .ENDIF
      rep movsb

; Trim off trailing zeros.

      .WHILE (byte ptr [edi-1] == '0')
	dec edi
      .ENDW

; If we cleared out all the decimal digits, kill the decimal point, too.

      .IF (byte ptr [edi-1] == '.')
	dec edi
      .ENDIF

; That's it.

      jmp ftsExit

    .ENDIF


; Now convert this to a standard, usable format.  If needed, a minus
; sign is already present in the outgoing buffer, and edi already points
; past it.

    movsb				; copy the first digit
    mov byte ptr [edi], '.'		; plop in a decimal point
    inc edi
    movsd				; copy four more digits
    movsw				; copy two more digits

if 0

; The printf %g specified trims off trailing zeros here.  I dislike
; this, so I've disabled it.  Comment out the if 0 and endif if you
; want this.

    .WHILE (byte ptr [edi][-1] == '0')
      dec edi
    .ENDW
endif

; Shove in the exponent.  If you support 10-byte reals, remember to
; allow 4 digits for the exponent.

    mov byte ptr [edi], 'e'	; start the exponent
    mov eax, [iExp]
    .IF (sdword ptr eax < 0)	; plop in the exponent sign
      mov byte ptr [edi][1], '-'
      neg eax
    .ELSE
      mov byte ptr [edi][1], '+'
    .ENDIF

    mov ecx, 10

    xor edx, edx
    div ecx
    add dl, '0'
    mov [edi][4], dl	; shove in the ones exponent digit

    xor edx, edx
    div ecx
    add dl, '0'
    mov [edi][3], dl	; shove in the tens exponent digit

    xor edx, edx
    div ecx
    add dl, '0'
    mov [edi][2], dl	; shove in the hundreds exponent digit

    add edi, 5		; point to terminator

; Clean up and go home.

ftsExit:
    mov byte ptr [edi], 0
    fldcw [stat]		; restore control word
    fwait

    ret

FloatToStr2	ENDP

	end
