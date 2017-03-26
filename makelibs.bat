@echo off

cd include
call bldlibs.bat
cd ..

cd tools\makecimp
call makevcrt.bat
cd ..\..

cd m32lib
call make.bat
cd ..

cd fpulib
call make.bat
cd ..

cd DateTime
call make.bat
cd ..

cd vkdebug
call setup.bat
cd ..

cd testinst
call makeit.bat
if exist testinst.exe testinst.exe
if not exist testinst.exe goto badinst

cd ..
goto theend

:badinst
@echo.
@echo It appears that your installation did not work corectly.
@echo Try running the MAKELIBS.BAT file in the MASM32 directory
@echo to manually build the libraries for MASM32. Ensure that
@echo your computer is not running other tasks when you try to
@echo build the libraries manually.

pause

:theend











