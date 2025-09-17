@echo off


:: Get the project name.  This will create the other necessary files.
set /p projectname=Enter project name:

:: Create the run scripts
echo [%time%]: Creating scripts for [%projectname%]...
echo @echo off > runrelease.bat
echo cd .. >> runrelease.bat
echo cd bin >> runrelease.bat
echo cd release >> runrelease.bat
echo %projectname% >> runrelease.bat
echo cd .. >> runrelease.bat
echo cd .. >> runrelease.bat
echo cd build >> runrelease.bat

echo @echo off > rundebug.bat
echo cd .. >> rundebug.bat
echo cd bin >> rundebug.bat
echo cd debug >> rundebug.bat
echo %projectname% >> rundebug.bat
echo cd .. >> rundebug.bat
echo cd .. >> rundebug.bat
echo cd build >> rundebug.bat


:: Creating premake config file...
echo [%time%]: Creating premake config file...
echo solution( "%projectname%" ) > premake4.lua
echo 	configurations { "Debug", "Release" } >> premake4.lua
@echo.	>> premake4.lua
echo 		project( "%projectname%" ) >> premake4.lua
echo 			kind( "WindowedApp" )			-- "WindowedApp" or "ConsoleApp" >> premake4.lua
echo 			language( "C++" ) >> premake4.lua
echo 			files( { "../src/**.cpp", "../src/**.h" } ) >> premake4.lua
echo 			links { "opengl32", "glu32" } >> premake4.lua
echo 			libdirs( { "/cb/MinGW/lib", "/cb/MinGW/libexec" } ) >> premake4.lua
echo 			includedirs( { "/cb/MinGW/include", "/cb/MinGW/include/GL" } ) >> premake4.lua
@echo.	>> premake4.lua
echo 				configuration "Debug" >> premake4.lua
echo 					defines { "DEBUG" } >> premake4.lua
echo 					targetdir( "../bin/Debug" ) >> premake4.lua
echo 					objdir( "../obj/Debug" ) >> premake4.lua
echo 					flags { "NoPCH", "OptimizeSpeed", "Symbols" } >> premake4.lua
@echo. >> premake4.lua
echo 				configuration "Release" >> premake4.lua
echo 					defines { "NDEBUG" } >> premake4.lua
echo 					targetdir( "../bin/Release" ) >> premake4.lua
echo 					objdir( "../obj/Release" ) >> premake4.lua
echo 					flags { "NoFramePointer", "NoPCH", "OptimizeSpeed" } >> premake4.lua


:: Creating build files...
echo [%time%]: Creating build files...
echo @echo off > builddebug.bat
echo mingw32-make clean >> builddebug.bat
echo mingw32-make config=debug >> builddebug.bat

echo @echo off > buildrelease.bat
echo mingw32-make clean >> buildrelease.bat
echo mingw32-make config=release >> buildrelease.bat

echo @echo off > clean.bat
echo mingw32-make clean >> clean.bat

echo @echo off > restart.bat
echo del *.sdf >> restart.bat
echo del *.sln >> restart.bat
echo del *.suo >> restart.bat
echo del *.workspace >> restart.bat
echo del *.cbp >> restart.bat
echo del *.vcproj >> restart.bat
echo del *.vcxproj >> restart.bat
echo del *.filters >> restart.bat
echo del *.user >> restart.bat
echo del *.xml >> restart.bat
echo del *.layout >> restart.bat
echo del *.make >> restart.bat
echo del Makefile >> restart.bat
echo rmdir _UpgradeReport_Files >> restart.bat
echo rmdir ipch >> restart.bat
echo cls >> restart.bat



rem restart.bat
echo [%time%]: Creating makefile and project files...
premake4.exe --cc=gcc gmake
premake4.exe codeblocks
premake4.exe vs2008

echo [%time%]: Build file process completed.


