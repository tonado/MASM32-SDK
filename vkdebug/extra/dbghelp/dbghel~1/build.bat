\masm32\bin\ml /c /coff dbghelp.asm > out.txt
\masm32\bin\Link /DLL /DEF:dbghelp.def /SUBSYSTEM:WINDOWS dbghelp.obj >> out.txt
del *.dll
del *.obj
del *.exp
copy dbghelp.lib \masm32\lib\dbghelp.lib
copy dbghelp.inc \masm32\include\dbghelp.inc
