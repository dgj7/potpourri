@echo off
cls

set projlocation=e:\devtools\trunk\c++\projects\library\
set projname=oglwin

del /s /q %projlocation%%projname%\src\mswin
robocopy /e %projlocation%mswin\src\mswin\ %projlocation%%projname%\src\mswin\

premake clean
premake gmake
mingw32-make clean
mingw32-make config=debug