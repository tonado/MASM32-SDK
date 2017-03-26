@echo off
: -------------------------------
: if resources exist, build them
: -------------------------------
\masm32\bin\rc.exe /v rsrc.rc

if exist %1.obj del "getcolor.obj"
if exist %1.exe del "getcolor.exe"

: -----------------------------------------
: assemble getcolor.asm into an OBJ file
: -----------------------------------------
\masm32\bin\ml.exe /c /coff "getcolor.asm"
if errorlevel 1 goto errasm

: --------------------------------------------------
: link the main OBJ file including the resource file
: --------------------------------------------------
\masm32\bin\polink.exe /SUBSYSTEM:WINDOWS "getcolor.obj" rsrc.res
if errorlevel 1 goto errlink
dir "getcolor.*"
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
