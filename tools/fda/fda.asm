; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
    include \masm32\include\masm32rt.inc
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

comment * -----------------------------------------------------
                        Build this  template with
                       "CONSOLE ASSEMBLE AND LINK"
        ----------------------------------------------------- *

    .code

start:
  
; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    call main

    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

main proc

    LOCAL pinput        :DWORD              ; 1st argument pointer
    LOCAL poutput       :DWORD              ; 2nd argument pointer
    LOCAL pname         :DWORD              ; 3rd argument pointer
    LOCAL pspare        :DWORD              ; spare buffer pointer
    LOCAL pdata         :DWORD              ; pointer to file data
    LOCAL flen          :DWORD              ; variable for file length
    LOCAL hout          :DWORD              ; output file handle
    LOCAL wcnt          :DWORD
    LOCAL hinc          :DWORD              ; file handle for output include file
    LOCAL pftr          :DWORD
    LOCAL paln          :DWORD
    LOCAL aflag         :DWORD              ; alignment flag
    LOCAL alind         :DWORD              ; variable to hold alignment choice
    LOCAL buffer1[260]  :BYTE               ; source file name buffer
    LOCAL buffer2[260]  :BYTE               ; target file name buffer
    LOCAL buffer3[32]   :BYTE               ; external data item name buffer
    LOCAL buffer4[260]  :BYTE               ; spare buffer
    LOCAL alnbuff[32]   :BYTE               ; buffer for alignment size
    LOCAL ifh           :IMAGE_FILE_HEADER
    LOCAL ish           :IMAGE_SECTION_HEADER
    LOCAL ist           :IMAGE_SYMBOL

    mov pinput,  ptr$(buffer1)              ; cast buffers to pointers
    mov poutput, ptr$(buffer2)
    mov pname,   ptr$(buffer3)
    mov pspare,  ptr$(buffer4)
    mov paln,    ptr$(alnbuff)

    invoke GetCL,1,pinput
    .if rv(exist,pinput) == 0               ; test if input file exists
      print "No source file",13,10
      call help
      ret
    .endif

    invoke GetCL,2,poutput                  ; test if valid argument for output file
    switch eax
      case 1
        jmp tstname
      case 2
        print "Missing target file name",13,10,13,10
        call help
        ret
      case 3
        print "Non matching quotes",13,10
        call help
        ret
      case 4
        print "Empty quotes",13,10
        call help
        ret
    endsw

  tstname:

    invoke GetCL,3,pname                    ; test if item name is present
    switch eax
      case 1
        mov pname, cat$(pspare,"_",pname)   ; prepend leading "_" to itemname
      case 2
        print "Missing data item name",13,10
        call help
        ret
      case 3
        print "Non matching quotes",13,10
        call help
        ret
      case 4
        print "Empty quotes",13,10
        call help
        ret
    endsw

    invoke GetCL,4,paln
    .if eax != 1
      mov aflag, IMAGE_SCN_ALIGN_4BYTES     ; default align is 4 if not set
      mov alind, 4
      jmp read_data
    .endif

    switch$ paln
      case$ "1"
        mov aflag, IMAGE_SCN_ALIGN_1BYTES
        mov alind, 1
      case$ "2"
        mov aflag, IMAGE_SCN_ALIGN_2BYTES
        mov alind, 2
      case$ "4"
        mov aflag, IMAGE_SCN_ALIGN_4BYTES
        mov alind, 4
      case$ "8"
        mov aflag, IMAGE_SCN_ALIGN_8BYTES
        mov alind, 8
      case$ "16"
        mov aflag, IMAGE_SCN_ALIGN_16BYTES
        mov alind, 16
      case$ "32"
        mov aflag, IMAGE_SCN_ALIGN_32BYTES
        mov alind, 32
      case$ "64"
        mov aflag, IMAGE_SCN_ALIGN_64BYTES
        mov alind, 64
      case$ "128"
        mov aflag, IMAGE_SCN_ALIGN_128BYTES
        mov alind, 128
      case$ "256"
        mov aflag, IMAGE_SCN_ALIGN_256BYTES
        mov alind, 256
      case$ "512"
        mov aflag, IMAGE_SCN_ALIGN_512BYTES
        mov alind, 512
      case$ "1024"
        mov aflag, IMAGE_SCN_ALIGN_1024BYTES
        mov alind, 1024
      case$ "2048"
        mov aflag, IMAGE_SCN_ALIGN_2048BYTES
        mov alind, 2048
      case$ "4096"
        mov aflag, IMAGE_SCN_ALIGN_4096BYTES
        mov alind, 4096
      case$ "8192"
        mov aflag, IMAGE_SCN_ALIGN_8192BYTES
        mov alind, 8192
      else$
        mov aflag, IMAGE_SCN_ALIGN_4BYTES       ; default is align by 4 if error.
        mov alind, 4
    endsw$

  read_data:

    print "File Data Assembler 2.0 Copyright (c) The MASM32 Project 1998-2005",13,10,13,10

    print "Loading source   : "
    print pinput,13,10

    mov pdata, InputFile(pinput)
    mov flen, ecx
    mov hout, fcreate(poutput)

    print "Creating module  : "
    print poutput,13,10

  ; ----------------------------------------------
  ; calculate the start offset of the symbol table
  ; ----------------------------------------------
    mov edx, SIZEOF IMAGE_FILE_HEADER
    add edx, SIZEOF IMAGE_SECTION_HEADER
    add edx, flen

  ; -----------------
  ; IMAGE_FILE_HEADER
  ; -----------------
    mov ifh.Machine,                IMAGE_FILE_MACHINE_I386 ; dw
    mov ifh.NumberOfSections,       1           ; dw
    mov ifh.TimeDateStamp,          0           ; dd
    mov ifh.PointerToSymbolTable,   edx         ; dd
    mov ifh.NumberOfSymbols,        1           ; dd
    mov ifh.SizeOfOptionalHeader,   0           ; dw
    mov ifh.Characteristics,        IMAGE_FILE_RELOCS_STRIPPED or \
                                    IMAGE_FILE_LINE_NUMS_STRIPPED         ; dw
  ; --------------------
  ; IMAGE_SECTION_HEADER
  ; --------------------
    lea eax, ish.Name1
    mov DWORD PTR [eax], "tad."     ; write ".data" to Name1 member
    mov DWORD PTR [eax+4], "a"

    mov ish.Misc.PhysicalAddress,   0           ; dd
    mov ish.VirtualAddress,         0           ; dd
    m2m ish.SizeOfRawData,          flen        ; dd

    mov edx, SIZEOF IMAGE_FILE_HEADER
    add edx, SIZEOF IMAGE_SECTION_HEADER
    mov ish.PointerToRawData,       edx         ; dd

    mov ish.PointerToRelocations,   0           ; dd
    mov ish.PointerToLinenumbers,   0           ; dd
    mov ish.NumberOfRelocations,    0           ; dw
    mov ish.NumberOfLinenumbers,    0           ; dw

    mov eax, IMAGE_SCN_CNT_INITIALIZED_DATA or IMAGE_SCN_MEM_READ or IMAGE_SCN_MEM_WRITE
    or eax, aflag
    mov ish.Characteristics, eax                ; dd

  ; -----------------
  ; COFF SYMBOL TABLE
  ; -----------------
    lea eax, ist.N.LongName
    mov DWORD PTR [eax], 0                      ; zero fill 1st 4 bytes
    mov DWORD PTR [eax+4], 4                    ; OFFSET is 4th byte into the string table

    mov ist.Value, 0
    mov ist.SectionNumber, 1
    mov ist.Type1, 0
    mov ist.StorageClass, IMAGE_SYM_CLASS_EXTERNAL
    mov ist.NumberOfAuxSymbols, 0

  ; --------------------
  ; write result to file
  ; --------------------
    mov wcnt, fwrite(hout,ADDR ifh,SIZEOF IMAGE_FILE_HEADER)
    mov wcnt, fwrite(hout,ADDR ish,SIZEOF IMAGE_SECTION_HEADER)
    mov wcnt, fwrite(hout,pdata,flen)       ; write the file data
    mov wcnt, fwrite(hout,ADDR ist,SIZEOF IMAGE_SYMBOL)

