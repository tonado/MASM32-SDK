@echo off

copy masm32.inc \masm32\include\masm32.inc

del masm32.lib                      : delete any existing MASM32 Library

dir /b *.asm > ml.rsp               : create a response file for ML.EXE
\masm32\bin\ml.exe /c /coff @ml.rsp
if errorlevel 0 goto okml
:::: del ml.rsp
echo ASSEMBLY ERROR BUILDING LIBRARY MODULES
pause
goto theend

:okml
\masm32\bin\link -lib *.obj /out:masm32.lib
if exist masm32.lib goto oklink

echo LINK ERROR BUILDING LIBRARY
echo The MASM32 Library was not built
goto theend

:oklink
copy masm32.lib \masm32\lib\masm32.lib

:theend
if exist masm32.lib del *.obj

dir \masm32\lib\masm32.lib
dir \masm32\include\masm32.inc
