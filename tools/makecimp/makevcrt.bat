@echo off
makecimp msvcrt.txt
del msvcrt.def
del msvcrt.exp
move msvcrt.inc \masm32\include\msvcrt.inc
move msvcrt.lib \masm32\lib\msvcrt.lib
