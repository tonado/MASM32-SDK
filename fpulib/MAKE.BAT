@echo off
echo.
echo        Assembling the FPULIB library.
echo.
dir /b *.asm > fpulib.rsp
\masm32\bin\ml /c /coff @fpulib.rsp
\masm32\bin\link -lib *.obj /out:fpu.lib
echo.
del *.obj
copy        fpu.lib \masm32\lib\fpu.lib
copy        fpu.inc \masm32\include\fpu.inc
echo.
echo        FPU.LIB and FPU.INC have been copied
echo        to the LIB and INCLUDE directories.
echo.
dir fpu.lib
del fpulib.rsp
