; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                        "Console Assemble & Link"

comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

This demo shows how to perform simple addition using registers and assembler
instructions in the first example. The second example shows how to compare
a memory variable to an immediate number and branch to different labels
depending on how large the number is. Branching logic in assembler is very
simple and compact code.

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

    .code                       ; Tell MASM where the code starts

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

start:                          ; The CODE entry point to the program

    call main                   ; branch to the "main" procedure

    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    LOCAL var1:DWORD            ; space for a DWORD variable
    LOCAL str1:DWORD            ; a string handle for the input data

  ; test the MOV and ADD instructions

    mov eax, 100                ; copy the IMMEDIATE number 100 into the EAX register
    mov ecx, 250                ; copy the IMMEDIATE number 250 into the ECX register
    add ecx, eax                ; ADD EAX to ECX
    print str$(ecx)             ; show the result at the console
    print chr$(13,10,13,10)

  ; ----------------------------------------
  ; The two following macros can be combined
  ; once you are familiar with how they work
  ; ----------------------------------------
 ;     mov str1, input("Enter a number : ")
 ;     mov var1, sval(str1)        ; convert the result to a signed integer

    mov var1, sval(input("Enter a number : "))

    cmp var1, 100               ; compare the variable to the immediate number 100
    je equal                    ; jump if var1 is equal to 100 to "equal"
    jg bigger                   ; jump if var1 is greater than 100 to "bigger"
    jl smaller                  ; jump if var1 is less than 100 to "smaller"

  equal:
    print chr$("The number you entered is 100",13,10)
    jmp over

  bigger:
    print chr$("The number you entered is greater than 100",13,10)
    jmp over

  smaller:
    print chr$("The number you entered is smaller than 100",13,10)

  over:

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
