; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                        "Console Assemble & Link"

comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

A distinction that is important to understand when writing assembler code
is the difference between the ADDRESS of a variable and the CONTENT of a
variable.

When you refer to a variable you are making DIRECT reference but when you
refer to the ADDRESS of a variable, you are making INDIRECT reference.
This terminology is useful to describe the difference between WHERE a
variable is in memory (its ADDRESS) and what is the value of the variable
(its CONTENT).

Having the ADDRESS of a variable establishes what is called using C
terminology "one" level of INDIRECTION. When you deal with arrays you can
have an array of addresses so when you also have te ADDRESS of the array,
to access the VALUE of the variable in the array from the original array
ADDRESS, you have an additional level of INDIRECTION.

Assembler code is very well suited to handle different levels of
INDIRECTION as long as you understand what the mechanism is and how it
works. The reason why the technique of using levels of INDIRECTION is
so useful is that a single DWORD address can access a much larger
number of variables and do it very quickly.

ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл *

    .486                                    ; create 32 bit code
    .model flat, stdcall                    ; 32 bit memory model
    option casemap :none                    ; case sensitive
 
    include \masm32\include\windows.inc     ; always first
    include \masm32\macros\macros.asm       ; MASM support macros

  ; -----------------------------------------------------------------
  ; include files that have MASM format prototypes for function calls
  ; -----------------------------------------------------------------
    include \masm32\include\masm32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

  ; ------------------------------------------------
  ; Library files that have definitions for function
  ; exports and tested reliable prebuilt code.
  ; ------------------------------------------------
    includelib \masm32\lib\masm32.lib
    includelib \masm32\lib\gdi32.lib
    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\kernel32.lib

    .data
    ; --------------------------
    ; initialise 10 DWORD values
    ; --------------------------
      itm0  dd 0
      itm1  dd 1
      itm2  dd 2
      itm3  dd 3
      itm4  dd 4
      itm5  dd 5
      itm6  dd 6
      itm7  dd 7
      itm8  dd 8
      itm9  dd 9
    ; ---------------------------------
    ; put their addresses into an array
    ; ---------------------------------
      array dd itm0,itm1,itm2,itm3,itm4
            dd itm5,itm6,itm7,itm8,itm9

    .code                       ; Tell MASM where the code starts

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

start:                          ; The CODE entry point to the program

    call main                   ; branch to the "main" procedure

    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    LOCAL cnt   :DWORD          ; allocate a loop counter

    push esi
    push edi

    mov cnt, 10                 ; set the number of loop iterations
    mov esi, array              ; put array address into ESI

  label1:
  ; --------------------------------------------------------
  ; The following line of code is how you remove 1 level
  ; of indirection from an ADDRESS. The technique is called
  ; DEREFERENCING. By enclosing ESI in square brackets it
  ; becomes a MEMORY OPERAND that is the actual data AT the
  ; ADDRESS in ESI.
  ; --------------------------------------------------------
    mov edi, [esi]              ; dereference it into EDI
    print str$(esi)             ; display the address of the value
    print chr$(" = address in memory",13,10)
    print str$(edi)             ; display the dereferenced value
    print chr$("       = content of address",13,10,13,10)
    add esi, 4                  ; add 4 to ESI to get next array item
    sub cnt, 1                  ; subtract 1 from the counter
    jnz label1                  ; jump back to label1 in cnt not zero

    pop edi
    pop esi

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
