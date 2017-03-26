; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                       "Console Assemble and Link"

comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

A normal component of almost all programs is data. It can be either numeric
data or text data. In MASM you have the distinction between data that is
initialised with a value or UNinitialised data that just reserves the
space to write data to.

Initialised data has this form.

.data
  var1  dd  0                           ; 32 bit value initialised to zero
  var2  dd  125                         ; 32 bit value initialised to 125
  txt1  db  "This is text in MASM",0    ; A zero terminated sequence of TEXT

  array dd 1,2,3,4,5,6,7,8              ; 8 x 32 bit values in sequence

Uninitialised data has this form.

.data?
  udat1 dd ?                            ; Uninitialised single 32 bit space
  buffa db 128 dup (?)                  ; 128 BYTES of uninitialised space

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
      txtmsg db "I am data in the initialised data section",0

    .code                       ; Tell MASM where the code starts

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

start:                          ; The CODE entry point to the program

    call main                   ; branch to the "main" procedure

    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    print OFFSET txtmsg         ; the "OFFSET" operator tells MASM that the text 
                                ; data is at an OFFSET within the file which means
                                ; in this instance that it is in the .DATA section

    ret                         ; return to the next instruction after "call"

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
