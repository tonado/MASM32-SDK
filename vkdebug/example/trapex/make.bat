\masm32\bin\ml.exe /c /coff /Zi trapex.asm > out.txt
\masm32\bin\link.exe /DEBUG /DEBUGTYPE:CV /SUBSYSTEM:WINDOWS trapex.obj >> out.txt
