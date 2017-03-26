; #########################################################################
;
;                             ARGCOUNT.ASM
;
; This file MUST be included BEFORE any INCLUDE files that are created with
; the L2EXTIA.EXE utility. The EXTERNDEF statements in the include files
; require the parameter count provided by this macro to be expanded in
; place. The INCLUDE files will not work if the parameter count macro is
; not run first.
;
; #########################################################################


    ArgCount MACRO number
      LOCAL txt
      txt equ <typedef PROTO :DWORD>
        REPEAT number - 1
          txt CATSTR txt,<,:DWORD>
        ENDM
      EXITM <txt>
    ENDM

    pr0  typedef PROTO
    pr1  ArgCount(1)
    pr2  ArgCount(2)
    pr3  ArgCount(3)
    pr4  ArgCount(4)
    pr5  ArgCount(5)
    pr6  ArgCount(6)
    pr7  ArgCount(7)
    pr8  ArgCount(8)
    pr9  ArgCount(9)
    pr10 ArgCount(10)
    pr11 ArgCount(11)
    pr12 ArgCount(12)
    pr13 ArgCount(13)
    pr14 ArgCount(14)
    pr15 ArgCount(15)
    pr16 ArgCount(16)
    pr17 ArgCount(17)
    pr18 ArgCount(18)
    pr19 ArgCount(19)
    pr20 ArgCount(20)
    pr21 ArgCount(21)
    pr22 ArgCount(22)
    pr23 ArgCount(23)
    pr24 ArgCount(24)
    pr25 ArgCount(25)

; #########################################################################
