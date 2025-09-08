@echo off
cls
premake clean
premake gmake
mingw32-make clean
mingw32-make config=debug
REM mingw32-make config=release


echo ========================================
call "../bin/debug/logger-test.exe"
echo.
echo ========================================