comment * ------------------------------------------------------------------
        The following code is a work around to solve a problem, the string
        table is written by writing the DWORD with an arbitrary length of
        64 bytes. The public data label is written directly after the DWORD
        and the balance of 64 bytes is zero filled. This solved the problem
        of the linker displaying an error about the end of the string table
        being invalid.
        ------------------------------------------------------------------ *

  ; ------------
  ; string table
  ; ------------

    mov wcnt, 64
    mov wcnt, fwrite(hout,ADDR wcnt,4)  ; write the table length to 1st DWORD

    mov edx, len(pname)
    mov wcnt, fwrite(hout,pname,edx)    ; write the data label name after it.

    mov edx, len(pname)                 ; length of name
    add edx, 4                          ; add 4 for 1st DWORD
    mov wcnt, 65
    sub wcnt, edx

    .data
      filler db 128 dup (0)
    .code

    mov wcnt, fwrite(hout,ADDR filler,wcnt)

    fclose hout
    free pdata
    free pftr

  ; ---------------------------------
  ; write the EXTERNDEF statement and
  ; length equate to the include file
  ; ---------------------------------
    mov poutput, lcase$(poutput)                ; ensure lower case
    mov poutput, remove$(poutput,".obj")        ; strip extension
    mov poutput, cat$(poutput,".inc")           ; add new extension

    print "Writing include  : "
    print poutput,13,10

    mov hinc, fcreate(poutput)

    fprint hinc,"; -----------------------------------------------------"
    fprint hinc,"; Include the contents of this file in your source file"
    fprint hinc,"; to access the data as an OFFSET and use the equate as"
    fprint hinc,"; the byte count for the file data in the object module"
    fprint hinc,"; -----------------------------------------------------"

    mov edx, len(pname)
    sub edx, 1
    mov pname, right$(pname,edx)

    mov poutput, ptr$(buffer2)
    mov poutput, cat$(poutput,"EXTERNDEF ",pname,":DWORD")
    fprint hinc,poutput

    mov poutput, ptr$(buffer2)
    mov poutput, cat$(poutput,"ln_",pname," equ ",chr$(60),str$(flen),chr$(62))
    fprint hinc, poutput

    fclose hinc

    print "Raw data size    : "
    print str$(flen)," bytes",13,10

    print "Data alignment   : "
    print str$(alind)," bytes",13,10

  ; -----------------------------------------

    ret

main endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

help proc

    .data

      txt db "File Data Assembler 2.0 Copyright (c) The MASM32 Project 1998-2005",13,10,13,10
          db "PARAMETERS",13,10
          db "      1 source file",13,10
          db "      2 target object file",13,10
          db "      3 data label name",13,10
          db "      4 data alignment [optional]",13,10,13,10
          db "NOTES",13,10
          db "      Source file MUST be an existing file",13,10
          db '      Target file MUST have an "obj" extension',13,10
          db "      The optional data aligment MUST be specified in powers of 2",13,10
          db "      Alignment range is 1 to 8192 bytes, default is 4 bytes.",13,10
          db "      Long names are supported but names with spaces MUST be",13,10
          db '      enclosed in quotations.',13,10
          db "OUTPUT",13,10
          db "      fda.exe produces two (2) files,",13,10
          db "      a. An object module file as named in the target.",13,10
          db "      b. An INCLUDE file of the same name as the target",13,10
          db "         which contains an EXTERNDEF for the data label",13,10
          db "         name and an equate that contains the bytecount",13,10
          db "         for the data in the object module.",13,10
          db "EXAMPLE",13,10
          db '      fda "My Source File.Ext" target.obj MyFile 16',13,10,0

    .code

    print OFFSET txt

    ret

help endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start
