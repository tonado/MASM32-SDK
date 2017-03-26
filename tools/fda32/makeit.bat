@echo off
: -------------------------------
: if resources exist, build them
: -------------------------------
if not exist main.rc goto over1
\masm32\BIN\Rc.exe /v main.rc
\masm32\BIN\Cvtres.exe /machine:ix86 main.res
:over1

if exist %1.obj del fda32.obj
if exist %1.exe del fda32.exe

: -----------------------------------------
: assemble template.asm into an OBJ file
: -----------------------------------------
\masm32\BIN\Ml.exe /c /coff fda32.asm
if errorlevel 1 goto errasm

: --------------------------------------------------
: link the main OBJ file with the resource OBJ file
: --------------------------------------------------
\masm32\BIN\Link.exe /SUBSYSTEM:WINDOWS fda32.obj main.obj
if errorlevel 1 goto errlink
dir fda32.*
goto TheEnd

:errlink
: ----------------------------------------------------
: display message if there is an error during linking
: ----------------------------------------------------
echo.
echo There has been an error while linking this project.
echo.
goto TheEnd

:errasm
: -----------------------------------------------------
: display message if there is an error during assembly
: -----------------------------------------------------
echo.
echo There has been an error while assembling this project.
echo.
goto TheEnd

:TheEnd

pause
