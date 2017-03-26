; --------------------------------------------------------------------------------------------------
;                           psxdll.inc Copyright The MASM32 SDK 1998-2010
; --------------------------------------------------------------------------------------------------

IFNDEF PSXDLL_INC
PSXDLL_INC equ <1>

GetProcessHeap PROTO STDCALL
HeapAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapFree PROTO STDCALL :DWORD,:DWORD,:DWORD
HeapReAlloc PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HeapSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlAnsiCharToUnicodeChar PROTO STDCALL :DWORD
RtlFillMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlMoveMemory PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlMultiByteToUnicodeN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlUnicodeToMultiByteSize PROTO STDCALL :DWORD,:DWORD,:DWORD
RtlUnwind PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
RtlUpcaseUnicodeChar PROTO STDCALL :DWORD
RtlUpcaseUnicodeToMultiByteN PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RtlZeroMemory PROTO STDCALL :DWORD,:DWORD
__PdxGetCmdLine PROTO C :VARARG
__PdxInitializeData PROTO STDCALL :DWORD,:DWORD
_exit PROTO C :VARARG
_sigjmp_store_mask PROTO C :VARARG
access PROTO C :VARARG
alarm PROTO C :VARARG
cfgetispeed PROTO C :VARARG
cfgetospeed PROTO C :VARARG
cfsetispeed PROTO C :VARARG
cfsetospeed PROTO C :VARARG
chdir PROTO C :VARARG
chmod PROTO C :VARARG
chown PROTO C :VARARG
close PROTO C :VARARG
closedir PROTO C :VARARG
creat PROTO C :VARARG
ctermid PROTO C :VARARG
cuserid PROTO C :VARARG
;;;; dup PROTO C :VARARG
dup2 PROTO C :VARARG
execl PROTO C :VARARG
execle PROTO C :VARARG
execlp PROTO C :VARARG
execv PROTO C :VARARG
execve PROTO C :VARARG
execvp PROTO C :VARARG
fcntl PROTO C :VARARG
fileno PROTO C :VARARG
fork PROTO C :VARARG
fpathconf PROTO C :VARARG
fstat PROTO C :VARARG
ftruncate PROTO C :VARARG
getcwd PROTO C :VARARG
getegid PROTO C :VARARG
getenv PROTO C :VARARG
geteuid PROTO C :VARARG
getgid PROTO C :VARARG
getgrgid PROTO C :VARARG
getgrnam PROTO C :VARARG
getgroups PROTO C :VARARG
getlogin PROTO C :VARARG
getpgrp PROTO C :VARARG
getpid PROTO C :VARARG
getppid PROTO C :VARARG
getpwnam PROTO C :VARARG
getpwuid PROTO C :VARARG
getreg PROTO C :VARARG
getuid PROTO C :VARARG
isatty PROTO C :VARARG
isatty2 PROTO C :VARARG
kill PROTO C :VARARG
link PROTO C :VARARG
lseek PROTO C :VARARG
mkdir PROTO C :VARARG
mkfifo PROTO C :VARARG
open PROTO C :VARARG
opendir PROTO C :VARARG
pathconf PROTO C :VARARG
pause PROTO C :VARARG
pipe PROTO C :VARARG
raise PROTO C :VARARG
read PROTO C :VARARG
readdir PROTO C :VARARG
remove PROTO C :VARARG
rename PROTO C :VARARG
rewinddir PROTO C :VARARG
rmdir PROTO C :VARARG
setgid PROTO C :VARARG
setpgid PROTO C :VARARG
setsid PROTO C :VARARG
setuid PROTO C :VARARG
sigaction PROTO C :VARARG
sigaddset PROTO C :VARARG
sigdelset PROTO C :VARARG
sigemptyset PROTO C :VARARG
sigfillset PROTO C :VARARG
sigismember PROTO C :VARARG
siglongjmp PROTO C :VARARG
signal PROTO C :VARARG
sigpending PROTO C :VARARG
sigprocmask PROTO C :VARARG
sigsuspend PROTO C :VARARG
sleep PROTO C :VARARG
stat PROTO C :VARARG
sysconf PROTO C :VARARG
system PROTO C :VARARG
tcdrain PROTO C :VARARG
tcflow PROTO C :VARARG
tcflush PROTO C :VARARG
tcgetattr PROTO C :VARARG
tcgetpgrp PROTO C :VARARG
tcsendbreak PROTO C :VARARG
tcsetattr PROTO C :VARARG
tcsetpgrp PROTO C :VARARG
time PROTO C :VARARG
times PROTO C :VARARG
ttyname PROTO C :VARARG
umask PROTO C :VARARG
uname PROTO C :VARARG
unlink PROTO C :VARARG
utime PROTO C :VARARG
;;;; wait PROTO C :VARARG
waitpid PROTO C :VARARG
  ; write arg type unknown

ELSE
  echo -----------------------------------------
  echo WARNING duplicate include file psxdll.inc
  echo -----------------------------------------
ENDIF
