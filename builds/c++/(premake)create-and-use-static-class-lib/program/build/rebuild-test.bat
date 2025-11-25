@echo off
cls
premake --file=premake-test.lua clean
premake --file=premake-test.lua gmake
mingw32-make clean
mingw32-make config=debug
REM mingw32-make config=release


echo ========================================
call "../bin/debug/library-test.exe"
echo.
echo ========================================
