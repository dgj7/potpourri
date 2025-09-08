@echo off
cls
premake clean
premake gmake
mingw32-make clean
mingw32-make config=debug