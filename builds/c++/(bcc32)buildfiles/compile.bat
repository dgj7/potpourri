PATH=c:\borland\bcc55\bin;%PATH%
del *.exe
del *.obj
del *.res
make -fmakefile err.txt
if exist application.exe goto RUN_EXE
:EDIT_ERR
call notepad.exe err.txt
:RUN_EXE
call application.exe
if exist err.txt delete err.txt
:END