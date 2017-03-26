@echo off

\masm32\bin\rc /v rsrc.rc
 
if exist "cpicker.obj" del "cpicker.obj"
if exist "cpicker.exe" del "cpicker.exe"

\masm32\bin\ml /c /coff "cpicker.asm"
if errorlevel 1 goto errasm

\masm32\bin\PoLink /SUBSYSTEM:WINDOWS "cpicker.obj" rsrc.res
if errorlevel 1 goto errlink

dir "cpicker.*"
goto TheEnd

:errlink
echo _
echo Link error
goto TheEnd

:errasm
echo _
echo Assembly Error
goto TheEnd

:TheEnd
 
pause
