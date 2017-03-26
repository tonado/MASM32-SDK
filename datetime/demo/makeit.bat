@echo off

if not exist rsrc.rc goto over1
\masm32\bin\rc /v rsrc.rc
\masm32\bin\cvtres /machine:ix86 rsrc.res
 :over1
 
if exist "WorldTimes.obj" del "WorldTimes.obj"
if exist "WorldTimes.exe" del "WorldTimes.exe"

\masm32\bin\ml /c /coff "WorldTimes.asm"
if errorlevel 1 goto errasm

if not exist rsrc.obj goto nores

\masm32\bin\Link /SUBSYSTEM:CONSOLE /OPT:NOREF "WorldTimes.obj" rsrc.res
 if errorlevel 1 goto errlink

dir "WorldTimes.*"
goto TheEnd

:nores
 \masm32\bin\Link /SUBSYSTEM:CONSOLE /OPT:NOREF "WorldTimes.obj"
 if errorlevel 1 goto errlink
dir "WorldTimes.*"
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
