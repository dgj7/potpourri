@echo off
del client.exe
gcc client.c die.c -o client.exe -lws2_32
client.exe 127.0.0.1 "this is a string that has more than 32 characters in order to test multiple sends" 5000
