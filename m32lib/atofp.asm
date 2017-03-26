; #########################################################################

    ; -----------------------------------------
    ; This procedure was written by Tim Roberts
    ; -----------------------------------------

	.486
	.model	flat
      option casemap :none  ; case sensitive


; Convert a string containing an ASCII representation of a floating 
; point value to an 8-byte double precision number.  Returns a pointer
; to the first character it couldn't convert.
;
; char * StrToFloat( char * szIn, double * fpOut );
;
; Here is a perl regular expression to describe the formats we accept:
;
;    (+|-)?[0-9]+(.[0-9]*)?(E(+|-)[0-9]+)
;
; Tim N. Roberts

	.code

ten	dq	10.0

ten_1	dt	1.0e1
	dt	1.0e2
	dt	1.0e3
	dt	1.0e4
	dt	1.0e5
	dt	1.0e6
	dt	1.0e7
	dt	1.0e8
	dt	1.0e9
	dt	1.0e10
	dt	1.0e11
	dt	1.0e12
	dt	1.0e13
	dt	1.0e14
	dt	1.0e15

ten_16	dt	1.0e16
	dt	1.0e32
	dt	1.0e48
	dt	1.0e64
	dt	1.0e80
	dt	1.0e96
	dt	1.0e112
	dt	1.0e128
	dt	1.0e144
	dt	1.0e160
	dt	1.0e176
	dt	1.0e192
	dt	1.0e208
	dt	1.0e224
	dt	1.0e240

ten_256	dt	1.0e256
; The remaining exponents are only necessary if we decide to support
; 10-byte doubles.  FloatToStr and StrToFloat only support 8-byte,
; but PowerOf10 doesn't care, so we'll include them.
	dt	1.0e512
	dt	1.0e768
	dt	1.0e1024
	dt	1.0e1280
	dt	1.0e1536
	dt	1.0e1792
	dt	1.0e2048
	dt	1.0e2304
	dt	1.0e2560
	dt	1.0e2816
	dt	1.0e3072
	dt	1.0e3328
	dt	1.0e3584
	dt	1.0e4096
	dt	1.0e4352
	dt	1.0e4608
	dt	1.0e4864

; Multiply a floating point value by an integral power of 10.
;
; Entry: EAX = power of 10, -4932..4932.
;	ST(0) = value to be multiplied
;
; Exit:	ST(0) = value x 10^eax

PowerOf10	PROC	public

    mov ecx, eax
    .IF	(SDWORD PTR eax < 0)
	neg eax
    .ENDIF

    fld1

    mov dl, al
    and edx, 0fh
    .IF	(!ZERO?)
	lea edx, [edx+edx*4]
	fld ten_1[edx*2][-10]
	fmulp st(1), st
    .ENDIF

    mov dl, al
    shr dl, 4
    and edx, 0fh
    .IF (!ZERO?)
	lea edx, [edx+edx*4]
	fld ten_16[edx*2][-10]
	fmulp st(1), st
    .ENDIF

    mov dl, ah
    and edx, 1fh
    .IF (!ZERO?)
	lea edx, [edx+edx*4]
	fld ten_256[edx*2][-10]
	fmulp st(1), st
    .ENDIF

    .IF (SDWORD PTR ecx < 0)
	fdivp st(1), st
    .ELSE
	fmulp st(1), st
    .ENDIF

    ret

PowerOf10	ENDP

;
; Convert a string to a double-precision floating point number
;
; char * StrToFloat( char * str, double * fpout );
;

StrToFloat	PROC	stdcall public, szIn: PTR BYTE, fpout: PTR QWORD
	LOCAL	sign: BYTE
	LOCAL	expsign: BYTE
	LOCAL	decimal: DWORD
	LOCAL	stat: WORD
	LOCAL	temp: WORD

    xor eax, eax
    mov [sign], al
    mov [expsign], al
    mov [decimal], -1

    fstcw [stat]
    mov [temp], 027fh
    fldcw [temp]

; First, see if we have a sign at the front end.

    mov esi, [szIn]
    mov al, [esi]

    .IF (al == '+')
	inc	esi
	mov	al, [esi]
    .ELSEIF (al == '-')
	inc	esi
	mov	[sign], 1
	mov	al, [esi]
    .ENDIF

    cmp al, 0		; null string?
    je sdExit

; Initialize the floating point unit.

    fclex
    xor ebx, ebx
    fldz
    xor ecx, ecx

; OK, now start our main loop.

;   esi => character in string now in al
;   al = next character to be converted
;   ebx = number of digits encountered thus far
;   ecx = exponent
;   ST(0) = accumulator

cvtloop:
    cmp al, 'E'
    je doExponent
    cmp al, 'e'
    je doExponent

    .IF (al == '.')
	mov [decimal], ebx	; remember decimal point location
    .ELSE
	sub al, '0'		; convert ASCII to BCD
	jb sdFinish	; if not a digit
	cmp al, 9
	ja sdFinish	; if not a digit
	mov [temp], ax
	fmul [ten]		; d *= 10
	fiadd [temp]		; d += new digit
	inc ebx		; increment digit counter
    .ENDIF

    inc esi
    mov al, [esi]
    jnz cvtloop
    jmp sdFinish

; We have the mantissa at the top of the stack.  Now convert the exponent.
; Fortunately, this is an integer.

;   esi = pointer to character in al
;   al = next character to convert
;   ebx = digit counter
;   ecx = accumulated exponent
;   ST(0) = mantissa

doExponent:
    inc esi
    mov al, [esi]
    cmp al, 0
    jz sdFinish

    ; Does the exponent have a sign?

    .IF	(al == '+')
	inc esi
	mov al, [esi]
    .ELSEIF (al == '-')
	inc esi
	mov [expsign], 1
	mov al, [esi]
    .ENDIF

    cmp al, 0
    jz sdFinish

expLoop:
    sub al, '0'
    jb sdFinish
    cmp al, 9
    ja sdFinish
    imul ecx, 10
    add ecx, eax

    inc esi
    mov al, [esi]
    jnz expLoop

; Adjust the exponent to account for decimal places.  At this juncture, 
; we work with the absolute value of the exponent.  That means we need
; to subtract the adjustment if the exponent will be negative, add if
; the exponent will be positive.

;  ST(0) = mantissa
;  ecx = unadjusted exponent
;  ebx = total number of digits

sdFinish:
    .IF ([expsign] != 0)
	neg ecx
    .ENDIF
    mov eax, [decimal]
    .IF (eax != -1)
	sub ebx, eax	; ebx = digits to right of decimal place
	sub ecx, ebx	; adjust exponent
    .ENDIF

; Multiply by 10^exponent.

;  ST(0) = mantissa
;  ecx = exponent

    mov eax, ecx
    call PowerOf10

; Negate the whole thing, if necessary.

    .IF	([sign] != 0)
	fchs
    .ENDIF

; That's it!  Store it and go home.

    mov edi, [fpout]
    fstp qword ptr [edi]	; store the reslt
    fwait

sdExit:
    fldcw [stat]
    mov eax, esi	; return pt to next unread char
    ret

StrToFloat	ENDP

	end
