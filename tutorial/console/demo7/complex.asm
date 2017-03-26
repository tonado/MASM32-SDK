; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                        "Console Assemble & Link"

comment @ ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

The standard Intel notation for addressing memory can look very daunting
to a beginner but it is in fact very compact and simple enough to use
once you know how it works. It is usually referred to as the "complex"
addressing modes. If you understand it properly you can write very compact
and fast code using the technique.

When you have code like,

mov eax, [ebx+ecx*4+32]

The section enclosed in square brackets is broken up in the following
manner.

[Base Address + Index * Scale + Displacement]

Base address
The starting address in memory

Index
A 32 bit register which is the variable for changing the address

Scale
The data size being worked on, it can be 1, 2, 4 or 8

Displacement
An optional additional offset to change the address by.

The example below will show how it works.

ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл @

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

    push ebx
    push esi
    push edi

    mov cnt, 10                 ; set the number of loop iterations

    mov ebx, array              ; put BASE ADDRESS of array in EBX
    xor esi, esi                ; Use ESI as INDEX and set to zero

    print chr$("Index being changed",13,10)

  label2:
    mov edi, [ebx+esi*4]
    print str$(edi)
    print chr$(13,10)
    add esi, 1                  ; each array member is accessed by changing the INDEX
    sub cnt, 1
    jnz label2

    print chr$("Displacement being changed",13,10)

    xor esi, esi

    mov edi, [ebx+esi*4]        ; no displacement
    print str$(edi)
    print chr$(13,10)

    mov edi, [ebx+esi*4+4]      ; added displacement of 4 bytes
    print str$(edi)
    print chr$(13,10)

    mov edi, [ebx+esi*4+8]      ; added displacement of 8 bytes
    print str$(edi)
    print chr$(13,10)

    mov edi, [ebx+esi*4+12]     ; added displacement of 12 bytes
    print str$(edi)
    print chr$(13,10)


    pop edi
    pop esi
    pop ebx

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
