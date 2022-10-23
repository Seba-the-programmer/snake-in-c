@echo off
dir *.c /B /A-D /S > %temp%\files
for /F "tokens=*" %%A in (%temp%\files) do (gcc -Wall -c %%A)
gcc main.o board.o snake.o apple.o -l Ws2_32 -o game.exe
del *.o
del %temp%\files
echo Compiling and linking complete