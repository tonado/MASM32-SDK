@echo off

copy DateTime.inc \masm32\include\DateTime.inc
del DateTime.lib                      : delete any existing MASM32 Library

dir /b *.asm > ml.rsp               : create a response file for ML.EXE
\masm32\bin\ml /c /coff @ml.rsp
if errorlevel 0 goto okml
echo ASSEMBLY ERROR BUILDING LIBRARY MODULES
goto theend

:okml
echo.
\masm32\bin\link -lib *.obj /out:DateTime.lib
if exist DateTime.lib goto oklink

echo LINK ERROR BUILDING LIBRARY
echo The DateTime Library was not built
goto theend

:oklink
copy DateTime.lib \masm32\lib\DateTime.lib

:theend
if exist ml.rsp del ml.rsp
if exist DateTime.lib del *.obj

dir \masm32\include\DateTime.inc
dir \masm32\lib\DateTime.lib