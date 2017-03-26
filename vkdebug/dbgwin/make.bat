rem to get release version run it with -r key
\masm32\bin\rc.exe rsrc.rc > out.txt
@echo off
if -%1 == --r goto release
    @echo on
    \masm32\bin\ml.exe /c /coff /Zi dbgwin.asm Registry.asm File.asm >> out.txt
    \masm32\bin\link.exe /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV dbgwin.obj Registry.obj File.obj rsrc.res >> out.txt
    @echo off
    goto ext
:release
    if exist *.pdb del *.pdb
    if exist *.nms del *.nms
    if exist *.ilk del *.ilk
    @echo on
    \masm32\bin\ml.exe /c /coff dbgwin.asm Registry.asm File.asm >> out.txt
    \masm32\bin\link.exe /SUBSYSTEM:WINDOWS dbgwin.obj Registry.obj File.obj rsrc.res >> out.txt
    del *.obj
    @echo off
:ext

copy dbgwin.exe \masm32\bin\dbgwin.exe
if exist dbgwin.obj del dbgwin.obj

