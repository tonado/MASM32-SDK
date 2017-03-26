\masm32\bin\ml /c /coff *.asm > out.txt
\masm32\bin\lib *.obj /out:debug.lib

del *.obj

copy debug.lib \masm32\lib\debug.lib >> out.txt
copy debug.inc \masm32\include\debug.inc >> out.txt