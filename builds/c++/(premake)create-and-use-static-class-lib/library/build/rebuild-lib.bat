@echo off
cls
premake --file=premake-lib.lua clean
premake --file=premake-lib.lua gmake
mingw32-make clean
mingw32-make config=debug
mingw32-make config=release


echo ========================================
echo build completed.
echo ========================================
