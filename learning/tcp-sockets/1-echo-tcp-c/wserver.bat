@echo off
del server.exe
gcc server.c die.c -o server.exe -lws2_32
server.exe 5000
