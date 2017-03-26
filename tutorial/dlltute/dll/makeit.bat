@echo off

if exist dlltute.obj del dlltute.obj
if exist dlltute.dll del dlltute.dll

\masm32\bin\ml /c /coff dlltute.asm

\masm32\bin\Link /SUBSYSTEM:WINDOWS /DLL /DEF:dlltute.def dlltute.obj

dir dlltute.*

pause