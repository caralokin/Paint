@echo off
cd bibliotecas\obj
gcc  -Wall -pedantic -Wextra  -I..\include ..\lib\*.c -c
cd..
ar -cru libpbrush.a .\obj\*.o
cd..
gcc -Wall -pedantic -Wextra pbrush++.c -I.\bibliotecas\include -L.\bibliotecas -lpbrush -lgdi32 -o pbrush++.exe 
pbrush++.exe